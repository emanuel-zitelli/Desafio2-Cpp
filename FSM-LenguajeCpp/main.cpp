#include "mainHeader.hpp"

int main()
{
    //semaforos
    Semaforo Principal;
    Semaforo Secundaria;
    //sus estados en variables globales para poder transmitirselo al otro semaforo
    std::string estadoPrincipal;
    std::string estadoSecundaria;
    
    
    inicializarSemaforo(&Principal, &Secundaria);
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