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

#include "./classes/class_principal.hpp" //heredan semaforo
#include "./classes/class_secundario.hpp"

#include "./classes/class_maquinaDeEstado.hpp" //heredan principal y semaforo

#endif //MAINHEADER_HPP