#include "circular_buffer.h"

#include <stdio.h>

// TODO: custom datatype to store structs
bool circ_buf_init(data_type_e type, uint32_t length, circular_buffer_t *circ_buf) {
    bool retVal = false;

    if(!circ_buf->isInitialized && length > 0) {
        circ_buf->entry_data_size = data_type_get_size(type);

        if(circ_buf->entry_data_size > 0) {
            circ_buf->data = malloc(length * circ_buf->entry_data_size);
            circ_buf->data_type = type;
            circ_buf->head_idx = 0;
            circ_buf->tail_idx = 0;
            circ_buf->length = length;
            circ_buf->isInitialized = true;
        }
    }

    return retVal;
}

bool circ_buf_push(circular_buffer_t *circ_buf, void *data_in) {
    bool retVal = false;

    if(circ_buf->isInitialized) {
        uint32_t next_head = circ_buf->head_idx + 1;

        if(next_head == circ_buf->length) next_head = 0;
        if(next_head == circ_buf->tail_idx) {
            // buffer is full, do not add entry
        } else {
            memcpy(&circ_buf->data[circ_buf->head_idx], data_in, circ_buf->entry_data_size);
            circ_buf->head_idx = next_head;
        }
    }
}

bool circ_buf_pop(circular_buffer_t *circ_buf, void *data_out) {
    bool retVal = false;

    if(circ_buf->isInitialized && circ_buf->tail_idx != circ_buf->head_idx) {
        memcpy(data_out, &circ_buf->data[circ_buf->tail_idx], circ_buf->entry_data_size);

        circ_buf->tail_idx++;
        if(circ_buf->tail_idx >= circ_buf->length) circ_buf->tail_idx = 0;
    }
}

bool circ_buf_reset(circular_buffer_t *circ_buf) {
    bool retVal = false;

    if(circ_buf->isInitialized) {
        circ_buf->head_idx = 0;
        circ_buf->tail_idx = 0;
        circ_buf->length = 0;
        retVal = true;
    }

    return retVal;
}

bool circ_buf_clear(circular_buffer_t *circ_buf) {
    bool retVal = false;

    if(circ_buf->isInitialized) {
        circ_buf->data_type = UNKNOWN;
        circ_buf->head_idx = 0;
        circ_buf->tail_idx = 0;
        circ_buf->length = 0;
        circ_buf->entry_data_size = 0;
        circ_buf->isInitialized = false;
        free(circ_buf->data);

        retVal = true;
    }

    return retVal;
}