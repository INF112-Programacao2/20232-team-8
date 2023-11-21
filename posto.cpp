#include "posto.h"
#include "estoque.h"
#include "vacina.h"

Posto::Posto(std::string nome, std::string endereco, Estoque estoque, Vacina vacina):
    _nome(nome), _endereco(endereco), _estoque(estoque), _vacina(vacina) {}

void Posto::set_nome(std::string nome){
    _nome = nome;
}

void Posto::set_endereco(std::string endereco){
    _endereco = endereco;
}

std::string Posto::get_nome(){
    return _nome;
}

std::string Posto::get_endereco(){
    return _endereco;
}