#include "gerente.h"
#include "usuario.h"
#include <string>


Gerente::Gerente(std::string login, std::string senha, std::string nome, std::string telefone, std::string email,
                std::string cpf, std::string data_nascimento,std::string nome2, std::string endereco):
    Usuario(login,senha,nome,telefone,email,cpf,data_nascimento), _posto(nome2,endereco){}

void alterar_estoque(){

}

void fazer_pedido(){
    
}