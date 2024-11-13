#ifndef CLASS_ESTADOAMARILLO_HPP
#define CLASS_ESTADOAMARILLO_HPP

class EstadoAmarillo : public Estado
{
public:

    void mostrar(const double& timer) override
    {
        std::cout << "Estado: Amarillo. Cambiando en: " << duracion-(timer)+1 << std::endl;;
    }

    void run(double& timer, int& ciclo, int& movimiento, int ciclo_otro, double timerOtro, double duracionAmarillo, std::string anteriorOtro) override
    {
        mostrar(timer);

        if(timer==duracion)
        {
            timer=0;
            rotarEstado(ciclo, movimiento);
        }
    }

};
#endif //CLASS_ESTADOAMARILLO_HPP