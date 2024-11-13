#ifndef CLASS_SEMAFORO_HPP
#define CLASS_SEMAFORO_HPP

class Semaforo  
{
public:

    //establecemos los tiempos con metodos
    void inicializarEstados(double tiempoVerde, double tiempoAmarillo, int ciclo)
    {
        verde.setDuracionMax(tiempoVerde);
        amarillo.setDuracionMax(tiempoAmarillo);

        Semaforo::ciclo=ciclo; //puede ser de cualquier objeto
    }

    //getter de ciclo, para que el otro semaforo sepa el estado
    int getCiclo()
    {
        return ciclo;
    }
    
    //funcionalidad
    std::string semaforo(double& timer, std::string nombreSemaforo, int ciclo_otro, double timerOtro, double duracionAmarillo, std::string anteriorOtro)
    { 
        std::cout << nombreSemaforo;
        switch(ciclo)
        {
            case Ciclo::Verde :
                verde.run(timer, ciclo, movimiento, ciclo_otro, timerOtro, duracionAmarillo, anteriorOtro);
                vieneDe="verde";
                break;

            case Ciclo::Amarillo :
                amarillo.run(timer, ciclo, movimiento, ciclo_otro, timerOtro, duracionAmarillo, anteriorOtro);
                break;

            case Ciclo::Rojo :
                 rojo.run(timer, ciclo, movimiento, ciclo_otro, timerOtro, duracionAmarillo, anteriorOtro);
                 vieneDe="rojo";
                 break;
        }
        return vieneDe;
    }
private:

    EstadoVerde verde;
    EstadoAmarillo amarillo;
    EstadoRojo rojo;

    int ciclo;
    int movimiento;

    std::string vieneDe;
};

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
#endif //CLASS_SEMAFORO_HPP

