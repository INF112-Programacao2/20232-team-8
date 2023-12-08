#ifndef INF112_GERENTE_H
#define INF112_GERENTE_H
#include <string>
#include <vector>
#include "usuario.h"
#include "vacina.h"
#include "estoque.h"
#include "posto.h"

class Gerente : public Usuario{
    private:
    Posto _posto;
    std::vector <Estoque*> _estoque;
    std::vector <Vacina*> _vacina;
    public:
    Gerente(std::string login, std::string senha, std::string nome, std::string telefone, std::string email,
                std::string cpf, std::string data_nascimento,std::string nome2, std::string endereco);
    void adicionar_estoque();
    void alterar_estoque();
    void visualizar_estoque();
};

#endif
