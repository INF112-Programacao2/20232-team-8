#ifndef INF112_POSTO_H
#define INF112_POSTO_H
#include <string>
#include "estoque.h"
#include "vacina.h"

class Posto {
    private:
    std::string _nome
    std::string _endereco;
    Estoque _estoque;
    Vacina _vacina;

    public:
    //construtor
    Posto(std::string nome, std::string _endereco, Estoque estoque, Vacina vacina);
    //métodos para alteração de variáveis
    void set_nome(std::string nome);
    void set_endereco(std::string endereco);

};

#endif
