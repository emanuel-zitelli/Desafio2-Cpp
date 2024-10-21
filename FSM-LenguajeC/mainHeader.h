#ifndef MAINHEADER_H
#define MAINHEADER_H

//bibliotecas
#include <stdlib.h>
#include <stdio.h>

typedef struct 
{
    short int verde;
    short int amarillo;
    short int rojo;

}temporizador;


void cambiarSemaforo(temporizador estado, short int verde, short int amarillo, short int rojo);


#endif //MAINHEADER_H