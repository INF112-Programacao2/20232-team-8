#include <string>
#include "aplicador.h"
#include "usuario.h"
#include <iostream>
#include <cctype>

Aplicador::Aplicador(std::string login, std::string senha, std::string nome, std::string telefone, std::string email,
                std::string cpf, std::string data_nascimento, std::string coren):
                Usuario(login,senha,nome,telefone,email,cpf,data_nascimento), _coren(coren){}

std::string Aplicador::get_coren(){
    return _coren;
}

void Aplicador::set_coren(std::string coren){
    _coren = coren;
}

void Aplicador::registrar_vacina(){
    std::string cns;
    bool validocns = true;
    std::cout << "Digite o número do Cartão Nacional de Saúde (CNS) do paciente: ";
    try { // verificar se é um número válido
        std::cin >> cns;
        for(int i=0; i<cns.length(); i++){
            if(!isdigit(cns[i]) || cns.length()<15){
                validocns=false;
                throw std::invalid_argument ("Digite um cns válido\n");
            }
        }
    } catch(std::invalid_argument &e){
        while(!validocns && cns.length()<15){
            std::cerr << e.what();
            std::cin >> cns;
            for(int i=0;i<cns.length();i++){
                if(!isdigit(cns[i])){
                    validocns=false;
                    break;
                }
                validocns=true;
            }
        }
    }

    //incompleto
}

void Aplicador::verificar_retorno(){

}

void Aplicador::definir_retorno(){

}