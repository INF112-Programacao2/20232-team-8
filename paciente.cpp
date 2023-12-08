#include "paciente.h"
#include "usuario.h"
#include <string>
#include <iostream>
#include <vector>

Paciente::Paciente(std::string login, std::string senha, std::string nome, std::string telefone, std::string email,
                std::string cpf, std::string data_nascimento, std::string cns):
                Usuario(login,senha,nome,telefone,email,cpf,data_nascimento), _cns(cns){}

std::string  Paciente::get_cns(){
    return _cns;
}

void Paciente::set_cns(std::string cns){
    _cns = cns;
}

void Paciente::modificar_dados(std::vector <Paciente*> p){
    std::string opcao=0;
    std::cout <<"Qual dado deseja modificar?\n";
    std::cout << "(1) Login\n(2) Senha\n(3) Nome\n(4) Telefone\n(5) E-mail\n(6) CPF\n(7) Data de nascimento\n(8) CNS\n";
    try{ //tratamento de exceção caso a opção seja inválida
        std::cin >> opcao;
        if(opcao!="1" || opcao!="2" || opcao!="3" || opcao!="4" || opcao!="5" || opcao!="6" || opcao!="7" || opcao!="8"){
            throw std::invalid_argument ("Opção inexistente, digite novamente!\n");
        }
    } catch(std::invalid_argument& e){
        while(opcao!="1" && opcao!="2" && opcao!="3" && opcao!="4" && opcao!="5" && opcao!="6" && opcao!="7" && opcao!="8"){
            std::cin.clear();
            std::cerr << e.what();
            std::cin >> opcao;
        }
    }
    //modificar login
    if(opcao == "1"){
    bool valido = true;
    std::string login;
        try{ //verifica se é válido
            std::cin >> login;
            for(int i=0;i<login.length();i++){
                if(ispunct(login[i])){
                    valido=false;
                    throw std::invalid_argument ("O login só pode conter letras e números, digite novamente\n");
                }
            }
            for(int i=0;i<p.size();i++){
                if(login==p[i]->get_login()){
                    valido=false;
                    throw std::invalid_argument ("Login já existente\n");
                }
            }
        } catch(std::invalid_argument& e){
            while(!valido){
                std::cerr << e.what();
                std::cin >> login;
                for(int i=0;i<login.length();i++){
                    if(ispunct(login[i])){
                        valido=false;
                        break;
                    }
                    valido=true;
                }
            }
        }
        if(valido==true){
            
        }
    }

}
void Paciente::visualizar_dados(){

}
