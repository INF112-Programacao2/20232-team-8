#ifndef INF112_VACINA_H
#define INF112_VACINA_H

#include <string>
#include "estoque.h"

class Vacina : public Estoque {
    private:
        //dados da classe estoque
        std::string _fabricante;
        std::string _tipo;
    public:
        //construtor
        Vacina(std::string fabricante, std::string tipo, std::string nome, int quantidade,
        std::string validade, std::string data_recebimento, std::string lote);
        //metodos get 
        std::string get_fabricante();
        std::string get_tipo();   
};
#endif
