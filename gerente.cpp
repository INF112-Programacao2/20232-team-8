#include <iostream>
#include <string>
#include "gerente.h"
#include "usuario.h"

Gerente::Gerente(std::string login, std::string senha, std::string nome, std::string telefone, std::string email,
                std::string cpf, std::string data_nascimento,std::string nome2, std::string endereco):
    Usuario(login,senha,nome,telefone,email,cpf,data_nascimento), _posto(nome2,endereco){}

void Gerente::adicionar_estoque(){
    std::cout << "vazio\n";
}

void Gerente::alterar_estoque(){
    std::cout << "vazio\n";
}

void Gerente::vizualizar_estoque(){
    std::cout << "vazio\n";
}

void Gerente::fazer_pedido(){
    std::cout << "vazio\n";
}