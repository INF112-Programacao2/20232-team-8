#ifndef INF112_APLICADOR_H
#define INF112_APLICADOR_H
#include "usuario.h"
#include "historico.h"
#include "gerente.h"
#include <string>
#include <vector>

class Aplicador : public Usuario {
private:
    std::string _coren;
    std::vector <Historico*> _historico;
public:
    Aplicador(std::string login, std::string senha, std::string nome, std::string telefone, std::string email, std::string cpf, std::string data_nascimento, std::string coren);

    std::string get_coren();
    void set_coren(std::string coren);
    void registrar_vacina(std::string cns, std::vector <Gerente*> _gerente);
    void verificar_retorno(std::string cns);
    void visualizar_dados(std::vector <Aplicador*> apli, int aux);
    void editar_dados(std::vector <Aplicador*> apli, int aux);
    void visualizar_historico(std::string cns);
    ~Aplicador();
};

#endif