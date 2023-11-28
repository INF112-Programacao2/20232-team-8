#include <string>
#include "aplicador.h"
#include "usuario.h"

Aplicador::Aplicador(std::string login, std::string senha, std::string nome, std::string telefone, std::string email,
                std::string cpf, std::string data_nascimento, std::string coren):
                Usuario(login,senha,nome,telefone,email,cpf,data_nascimento), _coren(coren){}

std::string Aplicador::get_coren(){
    return _coren;
}

void Aplicador::set_coren(std::string coren){
    _coren = coren;
}
