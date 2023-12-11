#ifndef INF112_HISTORICO_H
#define INF112_HISTORICO_H
#include <string>
#include "vacina.h"
#include <iostream>

class Historico {
private:
    std::string _nome_vacina, _cns, _coren, _data, _dose, _data_retorno, _fabricante, _lote, _tipo_vacina;
    bool _retorno;

public: 
    Historico(std::string nome_vacina, std::string cns, std::string coren, std::string data, std::string dose, bool retorno, std::string data_retorno, std::string fabricante, std::string lote, std::string tipo_vacina);

    std::string get_nome_vacina();
    std::string get_data();
    std::string get_dose();
    std::string get_coren();
    std::string get_lote();
    std::string get_fabricante();
    std::string get_tipo_vacina();
    void set_dose(int atualDose);
    bool get_retorno();
    void set_retorno(bool atualRetorno);
    std::string get_data_retorno();
    void set_data_retorno(std::string atualDdr);
    std::string get_cns();
};

#endif
