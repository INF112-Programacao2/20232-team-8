#include "paciente.h"
#include "usuario.h"
#include <string>

//Paciente(){}

std::string  Paciente::get_cns(){
    return _cns;
}

void Paciente::set_cns(std::string cns){
    _cns = cns;
}
