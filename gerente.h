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
    std::vector <Vacina*> vacina; //vector que o aplicador tera acesso
    void adicionar_estoque();
    void alterar_estoque();
    void visualizar_estoque();
    void editar_dados(std::vector <Gerente*> g, int aux);
    void visualizar_dados(std::vector <Gerente*> g, int aux);
    bool verificar_lote(std::string nome, std::string lote);
    std::string visualizar_fabricante(std::string lote);
    ~Gerente();
};

#endif
