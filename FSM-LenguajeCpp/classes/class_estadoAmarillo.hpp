#ifndef CLASS_ESTADOAMARILLO_HPP
#define CLASS_ESTADOAMARILLO_HPP

class EstadoAmarillo : virtual public Estado
{
public:

    void mostrar(double timer) override
    {
        std::cout << "Estado: Amarillo. Cambiando en: " << duracion-(timer)+1 << std::endl;;
    }

    void run(double timer) override
    {
        if(getCiclo()==estado::Amarillo && timer<duracion)
        {
            mostrar(timer);
        }
        else
            rotarEstado();
    }

};
#endif //CLASS_ESTADOAMARILLO_HPP