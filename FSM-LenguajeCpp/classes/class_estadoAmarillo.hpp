#ifndef CLASS_ESTADOAMARILLO_HPP
#define CLASS_ESTADOAMARILLO_HPP

class EstadoAmarillo : virtual public Estado
{
public:

    void mostrar(double* timer) override
    {
        std::cout << "Estado: Amarillo. Cambiando en: " << duracion-(*timer)+1 << std::endl;;
    }

    void setDuracion(double duracionAmarillo) override
    {
        duracion = duracionAmarillo;
    }

    void setEstado(bool enAmarillo) override
    {
        activado = enAmarillo;
    }
};
#endif //CLASS_ESTADOAMARILLO_HPP