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
        //metodos set
        void set_fabricante(std::string new_fabricante);
        void set_tipo(std::string new_tipo);
        void set_nome(std::string new_nome);
        void set_quantidade(int new_quantidade);
        void set_validade(std::string new_validade);
        void set_data_recebimento(std::string new_validade);
        void set_lote(std::string new_validade);
        //metodos get 
        std::string get_fabricante();
        std::string get_tipo();   
};
#endif
