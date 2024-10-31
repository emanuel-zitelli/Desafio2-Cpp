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
            <<", o menor al tiempo en Verde del semaforo principal, que es" 
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

void inicializarSemaforo(Semaforo* Principal, Semaforo* Secundaria)
{
    //sensor
    bool hayAutos;
    //variables para guardar los tiempos
    double tiempoVerdeP;
    double tiempoVerdeS;
    double tiempoAmarilloP;
    double tiempoAmarilloS;

    std::cout << "Ingrese el tiempo en Verde del Semaforo Principal: "; //el verde del principal no menor a 1
    tiempoVerdeP=validarTiempo(1);
    
    std::cout << "Ingrese el tiempo en Amarillo del Semaforo Principal: "; //lo mismo con el amarillo
    tiempoAmarilloP=validarTiempo(1);
    
    (*Principal).establecerTiempos(tiempoVerdeP, tiempoAmarilloP);

    std::cout << "Ingrese el tiempo en Verde del Semaforo Secundario: "; //el verde del secundario no menor a 1, y que no sea mas extendido que la principal
    tiempoVerdeS=validarTiempo(1, tiempoVerdeP);
    
    std::cout << "Ingrese el tiempo en Amarillo del Semaforo Secundario: ";
    tiempoAmarilloS=validarTiempo(1);

    (*Secundaria).establecerTiempos(tiempoVerdeS, tiempoAmarilloS);

    std::cout << "Hay autos en la carretera secundaria? (si:1 | no:0): ";
    std::cin >> hayAutos;
    
    if(hayAutos==true)
    {
        (*Principal).establecerEstado(0, 0, 1); //rojo al comienzo
        (*Secundaria).establecerEstado(1, 0, 0); //verde, para que pasen los autos
    }
    else if(hayAutos==false)
    {
        tiempoVerdeP+=5; //extendemos la duracion de verde en el semaforo principal si no hay autos en secundaria
        (*Principal).establecerTiempos(tiempoVerdeP, tiempoAmarilloP);

        (*Principal).establecerEstado(1, 0, 0); //rojo al comienzo
        (*Secundaria).establecerEstado(0, 0, 1);
    }
}