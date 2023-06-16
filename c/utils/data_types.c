#include "data_types.h"

uint32_t data_type_get_size(data_type_e type) {
    uint32_t size = 0;
    switch(type) {
        case CHAR:
            size = sizeof(char);
        break;
        case SHORT:
            size = sizeof(short);
        break;
        case INT:
            size = sizeof(int);
        break;
        case FLOAT:
            size = sizeof(float);
        break;
        case DOUBLE:
            size = sizeof(double);
        break;
        default:
            size = 0;
        break;
    }

    return size;
}