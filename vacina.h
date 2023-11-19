#ifndef INF112_VACINA_H
#define INF112_VACINA_H
#include <string>
#include "produto.h"

class Vacina : public Produto {
private:
    std::string _nome;
    std::string _fabricante;
    std::string _lote;
public:
    Vacina(std::string nome, std::string fabricante, std::string _lote, int quantidade);
    std::string get_nome();
    std::string get_fabricante();
    std::string get_lote();   
};
#endif
