#include <stdio.h>

struct circulo{
    unsigned int radio;
};

struct elipse{
    unsigned int radioX;
    unsigned int radioY;
};

struct rectangulo{
    unsigned int base;
    unsigned int altura;
};

typedef union figura{
    struct circulo circulo;
    struct elipse elipse;
    struct rectangulo rectangulo;
} figura;

struct fig{
    figura figura;
    unsigned char tipo;
};


double calcularSuperficie(struct fig fig);

int main(){
    struct fig fig;
    fig.tipo = 5;
    fig.figura.rectangulo.base = 10;
    fig.figura.rectangulo.altura = 5;
    printf("Superficie: %f", calcularSuperficie(fig));
    return 0;
}

double calcularSuperficie(struct fig fig){
    switch (fig.tipo){
        case 1:
            return 3.14 * fig.figura.circulo.radio * fig.figura.circulo.radio;
        case 2:
            return 3.14 * fig.figura.elipse.radioX * fig.figura.elipse.radioY;
        case 3:
            return (fig.figura.rectangulo.base * fig.figura.rectangulo.altura)/2;
        default:
            return (fig.figura.rectangulo.base * fig.figura.rectangulo.altura);
    }
}
