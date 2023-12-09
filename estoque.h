#ifndef INF112_ESTOQUE_H
#define INF112_ESTOQUE_H

#include <string>

class Estoque {
    private:
        //dados da classe estoque
        std::string _nome;
        int _quantidade;
        std::string _validade;
        std::string _data_recebimento;
        std::string _lote;
    public:
        //construtor
        Estoque(std::string nome, int quantidade, std::string validade, std::string data_recebimento, std::string lote);
        //metodos set 
        void set_quantidade(int new_quantidade);
        //metodos get
        std::string get_nome();
        int get_quantidade();
        std::string get_validade();
        std::string get_data_recebimento();
        std::string get_lote();
};

#endif
