#include "historico.h"
#include "vacina.h"

Historico::Historico(std::string nome_vacina, std::string cns, std::string coren, std::string data, std::string dose, bool retorno, std::string data_retorno, std::string fabricante, std::string lote, std::string tipo_vacina):
    _nome_vacina(nome_vacina), _cns(cns), _coren(coren), _data(data), _dose(dose), _retorno(retorno), _data_retorno(data_retorno), _fabricante(fabricante), _lote(lote), _tipo_vacina(tipo_vacina) {}

std::string Historico::get_nome_vacina(){
    return _nome_vacina;
}

std::string Historico::get_data(){
    return _data;
}

std::string Historico::get_dose(){
    return _dose;
}

std::string Historico::get_coren(){
    return _coren;
}

std::string Historico::get_fabricante(){
    return _fabricante;
}

std::string Historico::get_lote(){
    return _lote;
}

std::string Historico::get_tipo_vacina(){
    return _tipo_vacina;
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