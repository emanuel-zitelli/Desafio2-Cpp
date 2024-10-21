#include "mainHeader.h"

void cambiarSemaforo(temporizador estado, short int verde, short int amarillo, short int rojo)
{
    estado.verde=verde;
    estado.amarillo=amarillo;
    estado.rojo=rojo;
}