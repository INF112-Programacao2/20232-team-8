#include "aplicador.h"
#include <iostream>
#include <cctype>

Aplicador::Aplicador(std::string login, std::string senha, std::string nome, std::string telefone, std::string email, std::string cpf, std::string data_nascimento, std::string coren):
    Usuario(login,senha,nome,telefone,email,cpf,data_nascimento), _coren(coren){
        _
    }

Aplicador::~Aplicador() {}

std::string Aplicador::get_coren(){
    return _coren;
}

void Aplicador::set_coren(std::string coren){
    _coren = coren;
}

void Aplicador::registrar_vacina(){
    std::string numvac, nome_vacina, lote;
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
    std::cout << "Qual o lote da vacina?\n";
    try{
        std::cin >> lote;
        if(Gerente::verificar_lote(nome_vacina,lote) == false)
            throw std::invalid_argument ("Lote da vacina digitado não corresponde a um lote existente, digite novamente. ");
    } catch(std::invalid_argument &d){
        while(Gerente::verificar_lote(nome_vacina,lote) == false){
            std::cerr << d.what();
            std::cin >> lote;
        }
    }
    std::cout <<
}

void Aplicador::verificar_retorno(){
    
}

void Aplicador::definir_retorno(){

}