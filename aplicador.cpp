#include <string>
#include "aplicador.h"
#include "usuario.h"
#include <iostream>
#include <cctype>

Aplicador::Aplicador(std::string login, std::string senha, std::string nome, std::string telefone, std::string email, std::string cpf, std::string data_nascimento, std::string coren):
    Usuario(login,senha,nome,telefone,email,cpf,data_nascimento), _coren(coren){}

Aplicador::~Aplicador() {}

std::string Aplicador::get_coren(){
    return _coren;
}

void Aplicador::set_coren(std::string coren){
    _coren = coren;
}

void Aplicador::registrar_vacina(){
    std::string numvac, nome_vacina;
    std::cout << "Qual o nome da vacina aplicada?" << std::endl;
    std::cout << "(1) Coronavac\n(2) Astrazeneca\n(3) Pfizer\n (4) Janssen\n";
    try{ 
        std::cin >> numvac;
        if(numvac!="1" || numvac!="2" || numvac!="3" || numvac!="4"){
            throw std::invalid_argument ("Opção inexistente, digite novamente!");
        }
    } catch(std::invalid_argument& e){
        while(numvac!="1" && numvac!="2" && numvac!="3" && numvac!="4"){
            std::cerr << e.what();
            std::cin >> numvac;
        }
    }
    std::cout << "Qual o lote da vacina?\n";
    if(numvac == "1"){
        nome_vacina = "Coronavac";
    }
    if(numvac == "2"){
        nome_vacina = "Astrazeneca";
    }
    if(numvac == "3"){
        nome_vacina = "Pfizer";
    }
    if(numvac == "4"){
        nome_vacina = "Janssen";
    }
}

void Aplicador::verificar_retorno(){
    
}

void Aplicador::definir_retorno(){

}