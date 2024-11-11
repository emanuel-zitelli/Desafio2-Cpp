#ifndef MAINHEADER_HPP
#define MAINHEADER_HPP

//bibliotecas
#include <iostream>
#include <thread>   // Para std::this_thread::sleep_for
#include <chrono>   // Para std::chrono::seconds

//clases
#include "./classes/class_Estado.hpp" //establece como se comportan los distintos estados, es una clase base

#include "./classes/class_estadoVerde.hpp" //heredan de estado, padres de semaforo
#include "./classes/class_estadoAmarillo.hpp"
#include "./classes/class_estadoRojo.hpp"

#include "./classes/class_Semaforo.hpp" //hereda clases padres

enum estado
{
    Verde,
    Amarillo,
    Rojo
};

enum extremoCiclo
{
    Comienzo,
    Fin
};

//funciones
double validarTiempo(double limInf);
double validarTiempo(double limInf, double limSup);
//void inicializarSemaforo(Semaforo* Principal, Semaforo* Secundaria);


#endif //MAINHEADER_HPP