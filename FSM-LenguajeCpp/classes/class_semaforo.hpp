#ifndef CLASS_SEMAFORO_HPP
#define CLASS_SEMAFORO_HPP

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

class Semaforo 
{
public:

    //metodos en virtual para que funcione el semaforo
     void mostrarSemaforo(std::string mensaje)
     {
        std::cout << mensaje;
     }

    //establecemos los tiempos con metodos
    void establecerTiempos(float tiempoVerde, float tiempoAmarillo)
    {
        estadoVerde.setDuracion(tiempoVerde);
        estadoAmarillo.setDuracion(tiempoAmarillo);
    }

    void moverCiclo(controlSemaforo* control, controlSemaforo* controlOtroSemaforo)
    {
        

        switch ((*control).estado[0])
        {
        case 'v': // Estado 'verde'
            if ((*control).timer == (*control).tiempoEstados.verde)
            {
                (*control).vieneDe = "verde";
                (*control).ciclo += (*control).movimiento;
                (*control).timer = 0;
                (*control).autorizarCambio = false;
            }
            break;

        case 'a': // Estado 'amarillo'
            if ((*control).timer == (*control).tiempoEstados.amarillo)
            {
                (*control).ciclo += (*control).movimiento;
                (*control).timer = 0;
                (*control).autorizarCambio = true; // Como voy a salir de amarillo, el otro semáforo puede salir de rojo también
            }
            break;

        case 'r': // Estado 'rojo'
            if (((*controlOtroSemaforo).vieneDe == "verde" && (*controlOtroSemaforo).autorizarCambio) || ((*controlOtroSemaforo).timer == (*controlOtroSemaforo).tiempoEstados.amarillo && (*controlOtroSemaforo).estado == "amarillo" && (*controlOtroSemaforo).vieneDe == "verde"))
            {
                (*control).vieneDe = "rojo";
                (*control).ciclo += (*control).movimiento;
                (*control).timer = 0;
            }
            break;
        }
    }
    void semaforo(controlSemaforo* control, controlSemaforo* controlOtroSemaforo, std::string nombreSemaforo)
    { 
        mostrarSemaforo(nombreSemaforo);
        switch ((*control).ciclo)
        {
            case estado::Verde:
                estadoVerde.mostrar((*control).timer);
                (*control).estado = "verde";
                break;

            case estado::Amarillo:
                estadoAmarillo.mostrar((*control).timer);
                (*control).estado = "amarillo";
                break;

            case estado::Rojo:
                estadoRojo.mostrar((*control).timer);
                (*control).estado = "rojo";
                break;
        }
        moverCiclo(control, controlOtroSemaforo);
    }
/*
    //establecemos los estados con metodos tambien
    void establecerEstado(bool verde, bool amarillo, bool rojo)
    {
        estadoVerde.setEstado(verde);
        estadoAmarillo.setEstado(amarillo);
        estadoRojo.setEstado(rojo);

        timer=1; //Cuando cambiamos el Estado empieza una cuenta regresiva nueva
    }
*/
/*  
    void cambiarSemaforo(std::string* estadoActual, std::string* otroSemaforo, std::string nombreSemaforo)
    {
        if(estadoVerde.estaActivado()==true)
        {   
            mostrarSemaforo(nombreSemaforo);
            estadoVerde.mostrar(&timer);
            timer++;

            if (timer > estadoVerde.CuantoDura())
            {
                establecerEstado(0, 1, 0);
                (*estadoActual) = "amarillo";
                estadoAnterior = "verde";
            }
        }
        else if(estadoAmarillo.estaActivado()==true)
        {
            mostrarSemaforo(nombreSemaforo);
            estadoAmarillo.mostrar(&timer);
            timer++;
            if (timer > estadoAmarillo.CuantoDura())
            {
                if (estadoAnterior == "verde")
                {
                    establecerEstado(0, 0, 1);
                    (*estadoActual) = "rojo";
                }

                else if (estadoAnterior == "rojo")
                {
                    establecerEstado(1, 0, 0);
                    (*estadoActual) = "verde";
                }
                estadoAnterior = "amarillo";
            }
        }

        else if(estadoRojo.estaActivado()==true)
        {
            if(*otroSemaforo == "rojo")
            {
                
                establecerEstado(0, 1, 0);
                (*estadoActual)="amarillo";
                estadoAnterior = "rojo";
                mostrarSemaforo(nombreSemaforo);
                estadoAmarillo.mostrar(&timer);
            }
            else
            {
                mostrarSemaforo(nombreSemaforo);
                estadoRojo.mostrar(&timer);
            }
                
            timer++;
        }
    }*/

protected:
    

private:

    EstadoVerde estadoVerde;
    EstadoAmarillo estadoAmarillo;
    EstadoRojo estadoRojo;

};


#endif //CLASS_SEMAFORO_HPP