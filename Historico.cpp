#include "historico.h"
#include "vacina.h"
#include "posto.h"

Historico::Historico(std::string data, int dose, bool retorno, std::string dataDeRetorno, Vacina vacina_, Posto posto_):
    _data(data), _dose(dose), _retorno(retorno), _dataDeRetorno(dataDeRetorno), _vacina_(vacina_), _posto_(posto_) {}

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