#include "mainHeader.hpp"

int main()
{
    Semaforo principal, secundario;
    double timerPrincipal=0, timerSecundario=0;
    std::string anteriorPrincipal, anteriorSecundario;
    Ingreso inicializarPrincipal, inicializarSecundario;
    
    inicializarSemaforo(principal, secundario, inicializarPrincipal, inicializarSecundario);
    while(true)
    {   
        system("cls");
        
        timerPrincipal++;
        timerSecundario++;

        anteriorPrincipal=principal.semaforo(timerPrincipal, "Semaforo Principal ", secundario.getCiclo(), timerSecundario, inicializarSecundario.tiempoAmarillo, anteriorSecundario);
        std::cout << "\n";
        anteriorSecundario=secundario.semaforo(timerSecundario, "Semaforo Secundario ", principal.getCiclo(), timerPrincipal, inicializarPrincipal.tiempoAmarillo, anteriorPrincipal);

        std::this_thread::sleep_for(std::chrono::seconds(1)); //le damos una espera de 1 segundo a la ejecucion del programa
    }
    return 0;
}