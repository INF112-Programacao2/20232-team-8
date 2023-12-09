#ifndef INF112_PACIENTE_H
#define INF112_PACIENTE_H
#include "usuario.h"
#include "historico.h"
#include "vacina.h"
#include <string>
#include <vector>

class Paciente : public Usuario{
private:
    std::string _cns;
    std::vector <Historico*> _historico;
public:
    Paciente(std::string login, std::string senha, std::string nome, std::string telefone, std::string email,
                std::string cpf, std::string data_nascimento, std::string cns);
    std::string get_cns();
    void set_cns(std::string cns);
    void modificar_dados(std::vector <Paciente*> p, int aux);
    void visualizar_dados(std::vector <Paciente*> p, int aux);
};

#endif
