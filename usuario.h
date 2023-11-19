#ifndef INF112_USUARIO_H
#define INF112_USUARIO_H
#include <string>

class Usuario{
private:
    std::string _nome;
    long long int _cpf;
    std::string _datanascimento;
    long long int _telefone;
public:
    std::string get_nome();
    long long int get_cpf();
    std::string get_datanascimento();
    long long int _telefone();    
};

#endif
