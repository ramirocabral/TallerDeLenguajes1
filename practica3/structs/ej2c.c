#include <stdio.h>

typedef struct punt{
    float x;
    float y;
    float z;
} punto3d;

int main(){
    printf("%d \n", sizeof(punto3d));

    punto3d p[4];

    printf("%d \n", sizeof(p));

}

