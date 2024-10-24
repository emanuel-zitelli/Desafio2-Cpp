#ifndef CLASS_MAQUINADEESTADO_HPP
#define CLASS_MAQUINADEESTADO_HPP

class FSM : public Principal, public Secundario
{
public:
    void setHayAutos(bool preferencia)
    {
        FSM::hayAutos = preferencia;
    }
    void comenzar()
    {
        Principal semaforoPrincipal;
        Secundario semaforoSecundario;
    }
private:
    bool hayAutos;
    
};

#endif //CLASS_MAQUINADEESTADO_HPP