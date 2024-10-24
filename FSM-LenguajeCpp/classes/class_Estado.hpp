#ifndef CLASS_ESTADO_HPP
#define CLASS_ESTADO_HPP

class Estado //clase abstracta, pura
{
    virtual void mostrar(double* timer) = 0; // Metodos abstractos, son la base de los estados verde, amarillo y rojo
    virtual void setDuracion(double duracion) = 0;
    virtual void setEstado(bool activado) = 0;

protected:
    double duracion;
    bool activado;
}; 



#endif //CLASS_ESTADO_HPP