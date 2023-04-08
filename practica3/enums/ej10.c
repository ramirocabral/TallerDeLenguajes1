#include <stdio.h>
#include <math.h>

enum telefono{
    BLUETOOTH=128,
    WIFI=64, 
    GPS=32, 
    NFC=16, 
    USB=8, 
    HDMI=4, 
    JACK=2, 
    SD=1
    };

int main(){
    const int TODOS = 255;
    const int NINGUNO = 0;

    enum telefono tel;

    int activos = 0;

    //prender el bluetooth

    tel = BLUETOOTH;

    activos = activos | tel;  //or

    //apagar el bluetooth

    tel = ~BLUETOOTH;  //ca1

    activos = activos & tel;

    //invertir el estado actual del modulo bluetooth

    tel = BLUETOOTH;

    activos = activos ^ tel;  //xor

    //determinar si el modulo bluetooth esta activo

    tel = BLUETOOTH;

    if(activos & tel)
        printf("Bluetooth activo");


    return 0;
}

