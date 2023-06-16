#ifndef DATA_TYPES_H
#define DATA_TYPES_H

#include <stdint.h>

typedef enum {
    UNKNOWN,
    CHAR,
    SHORT,
    INT,
    FLOAT,
    DOUBLE,
    STRUCT
} data_type_e;

#endif /* DATA_TYPES_H */