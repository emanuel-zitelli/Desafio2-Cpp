#ifndef CLASS_ESTADOVERDE_HPP
#define CLASS_ESTADOVERDE_HPP

class EstadoVerde : public Estado 
{
public:

    void mostrar(const double& timer) override 
    {
        std::cout << "Estado: Verde. Cambiando en: " << duracion - (timer)+1<< std::endl;
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
#endif //CLASS_ESTADOVERDE_HPP