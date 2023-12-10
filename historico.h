#ifndef INF112_HISTORICO_H
#define INF112_HISTORICO_H
#include <string>
#include "vacina.h"
#include <iostream>

class Historico {
private:
    std::string _cns, _coren, _data, _dose, _dataDeRetorno, _fabricante, _lote;
    bool _retorno;

public: 
    Historico(std::string cns, std::coren, std::string data, std::string dose, bool retorno, std::string dataDeRetorno, std::string fabricante, std::string lote);

    std::string get_data();
    int get_dose();
    void set_dose(int atualDose);
    bool get_retorno();
    void set_retorno(bool atualRetorno);
    std::string get_dataDeRetorno();
    void set_dataDeRetorno(std::string atualDdr);
};

#endif
