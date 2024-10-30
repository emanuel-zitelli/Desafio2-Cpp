#ifndef CLASS_ESTADO_HPP
#define CLASS_ESTADO_HPP

class Estado //clase base de verde, amarillo y rojo
{
public: 

    virtual void mostrar(double* timer) = 0; // Metodos abstractos, son la base de los estados verde, amarillo y rojo
    virtual void setDuracion(double duracion) = 0;
    virtual void setEstado(bool activado) = 0;
    
    bool estaActivado()
    {
        return activado;
    }

    double CuantoDura()
    {
        return duracion;
    }

protected:
    double duracion;
    bool activado;
}; 



#endif //CLASS_ESTADO_HPP