#ifndef CLASS_ESTADOROJO_HPP
#define CLASS_ESTADOROJO_HPP

class EstadoRojo : virtual public Estado 
{
public:

    void mostrar(double timer) override 
    {
        std::cout << "Estado: Rojo. Esperando al otro semaforo. Tiempo Transcurrido:  " << timer-1 << std::endl;
    }
 
    void run(double timer) override
    {
        if(getCiclo()==estado::Rojo && timer<duracion)
        {
            mostrar(timer);
        }
        else
            rotarEstado();
    }
};
#endif //CLASS_ESTADOROJO_HPP