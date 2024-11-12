#ifndef CLASS_ESTADO_HPP
#define CLASS_ESTADO_HPP

class Estado //clase base de verde, amarillo y rojo
{
public: 

    virtual void mostrar(const double& timer) = 0; // Metodos abstractos, son la base de los estados verde, amarillo y rojo
    virtual void run(double& timer, int& ciclo, int& movimiento, int ciclo_otro, int timerOtro) = 0; //la funcionalidad principal de cada estado
    
    //getters
    double getDuracion()
    {
        return duracion;
    }
    /*
    std::string getEstado()
    {
        return estado;
    }
    */
    void setDuracionMax(int duracion)
    {
        Estado::duracion = duracion;
    }

    void rotarEstado(int& ciclo, int& movimiento)
    {
        switch (ciclo) // Controla los cambios de estado, de rojo a amarillo y de amarillo a verde, y luego a la inversa.
        {
        case 0:
            movimiento = 1;
            break;

        case 2:
            movimiento = -1;
            break;
        }

        ciclo+=movimiento;
    }
protected:
    double duracion;
}; 



#endif //CLASS_ESTADO_HPP