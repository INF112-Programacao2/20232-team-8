#ifndef INF112_USUARIO_H
#define INF112_USUARIO_H
#include <string>

class Usuario{
private:
    std::string _login;
    std::string _senha;
    std::string _nome;
    std::string _telefone;
    std::string _email;
    std::string _cpf;
    std::string _data_nascimento;
public:
    Usuario(std::string login, std::string senha, std::string nome, std::string telefone, std::string email,
                std::string cpf, std::string data_nascimento);
    std::string get_login();
    std::string get_senha();
    std::string get_nome();
    std::string get_telefone();
    std::string get_email();
    std::string get_cpf();
    std::string get_data_nascimento();
    void set_login(std::string login);
    void set_senha(std::string senha);
    void set_nome(std::string nome);
    void set_telefone(std::string telefone);
    void set_email(std::string email);
    void set_cpf(std::string cpf);
    void set_data_nascimento(std::string data_nascimento);
};

#endif
