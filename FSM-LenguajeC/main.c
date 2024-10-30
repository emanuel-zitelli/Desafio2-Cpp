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
    
    printf("Ingrese el tiempo en Verde del Semaforo Principal: "); //el verde del principal no menor a 1
    tiempoPrincipal.verde=validarTiempoInf(1);
    
    printf("Ingrese el tiempo en Amarillo del Semaforo Principal: "); //lo mismo con el amarillo
    tiempoPrincipal.amarillo=validarTiempoInf(1);
    
    printf("Ingrese el tiempo en Verde del Semaforo Secundario: "); //el verde del secundario no menor a 1, y que no sea mas extendido que la principal
    tiempoSecundaria.verde=validarTiempoInfSup(1, tiempoPrincipal.verde);
    
    printf("Ingrese el tiempo en Amarillo del Semaforo Secundario: ");
    tiempoSecundaria.amarillo=validarTiempoInf(1);

    


    printf("Hay autos en la carretera secundaria? (si:1 | no:0): ");
    scanf("%d", &hayAutos);
    
    if(hayAutos==true)
    {
         
        cambiarSemaforo(&estadoPrincipal, 0, 0, 1); //rojo en la principal, que pasen los autos de la secundaria
        cambiarSemaforo(&estadoSecundaria, 1, 0, 0); //verde
    }
    else if(hayAutos==false)
    {
        tiempoPrincipal.verde+=5; //extendemos la duracion de verde en el semaforo principal si no hay autos en secundaria
        cambiarSemaforo(&estadoPrincipal, 1, 0, 0); // verde en la principal y extendemos su estado verde
        cambiarSemaforo(&estadoSecundaria, 0, 0, 1); // rojo en la secundaria
    }
    
    
   
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