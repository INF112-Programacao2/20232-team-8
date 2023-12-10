#ifndef INF112_GERENTE_H
#define INF112_GERENTE_H
#include <string>
#include <vector>
#include "usuario.h"
#include "vacina.h"
#include "estoque.h"

class Gerente : public Usuario{
    private:
    std::vector <Estoque*> _estoque;
    std::vector <Vacina*> _vacina;
    public:
    Gerente(std::string login, std::string senha, std::string nome, std::string telefone, std::string email,
                std::string cpf, std::string data_nascimento);
    void adicionar_estoque();
    void alterar_estoque();
    void visualizar_estoque();
    void editar_dados();
    void visualizar_dados();
};

#endif
