#include <stdio.h>

int main(){
    int pais,cant;
    int cant1 = 9999, cant2 = 9999,pais1 = -1,pais2 = -1;
    for (int i=0; i < 4 ; i++){
        printf("Ingrese el pais: ");
        scanf("%d",&pais);
        printf("Ingrese la cantidad de habitantes: ");
        scanf("%d",&cant);
        if (cant < cant1){
            cant2 = cant1;
            pais2 = pais1;
            cant1 = cant;
            pais1 = pais;
        }
        else if (cant < cant2){
            cant2 = cant;
            pais2 = pais;
        }
    }

        printf("El pais con menor cantidad de habitantes es: %d con %d habitantes \n", pais1,cant1);
        printf("El segundo pais con menor cantidad de habitantes es: %d con %d habitantes", pais2,cant2);
        
    return 0;
}