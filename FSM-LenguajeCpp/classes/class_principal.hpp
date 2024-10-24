#ifndef CLASS_PRINCIPAL_HPP
#define CLASS_PRINCIPAL_HPP

class Principal : virtual public Semaforo
{
public: 

    void mostrarSemaforo() override
    {
        std::cout << "Semaforo: Principal ";
    }

    void rotarEstados(double* timer)
    {
        if(enVerde==true)
        {
            mostrarSemaforo();
            mostrar(timer);

            if(((*timer)+1)>duracion)
            {
                (*timer)=0;
                setEstado(false);
                setEstado(true);
                setEstado(false);
            }
        }

        else if(enAmarillo==true)
        {
            mostrarSemaforo();
            mostrarAmarillo(timer);

            if(((*timer)+1)>duracion)
            {
                (*timer)=0;
                setEstado(false);
                setEstado(false);
                setEstado(true);
            }
        }

        else if(enRojo==true)
        {
            mostrarSemaforo();
            mostrar(timer);

            if(((*timer)+1)>duracion)
            {
                (*timer)=0;
                setEstado(true);
                setEstado(false);
                setEstado(false);
            }

            
        }
    }
    

protected: 
};


    
#endif //CLASS_PRINCIPAL_HPP