#include "historico.h"
#include "vacina.h"

Historico(std::string cns, std::coren, std::string data, std::string dose, bool retorno, std::string dataDeRetorno, std::string fabricante, std::string lote):
    _cns(cns), _coren(coren), _data(data), _dose(dose), _retorno(retorno), _dataDeRetorno(dataDeRetorno), _fabricante(fabricante), _lote(lote) {}

std::string Historico::get_data(){
    return _data;
}

int Historico::get_dose(){
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

std::string Historico::get_dataDeRetorno(){
    return _dataDeRetorno;
}

void Historico::set_dataDeRetorno(std::string atualDdr){
    _dataDeRetorno = atualDdr;
}
