#include <stdio.h>

typedef struct telefono{
    unsigned int bluetooth:1;
    unsigned int wifi:1;
    unsigned int gps:1;
    unsigned int datos:1;
    unsigned int frontal:1;
    unsigned int trasera:1;
    unsigned int linterna:1;
    unsigned int vibrar:1;
} telefono;

