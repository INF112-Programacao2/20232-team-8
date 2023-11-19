#include <iostream>
#include "estoque.h"

//construtor
Estoque::Estoque(std::string nome, int quantidade, std::string validade, std::string data_recebimento, std::string lote) :
    _nome(nome), _quantidade(quantidade), _validade(validade), _data_recebimento(_data_recebimento), _lote(lote) {}

//metodos set
void Estoque::set_nome(std::string new_nome){
    _nome = new_nome;
}

void Estoque::set_quantidade(int new_quantidade){
    _quantidade = new_quantidade;
}

void Estoque::set_validade(std::string new_validade){
    _validade = new_validade;
}

void Estoque::set_data_recebimento(std::string new_data_recebimento){
    _data_recebimento = new_data_recebimento;
}

void Estoque::set_lote(std::string new_lote){
    _lote = new_lote;
}

//metodos get
std::string Estoque::get_nome(){
    return _nome;
}

int Estoque::get_quantidade(){
    return _quantidade;
}

std::string Estoque::get_validade(){
    return _validade;
}

std::string Estoque::get_data_recebimento(){
    return _data_recebimento;
}

std::string Estoque::get_lote(){
    return _lote;
}
