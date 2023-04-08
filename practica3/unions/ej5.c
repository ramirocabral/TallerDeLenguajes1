#include <stdio.h>

typedef struct f1{
    int x;
    int y;
    int alto;
    int ancho;
} forma1;

typedef union vent{
    forma1 f1;
    int f2[2][2]; //x1,x2 /ancho,alto
    int f3[4]; //x1,x2,ancho,alto
}
