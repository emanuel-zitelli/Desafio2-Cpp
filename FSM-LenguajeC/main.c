#include "mainHeader.h"

int main()
{
    unsigned long int timerPrincipal=1;
    unsigned long int timerSecundaria=1;
    
    
    Tiempo tiempoPrincipal;
    Tiempo tiempoSecundaria;

    Estado estadoPrincipal;
    Estado estadoSecundaria;

    Estado anteriorPrincipal;
    Estado anteriorSecundaria;
    
    tiempoPrincipal.verde=35; //35
    tiempoPrincipal.amarillo=5; //5
    
    tiempoSecundaria.verde=15; //15
    tiempoSecundaria.amarillo=5; //5

    //tiempoPrincipal.rojo= (tiempoSecundaria.verde + tiempoSecundaria.amarillo);
    //tiempoSecundaria.rojo= (tiempoPrincipal.verde + tiempoPrincipal.amarillo);

    cambiarSemaforo(&anteriorPrincipal, 0, 0, 0);
    cambiarSemaforo(&anteriorSecundaria, 0, 0, 0);

    cambiarSemaforo(&estadoPrincipal, 1, 0, 0); //verde
    cambiarSemaforo(&estadoSecundaria, 0, 0, 1); //rojo

    while(1)
    {
        semaforoPrincipal(&timerPrincipal, &estadoPrincipal, &anteriorPrincipal, tiempoPrincipal, &estadoSecundaria);
        semaforoSecundario(&timerSecundaria, &estadoSecundaria, &anteriorSecundaria, tiempoSecundaria, &estadoPrincipal);
        timerPrincipal++;
        timerSecundaria++;

        
        Sleep(1000);
        system("cls");
    }
    return 0;
}