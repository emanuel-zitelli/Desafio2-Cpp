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

//implementacion nueva de estructura
typedef struct 
{
    int ciclo; //3 ciclos, de 0 a 2
    int movimiento;
    int timer;
    int autorizarCambio;

    char estado[9];
    char vieneDe[9];

    Tiempo tiempoEstados;

}controlSemaforo;

float validarTiempoInf(float limInf);
float validarTiempoInfSup(float limInf, float limSup);
void cambiarSemaforo(Estado* estado, short int verde, short int amarillo, short int rojo);
void semaforoPrincipal(unsigned long int* timer, Estado* estadoPrincipal, Estado* anteriorPrincipal, Tiempo tiempoPrincipal, Estado* estadoSecundario);
void semaforoSecundario(unsigned long int* timer, Estado* estadoSecundario, Estado* anteriorSecundaria, Tiempo tiempoSecundaria, Estado* estadoPrincipal);


//nueva implementacion
void moverCiclo(controlSemaforo* controlPrincipal, controlSemaforo* controlSecundario);
void semaforo(controlSemaforo* control, controlSemaforo* controlSecundario);
void inicializarSemaforos(controlSemaforo* control, controlSemaforo* controlSecundario, int* sensor);
#endif //MAINHEADER_H