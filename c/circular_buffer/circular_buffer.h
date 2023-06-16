#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include "../utils/data_types.h"

#include "stdint.h"
#include <stdbool.h>

typedef struct {
    bool isInitialized;
    uint32_t length;
    uint32_t head_idx;
    uint32_t tail_idx;
    data_type_e data_type;
    uint32_t entry_data_size;
    void *data;
} circular_buffer_t;

bool circ_buf_init(data_type_e type, uint32_t length, circular_buffer_t *circ_buf);
bool circ_buf_push(circular_buffer_t *circ_buf, void *data_in);
bool circ_buf_pop(circular_buffer_t *circ_buf, void *data_out);
bool circ_buf_reset(circular_buffer_t *circ_buf);
bool circ_buf_clear(circular_buffer_t *circ_buf);

#endif /* CIRCULAR_BUFFER_H */