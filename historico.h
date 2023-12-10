#ifndef INF112_HISTORICO_H
#define INF112_HISTORICO_H
#include <string>
#include "vacina.h"

class Historico {
private:
    std::string _data;
    int _dose;
    bool _retorno;
    std::string _dataDeRetorno;
    Vacina _vacina_;
    std::string _cns;

public: 
    Historico(std::string data, int dose, bool retorno, std::string dataDeRetorno, Vacina vacina_, std::string cns);

    std::string get_data();
    int get_dose();
    void set_dose(int atualDose);
    bool get_retorno();
    void set_retorno(bool atualRetorno);
    std::string get_dataDeRetorno();
    void set_dataDeRetorno(std::string atualDdr);
};

#endif
