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
    std::string nome2, endereco;
    //dados de estoque
    std::string nome3, validade, data_recebimento, lote; 
    int quantidade, dia, mes, ano;
    //dados de vacina
    std::string fabricante, tipo, aplicacao;
    //valor das opcoes
    std::string opcao1, opcao2, opcao3;
    int aux; //guarda o indice do usuario
    //objetos criados já existentes no sistema
    p.push_back(new Paciente("lilicesm","abcde","Alice","3299774784","lilicesm@gmail.com","12345678912","30/12/2004","12345"));
    p.push_back(new Paciente("jugama","ndsfkl","Julia","3299980345","jugama@gmail.com","65316789032","19/05/2005","54665"));
    a.push_back(new Aplicador("cecicassab","67567","Cecilia","32984365837","ceci@gmail.com","13138476532","31/12/2004","86709"));
    a.push_back(new Aplicador("marycosta","6575","Maryana","32997654890","marycosta@gmail.com","95643123897","06/06/2003","98765"));
    g.push_back(new Gerente("mariads","4292","Maria","45997654890","mariasouza@gmail.com","95643123897","07/10/2004", "posto1", "sao sebastiao"));
    //definição de que tipo de usuário acessará o sistema, o que define diferentes funções
    std::cout << "--------------- Inicio --------------- " << std::endl;
    std::cout << "Que tipo de usuário você é?\n";
    std::cout << "(1) Paciente\n(2) Gerente\n(3) Aplicador\n";
    try{ //tratamento de exceção caso a opção seja inválida
        std::cin >> opcao1;
        if(opcao1!="1" || opcao1!="2" || opcao1!="3"){
            throw std::invalid_argument ("Opção inexistente, digite novamente!\n");
        }
    } catch(std::invalid_argument& e){
        while(opcao1!="1" && opcao1!="2" && opcao1!="3"){
            std::cerr << e.what();
            std::cin >> opcao1;
        }
    }
    if(opcao1=="1"){ //área de acesso do paciente
        std::cout << "\nVocê deseja realizar login ou cadastro?\n";
        std::cout << "(1) Login\n(2) Cadastro\n";
        try{ //tratamento de exceção caso a opção seja inválida
            std::cin >> opcao2;
            if(opcao2!="1" || opcao2!="2"){
                throw std::invalid_argument ("Opção inexistente, digite novamente!\n");
        }
        } catch(std::invalid_argument& e){
            while(opcao2!="1" && opcao2!="2"){
                std::cerr << e.what();
                std::cin >> opcao2;
            }
        }
        if(opcao2=="1"){//verifica se o usuário está cadastrado
            std::cout << "\n--------------- Login --------------- " << std::endl;
            std::cout << "Digite seu nome de usuário: ";
            std::cin >> nome;
            std::cout << "Digite sua senha: ";
            std::cin >> senha;
            bool existe=false;
            for(int i=0;i<p.size();i++){
                if(nome==p[i]->get_nome()){
                    existe=true;
                    break;
                }
            }
            if(!existe){ //se não existir, realiza o cadastro
                std::cout << "Usuário inexistente, realize cadastro\n";
                opcao2=2;
            }
        }
        if(opcao2=="2"){ //realiza o cadastro
            //leitura dos dados e tratamento de excessão
            std::cout << "\n--------------- Cadastro --------------- " << std::endl;
            std::cout << "Digite o nome de usuário desejado: ";
            bool valido=true;
            bool validonome=true;
            bool validotel=true;
            bool validocpf=true;
            bool validoemail=false;
            bool validodata=true;
            bool validocns=true;
            try{ //verifica se é válido
                std::cin >> login;
                for(int i=0;i<login.length();i++){
                    if(ispunct(login[i])){
                        valido=false;
                        throw std::invalid_argument ("O login só pode conter letras e números, digite novamente\n");
                    }
                }
            } catch(std::invalid_argument& e){
                while(!valido){
                    std::cerr << e.what();
                    std::cin >> login;
                    for(int i=0;i<login.length();i++){
                        if(ispunct(login[i])){
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
                    for(int i=0;i<nome.length();i++){
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
                if(telefone.length()<10){
                    validotel=false;
                    throw std::invalid_argument ("O telefone tem no mínimo 10 dígitos e só pode conter letras, digite novamente\n");
                }
                for(int i=0;i<telefone.length();i++){
                    if(isalpha(telefone[i])){
                        validotel=false;
                        throw std::invalid_argument ("O telefone tem no mínimo 10 dígitos e só pode conter letras, digite novamente\n");
                    }
                }
            } catch(std::invalid_argument& e){
                while(!validotel){
                    std::cerr << e.what();
                    std::cin >> telefone;
                    for(int i=0;i<telefone.length();i++){
                        if(isalpha(telefone[i])){
                            validotel=false;
                            break;
                        }
                        validotel=true;
                    }
                    if(telefone.length()<10){
                        validotel=false;
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
                    validocpf=false;
                    throw std::invalid_argument ("Digite um cpf válido\n");
                }
                for(int i=0;i<cpf.length();i++){
                    if(isalpha(cpf[i])){
                        validocpf=false;
                        throw std::invalid_argument ("Digite um cpf válido\n");
                    }
                }
            } catch(std::invalid_argument& e){
                while(!validocpf){
                    std::cerr << e.what();
                    std::cin >> cpf;
                    for(int i=0;i<cpf.length();i++){
                        if(isalpha(cpf[i])){
                            validocpf=false;
                            break;
                        }
                        validocpf=true;
                    }
                    if(cpf.length()<11){
                        validocpf=false;
                    }
                }
            }
            std::cout << "Digite sua data de nascimento: ";
            std::cin >> data_nascimento;
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
            //construtor do paciente
            p.push_back(new Paciente(login,senha,nome,telefone,email,cpf,data_nascimento,cns));

        }
    }
    else if(opcao1=="2"){ //área de acesso do gerente
        std::cout << "\nVocê deseja realizar login ou cadastro?\n";
        std::cout << "(1) Login\n(2) Cadastro\n";
        try{ //tratamento de exceção caso a opção seja inválida
            std::cin >> opcao2;
            if(opcao2!="1" || opcao2!="2"){
                throw std::invalid_argument ("Opção inexistente, digite novamente!\n");
        }
        } catch(std::invalid_argument& e){
            while(opcao2!="1" && opcao2!="2"){
                std::cerr << e.what();
                std::cin >> opcao2;
            }
        }
        if(opcao2=="1"){//verifica se o usuário está cadastrado
            std::cout << "\n--------------- Login --------------- " << std::endl;
            std::cout << "Digite seu nome de usuário: ";
            std::cin >> login;
            std::cout << "Digite sua senha: ";
            std::cin >> senha;
            bool existe=false;
            for(int i=0;i<g.size();i++){
                if(login==g[i]->get_login()){
                    aux = i;
                    existe=true;
                    break;
                }
            }
            if(!existe){ //se não existir, realiza o cadastro
                std::cout << "Usuário inexistente, realize cadastro\n";
                opcao2="2";
            }
        }
        if(opcao2=="2"){ //realiza o cadastro
            //leitura dos dados e tratamento de excessão
            std::cout << "\n--------------- Cadastro --------------- " << std::endl;
            std::cout << "Digite o nome de usuário desejado: ";
            bool valido=true;
            bool validonome=true;
            bool validotel=true;
            bool validocpf=true;
            bool validoemail=false;
            bool validonome2=true;
            try{ //verifica se é válido
                std::cin >> login;
                for(int i=0;i<login.length();i++){
                    if(ispunct(login[i])){
                        valido=false;
                        throw std::invalid_argument ("O login só pode conter letras e números, digite novamente\n");
                    }
                }
            } catch(std::invalid_argument& e){
                while(!valido){
                    std::cerr << e.what();
                    std::cin >> login;
                    for(int i=0;i<login.length();i++){
                        if(ispunct(login[i])){
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
                    for(int i=0;i<nome.length();i++){
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
                if(telefone.length()<10){
                    validotel=false;
                    throw std::invalid_argument ("O telefone tem no mínimo 10 dígitos e só pode conter letras, digite novamente\n");
                }
                for(int i=0;i<telefone.length();i++){
                    if(isalpha(telefone[i])){
                        validotel=false;
                        throw std::invalid_argument ("O telefone tem no mínimo 10 dígitos e só pode conter letras, digite novamente\n");
                    }
                }
            } catch(std::invalid_argument& e){
                while(!validotel){
                    std::cerr << e.what();
                    std::cin >> telefone;
                    for(int i=0;i<telefone.length();i++){
                        if(isalpha(telefone[i])){
                            validotel=false;
                            break;
                        }
                        validotel=true;
                    }
                    if(telefone.length()<10){
                        validotel=false;
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
                    validocpf=false;
                    throw std::invalid_argument ("Digite um cpf válido\n");
                }
                for(int i=0;i<cpf.length();i++){
                    if(isalpha(cpf[i])){
                        validocpf=false;
                        throw std::invalid_argument ("Digite um cpf válido\n");
                    }
                }
            } catch(std::invalid_argument& e){
                while(!validocpf){
                    std::cerr << e.what();
                    std::cin >> cpf;
                    for(int i=0;i<cpf.length();i++){
                        if(isalpha(cpf[i])){
                            validocpf=false;
                            break;
                        }
                        validocpf=true;
                    }
                    if(cpf.length()<11){
                        validocpf=false;
                    }
                }
            }
            //tem que adicionar excecao depois
            std::cout << "Digite sua data de nascimento: ";
            std::cin >> data_nascimento;
            //variaveis do posto
            std::cout << "Digite o nome do posto onde trabalha: ";
            try{ //verifica se é válido
                std::cin >> nome2;
                for(int i=0;i<nome2.length();i++){
                    if(!isalpha(nome2[i])){
                        validonome2=false;
                        throw std::invalid_argument ("O nome só pode conter letras, digite novamente\n");
                    }
                }
            } catch(std::invalid_argument& e){
                while(!validonome2){
                    std::cerr << e.what();
                    std::cin >> nome2;
                    for(int i=0;i<nome2.length();i++){
                        if(!isalpha(nome2[i])){
                            validonome2=false;
                            break;
                        }
                        validonome2=true;
                    }
                }
            }
            std::cout << "Digite o endereço do posto onde trabalha: ";
            std::cin >> endereco;
            //construtor do gerente
            g.push_back(new Gerente(login,senha,nome,telefone,email,cpf,data_nascimento,nome2,endereco));
        }
        //operações do gerente
        std::cout << "\nQual operação deseja realizar?\n";
        std::cout << "(1) Adicionar Estoque\n(2) Alterar estoque\n(3) Vizualizar estoque\n(4) Fazer Pedido\n";
        try{ //tratamento de exceção caso a opção seja inválida
        std::cin >> opcao3;
        if(opcao3!="1" || opcao3!="2" || opcao3!="3" || opcao3!="4"){
            std::cin.clear();
            throw std::invalid_argument ("Opção inexistente, digite novamente!\n");
        }
        } catch(std::invalid_argument& e){
            while(opcao3!="1" && opcao3!="2" && opcao3!="3" && opcao3!="4"){
                std::cin.clear();
                std::cerr << e.what();
                std::cin >> opcao3;
            }
        } 
        //operacao de adicionar o estoque
        if(opcao3 == "1"){
            g[aux]->adicionar_estoque();
        }
        //operacao de alterar o estoque
        if(opcao3 == "2"){
            g[aux]->alterar_estoque();
        }
        //operacao de vizualizar o estoque
        if(opcao3 == "3"){
            g[aux]->vizualizar_estoque();
        }
        //operacao de fazer pedido
        if(opcao3 == "4"){
            g[aux]->fazer_pedido();
        }
    }
    else if(opcao1=="3"){ //área de acesso do aplicador
        std::cout << "Você deseja realizar login ou cadastro?\n";
        std::cout << "(1) Login\n(2) Cadastro\n";
        try{ //tratamento de exceção caso a opção seja inválida
            std::cin >> opcao2;
            if(opcao2!="1" || opcao2!="2"){
                throw std::invalid_argument ("Opção inexistente, digite novamente!\n");
        }
        } catch(std::invalid_argument& e){
            while(opcao2!="1" || opcao2!="2"){
                std::cerr << e.what();
                std::cin >> opcao2;
            }
        }
        if(opcao2=="1"){//verifica se o usuário está cadastrado
            std::cout << "\n--------------- Login --------------- " << std::endl;
            std::cout << "Digite seu nome de usuário: ";
            std::cin >> nome;
            std::cout << "Digite sua senha: ";
            std::cin >> senha;
            bool existe=false;
            for(int i=0;i<p.size();i++){
                if(nome==p[i]->get_nome()){
                    existe=true;
                    break;
                }
            }
            if(!existe){ //se não existir, realiza o cadastro
                std::cout << "Usuário inexistente, realize cadastro\n";
                opcao2=2;
            }
        }
        if(opcao2=="2"){ //realiza o cadastro
            //leitura dos dados e tratamento de excessão
            std::cout << "\n--------------- Cadastro --------------- " << std::endl;
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
                    if(ispunct(login[i])){
                        valido=false;
                        throw std::invalid_argument ("O login só pode conter letras e números, digite novamente\n");
                    }
                }
            } catch(std::invalid_argument& e){
                while(!valido){
                    std::cerr << e.what();
                    std::cin >> login;
                    for(int i=0;i<login.length();i++){
                        if(ispunct(login[i])){
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
                    for(int i=0;i<nome.length();i++){
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
                if(telefone.length()<10){
                    validotel=false;
                    throw std::invalid_argument ("O telefone tem no mínimo 10 dígitos e só pode conter letras, digite novamente\n");
                }
                for(int i=0;i<telefone.length();i++){
                    if(isalpha(telefone[i])){
                        validotel=false;
                        throw std::invalid_argument ("O telefone tem no mínimo 10 dígitos e só pode conter letras, digite novamente\n");
                    }
                }
            } catch(std::invalid_argument& e){
                while(!validotel){
                    std::cerr << e.what();
                    std::cin >> telefone;
                    for(int i=0;i<telefone.length();i++){
                        if(isalpha(telefone[i])){
                            validotel=false;
                            break;
                        }
                        validotel=true;
                    }
                    if(telefone.length()<10){
                        validotel=false;
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
                    validocpf=false;
                    throw std::invalid_argument ("Digite um cpf válido\n");
                }
                for(int i=0;i<cpf.length();i++){
                    if(isalpha(cpf[i])){
                        validocpf=false;
                        throw std::invalid_argument ("Digite um cpf válido\n");
                    }
                }
            } catch(std::invalid_argument& e){
                while(!validocpf){
                    std::cerr << e.what();
                    std::cin >> cpf;
                    for(int i=0;i<cpf.length();i++){
                        if(isalpha(cpf[i])){
                            validocpf=false;
                            break;
                        }
                        validocpf=true;
                    }
                    if(cpf.length()<11){
                        validocpf=false;
                    }
                }
            }
            // falta adicionar exceção
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
            //construtor de aplicador
            a.push_back(new Aplicador(login,senha,nome,telefone,email,cpf,data_nascimento,coren));
        }
        // operações do aplicador
        std::cout << "\nQual operação deseja realizar?\n";
        std::cout << "(1) Registrar vacina aplicada\n(2) Verificar data de retorno do paciente\n (3) Definir data de retorno do paciente\n";
        try{ 
            std::cin >> opcao3;
            if(opcao3!="1" || opcao3!="2" || opcao3!="3"){
                std::cin.clear();
                throw std::invalid_argument ("Opção inexistente, digite novamente!\n");
            }
        } catch(std::invalid_argument &e){
            while(opcao3!="1" && opcao3!="2" && opcao3!="3"){
                std::cin.clear();
                std::cerr << e.what();
                std::cin >> opcao3;
            }
        }
        if(opcao3=="1")
            a[aux] -> registrar_vacina();
}