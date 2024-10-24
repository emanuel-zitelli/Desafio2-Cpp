#include "mainHeader.hpp"

int main()
{
    Principal prueba;
    double timer=1;

    prueba.setDuracion(5);
    prueba.setDuracion(5);
    prueba.setDuracion(5);
    
    prueba.setEstado(true);

    
    while(true)
    {   prueba.rotarEstados(&timer);
        
        timer++;
        std::this_thread::sleep_for(std::chrono::seconds(1)); //lo mismo que sleep en C
        system("cls");
    }
    return 0;

    
}