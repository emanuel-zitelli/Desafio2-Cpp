#ifndef CLASS_ESTADOVERDE_HPP
#define CLASS_ESTADOVERDE_HPP

class EstadoVerde : virtual public Estado 
{
public:

    void mostrar(double timer) override 
    {
        std::cout << "Estado: Verde. Cambiando en: " << duracion - (timer)+1<< std::endl;
    }

    void run(double timer) override
    {
        if(getCiclo()==estado::Verde && timer<duracion)
        {
            mostrar(timer);
        }
        else
            rotarEstado();
    }
    
};
#endif //CLASS_ESTADOVERDE_HPP