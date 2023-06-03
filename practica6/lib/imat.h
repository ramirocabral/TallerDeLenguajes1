


int potencia(int x, int y){
    if (y == 0) return 1;
    return x*potencia(x,y-1);
}

int cuadrado(int x){return (x*x);}

int cubo(int x){return (x*x*x);}

int absoluto(int i){
    if (i < 0) return -i;
    return i;
}

int factorial(int i){
    if (i == 1) return 1;
    return i*factorial(i-1);
}

int sumatoria(int i){
    return (i*(i+1)/2);
}

int multiplo(int x, int y){
    if (x % y) return 0;
    return 1;
}

int divisor(int x, int y){
    if (y%x) return 0;
    return 1;
}

int par(int i){
    if (i%2) return 0;
    return 1;
}

int impar(int i){
    return (i%2);
}