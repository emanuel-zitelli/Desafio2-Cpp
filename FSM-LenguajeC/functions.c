#include "mainHeader.h"

void cambiarSemaforo(Estado* estado, short int verde, short int amarillo, short int rojo)
{
    (*estado).verde=verde;
    (*estado).amarillo=amarillo;
    (*estado).rojo=rojo;
}

void semaforoPrincipal(unsigned long int* timer, Estado* estadoPrincipal, Estado* anteriorPrincipal, Tiempo tiempoPrincipal)
{
    if((*estadoPrincipal).verde == 1) 
    {
        printf("Estado Carretera Principal: Verde, timer: %i \n", *timer);
        if((*timer)+1>tiempoPrincipal.verde)
            {
                *timer = 0;
                *anteriorPrincipal = *estadoPrincipal;
                cambiarSemaforo(estadoPrincipal, 0, 1, 0);
                
            
            }
    }
    else if((*estadoPrincipal).amarillo==1)
    {   
        printf("Estado Carretera Principal: Amarillo, timer: %i \n", *timer);
        if((*timer)+1>tiempoPrincipal.amarillo)
           {
                *timer = 0;

                if((*anteriorPrincipal).verde == 1)
                    cambiarSemaforo(estadoPrincipal, 0, 0, 1);
                if((*anteriorPrincipal).rojo == 1)
                    cambiarSemaforo(estadoPrincipal, 1, 0, 0);
                
           }
    }
    else if((*estadoPrincipal).rojo == 1)
    {
        printf("Estado Carretera Principal: Rojo, timer: %i \n", *timer);
        if((*timer)+1>tiempoPrincipal.rojo)
        {
            
            *timer = 0;
            *anteriorPrincipal = *estadoPrincipal;
            cambiarSemaforo(estadoPrincipal, 0, 1, 0);
            
        }
    }
}

void semaforoSecundario(unsigned long int* timer, Estado* estadoSecundaria, Estado* anteriorSecundaria, Tiempo tiempoSecundaria)
{
    if((*estadoSecundaria).verde == 1) 
    {
        printf("Estado Carretera Secundaria:Verde, timer: %i \n", *timer);
        if((*timer)+1>tiempoSecundaria.verde)
            {
                *timer = 0;
                *anteriorSecundaria = *estadoSecundaria;
                cambiarSemaforo(estadoSecundaria, 0, 1, 0);
                
            
            }
    }
    else if((*estadoSecundaria).amarillo==1)
    {   
        printf("Estado Carretera Secundaria: Amarillo, timer: %i \n", *timer);
        if((*timer)+1>tiempoSecundaria.amarillo)
           {
                *timer = 0;

                if((*anteriorSecundaria).verde == 1)
                    cambiarSemaforo(estadoSecundaria, 0, 0, 1);
                if((*anteriorSecundaria).rojo == 1)
                    cambiarSemaforo(estadoSecundaria, 1, 0, 0);
                
           }
    }
    else if((*estadoSecundaria).rojo == 1)
    {
        printf("Estado Carretera Secundaria: Rojo, timer %i \n", *timer);
        if((*timer)+1>tiempoSecundaria.rojo)
        {
            *timer = 0;
            *anteriorSecundaria = *estadoSecundaria;
            cambiarSemaforo(estadoSecundaria, 0, 1, 0);
            
        }
    }
}



   

