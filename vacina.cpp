#include "vacina.h"
#include "estoque.h"

#include <string>

Vacina::Vacina(std::string fabricante, std::string tipo, std::string nome, int quantidade,
std::string validade, std::string data_recebimento, std::string lote):
    _fabricante(fabricante), _tipo(tipo),
    //dados herdados da classe estoque
    Estoque(nome, quantidade, validade, data_recebimento, lote) {}

//metodos get
std::string Vacina::get_fabricante(){
    return _fabricante;
}
std::string Vacina::get_tipo(){
    return _tipo;
}
