#include "Posto.h"
#include "Estoque.h"
#include "Vacina.h"

Posto::Posto(std::string nome, std::string endereco, Estoque estoque, Vacina vacina):
    _nome(nome), _endereco(endereco), _estoque(estoque), _vacina(vacina) {}
