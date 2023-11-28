#include "paciente.h"
#include "usuario.h"
#include <string>

Paciente::Paciente(std::string login, std::string senha, std::string nome, std::string telefone, std::string email,
                std::string cpf, std::string data_nascimento, std::string cns):
                Usuario(login,senha,nome,telefone,email,cpf,data_nascimento), _cns(cns){}

std::string  Paciente::get_cns(){
    return _cns;
}

void Paciente::set_cns(std::string cns){
    _cns = cns;
}
