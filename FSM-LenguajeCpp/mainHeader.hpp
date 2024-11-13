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

struct Ingreso
{
    double tiempoVerde;
    double tiempoAmarillo;

    int ciclo;

    bool hayAutos;

};

enum ExtremoCiclo
{
    Comienzo=0,
    Fin=2
};

enum Ciclo
{
    Verde,
    Amarillo,
    Rojo
};



//las clases van a lo ultimo, sino el compilador no les da las declaraciones de estructuras, enums, funciones, etc
#include "./classes/class_Estado.hpp" //establece como se comportan los distintos estados, es una clase base

#include "./classes/class_estadoVerde.hpp" //heredan de estado, padres de semaforo
#include "./classes/class_estadoAmarillo.hpp"
#include "./classes/class_estadoRojo.hpp"

#include "./classes/class_Semaforo.hpp" //hereda clases padres

//funciones
double validarTiempo(double limInf);
double validarTiempo(double limInf, double limSup);
void inicializarSemaforo(Semaforo& principal, Semaforo& secundario, Ingreso& inicializarPrincipal, Ingreso& inicializarSecundario);





#endif //MAINHEADER_HPP