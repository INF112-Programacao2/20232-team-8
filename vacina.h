#ifndef INF112_VACINA_H
#define INF112_VACINA_H

#include <string>
#include "estoque.h"

class Vacina : public Estoque {
    private:
        //dados da classe estoque
        std::string _fabricante;
        std::string _tipo;
        std::string _aplicacao;
    public:
        //construtor
        Vacina(std::string fabricante, std::string tipo, std::string aplicacao, std::string nome, int quantidade,
        std::string validade, std::string data_recebimento, std::string lote);
        //metodos set
        void set_fabricante(std::string new_fabricante);
        void set_tipo(std::string new_tipo);
        void set_aplicacao(std::string new_aplicacao);
        //metodos get 
        std::string get_fabricante();
        std::string get_tipo();
        std::string get_aplicacao();   
};
#endif
