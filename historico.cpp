#include "historico.h"
#include "vacina.h"

Historico::Historico(std::string cns, std::string coren, std::string data, std::string dose, bool retorno, std::string data_retorno, std::string fabricante, std::string lote):
    _cns(cns), _coren(coren), _data(data), _dose(dose), _retorno(retorno), _data_retorno(data_retorno), _fabricante(fabricante), _lote(lote) {}

std::string Historico::get_data(){
    return _data;
}

std::string Historico::get_dose(){
    return _dose;
}

void Historico::set_dose(int atualDose){
    _dose = atualDose;
}

bool Historico::get_retorno(){
    return _retorno;
}

void Historico::set_retorno(bool atualRetorno){
    _retorno = atualRetorno;
}

std::string Historico::get_data_retorno(){
    return _data_retorno;
}

void Historico::set_data_retorno(std::string atualDdr){
    _data_retorno = atualDdr;
}

std::string Historico::get_cns(){
    return _cns;
}