#include <stdio.h>

struct rgb_24{
    unsigned char red;
    unsigned char green;
    unsigned char blue;
};


struct rgb_16{
    unsigned int red:5;
    unsigned int green:6;
    unsigned int blue:5;
};

void rgb24_to_rgb16(struct rgb_24 *rgb24, struct rgb_16 *rgb16){
    rgb16->red = rgb24->red >> 3;
    rgb16->green = rgb24->green >> 2;
    rgb16->blue = rgb24->blue >> 3;
}

void rgb16_to_rgb24(struct rgb_16 *rgb16, struct rgb_24 *rgb24){
    rgb24->red = rgb16->red << 3;
    rgb24->green = rgb16->green << 2;
    rgb24->blue = rgb16->blue << 3;
}


int main(){
    struct rgb_24 rgb24;
    struct rgb_16 rgb16;

    rgb24.red = 5;
    rgb24.green = 6;
    rgb24.blue = 7;

    rgb24_to_rgb16(&rgb24, &rgb16);

    printf("rgb24: %d %d %d \t rgb16: %d %d %d \n", rgb24.red, rgb24.green, rgb24.blue, rgb16.red, rgb16.green, rgb16.blue);

    return 0;
}