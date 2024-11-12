#ifndef MAINHEADER_HPP
#define MAINHEADER_HPP

//bibliotecas
#include <iostream>
#include <thread>   // Para std::this_thread::sleep_for
#include <chrono>   // Para std::chrono::seconds
struct Tiempo
{
    float verde;
    float amarillo;
    //float rojo; el tiempo del rojo depende del estado de la otra carretera

}; //en segundos


struct controlSemaforo
{
    int ciclo; //3 ciclos, de 0 a 2
    int movimiento;
    int timer;
    int autorizarCambio;

    std::string estado;
    std::string vieneDe;

    Tiempo tiempoEstados;

};
enum estado
{
    Verde,
    Amarillo,
    Rojo
};
/*
enum extremoCiclo
{
    Comienzo=1,
    Fin=2
};
*/
//funciones
double validarTiempo(double limInf);
double validarTiempo(double limInf, double limSup);
//void inicializarSemaforo(Semaforo* Principal, Semaforo* Secundaria);

//las clases van a lo ultimo, sino el compilador no les da las declaraciones de estructuras, enums, funciones, etc
#include "./classes/class_Estado.hpp" //establece como se comportan los distintos estados, es una clase base

#include "./classes/class_estadoVerde.hpp" //heredan de estado, padres de semaforo
#include "./classes/class_estadoAmarillo.hpp"
#include "./classes/class_estadoRojo.hpp"

#include "./classes/class_Semaforo.hpp" //hereda clases padres






#endif //MAINHEADER_HPP