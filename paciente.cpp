#include "paciente.h"
#include "usuario.h"
#include <string>
#include <iostream>
#include <vector>

//Construtor para paciente
Paciente::Paciente(std::string login, std::string senha, std::string nome, std::string telefone, std::string email,
                std::string cpf, std::string data_nascimento, std::string cns):
                Usuario(login,senha,nome,telefone,email,cpf,data_nascimento), _cns(cns){}

//função acessa o cns
std::string Paciente::get_cns(){
    return _cns;
}

//função modifica o cns
void Paciente::set_cns(std::string cns){
    _cns = cns;
}

//função modifica os dados do paciente
void Paciente::modificar_dados(std::vector <Paciente*> p, int aux){
    std::string opcao;
    std::cout <<"\nQual dado deseja modificar?\n";
    std::cout << "(1) Login\n(2) Senha\n(3) Nome\n(4) Telefone\n(5) E-mail\n(6) Data de nscimento\n";
    try{ //tratamento de exceção caso a opção seja inválida
        std::cin >> opcao;
        if(opcao!="1" || opcao!="2" || opcao!="3" || opcao!="4" || opcao!="5" || opcao!="6"){
            throw std::invalid_argument ("Opção inexistente, digite novamente!\n");
        }
    } catch(std::invalid_argument& e){
        while(opcao!="1" && opcao!="2" && opcao!="3" && opcao!="4" && opcao!="5" && opcao!="6"){
            std::cin.clear();
            std::cerr << e.what();
            std::cin >> opcao;
        }
    }
    //modificar login
    if(opcao == "1"){
    teste_login:
    bool valido = true;
    std::string login;
        std::cout << "\nDigite o novo login desejado: ";
        try{ //verifica se é válido
            std::cin >> login;
            for(int i=0;i<login.length();i++){
                if(ispunct(login[i])){
                    valido=false;
                    throw std::invalid_argument ("O login só pode conter letras e números, digite novamente\n");
                }
            }
            for(int i=0;i<p.size();i++){
                if(login==p[i]->get_login()){
                    valido=false;
                    throw std::invalid_argument ("Login já existente\n");
                }
            }
        } catch(std::invalid_argument& e){
            while(!valido){
                std::cerr << e.what();
                goto teste_login;
            }
        }
        if(valido==true){//chama a função do usuário para mudar o login
            p[aux]->set_login(login);
            std::cout << "Login modificado com sucesso.\n";
        }
    }
    //modificar senha
    if(opcao == "2"){
    std::string senha;
        std::cout << "\nDigite a nova senha desejada: ";
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
        
        p[aux]->set_senha(senha);//chama a função do usuário para mudar a senha
        std::cout << "Senha modificada com sucesso.\n";
        
    }
    //modificar nome
    if(opcao == "3"){
    std::string nome;
    bool valido = true;
        std::cout << "\nDigite o novo nome desejado: ";
        try{ //verifica se é válido
            std::cin.ignore();
            getline(std::cin,nome);
            for(int i=0;i<nome.length();i++){
                if(!isalpha(nome[i])){
                    valido=false;
                    throw std::invalid_argument ("O nome só pode conter letras, digite novamente\n");
                }
            }
        } catch(std::invalid_argument& e){
            while(!valido){
                std::cerr << e.what();
                std::cin >> nome;
                for(int i=0;i<nome.length();i++){
                    if(!isalpha(nome[i])){
                        valido=false;
                            break;
                    }
                    valido=true;
                }
            }
        }
        if(valido==true){//chama a função do usuário para mudar o nome
            p[aux]->set_nome(nome);
            std::cout << "Nome modificado com sucesso.\n";
        }
    }
    //modificar telefone
    if(opcao=="4"){
    std::string telefone;
    bool valido = true;
        std::cout << "\nDigite o novo número de telefone desejado: ";
        try{ //verifica se é válido
                std::cin >> telefone;
                if(telefone.length()<10){
                    valido=false;
                    throw std::invalid_argument ("O telefone tem no mínimo 10 dígitos e só pode conter números, digite novamente\n");
                }
                for(int i=0;i<telefone.length();i++){
                    if(isalpha(telefone[i])){
                        valido=false;
                        throw std::invalid_argument ("O telefone tem no mínimo 10 dígitos e só pode conter números, digite novamente\n");
                    }
                }
            } catch(std::invalid_argument& e){
                while(!valido){
                    std::cerr << e.what();
                    std::cin >> telefone;
                    for(int i=0;i<telefone.length();i++){
                        if(isalpha(telefone[i])){
                            valido=false;
                            break;
                        }
                        valido=true;
                    }
                    if(telefone.length()<10){
                        valido=false;
                    }
                }
            }
            if(valido==true){//chama a função do usuário para mudar o telefone
                p[aux]->set_telefone(telefone);
                std::cout << "Número de telefone modificado com sucesso.\n";
            }
    }
    //modificar o email
    if(opcao=="5"){
    std::string email;
    bool valido = true;
        std::cout << "\nDigite o novo e-mail desejado: ";
        try { //verifica se possui @ e é um email válido
                std::cin >> email;
                for(int i=0;i<email.length();i++){
                    if(email[i]=='@')
                        valido=true;
                }
                if(!valido){
                    throw std::invalid_argument ("Digite um email válido\n");
                }
            } catch(std::invalid_argument& e) {
                while(!valido){
                    std::cerr << e.what();
                    std::cin >> email;
                    for(int i=0;i<email.length();i++){
                        if(email[i]=='@')
                            valido=true;
                    }
                }
            }
            if(valido==true){//chama a função do usuário para mudar o email
                p[aux]->set_email(email);
                std::cout << "E-mail modificado com sucesso.\n";
            }
    }

    //modificar data de nascimento
    if(opcao=="6"){
        std::string data_nascimento;
        bool valido = true;
        std::string d,m,a;
            s:
            try{
                std::cout << "\nDigite a nova data de nascimento no formato dd/mm/aaaa: ";
                std::cin >> data_nascimento;
                if(data_nascimento.length()!=10){
                    valido=false;
                    throw std::invalid_argument("Digite a data de nascimento no formato especificado\n");
                }
                //verifica se não foi digitada alguma letra
                if(!isdigit(data_nascimento[0]) || !isdigit(data_nascimento[1]) || isalnum(data_nascimento[2]) || !isdigit(data_nascimento[3]) || !isdigit(data_nascimento[4]) || isalnum(data_nascimento[5]) || !isdigit(data_nascimento[6]) || !isdigit(data_nascimento[7]) || !isdigit(data_nascimento[8]) || !isdigit(data_nascimento[9])){
                    valido=false;
                    throw std::invalid_argument("Digite a data no formato especificado.\n");
                }
                d[0]=data_nascimento[0]; d[1]=data_nascimento[1];
                m[0]=data_nascimento[3]; m[1]=data_nascimento[4];
                a[0]=data_nascimento[6]; a[1]=data_nascimento[7]; a[2]=data_nascimento[8]; a[3]=data_nascimento[9];
                if(stoi(d)<=0){
                    valido=false;
                    throw std::invalid_argument("Dia inválido, digite novamente\n");
                }
                if(stoi(m)>12 || stoi(m)<0){
                    valido=false;
                    throw std::invalid_argument("Mês inválido, digite novamente\n");
                }
                if((stoi(m)==1 || stoi(m)==3 || stoi(m)==5 || stoi(m)==7 || stoi(m)==8 || stoi(m)==10 || stoi(m)==12) && stoi(d)>31){
                    valido=false;
                    throw std::invalid_argument("Data inexistente, digite novamente\n");
                }
                else if((stoi(m)==4 || stoi(m)==6 || stoi(m)==9 || stoi(m)==11) && stoi(d)>31){
                    valido=false;
                    throw std::invalid_argument("Data inexistente, digite novamente\n");
                }
                else if(stoi(m)==2 && stoi(d)>28){
                    valido=false;
                    throw std::invalid_argument("Data inexistente, digite novamente\n");
                }
                else if(stoi(a)>2023 || stoi(a)<1907){
                    valido=false;
                    throw std::invalid_argument("Ano inválido, digite novamente\n");
                }
                valido=true;
            } catch(std::invalid_argument& e){
                std::cerr << e.what();
                if(!valido){
                    goto s;
                }
            }
            if(valido==true){
                p[aux]->set_data_nascimento(data_nascimento);
                std::cout << "Data de nascimento modificada com sucesso.\n";
            }

    }

}

//função que exibe os dados do paciente
void Paciente::visualizar_dados(std::vector <Paciente*> p, int aux){
    std::cout << "\n--------------- Dados --------------- " << std::endl;
    std::cout << "Login: " << p[aux]->get_login() << std::endl;
    std::cout << "Nome: " << p[aux]->get_nome() << std::endl;
    std::cout << "Telefone: " << p[aux]->get_telefone() << std::endl;
    std::cout << "E-mail: " << p[aux]->get_email() << std::endl;
    std::cout << "CPF: " << p[aux]->get_cpf() << std::endl;
    std::cout << "Data de nascimento: " << p[aux]->get_data_nascimento() << std::endl;
    std::cout << "Cartão Nacional de Saúde (CNS): " << p[aux]->get_cns() << std::endl;
    std::cout << "--------------------------------------- " << std::endl;

}

