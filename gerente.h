#ifndef INF112_GERENTE_H
#define INF112_GERENTE_H
#include <string>
#include "usuario.h"

class Gerente : public Usuario{
private:
//  Vacina _vacina;
//  Estoque _estoque;
public:
    Gerente();
    void alterar_estoque();
    void fazer_pedido();
};

#endif
