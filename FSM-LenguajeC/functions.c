#include "mainHeader.h"

void cambiarSemaforo(Estado* estado, short int verde, short int amarillo, short int rojo)
{
    (*estado).verde=verde;
    (*estado).amarillo=amarillo;
    (*estado).rojo=rojo;
}

Tiempo inicializarTiempos(Tiempo carretera, float verde, float amarillo)
{
    carretera.verde=verde;
    carretera.amarillo=amarillo;

    return carretera;
}

void semaforoPrincipal(unsigned long int* timer, Estado* estadoPrincipal, Estado* anteriorPrincipal, Tiempo tiempoPrincipal, Estado* estadoSecundario)
{ 
    //si su estado esta en verde, mostramos por pantalla el estado en verde y el tiempo
    if((*estadoPrincipal).verde == 1) 
    {
        printf("Estado Carretera Principal: Verde. Cambiando: en %.1fs\n", ((tiempoPrincipal.verde)-(*timer)+1));
        //si el segundo que viene ya se pasa del tiempo en verde...
        if((*timer)+1>tiempoPrincipal.verde)
            {
                *timer = 0; //reestablecemos el timer
                *anteriorPrincipal = *estadoPrincipal; //guardamos el estado
                cambiarSemaforo(estadoPrincipal, 0, 1, 0); //pasamos el semaforo a amarillo
            }
        
    }
    else if((*estadoPrincipal).amarillo==1) //si esta en estado amarillo, lo mostramos por pantalla
    {   
        printf("Estado Carretera Principal: Amarillo. Cambiando: en %.1fs\n", ((tiempoPrincipal.amarillo)-(*timer)+1));
        if((*timer)+1>tiempoPrincipal.amarillo) //si el proximo segundo se acaba el tiempo de amarillo...
           {
                *timer = 0; //reestablecemos el timer
                //evaluamos si hay que ir a verde o a rojo, de esta manera siempre vamos de verde a rojo a traves de amarillo
                if((*anteriorPrincipal).verde == 1)
                    cambiarSemaforo(estadoPrincipal, 0, 0, 1);
                if((*anteriorPrincipal).rojo == 1)
                    cambiarSemaforo(estadoPrincipal, 1, 0, 0);
                
           }
           
    }
    else if((*estadoPrincipal).rojo == 1) //si el estado es rojo, mostramos por pantalla
    {   
        if((*estadoSecundario).rojo == 1)
        {
            *timer = 1; //reiniciamos el timer
            *anteriorPrincipal = *estadoPrincipal; //guardamos el estado
            cambiarSemaforo(estadoPrincipal, 0, 1, 0); //volvemos a amarillo, que luego de su tiempo ira a verde

            /*tenemos que poner una condicion para el printf, sino cambia a amarillo pero solo tenemos el mensaje de rojo
             y en secundaria se cambia a rojo, por lo que sale un estado rojo para ambos semaforos
             */
            printf("Estado Carretera Principal: Amarillo. Cambiando: en %.1fs\n", ((tiempoPrincipal.amarillo)-(*timer)+1));
        }
        else
            printf("Estado Carretera Principal: Rojo. Esperando al Semaforo Secundario. Tiempo Transcurrido: %lu\n", (*timer)-1);
            
    }
}

void semaforoSecundario(unsigned long int* timer, Estado* estadoSecundaria, Estado* anteriorSecundaria, Tiempo tiempoSecundaria, Estado* estadoPrincipal )
{
    if((*estadoSecundaria).verde == 1) 
    {
        printf("Estado Carretera Secundaria:Verde. Cambiando: en %.1fs\n", ((tiempoSecundaria.verde)-(*timer)+1));
        if((*timer)+1>tiempoSecundaria.verde)
            {
                *timer = 0;
                *anteriorSecundaria = *estadoSecundaria;
                cambiarSemaforo(estadoSecundaria, 0, 1, 0);
            }
        
    }
    else if((*estadoSecundaria).amarillo==1)
    {   
        printf("Estado Carretera Secundaria: Amarillo. Cambiando: en %.1fs\n", ((tiempoSecundaria.amarillo)-(*timer)+1));
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
        printf("Estado Carretera Secundaria: Rojo. Esperando al Semaforo Principal. Tiempo Transcurrido: %lu\n", (*timer)-1);
        if((*estadoPrincipal).rojo == 1)
        {
            *timer = 1;
            *anteriorSecundaria = *estadoSecundaria;
            cambiarSemaforo(estadoSecundaria, 0, 1, 0);
        }
        
            
    }
}



   

