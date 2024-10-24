#ifndef CLASS_ESTADOROJO_HPP
#define CLASS_ESTADOROJO_HPP

class EstadoRojo : virtual public Estado 
{
public:

    void mostrar(double* timer) override 
    {
        std::cout << "Estado: Rojo. Cambiando en: " << duracion - (*timer) + 1 << std::endl;
    }

    void setDuracion(double duracionRojo) override 
    {
        duracion = duracionRojo;
    }

    void setEstado(bool enRojo) override 
    {
        activado = enRojo;
    }
};
#endif //CLASS_ESTADOROJO_HPP