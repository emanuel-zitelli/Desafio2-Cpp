#ifndef CLASS_ESTADOROJO_HPP
#define CLASS_ESTADOROJO_HPP

class EstadoRojo : public Estado 
{
public:

    void mostrar(const double& timer) override 
    {
        std::cout << "Estado: Rojo. Esperando al otro semaforo. Tiempo Transcurrido:  " << timer-1 << std::endl;
    }
 
    void run(double& timer, int& ciclo, int& movimiento, int ciclo_otro, double timerOtro, double duracionAmarillo, std::string anteriorOtro) override
    {
        mostrar(timer);
        
        if((ciclo_otro==2) || (ciclo_otro==1 && timerOtro==duracionAmarillo && anteriorOtro=="verde"))
        {
            timer=0;
            rotarEstado(ciclo, movimiento);
        }
    }
};
#endif //CLASS_ESTADOROJO_HPP