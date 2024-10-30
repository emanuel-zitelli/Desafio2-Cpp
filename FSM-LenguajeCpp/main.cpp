#include "mainHeader.hpp"

int main()
{

    Semaforo Principal;
    Semaforo Secundaria;
    std::string estadoPrincipal;
    std::string estadoSecundaria;

    Principal.establecerEstado(1, 0, 0);
    Principal.establecerTiempos(10, 5);

    Secundaria.establecerEstado(0, 0, 1);
    Secundaria.establecerTiempos(10, 5);
    
    
    while(true)
    {   
        Principal.mostrarSemaforo("Semaforo Principal: ");
        Principal.cambiarSemaforo(&estadoPrincipal, &estadoSecundaria);

        Secundaria.mostrarSemaforo("Semaforo Secundario: ");
        Secundaria.cambiarSemaforo(&estadoSecundaria, &estadoPrincipal);
       
        std::this_thread::sleep_for(std::chrono::seconds(1)); //le damos una espera de 1 segundo a la ejecucion del programa
        system("cls");
        
    }
    return 0;
}