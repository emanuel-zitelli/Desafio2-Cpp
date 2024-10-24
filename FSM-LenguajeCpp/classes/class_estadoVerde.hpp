#ifndef CLASS_ESTADOVERDE_HPP
#define CLASS_ESTADOVERDE_HPP

class EstadoVerde : virtual public Estado 
{
public:

    void mostrar(double* timer) override 
    {
        std::cout << "Estado: Verde. Cambiando en: " << duracion - (*timer) + 1 << std::endl;
    }

    void setDuracion(double duracionVerde) override 
    {
        duracion = duracionVerde;
    }

    void setEstado(bool enVerde) override 
    {
        activado = enVerde;
    }
};
#endif //CLASS_ESTADOVERDE_HPP