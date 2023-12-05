#ifndef INF112_POSTO_H
#define INF112_POSTO_H
#include <string>
#include <vector>
#include "estoque.h"
#include "vacina.h"

class Posto {
    private:
    std::string _nome;
    std::string _endereco;
    std::vector <Estoque*> _estoque;
    std::vector <Vacina*> _vacina;

    public:
    //construtor
    Posto(std::string nome, std::string endereco);
    //métodos para alteração de variáveis
    void set_nome(std::string nome);
    void set_endereco(std::string endereco);
    //métodos para visualização de variáveis
    std::string get_nome();
    std::string get_endereco();

};

#endif
