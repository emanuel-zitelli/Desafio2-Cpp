#include "mainHeader.h"

int main()
{
    unsigned long int timerPrincipal=1;
    unsigned long int timerSecundaria=1;
    int hayAutos; //sensor

    Tiempo tiempoPrincipal;
    Tiempo tiempoSecundaria;

    Estado estadoPrincipal;
    Estado estadoSecundaria;

    Estado anteriorPrincipal;
    Estado anteriorSecundaria;
    
    printf("Hay autos en la carretera secundaria? (si:1 | no:0): ");
    scanf("%d", &hayAutos);
    
    if(hayAutos==true)
    {
        tiempoPrincipal=inicializarTiempos(tiempoPrincipal, 30, 5); 
        cambiarSemaforo(&estadoPrincipal, 0, 0, 1); //rojo en la principal, que pasen los autos de la secundaria
        cambiarSemaforo(&estadoSecundaria, 1, 0, 0); //verde
    }
    else if(hayAutos==false)
    {
        tiempoPrincipal = inicializarTiempos(tiempoPrincipal, 35, 5); // extiende el estado verde de la principal
        cambiarSemaforo(&estadoPrincipal, 1, 0, 0); // verde en la principal y extendemos su estado verde
        cambiarSemaforo(&estadoSecundaria, 0, 0, 1); // rojo en la secundaria
    }
    tiempoSecundaria=inicializarTiempos(tiempoSecundaria, 15, 5); //siempre el mismo tiempo
    
   
    cambiarSemaforo(&anteriorPrincipal, 0, 0, 0); //hacelos que los estados anteriores sean nulos
    cambiarSemaforo(&anteriorSecundaria, 0, 0, 0);

    //funcionalidad de semaforo. 
    while(true)
    {
        //la funcionalidad basica es la de tener un timer e ir mostrando mensajes segun su estado y el tiempo
        semaforoPrincipal(&timerPrincipal, &estadoPrincipal, &anteriorPrincipal, tiempoPrincipal, &estadoSecundaria);
        semaforoSecundario(&timerSecundaria, &estadoSecundaria, &anteriorSecundaria, tiempoSecundaria, &estadoPrincipal);
        
        
        timerPrincipal++;
        timerSecundaria++;
        
        Sleep(1000);
        system("cls");
    }
    return 0;
}