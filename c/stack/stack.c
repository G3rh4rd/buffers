#include "stack.h"

bool stack_init(data_type_e data_type, stack_t *stack) {
    bool retVal = false;

    stack->data_entry_size = data_type_get_size(data_type);
    
    if(stack->data_entry_size > 0) {
        stack->data_type = data_type;
        stack->length = 0;
        retVal = true;
    }
}

bool stack_push(stack_t *stack, void *data_in) {
    bool retVal = false;

    if(stack->data_entry_size > 0) {
        // TODO: check if malloc is needed, if the length is 0
        /**
         * If realloc cannot extend the buffer, it will return NULL and leave
         * the original buffer intact; however, if we assign NULL back to array,
         * we lose our handle to the original buffer, causing a memory leak, so
         * we assign the result to a temporary variable.
         */
        void *tmp = realloc(stack->data, (stack->length + 1) * stack->data_entry_size);

        if(tmp) {
        stack->data = tmp;
            memcpy(&stack->data[stack->length * stack->data_entry_size], data_in, stack->data_entry_size);
            stack->length++;
            retVal = true;
        } else {
            // realloc failed to extend the buffer; original buffer
            // is left intact.
        }
    }

    return retVal;
}

bool stack_pop(stack_t *stack, void *data_out) {
    bool retVal = false;

    if(stack->data_entry_size > 0) {
        if(stack->length > 0) {
            memcpy(data_out, &stack->data[(stack->length-1) * stack->data_entry_size], stack->data_entry_size);
        }

        if(stack->length == 1) {
            free(stack->data);
            stack->length = 0;
            retVal = true;
        } else {
            /**
             * If realloc cannot extend the buffer, it will return NULL and leave
             * the original buffer intact; however, if we assign NULL back to array,
             * we lose our handle to the original buffer, causing a memory leak, so
             * we assign the result to a temporary variable.
             */
            void *tmp = realloc(stack->data, (stack->length - 1) * stack->data_entry_size);

            if(tmp) {
                stack->data = tmp;
                stack->length--;
                retVal = true;
            } else {
                // realloc failed to extend the buffer; original buffer
                // is left intact.
            }
        }
    }

    return retVal;
}

bool stack_clear(stack_t *stack) {
    bool retVal = false;

    if(stack->length > 0) {
        free(stack->data);
        stack->length = 0;
        stack->data_entry_size = 0;
        retVal = true;
    }

    return retVal;
}