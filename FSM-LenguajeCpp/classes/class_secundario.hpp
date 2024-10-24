#ifndef CLASS_SECUNDARIO_HPP
#define  CLASS_SECUNDARIO_HPP

class Secundario : public Semaforo
{
public:
    void mostrarSemaforo() override
    {
        std::cout << "Semaforo Secundario: ";
    }
protected:
    
};
#endif //CLASS_SECUNDARIO_HPP