#include <iostream>
#include "estoque.h"

//construtor
Estoque::Estoque(std::string nome, int quantidade, std::string validade, std::string data_recebimento, std::string lote) :
    _nome(nome), _quantidade(quantidade), _validade(validade), _data_recebimento(data_recebimento), _lote(lote) {}

//metodos set
void Estoque::set_quantidade(int new_quantidade){
    _quantidade = new_quantidade;
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
