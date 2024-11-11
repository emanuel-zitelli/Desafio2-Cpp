#include "mainHeader.h"

void cambiarSemaforo(Estado* estado, short int verde, short int amarillo, short int rojo)
{
    (*estado).verde=verde;
    (*estado).amarillo=amarillo;
    (*estado).rojo=rojo;
}

float validarTiempoInfSup(float limInf, float limSup) 
{
    short int flag=0;
    float dato;

    do
    {
        if(flag==1)
        {
            printf("Dato incorrecto. No puede ser menor a %.1f, o menor al tiempo en Verde del semaforo principal, que es %.1f \n", limInf, limSup);
        }
        flag=1;
        scanf("%f", &dato);
    } while (dato<limInf || dato>=limSup);
    
    return dato;
}
float validarTiempoInf(float limInf) //sobrecarga de funciones, segun el parametro va a una u otra
{
    short int flag=0;
    float dato;

    do
    {
        if(flag==1)
        {
            printf("El dato no puede ser menor a %.1f \n", limInf);
        }
        flag=1;
        scanf("%f", &dato);
    } while (dato<limInf);
    
    return dato;
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

//nueva implementacion
void moverCiclo(controlSemaforo* control, controlSemaforo* controlOtroSemaforo)
{   
    switch((*control).ciclo) //controla los cambios de estado, de rojo a amarillo y de amarillo a verde, y luego a la inversa
    {
        case 0:
             (*control).movimiento = 1;
             break;
        case 2:
            (*control).movimiento = -1;
            break;
    }      

    switch((*control).estado[0])
    {
        case 'v':

            if((*control).timer==(*control).tiempoEstados.verde)
            {
                strcpy((*control).vieneDe, "verde");
                (*control).ciclo += (*control).movimiento;
                (*control).timer=0;
                (*control).autorizarCambio=0;
            }
            break;

        case 'a':

            if((*control).timer==(*control).tiempoEstados.amarillo)
            {
                (*control).ciclo += (*control).movimiento;
                (*control).timer=0;
                (*control).autorizarCambio = 1; //como voy a salir de amarillo el otro semaforo puede salir de rojo tambien
            }
            break;

        case 'r':

            if((strcmp((*controlOtroSemaforo).vieneDe,"verde")==0 && (*controlOtroSemaforo).autorizarCambio) || (*controlOtroSemaforo).timer==(*controlOtroSemaforo).tiempoEstados.amarillo && strcmp((*controlOtroSemaforo).estado, "amarillo")==0 && strcmp((*controlOtroSemaforo).vieneDe,"verde")==0) 
            {
                strcpy((*control).vieneDe, "rojo");
                (*control).ciclo += (*control).movimiento;
                (*control).timer=0;
            }  
            break;
    }
}

void semaforo(controlSemaforo* control, controlSemaforo* controlOtroSemaforo)
{
    
    int estadoVerde=0, estadoAmarillo=1, estadoRojo=2,  
    estados[3][3]= {
        {1, 0, 0},  //fila de verde
        {0, 1, 0},  //fila de amarillo
        {0, 0, 1}   //fila de rojo
    };


    if(estados[estadoVerde][(*control).ciclo])
    {
        printf("Estado: Verde. Cambiando: en %.1fs\n", ((*control).tiempoEstados.verde+1)-(*control).timer);
        strcpy((*control).estado, "verde");
    }
        
    else if(estados[estadoAmarillo][(*control).ciclo])
    {
        printf("Estado: Amarillo. Cambiando: en %.1fs\n", ((*control).tiempoEstados.amarillo+1)-(*control).timer);
        strcpy((*control).estado, "amarillo");
    }
    
    else if(estados[estadoRojo][(*control).ciclo])
    {
        printf("Estado: Rojo. Tiempo transcurrido: %i\n", (*control).timer-1);
        strcpy((*control).estado, "rojo");
    }
/*

    switch((*control).ciclo)
    {
        case 0:
            printf("Estado: Verde. Cambiando: en %.1fs\n", ((*control).tiempoEstados.verde+1)-(*control).timer);
            strcpy((*control).estado, "verde");
            break;

        case 1:
            printf("Estado: Amarillo. Cambiando: en %.1fs\n", ((*control).tiempoEstados.amarillo+1)-(*control).timer);
            strcpy((*control).estado, "amarillo");
            break;

        case 2:
            printf("Estado: Rojo. Tiempo transcurrido: %i\n", (*control).timer-1);
            strcpy((*control).estado, "rojo");
            break;
    }
*/
moverCiclo(control, controlOtroSemaforo);
}

void inicializarSemaforos(controlSemaforo* control, controlSemaforo* controlSecundario, int* sensor)
{
    (*control).timer=0;
    (*controlSecundario).timer=0;
   
    
    printf("Ingrese el tiempo en Verde del Semaforo Principal: "); //el verde del principal no menor a 1
    (*control).tiempoEstados.verde=validarTiempoInf(1);
    
    printf("Ingrese el tiempo en Amarillo del Semaforo Principal: "); //lo mismo con el amarillo
    (*control).tiempoEstados.amarillo=validarTiempoInf(1);
    
    printf("Ingrese el tiempo en Verde del Semaforo Secundario: "); //el verde del secundario no menor a 1, y que no sea mas extendido que la principal
    (*controlSecundario).tiempoEstados.verde=validarTiempoInfSup(1, (*control).tiempoEstados.verde);
    
    printf("Ingrese el tiempo en Amarillo del Semaforo Secundario: ");
    (*controlSecundario).tiempoEstados.amarillo=validarTiempoInf(1);


    printf("Hay autos en la carretera secundaria? (si:1 | no:0): ");
    scanf("%d", sensor);
    
    if((*sensor)==true)
    {
         
        (*control).ciclo=2; //rojo en la principal, que pasen los autos de la secundaria
        (*controlSecundario).ciclo=0; //verde
    }
    else
    {
        (*control).tiempoEstados.verde+=5; //extendemos la duracion de verde en el semaforo principal si no hay autos en secundaria
        (*control).ciclo=0; // verde en la principal y extendemos su estado verde
        (*controlSecundario).ciclo=2; // rojo en la secundaria
    }
}
   

