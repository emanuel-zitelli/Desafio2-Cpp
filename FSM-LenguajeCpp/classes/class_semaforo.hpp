#ifndef CLASS_SEMAFORO_HPP
#define CLASS_SEMAFORO_HPP

class Semaforo : public EstadoVerde, public EstadoAmarillo, public EstadoRojo
{
public:
    //metodos en virtual para que funcione el semaforo
    virtual void mostrarSemaforo() = 0;

protected:

    double timer=1;
    std::string estadoAnterior;
    std::string estadoActual;
};
#endif //CLASS_SEMAFORO_HPP