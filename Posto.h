#ifndef INF112_POSTO_H
#define INF112_POSTO_H
#include <string>
#include "produto.h"

class Posto {
    private:
    std::string _login;
    int _senha;
    std::string _endereco;
    Produto _estoque;

    public:
    Posto(std::string _login, int _senha, std::string _endereco, Produto _estoque);
};

#endif
