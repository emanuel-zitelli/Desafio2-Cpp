#include "mainHeader.hpp"

int main()
{

    while(true)
    {
        std::cout << "Hola";
        std::this_thread::sleep_for(std::chrono::seconds(1)); //lo mismo que sleep en C
    }
    return 0;
}