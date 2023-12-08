#ifndef INF112_APLICADOR_H
#define INF112_APLICADOR_H
#include "usuario.h"
#include "historico.h"
#include <string>

class Aplicador: public Usuario {
private:
    std::string _coren;
public:
    Aplicador(std::string login, std::string senha, std::string nome, std::string telefone, std::string email,
                std::string cpf, std::string data_nascimento, std::string coren);
    ~Aplicador();
    
    std::string get_coren();
    void set_coren(std::string coren);
    void registrar_vacina();
    void verificar_retorno();
    void definir_retorno();
};


#endif
