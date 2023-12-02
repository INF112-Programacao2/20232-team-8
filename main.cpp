#include <string>
#include "aplicador.h"
#include "historico.h"
#include "paciente.h"
#include "posto.h"
#include "usuario.h"
#include "vacina.h"
#include "estoque.h"
#include "gerente.h"
#include <iostream>
#include <vector>
#include <string>
#include <exception>

int main(void){
    //vector para cada tipo de usuário
    std::vector <Paciente*> p;
    std::vector <Gerente*> g;
    std::vector <Aplicador*> a;
    //variáveis para a inicialização dos objetos
    std::string login, senha, nome, telefone, email, cpf, data_nascimento, coren, cns;
    int opcao1, opcao2;
    //objetos criados já existentes no sistema
    pacientes.push_back(Paciente("lilicesm","abcde","Alice","3299774784","lilicesm@gmail.com","12345678912","30/12/2004","12345"));
    p.push_back(Paciente("jugama","ndsfkl","Julia","3299980345","jugama@gmail.com","65316789032","19/05/2005","54665"));
    a.push_back(Aplicador("cecicassab","67567","Cecilia","32984365837","ceci@gmail.com","13138476532","31/12/2004","86709"));
    a.push_back(Aplicador("marycosta","6575","Maryana","32997654890","marycosta@gmail.com","95643123897","06/06/2003","98765"));
    //definição de que tipo de usuário acessará o sistema, o que define diferentes funções
    std::cout << "----------------------------------" << std::endl;
    std::cout << "Que tipo de usuário você é?\n";
    std::cout << "(1) Paciente\n(2) Gerente\n(3) Aplicador\n";
    try{ //tratamento de exceção caso a opção seja inválida
        std::cin >> opcao1;
        if(opcao1!=1 || opcao1!=2 || opcao1!=3 || !isdigit(opcao1)){
            throw std::invalid_argument ("Opção inexistente, digite novamente!\n");
        }
    } catch(std::invalid_argument& e){
        while(opcao1!=1 && opcao1!=2 && opcao1!=3 && !isdigit(opcao1)){
            std::cerr << e.what();
            std::cin >> opcao1;
        }
    }
    if(opcao1==1){ //área de acesso do paciente
        std::cout << "\nVocê deseja realizar login ou cadastro?\n";
        std::cout << "(1) Login\n(2) Cadastro\n";
        try{ //tratamento de exceção caso a opção seja inválida
            std::cin >> opcao2;
            if(opcao2!=1 || opcao2!=2 || !isdigit(opcao2)){
                throw std::invalid_argument ("Opção inexistente, digite novamente!\n");
        }
        } catch(std::invalid_argument& e){
            while(opcao2!=1 && opcao2!=2 && !isdigit(opcao2)){
                std::cerr << e.what();
                std::cin >> opcao2;
            }
        }
        if(opcao2==1){//verifica se o usuário está cadastrado
            std::cout << "Digite seu nome de usuário: ";
            std::cin >> nome;
            std::cout << "Digite sua senha: ";
            std::cin >> senha;
            bool existe=false;
            for(int i=0;i<p.size();i++){
                if(nome==p[i].get_nome()){
                    existe=true;
                    break;
                }
            }
            if(!existe){ //se não existir, realiza o cadastro
                std::cout << "Usuário inexistente, realize cadastro\n";
                opcao2=2;
            }
        }
        if(opcao2==2){ //realiza o cadastro
            //leitura dos dados e tratamento de excessão
            std::cout << "Digite o nome de usuário desejado: ";
            bool valido=true;
            bool validonome=true;
            bool validotel=true;
            bool validocpf=true;
            bool validoemail=false;
            bool validocns=true;
            try{ //verifica se é válido
                std::cin >> login;
                for(int i=0;i<login.length();i++){
                    if(!isalpha(login[i]) || !isdigit(login[i])){
                        valido=false;
                        throw std::invalid_argument ("O login só pode conter letras e números, digite novamente\n");
                    }
                }
            } catch(std::invalid_argument& e){
                while(!valido){
                    std::cerr << e.what();
                    std::cin >> login;
                    for(int i=0;i<login.length();i++){
                        if(!isalpha(login[i]) || !isdigit(login[i])){
                            valido=false;
                            break;
                        }
                        valido=true;
                    }
                }
            }
            std::cout << "Escolha uma senha: ";
            try{ //verifica se é válida
                std::cin >> senha;
                if(senha.length()<8){
                    throw std::invalid_argument ("A senha deve ter no mínimo 8 caracteres\n");
                }
            } catch(std::invalid_argument& e){
                while(senha.length()<8){
                    std::cerr << e.what();
                    std::cin >> senha;
                }
            }
            std::cout << "Digite seu nome: ";
            try{ //verifica se é válido
                std::cin >> nome;
                for(int i=0;i<nome.length();i++){
                    if(!isalpha(nome[i])){
                        validonome=false;
                        throw std::invalid_argument ("O nome só pode conter letras, digite novamente\n");
                    }
                }
            } catch(std::invalid_argument& e){
                while(!validonome){
                    std::cerr << e.what();
                    std::cin >> nome;
                    for(int i=0;i,nome.length();i++){
                        if(!isalpha(nome[i])){
                            validonome=false;
                            break;
                        }
                        validonome=true;
                    }
                }
            }
            std::cout << "Digite um número de contato: ";
            try{ //verifica se é válido
                std::cin >> telefone;
                for(int i=0;i<telefone.length();i++){
                    if(isalpha(telefone[i]) || telefone.length()<10){
                        validotel=false;
                        throw std::invalid_argument ("O telefone tem no mínimo 10 dígitos e só pode conter letras, digite novamente\n");
                    }
                }
            } catch(std::invalid_argument& e){
                while(!validotel){
                    std::cerr << e.what();
                    for(int i=0;i,nome.length();i++){
                        if(isalpha(nome[i]) || telefone.length()<10){
                            validotel=false;
                            break;
                        }
                        validotel=true;
                    }
                }
            }
            std::cout << "Digite seu email: ";
            try { //verifica se possui @ e é um email válido
                std::cin >> email;
                for(int i=0;i<email.length();i++){
                    if(email[i]=='@')
                        validoemail=true;
                }
                if(!validoemail){
                    throw std::invalid_argument ("Digite um email válido\n");
                }
            } catch(std::invalid_argument& e) {
                while(!validoemail){
                    std::cerr << e.what();
                    std::cin >> email;
                    for(int i=0;i<email.length();i++){
                        if(email[i]=='@')
                            validoemail=true;
                    }
                }
            }
            std::cout << "Digite seu cpf: ";
            try { //verifica se o cpf é válido
                std::cin >> cpf;
                if(cpf.length()<11){
                    throw std::invalid_argument ("Digite um cpf válido\n");
                }
            } catch(std::invalid_argument& e){
                while(cpf.length()<11){
                    std::cerr << e.what();
                    std::cin >> cpf;
                }
            }
            std::cout << "Digite sua data de nascimento: ";
            //std::cin >> data_nascimento;
            std::cout << "Digite o número do seu cartão nacional de saúde: ";
            try { //verifica se é um número válido
                std::cin >> cns;
                for(int i=0;i<cns.length();i++){
                    if(!isdigit(cns[i]) || cns.length()<15){
                        validocns=false;
                        throw std::invalid_argument ("Digite um cns válido\n");
                    }
                }
            } catch(std::invalid_argument& e){
                while(!validocns && cns.length()<15){
                    std::cerr << e.what();
                    std::cin >> cns;
                    for(int i=0;i<cns.length();i++){
                        if(!isdigit(cns[i])){
                            validocns=false;
                            break;
                        }
                        validocns=true;
                    }
                }
            }

        }
    }
    else if(opcao1==2){ //área de acesso do gerente
        std::cout << "Você deseja realizar login ou cadastro?\n";
        std::cout << "(1) Login\n(2) Cadastro\n";
        try{ //tratamento de exceção caso a opção seja inválida
            std::cin >> opcao2;
            if(opcao2!=1 || opcao2!=2 || !isdigit(opcao2)){
                throw std::invalid_argument ("Opção inexistente, digite novamente!\n");
        }
        } catch(std::invalid_argument& e){
            while(opcao2!=1 || opcao2!=2 || !isdigit(opcao2)){
                std::cerr << e.what();
                std::cin >> opcao2;
            }
        }
        if(opcao2==1){//verifica se o usuário está cadastrado
            std::cout << "Digite seu nome de usuário: ";
            std::cin >> nome;
            std::cout << "Digite sua senha: ";
            std::cin >> senha;
            bool existe=false;
            for(int i=0;i<p.size();i++){
                if(nome==p[i].get_nome()){
                    existe=true;
                    break;
                }
            }
            if(!existe){ //se não existir, realiza o cadastro
                std::cout << "Usuário inexistente, realize cadastro\n";
                opcao2=2;
            }
        }
        if(opcao2==2){ //realiza o cadastro
            //leitura dos dados e tratamento de excessão
            std::cout << "Digite o nome de usuário desejado: ";
            bool valido=true;
            bool validonome=true;
            bool validotel=true;
            bool validocpf=true;
            bool validoemail=false;
            try{ //verifica se é válido
                std::cin >> login;
                for(int i=0;i<login.length();i++){
                    if(!isalpha(login[i]) || !isdigit(login[i])){
                        valido=false;
                        throw std::invalid_argument ("O login só pode conter letras e números, digite novamente\n");
                    }
                }
            } catch(std::invalid_argument& e){
                while(!valido){
                    std::cerr << e.what();
                    std::cin >> login;
                    for(int i=0;i<login.length();i++){
                        if(!isalpha(login[i]) || !isdigit(login[i])){
                            valido=false;
                            break;
                        }
                        valido=true;
                    }
                }
            }
            std::cout << "Escolha uma senha: ";
            try{ //verifica se é válida
                std::cin >> senha;
                if(senha.length()<8){
                    throw std::invalid_argument ("A senha deve ter no mínimo 8 caracteres\n");
                }
            } catch(std::invalid_argument& e){
                while(senha.length()<8){
                    std::cerr << e.what();
                    std::cin >> senha;
                }
            }
            std::cout << "Digite seu nome: ";
            try{ //verifica se é válido
                std::cin >> nome;
                for(int i=0;i<nome.length();i++){
                    if(!isalpha(nome[i])){
                        validonome=false;
                        throw std::invalid_argument ("O nome só pode conter letras, digite novamente\n");
                    }
                }
            } catch(std::invalid_argument& e){
                while(!validonome){
                    std::cerr << e.what();
                    std::cin >> nome;
                    for(int i=0;i,nome.length();i++){
                        if(!isalpha(nome[i])){
                            validonome=false;
                            break;
                        }
                        validonome=true;
                    }
                }
            }
            std::cout << "Digite um número de contato: ";
            try{ //verifica se é válido
                std::cin >> telefone;
                for(int i=0;i<telefone.length();i++){
                    if(isalpha(telefone[i]) || telefone.length()<10){
                        validotel=false;
                        throw std::invalid_argument ("O telefone tem no mínimo 10 dígitos e só pode conter letras, digite novamente\n");
                    }
                }
            } catch(std::invalid_argument& e){
                while(!validotel){
                    std::cerr << e.what();
                    for(int i=0;i,nome.length();i++){
                        if(isalpha(nome[i]) || telefone.length()<10){
                            validotel=false;
                            break;
                        }
                        validotel=true;
                    }
                }
            }
            std::cout << "Digite seu email: ";
            try { //verifica se possui @ e é um email válido
                std::cin >> email;
                for(int i=0;i<email.length();i++){
                    if(email[i]=='@')
                        validoemail=true;
                }
                if(!validoemail){
                    throw std::invalid_argument ("Digite um email válido\n");
                }
            } catch(std::invalid_argument& e) {
                while(!validoemail){
                    std::cerr << e.what();
                    std::cin >> email;
                    for(int i=0;i<email.length();i++){
                        if(email[i]=='@')
                            validoemail=true;
                    }
                }
            }
            std::cout << "Digite seu cpf: ";
            try { //verifica se o cpf é válido
                std::cin >> cpf;
                if(cpf.length()<11){
                    throw std::invalid_argument ("Digite um cpf válido\n");
                }
            } catch(std::invalid_argument& e){
                while(cpf.length()<11){
                    std::cerr << e.what();
                    std::cin >> cpf;
                }
            }
            std::cout << "Digite sua data de nascimento: ";
            //std::cin >> data_nascimento;
        }
    }
    else if(opcao1==3){ //área de acesso do aplicador
        std::cout << "Você deseja realizar login ou cadastro?\n";
        std::cout << "(1) Login\n(2) Cadastro\n";
        try{ //tratamento de exceção caso a opção seja inválida
            std::cin >> opcao2;
            if(opcao2!=1 || opcao2!=2 || !isdigit(opcao2)){
                throw std::invalid_argument ("Opção inexistente, digite novamente!\n");
        }
        } catch(std::invalid_argument& e){
            while(opcao2!=1 || opcao2!=2 || !isdigit(opcao2)){
                std::cerr << e.what();
                std::cin >> opcao2;
            }
        }
        if(opcao2==1){//verifica se o usuário está cadastrado
            std::cout << "Digite seu nome de usuário: ";
            std::cin >> nome;
            std::cout << "Digite sua senha: ";
            std::cin >> senha;
            bool existe=false;
            for(int i=0;i<p.size();i++){
                if(nome==p[i].get_nome()){
                    existe=true;
                    break;
                }
            }
            if(!existe){ //se não existir, realiza o cadastro
                std::cout << "Usuário inexistente, realize cadastro\n";
                opcao2=2;
            }
        }
        if(opcao2==2){ //realiza o cadastro
            //leitura dos dados e tratamento de excessão
            std::cout << "Digite o nome de usuário desejado: ";
            bool valido=true;
            bool validonome=true;
            bool validotel=true;
            bool validocpf=true;
            bool validoemail=false;
            bool validocoren=true;
            try{ //verifica se é válido
                std::cin >> login;
                for(int i=0;i<login.length();i++){
                    if(!isalpha(login[i]) || !isdigit(login[i])){
                        valido=false;
                        throw std::invalid_argument ("O login só pode conter letras e números, digite novamente\n");
                    }
                }
            } catch(std::invalid_argument& e){
                while(!valido){
                    std::cerr << e.what();
                    std::cin >> login;
                    for(int i=0;i<login.length();i++){
                        if(!isalpha(login[i]) || !isdigit(login[i])){
                            valido=false;
                            break;
                        }
                        valido=true;
                    }
                }
            }
            std::cout << "Escolha uma senha: ";
            try{ //verifica se é válida
                std::cin >> senha;
                if(senha.length()<8){
                    throw std::invalid_argument ("A senha deve ter no mínimo 8 caracteres\n");
                }
            } catch(std::invalid_argument& e){
                while(senha.length()<8){
                    std::cerr << e.what();
                    std::cin >> senha;
                }
            }
            std::cout << "Digite seu nome: ";
            try{ //verifica se é válido
                std::cin >> nome;
                for(int i=0;i<nome.length();i++){
                    if(!isalpha(nome[i])){
                        validonome=false;
                        throw std::invalid_argument ("O nome só pode conter letras, digite novamente\n");
                    }
                }
            } catch(std::invalid_argument& e){
                while(!validonome){
                    std::cerr << e.what();
                    std::cin >> nome;
                    for(int i=0;i,nome.length();i++){
                        if(!isalpha(nome[i])){
                            validonome=false;
                            break;
                        }
                        validonome=true;
                    }
                }
            }
            std::cout << "Digite um número de contato: ";
            try{ //verifica se é válido
                std::cin >> telefone;
                for(int i=0;i<telefone.length();i++){
                    if(isalpha(telefone[i]) || telefone.length()<10){
                        validotel=false;
                        throw std::invalid_argument ("O telefone tem no mínimo 10 dígitos e só pode conter letras, digite novamente\n");
                    }
                }
            } catch(std::invalid_argument& e){
                while(!validotel){
                    std::cerr << e.what();
                    for(int i=0;i,nome.length();i++){
                        if(isalpha(nome[i]) || telefone.length()<10){
                            validotel=false;
                            break;
                        }
                        validotel=true;
                    }
                }
            }
            std::cout << "Digite seu email: ";
            std::cin >> email;
            try { //verifica se possui @ e é um email válido
                std::cin >> email;
                for(int i=0;i<email.length();i++){
                    if(email[i]=='@')
                        validoemail=true;
                }
                if(!validoemail){
                    throw std::invalid_argument ("Digite um email válido\n");
                }
            } catch(std::invalid_argument& e) {
                while(!validoemail){
                    std::cerr << e.what();
                    std::cin >> email;
                    for(int i=0;i<email.length();i++){
                        if(email[i]=='@')
                            validoemail=true;
                    }
                }
            }
            std::cout << "Digite seu cpf: ";
            try { //verifica se o cpf é válido
                std::cin >> cpf;
                if(cpf.length()<11){
                    throw std::invalid_argument ("Digite um cpf válido\n");
                }
            } catch(std::invalid_argument& e){
                while(cpf.length()<11){
                    std::cerr << e.what();
                    std::cin >> cpf;
                }
            }
            std::cout << "Digite sua data de nascimento: ";
            std::cin >> data_nascimento;
            std::cout << "Digite seu número do coren: ";
            try { //verifica se o valor digitado é válido
                std::cin >> coren;
                for(int i=0;i<coren.length();i++){
                    if(!isdigit(coren[i])){
                        validocoren=false;
                        throw std::invalid_argument ("Digite um número válido\n");
                    }
                }
            } catch(std::invalid_argument& e){
                while(!validocoren){
                    std::cerr << e.what();
                    std::cin >> coren;
                    for(int i=0;i<coren.length();i++){
                        if(!isdigit(coren[i])){
                            validocoren=false;
                            break;
                        }
                        validocoren=true;
                    }
                }
            }
        }
        //construtor do aplicador
        a.push_back(new Aplicador(login,senha,nome,telefone,email,cpf,data_nascimento, coren));
    }
