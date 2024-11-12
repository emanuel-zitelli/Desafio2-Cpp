#include "mainHeader.hpp"

int main()
{
    Semaforo principal;
    Semaforo secundario;
    double timerPrincipal=0, timerSecundario=0;
    
    principal.inicializarEstados(10, 5, 10, 0);
    secundario.inicializarEstados(5, 5, 15, 2);
    
    while(true)
    {   
        system("cls");
        
        timerPrincipal++;
        timerSecundario++;

        principal.semaforo(timerPrincipal, "Semaforo Principal ", secundario.getCiclo(), timerSecundario);
        std::cout << "\n";
        secundario.semaforo(timerSecundario, "Semaforo Secundario ", principal.getCiclo(), timerPrincipal);

        std::this_thread::sleep_for(std::chrono::seconds(1)); //le damos una espera de 1 segundo a la ejecucion del programa
    }
    return 0;
}