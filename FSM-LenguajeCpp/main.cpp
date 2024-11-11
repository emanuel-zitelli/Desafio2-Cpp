#include "mainHeader.hpp"

int main()
{
    //semaforos
    Semaforo principal;
    Semaforo secundaria;
    //sus estados en variables accesibles a toda funcion, para poder transmitirselo al otro semaforo
   controlSemaforo controlPrincipal;
   controlSemaforo controlSecundaria;
    
    controlPrincipal.tiempoEstados.verde=15;
    controlPrincipal.tiempoEstados.amarillo=5;
    principal.establecerTiempos(controlPrincipal.tiempoEstados.verde, controlPrincipal.tiempoEstados.amarillo);
   

    controlSecundaria.tiempoEstados.verde=10;
    controlSecundaria.tiempoEstados.amarillo=5;
    secundaria.establecerTiempos(controlSecundaria.tiempoEstados.verde, controlSecundaria.tiempoEstados.amarillo);
    controlPrincipal.ciclo=0;
    controlSecundaria.ciclo=2;

    controlPrincipal.timer=0;
    controlSecundaria.timer=0;


    //inicializarSemaforo(&principal, &secundaria);
    while(true)
    {   
        system("cls");
        controlPrincipal.timer++;
        controlSecundaria.timer++;
        
        principal.semaforo(&controlPrincipal, &controlSecundaria, "Semaforo Principal ");
        std::cout << "\n";
        secundaria.semaforo(&controlSecundaria, &controlPrincipal, "Semaforo Secundario ");
       
        std::this_thread::sleep_for(std::chrono::seconds(1)); //le damos una espera de 1 segundo a la ejecucion del programa
        system("cls");
        
    }
    return 0;
}