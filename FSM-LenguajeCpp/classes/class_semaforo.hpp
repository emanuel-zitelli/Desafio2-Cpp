#ifndef CLASS_SEMAFORO_HPP
#define CLASS_SEMAFORO_HPP

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

    //establecemos los estados con metodos tambie
    void establecerEstado(bool verde, bool amarillo, bool rojo)
    {
        estadoVerde.setEstado(verde);
        estadoAmarillo.setEstado(amarillo);
        estadoRojo.setEstado(rojo);

        timer=1; //Cuando cambiamos el Estado empieza una cuenta regresiva nueva
    }
    
    void cambiarSemaforo(std::string* estadoActual, std::string* otroSemaforo)
    {
        if(estadoVerde.estaActivado()==true)
        {
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
                estadoAmarillo.mostrar(&timer);
            }
            else
                estadoRojo.mostrar(&timer);
            timer++;
        }
    }

protected:

    double timer;
    std::string estadoAnterior;

private:

    EstadoVerde estadoVerde;
    EstadoAmarillo estadoAmarillo;
    EstadoRojo estadoRojo;

};


#endif //CLASS_SEMAFORO_HPP