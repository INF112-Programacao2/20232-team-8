#ifndef INF112_HISTORICO_H
#define INF112_HISTORICO_H
#include <string>
#include "vacina.h"
#include <iostream>

class Historico {
private:
    std::string _cns, _coren, _data, _dose, _data_retorno, _fabricante, _lote;
    bool _retorno;

public: 
    Historico(std::string cns, std::string coren, std::string data, std::string dose, bool retorno, std::string data_retorno, std::string fabricante, std::string lote);

    std::string get_data();
    std::string get_dose();
    std::string get_coren();
    std::string get_lote();
    std::string get_fabricante();
    void set_dose(int atualDose);
    bool get_retorno();
    void set_retorno(bool atualRetorno);
    std::string get_data_retorno();
    void set_data_retorno(std::string atualDdr);
    std::string get_cns();
};

#endif
