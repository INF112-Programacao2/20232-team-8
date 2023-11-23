#include "usuario.h"
#include <iostream>
#include <string>

Usuario::Usuario(std::string login, std::string senha, std::string nome, std::string telefone, std::string email,
                    std::string cpf, std::string data_nascimento) :
    _login(login), _senha(senha), _nome(nome), _telefone(telefone), _email(email), _cpf(cpf), _data_nascimento(data_nascimento) {}

std::string Usuario::get_login(){
    return _login;
}

std::string Usuario::get_senha(){
    return _senha;
}

std::string Usuario::get_nome(){
    return _nome;
}

std::string Usuario::get_telefone(){
    return _telefone;
}

std::string Usuario::get_email(){
    return _email;
}

std::string Usuario::get_cpf(){
    return _cpf;
}

std::string Usuario::get_data_nascimento(){
    return _data_nascimento;
}

void Usuario::set_login(std::string login){
    _login = login;
}

void Usuario::set_senha(std::string senha){
    _senha = senha;
}

void Usuario::set_nome(std::string nome){
    _nome = nome;
}

void Usuario::set_telefone(std::string telefone){
    _telefone = telefone;
}

void Usuario::set_email(std::string email){
    _email = email;
}

void Usuario::set_cpf(std::string cpf){
    _cpf = cpf;
}

void Usuario::set_data_nascimento(std::string data_nascimento){
    _data_nascimento = data_nascimento;
}
