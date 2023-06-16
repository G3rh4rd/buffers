#ifndef STACK_H
#define STACK_H

#include "../utils/data_types.h"
#include <stdint.h>
#include <stdbool.h>

typedef struct {
    uint32_t length;
    uint32_t data_entry_size;
    data_type_e data_type;
    void *data;
} stack_t;

bool stack_init(data_type_e data_type, stack_t *stack);
bool stack_push(stack_t *stack, void *data_in);
bool stack_pop(stack_t *stack, void *data_out);
bool stack_clear(stack_t *stack);

#endif /* STACK_H */