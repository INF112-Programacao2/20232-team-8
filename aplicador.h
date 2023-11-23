#ifndef INF112_APLICADOR_H
#define INF112_APLICADOR_H
#include "usuario.h"
#include <string>

class Aplicador: public Usuario {
private:
    std::string _coren;
public:
    Aplicador();
    std::string get_coren();
    void set_coren(std::string coren);
};


#endif
