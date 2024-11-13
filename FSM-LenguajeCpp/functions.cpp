#include "mainHeader.hpp"

double validarTiempo(double limInf, double limSup) 
{
    short int flag=0;
    double dato;

    do
    {
        if(flag==1)
        {
            std::cout 
            << "Dato incorrecto. No puede ser menor a "
            << limInf
            <<", o menor al tiempo en Verde del semaforo principal, que es " 
            << limSup << "\n";
        }
        flag=1;
        std::cin >> dato;
    }while (dato<limInf || dato>=limSup);
    
    return dato;
}
double validarTiempo(double limInf) //sobrecarga de funciones, segun el parametro va a una u otra
{
    short int flag=0;
    double dato;

    do
    {
        if(flag==1)
        {
            std::cout 
            << "El dato no puede ser menor a  "
            <<limInf 
            << "\n" ;
        }
        flag=1;
        std::cin >> dato;
    } while (dato<limInf);
    
    return dato;
}

void inicializarSemaforo(Semaforo& principal, Semaforo& secundario, Ingreso& inicializarPrincipal, Ingreso& inicializarSecundario)
{
    //sensor
    bool hayAutos;

    std::cout << "Ingrese el tiempo en Verde del Semaforo Principal: "; //el verde del principal no menor a 1
    inicializarPrincipal.tiempoVerde=validarTiempo(1);
    
    std::cout << "Ingrese el tiempo en Amarillo del Semaforo Principal: "; //lo mismo con el amarillo
    inicializarPrincipal.tiempoAmarillo=validarTiempo(1);
    

    std::cout << "Ingrese el tiempo en Verde del Semaforo Secundario: "; //el verde del secundario no menor a 1, y que no sea mas extendido que la principal
    inicializarSecundario.tiempoVerde=validarTiempo(1, inicializarPrincipal.tiempoVerde);
    
    std::cout << "Ingrese el tiempo en Amarillo del Semaforo Secundario: ";
    inicializarSecundario.tiempoAmarillo=validarTiempo(1);

    std::cout << "Hay autos en la carretera secundaria? (si:1 | no:0): ";
    std::cin >> hayAutos;

    if(hayAutos==true)
    {
        principal.inicializarEstados(inicializarPrincipal.tiempoVerde, inicializarPrincipal.tiempoAmarillo, 2); //rojo al comienzo
        secundario.inicializarEstados(inicializarSecundario.tiempoVerde, inicializarSecundario.tiempoAmarillo, 0); //verde, para que pasen los autos
    }
    else if(hayAutos==false)
    {
        inicializarPrincipal.tiempoVerde+=5; //extendemos la duracion de verde en el semaforo principal si no hay autos en secundaria
        principal.inicializarEstados(inicializarPrincipal.tiempoVerde, inicializarPrincipal.tiempoAmarillo, 0); //verde al comienzo
        secundario.inicializarEstados(inicializarSecundario.tiempoVerde, inicializarSecundario.tiempoAmarillo, 2); //rojo, porque no hay autos
    }
}