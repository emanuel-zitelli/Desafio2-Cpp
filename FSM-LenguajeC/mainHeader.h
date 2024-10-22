#ifndef MAINHEADER_H
#define MAINHEADER_H

//bibliotecas
#include <stdlib.h>
#include <stdio.h>
#include <windows.h> //para sleep()

typedef struct 
{
    float verde;
    float amarillo;
    float rojo;

}Tiempo;

typedef struct
{
    short int verde;
    short int amarillo;
    short int rojo;
}Estado;


void cambiarSemaforo(Estado* estado, short int verde, short int amarillo, short int rojo);
void semaforoPrincipal(unsigned long int* timer, Estado* estadoPrincipal, Estado* anteriorPrincipal, Tiempo tiempoPrincipal);
void semaforoSecundario(unsigned long int* timer, Estado* estadoSecundario, Estado* anteriorSecundaria, Tiempo tiempoSecundaria);

#endif //MAINHEADER_H