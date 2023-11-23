#ifndef INF112_PACIENTE_H
#define INF112_PACIENTE_H
#include "usuario.h"
#include <string>

class Paciente : public Usuario{
private:
    std::string _cns;
    //Historico;
public:
    Paciente();
    std::string get_cns();
    void set_cns(std::string cns);
};

#endif
