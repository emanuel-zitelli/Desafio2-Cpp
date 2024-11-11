#ifndef CLASS_ESTADO_HPP
#define CLASS_ESTADO_HPP

class Estado //clase base de verde, amarillo y rojo
{
public: 

    virtual void mostrar(double timer) = 0; // Metodos abstractos, son la base de los estados verde, amarillo y rojo
    virtual void run(double timer) = 0;
    
    void setCicloActual(int ciclo) //para establecer el ciclo de cada semaforo
    {
        Estado::ciclo = ciclo;
    }

    void rotarEstado()
    {
        switch (ciclo) // Controla los cambios de estado, de rojo a amarillo y de amarillo a verde, y luego a la inversa.
        {
        case extremoCiclo::Comienzo:
            movimiento = 1;
            break;

        case extremoCiclo::Fin:
            movimiento = -1;
            break;
        }

        ciclo+=movimiento;
    }

    int getCiclo() //para que cada estado pueda consultar en que ciclo estan
    {
        return ciclo;
    }

    int getTimer(int estado) //se pueden obtener los timers para que un semaforo consulte el timer del otro
    {
        if(estado==estado::Verde)
            return timerVerde;

        else if(estado==estado::Amarillo)
            return timerAmarillo;
    }
    

protected:
    float duracion;
    float activo;
    
    int movimiento;
    std::string estado;
    std::string vieneDe;

private:
    int ciclo; //3 ciclos, de 0 a 2
    double timerVerde=0;
    double timerAmarillo=0;
}; 



#endif //CLASS_ESTADO_HPP