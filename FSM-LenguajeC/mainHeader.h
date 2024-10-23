#ifndef MAINHEADER_H
#define MAINHEADER_H

//bibliotecas
#include <stdlib.h>
#include <stdio.h>
#include <windows.h> //para sleep()
#include <stdbool.h> //define true y false

typedef struct 
{
    float verde;
    float amarillo;
    //float rojo; el tiempo del rojo depende del estado de la otra carretera

}Tiempo; //en segundos

typedef struct
{
    short int verde;
    short int amarillo;
    short int rojo;
}Estado;

Tiempo inicializarTiempos(Tiempo carretera, float verde, float amarillo);
void cambiarSemaforo(Estado* estado, short int verde, short int amarillo, short int rojo);
void semaforoPrincipal(unsigned long int* timer, Estado* estadoPrincipal, Estado* anteriorPrincipal, Tiempo tiempoPrincipal, Estado* estadoSecundario);
void semaforoSecundario(unsigned long int* timer, Estado* estadoSecundario, Estado* anteriorSecundaria, Tiempo tiempoSecundaria, Estado* estadoPrincipal);

#endif //MAINHEADER_H