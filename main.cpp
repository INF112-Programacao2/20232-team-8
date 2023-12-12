#include <string>
#include "aplicador.h"
#include "historico.h"
#include "paciente.h"
#include "usuario.h"
#include "vacina.h"
#include "estoque.h"
#include "gerente.h"
#include <iostream>
#include <vector>
#include <string>
#include <exception>
#include <stdlib.h>

int main(void){ 
    //vector para cada tipo de usuário
    std::vector <Paciente*> _paciente;
    std::vector <Gerente*> _gerente;
    std::vector <Aplicador*> _aplicador;
    //variáveis para a inicialização dos objetos
    std::string login, senha, nome, telefone, email, cpf, data_nascimento, coren, cns;
    //dados de estoque
    std::string nome3, validade, data_recebimento, lote; 
    int quantidade, dia, mes, ano;
    //dados de vacina
    std::string fabricante, tipo, aplicacao;
    //valor das opcoes
    std::string opcao1, opcao2, opcao3;
    int aux, aux1; //guarda o indice do usuario
    //objetos criados já existentes no sistema
    _paciente.push_back(new Paciente("lilicesm","abcde","Alice","3299774784","lilicesm@gmail.com","12345678912","30/12/2004","12345"));
    _paciente.push_back(new Paciente("jugama","ndsfkl","Julia","3299980345","jugama@gmail.com","65316789032","19/05/2005","54665"));
    _aplicador.push_back(new Aplicador("cecicassab","67567","Cecilia","32984365837","ceci@gmail.com","13138476532","31/12/2004","86709"));
    _aplicador.push_back(new Aplicador("marycosta","6575","Maryana","32997654890","marycosta@gmail.com","95643123897","06/06/2003","98765"));
    _gerente.push_back(new Gerente("mariads","4292","Maria","45997654890","mariasouza@gmail.com","95643123897","07/10/2004"));
    //definição de que tipo de usuário acessará o sistema, o que define diferentes funções
    inicio: //flag para o goto ao escolher a opção encerrar sessão
    std::cout << "--------------- Inicio --------------- " << std::endl;
    std::cout << "Qual área deseja acessar?\n";
    std::cout << "(1) Paciente\n(2) Gerente\n(3) Aplicador\n(4) Encerrar programa\n";
    try{ //tratamento de exceção caso a opção seja inválida
        std::cin >> opcao1;
        if(opcao1!="1" || opcao1!="2" || opcao1!="3" || opcao1!="4"){
            throw std::invalid_argument ("Opção inexistente, digite novamente!\n");
        }
    } catch(std::invalid_argument& e){
        while(opcao1!="1" && opcao1!="2" && opcao1!="3" && opcao1!="4"){
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
            bool existe=false;
            std::cout << "\n--------------- Login --------------- " << std::endl;
            std::cout << "Digite seu nome de usuário: ";
            std::cin >> login;
            for(int i=0;i<_paciente.size();i++){
                if(login==_paciente[i]->get_login()){
                    aux1 = i;
                    existe=true;
                    break;
                }
            }
            if(!existe){ //se não existir, realiza o cadastro
                std::cout << "Usuário inexistente, realize cadastro\n";
                opcao2="2";
            }
            if(existe){
                std::cout << "Digite sua senha: "; //se existir o usuário, verifica se a senha está correta
                std::cin >> senha;
                while(senha!=_paciente[aux1]->get_senha()){
                    std::cout << "Senha incorreta, digite novamente\n";
                    std::cin >> senha;
                }
            }
            std::cout << "------------------------------------- " << std::endl;
        }
        if(opcao2=="2"){ //realiza o cadastro
            //leitura dos dados e tratamento de excessão
            std::cout << "\n--------------- Cadastro --------------- " << std::endl;
            std::cout << "Digite o nome de usuário desejado: ";
            //booleanos para o tratamento de exceção das variáveis lidas
            bool valido=true;
            bool validonome=true;
            bool validotel=true;
            bool validocpf=true;
            bool validoemail=false;
            bool validodata=true;
            bool validocns=true;
            try{ //verifica se é válido
                std::cin >> login;
                //verifica se o login já está cadastrado
                for(int i=0;i<_paciente.size();i++){
                    if(login==_paciente[i]->get_login()){ 
                        valido=false;
                        throw std::invalid_argument("Login já existente, escolha outro\n");
                    }
                }
                //verifica se o login contem algum caractere especial
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
                //verifica se a senha tem o tamanho mínimo definido como 8 caracteres
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
                std::cin.ignore();
                getline(std::cin,nome);
                //verifica se o nome só contem caracteres alfabéticos
                for(int i=0;i<nome.length();i++){
                    if(!isalpha(nome[i]) && !isspace(nome[i])){
                        validonome=false;
                        throw std::invalid_argument ("O nome só pode conter letras, digite novamente\n");
                    }
                }
            } catch(std::invalid_argument& e){
                while(!validonome){
                    std::cerr << e.what();
                    std::cin >> nome;
                    for(int i=0;i<nome.length();i++){
                        if(!isalpha(nome[i]) && !isspace(nome[i])){
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
                //verifica se o tamanho do número informado corresponde ao tamanho de um número telefônico
                if(telefone.length()<10){
                    validotel=false;
                    throw std::invalid_argument ("O telefone tem no mínimo 10 dígitos e só pode conter números, digite novamente\n");
                }
                //verifica se o telefone só contem dígitos
                for(int i=0;i<telefone.length();i++){
                    if(isalpha(telefone[i])){
                        validotel=false;
                        throw std::invalid_argument ("O telefone tem no mínimo 10 dígitos e só pode conter números, digite novamente\n");
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
                //verifica se o cpf já está cadastrado
                for(int i=0;i<_paciente.size();i++){
                    if(cpf==_paciente[i]->get_cpf()){
                        validocpf=false;
                        throw std::invalid_argument("Cpf já cadastrado\n");
                    }
                }
                //verifica se a string de entrada possui o tamanho correto
                if(cpf.length()<11){
                    validocpf=false;
                    throw std::invalid_argument ("Digite um cpf válido\n");
                }
                //verifica se o cpf só contem números
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
            //strings auxiliares para tratamento de exceção de data
            std::string d,m,a;
            s:
            try{
                std::cout << "Digite a data de nascimento no formato dd/mm/aaaa: ";
                std::cin >> data_nascimento;
                //verifica se a data está no formato especificado
                if(data_nascimento.length()!=10){
                    validodata=false;
                    throw std::invalid_argument("Digite a data de nascimento no formato especificado\n");
                }
                //verifica se não foi digitada alguma letra
                if(!isdigit(data_nascimento[0]) || !isdigit(data_nascimento[1]) || isalnum(data_nascimento[2]) || !isdigit(data_nascimento[3]) || !isdigit(data_nascimento[4]) || isalnum(data_nascimento[5]) || !isdigit(data_nascimento[6]) || !isdigit(data_nascimento[7]) || !isdigit(data_nascimento[8]) || !isdigit(data_nascimento[9])){
                    validodata=false;
                    throw std::invalid_argument("Digite a data no formato especificado.\n");
                }
                //utiliza as strings auxiliares para analizar cada caso
                d[0]=data_nascimento[0]; d[1]=data_nascimento[1];
                m[0]=data_nascimento[3]; m[1]=data_nascimento[4];
                a[0]=data_nascimento[6]; a[1]=data_nascimento[7]; a[2]=data_nascimento[8]; a[3]=data_nascimento[9];
                //verifica se o dia é válido
                if(stoi(d)<=0){
                    validodata=false;
                    throw std::invalid_argument("Dia inválido, digite novamente\n");
                }
                //verifica se o mẽs é válido
                if(stoi(m)>12 || stoi(m)<0){
                    validodata=false;
                    throw std::invalid_argument("Mês inválido, digite novamente\n");
                }
                //verifica se a data existe baseado no mẽs e sua respectiva quantidade de dias
                if((stoi(m)==1 || stoi(m)==3 || stoi(m)==5 || stoi(m)==7 || stoi(m)==8 || stoi(m)==10 || stoi(m)==12) && stoi(d)>31){
                    validodata=false;
                    throw std::invalid_argument("Data inexistente, digite novamente\n");
                }
                else if((stoi(m)==4 || stoi(m)==6 || stoi(m)==9 || stoi(m)==11) && stoi(d)>31){
                    validodata=false;
                    throw std::invalid_argument("Data inexistente, digite novamente\n");
                }
                else if(stoi(m)==2 && stoi(d)>28){
                    validodata=false;
                    throw std::invalid_argument("Data inexistente, digite novamente\n");
                }
                //verifica se o ano é válido
                else if(stoi(a)>2023 || stoi(a)<1907){
                    validodata=false;
                    throw std::invalid_argument("Ano inválido, digite novamente\n");
                }
                validodata=true;
            } catch(std::invalid_argument& e){
                std::cerr << e.what();
                if(!validodata){
                    goto s;
                }
            }
            std::cout << "Digite o número do seu cartão nacional de saúde: ";
            try { //verifica se é um número válido
                std::cin >> cns;
                //verifica se é um cns já cadastrado
                for(int i=0;i<_paciente.size();i++){
                    if(cns==_paciente[i]->get_cns()){
                        valido=false;
                        throw std::invalid_argument("Número de cartão nacional de saúde já cadastrado\n");
                    }
                }
                //verfica o tamanho e se contem somente números
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
            std::cout << "---------------------------------------- " << std::endl;
            //construtor do paciente
            _paciente.push_back(new Paciente(login,senha,nome,telefone,email,cpf,data_nascimento,cns));
            //guarda o indice do paciente para utilização das funções
            for(int i=0; i<_paciente.size(); i++){
                if(_paciente[i]->get_login() == login){
                    aux1 = i;
                    break;
                }
            }
        }

        while(true){
            //operações do paciente
            std::cout << "\nQual operação deseja realizar?\n";
            std::cout << "(1) Modificar Dados\n(2) Visualizar Dados\n(3) Visualizar histórico de vacinas\n(4) Encerrar Sessão\n";
            try{ //tratamento de exceção caso a opção seja inválida
            std::cin >> opcao3;
            if(opcao3!="1" || opcao3!="2" || opcao3!="3" || opcao3!="4"){
                throw std::invalid_argument ("Opção inexistente, digite novamente!\n");
            }
            } catch(std::invalid_argument& e){
            while(opcao3!="1" && opcao3!="2" && opcao3!="3" && opcao3!="4"){
                std::cin.clear();
                std::cerr << e.what();
                std::cin >> opcao3;
                }
            } 
            //operacao de modificar dados
            if(opcao3 == "1"){
                _paciente[aux1]->modificar_dados(_paciente, aux1);
            }
            //operacao de visualizar dados
            if(opcao3 == "2"){
                _paciente[aux1]->visualizar_dados(_paciente, aux1);
            }
            //operacao de visualizar historico de vacinas
            if(opcao3 == "3"){
                for(int i=0; i<_aplicador.size(); i++){
                    _aplicador[i]->visualizar_historico(_paciente[aux1]->get_cns());
                }
            }
            //operacao de encerrar sessão
            if(opcao3 == "4"){
                std::cout << std::endl;
                goto inicio;
            }
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
            bool existe = false;
            for(int i=0;i<_gerente.size();i++){
                if(login==_gerente[i]->get_login()){
                    aux = i; //guarda do indice do usuario
                    existe=true;
                    break;
                }
            }
            if(!existe){ //se não existir, realiza o cadastro
                std::cout << "Usuário inexistente, realize cadastro\n";
                opcao2="2";
            }
            //verifica se a senha está correta
            std::cout << "Digite sua senha: ";
            bool senha_correta;
            try{
                senha_correta = true;
                std::cin >> senha;
                for(int i=0; i<senha.size(); i++){
                    if(senha[i] != _gerente[aux]->get_senha()[i]){
                        senha_correta = false;
                        throw std:: invalid_argument ("Senha incorreta! Digite novamente: ");
                    }
                }
            }catch(std::invalid_argument& e){
                while(!senha_correta){
                    std::cerr << e.what();
                    senha_correta = true;
                    std::cin >> senha;
                    for(int i=0; i<senha.size(); i++){
                        if(senha[i] != _gerente[aux]->get_senha()[i]){
                            senha_correta = false;
                        }
                    }
                }
            }
            std::cout << "------------------------------------- " << std::endl;
        }
        if(opcao2=="2"){ //realiza o cadastro
            //leitura dos dados e tratamento de excessão
            std::cout << "\n--------------- Cadastro --------------- " << std::endl;
            std::cout << "Digite o nome de usuário desejado: ";
            //booleanos para tratamento de exceçao
            bool valido=true;
            bool validonome=true;
            bool validotel=true;
            bool validocpf=true;
            bool validoemail=false;
            bool validodata=true;
            try{ //verifica se é válido
                std::cin >> login;
                //verifica se já está cadastrado
                for(int i=0;i<_gerente.size();i++){
                    if(login==_gerente[i]->get_login()){
                        valido=false;
                        throw std::invalid_argument("Login já existente, escolha outro\n");
                    }
                }
                //verifica se possui algum caractere especial
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
                //verifica se tem o tamanho mínimo estipulado de 8 caracteres
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
                std::cin.ignore();
                getline(std::cin,nome);
                //verifica se só possui caracteres alfabéticos
                for(int i=0;i<nome.length();i++){
                    if(!isalpha(nome[i]) && !isspace(nome[i])){
                        validonome=false;
                        throw std::invalid_argument ("O nome só pode conter letras, digite novamente\n");
                    }
                }
            } catch(std::invalid_argument& e){
                while(!validonome){
                    std::cerr << e.what();
                    std::cin >> nome;
                    for(int i=0;i<nome.length();i++){
                        if(!isalpha(nome[i]) && !isspace(nome[i])){
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
                //verifica se possui o tamanho correto
                if(telefone.length()<10){
                    validotel=false;
                    throw std::invalid_argument ("O telefone tem no mínimo 10 dígitos e só pode conter números, digite novamente\n");
                }
                //verifica se possui letra
                for(int i=0;i<telefone.length();i++){
                    if(isalpha(telefone[i])){
                        validotel=false;
                        throw std::invalid_argument ("O telefone tem no mínimo 10 dígitos e só pode conter números, digite novamente\n");
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
                //verifica se o cpf já está cadastrado
                for(int i=0;i<_gerente.size();i++){
                    if(cpf==_gerente[i]->get_cpf()){
                        validocpf=false;
                        throw std::invalid_argument("Cpf já cadastrado\n");
                    }
                }
                //verifica se possui o tamanho correto
                if(cpf.length()<11){
                    validocpf=false;
                    throw std::invalid_argument ("Digite um cpf válido\n");
                }
                //verifica se possui letras
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
            //tratamento de exceção da data
            std::string d,m,a;
            i:
            try{
                std::cout << "Digite a data de nascimento no formato dd/mm/aaaa: ";
                std::cin >> data_nascimento;
                //verifica se a data está no formato estipulado
                if(data_nascimento.length()!=10){
                    validodata=false;
                    throw std::invalid_argument("Digite a data de nascimento no formato especificado\n");
                }
                //verifica se não foi digitada alguma letra
                if(!isdigit(data_nascimento[0]) || !isdigit(data_nascimento[1]) || isalnum(data_nascimento[2]) || !isdigit(data_nascimento[3]) || !isdigit(data_nascimento[4]) || isalnum(data_nascimento[5]) || !isdigit(data_nascimento[6]) || !isdigit(data_nascimento[7]) || !isdigit(data_nascimento[8]) || !isdigit(data_nascimento[9])){
                    validodata=false;
                    throw std::invalid_argument("Digite a data no formato especificado.\n");
                }
                d[0]=data_nascimento[0]; d[1]=data_nascimento[1];
                m[0]=data_nascimento[3]; m[1]=data_nascimento[4];
                a[0]=data_nascimento[6]; a[1]=data_nascimento[7]; a[2]=data_nascimento[8]; a[3]=data_nascimento[9];
                //verifica se o dia é válido
                if(stoi(d)<=0){
                    validodata=false;
                    throw std::invalid_argument("Dia inválido, digite novamente\n");
                }
                //verifica se o mês é válido
                if(stoi(m)>12 || stoi(m)<0){
                    validodata=false;
                    throw std::invalid_argument("Mês inválido, digite novamente\n");
                }
                //verifica se a data existe baseado na quantidade de dias do mês informado
                if((stoi(m)==1 || stoi(m)==3 || stoi(m)==5 || stoi(m)==7 || stoi(m)==8 || stoi(m)==10 || stoi(m)==12) && stoi(d)>31){
                    validodata=false;
                    throw std::invalid_argument("Data inexistente, digite novamente\n");
                }
                else if((stoi(m)==4 || stoi(m)==6 || stoi(m)==9 || stoi(m)==11) && stoi(d)>31){
                    validodata=false;
                    throw std::invalid_argument("Data inexistente, digite novamente\n");
                }
                else if(stoi(m)==2 && stoi(d)>28){
                    validodata=false;
                    throw std::invalid_argument("Data inexistente, digite novamente\n");
                }
                //verifica se o ano é válido
                else if(stoi(a)>2023 || stoi(a)<1907){
                    validodata=false;
                    throw std::invalid_argument("Ano inválido, digite novamente\n");
                }
                validodata=true;
            } catch(std::invalid_argument& e){
                std::cerr << e.what();
                if(!validodata){
                    goto i;
                }
            }
            std::cout << "---------------------------------------- " << std::endl;
            //construtor do gerente
            _gerente.push_back(new Gerente(login,senha,nome,telefone,email,cpf,data_nascimento));
            //guarda o indice do gerente que está acessando o programa para uso das funções
            for(int i=0; i<_gerente.size(); i++){
                if(_gerente[i]->get_login() == login){
                    aux = i;
                    break;
                }
            }
        }
    
        while(true){
            //operações do gerente
            std::cout << "\nQual operação deseja realizar?\n";
            std::cout << "(1) Adicionar Estoque\n(2) Alterar estoque\n(3) Visualizar estoque\n(4) Editar dados pessoais\n(5) Visualizar dados pessoais\n(6) Encerrar Sessão\n";
            try{ //tratamento de exceção caso a opção seja inválida
                std::cin >> opcao3;
            if(opcao3!="1" || opcao3!="2" || opcao3!="3" || opcao3!="4" || opcao3!="5" || opcao3!="6"){
                throw std::invalid_argument ("Opção inexistente, digite novamente!\n");
            }
            } catch(std::invalid_argument& e){
                while(opcao3!="1" && opcao3!="2" && opcao3!="3" && opcao3!="4" && opcao3!="5" && opcao3!="6"){
                    std::cin.clear();
                    std::cerr << e.what();
                    std::cin >> opcao3;
                }
            } 
            //operacao de adicionar o estoque
            if(opcao3 == "1"){
                _gerente[aux]->adicionar_estoque();
            }
            //operacao de alterar o estoque
            if(opcao3 == "2"){
                _gerente[aux]->alterar_estoque();
            }
            //operacao de visualizar o estoque
            if(opcao3 == "3"){
                _gerente[aux]->visualizar_estoque();
            }
            //operacao de editar dados pessoais
            if(opcao3 == "4"){
                _gerente[aux]->editar_dados(_gerente, aux);
            }
            //operacao de visualizar dados pessoais
            if(opcao3 == "5"){
                _gerente[aux]->visualizar_dados(_gerente, aux);
            }
            //encerrar sessão
            if(opcao3 == "6"){
                std::cout << std::endl;
                goto inicio;
            }
        }
    }
    else if(opcao1=="3"){ //área de acesso do aplicador
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
            bool existe=false;
            for(int i=0;i<_aplicador.size();i++){
                if(login==_aplicador[i]->get_login()){
                    existe=true;
                    aux1=i;
                    break;
                }
            }
            if(!existe){ //se não existir, realiza o cadastro
                std::cout << "Usuário inexistente, realize cadastro\n";
                opcao2=2;
            }
            //se o login existir verifica se a senha digitada corresponde
            if(existe){
                std::cout << "Digite sua senha: ";
                std::cin >> senha;
                while(senha!=_aplicador[aux1]->get_senha()){
                    std::cout << "Senha incorreta, digite novamente\n";
                    std::cin >> senha;
                }
            }
            std::cout << "------------------------------------- " << std::endl;
        }
        if(opcao2=="2"){ //realiza o cadastro
            //leitura dos dados e tratamento de excessão
            std::cout << "\n--------------- Cadastro --------------- " << std::endl;
            std::cout << "Digite o nome de usuário desejado: ";
            //booleanos para o tratamento de exceção
            bool valido=true;
            bool validonome=true;
            bool validotel=true;
            bool validocpf=true;
            bool validoemail=false;
            bool validocoren=true;
            bool validodata=true;
            try{ //verifica se é válido
                std::cin >> login;
                //verifica se o login já está em uso
                for(int i=0;i<_aplicador.size();i++){
                    if(login==_aplicador[i]->get_login()){
                        valido=false;
                        throw std::invalid_argument("Login já existente, escolha outro\n");
                    }
                }
                //verifica se possui algum caracter especial
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
                //verifica se a senha possui o tamanho mínimo
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
                std::cin.ignore();
                getline(std::cin,nome);
                //verifica se o nome só possui letras
                for(int i=0;i<nome.length();i++){
                    if(!isalpha(nome[i]) && !isspace(nome[i])){
                        validonome=false;
                        throw std::invalid_argument ("O nome só pode conter letras, digite novamente\n");
                    }
                }
            } catch(std::invalid_argument& e){
                while(!validonome){
                    std::cerr << e.what();
                    std::cin >> nome;
                    for(int i=0;i<nome.length();i++){
                        if(!isalpha(nome[i]) && !isspace(nome[i])){
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
                //verifica se o tamanho está correto
                if(telefone.length()<10){
                    validotel=false;
                    throw std::invalid_argument ("O telefone tem no mínimo 10 dígitos e só pode conter números, digite novamente\n");
                }
                //verifica se só possui números
                for(int i=0;i<telefone.length();i++){
                    if(isalpha(telefone[i])){
                        validotel=false;
                        throw std::invalid_argument ("O telefone tem no mínimo 10 dígitos e só pode conter números, digite novamente\n");
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
                //verifica se já está cadastrado
                for(int i=0;i<_aplicador.size();i++){
                    if(cpf==_aplicador[i]->get_cpf()){
                        validocpf=false;
                        throw std::invalid_argument("Cpf já cadastrado\n");
                    }
                }
                //verifica se tem o tamanho correto
                if(cpf.length()<11){
                    validocpf=false;
                    throw std::invalid_argument ("Digite um cpf válido\n");
                }
                //verifica se possui letras
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
            //strings auxiliares para tratamento de exceção da data
            std::string d,m,a;
            t:
            try{
                std::cout << "Digite a data de nascimento no formato dd/mm/aaaa: ";
                std::cin >> data_nascimento;
                //verifica se a data está no formato especificado
                if(data_nascimento.length()!=10){
                    validodata=false;
                    throw std::invalid_argument("Digite a data de nascimento no formato especificado\n");
                }
                //verifica se não foi digitada alguma letra
                if(!isdigit(data_nascimento[0]) || !isdigit(data_nascimento[1]) || isalnum(data_nascimento[2]) || !isdigit(data_nascimento[3]) || !isdigit(data_nascimento[4]) || isalnum(data_nascimento[5]) || !isdigit(data_nascimento[6]) || !isdigit(data_nascimento[7]) || !isdigit(data_nascimento[8]) || !isdigit(data_nascimento[9])){
                    validodata=false;
                    throw std::invalid_argument("Digite a data no formato especificado.\n");
                }
                d[0]=data_nascimento[0]; d[1]=data_nascimento[1];
                m[0]=data_nascimento[3]; m[1]=data_nascimento[4];
                a[0]=data_nascimento[6]; a[1]=data_nascimento[7]; a[2]=data_nascimento[8]; a[3]=data_nascimento[9];
                //verifica se o dia é válido
                if(stoi(d)<=0){
                    validodata=false;
                    throw std::invalid_argument("Dia inválido, digite novamente\n");
                }
                //verifica se o mês é válido
                if(stoi(m)>12 || stoi(m)<0){
                    validodata=false;
                    throw std::invalid_argument("Mês inválido, digite novamente\n");
                }
                //verifica se a data existe de acordo com a quantidade de dias do mês digitado
                if((stoi(m)==1 || stoi(m)==3 || stoi(m)==5 || stoi(m)==7 || stoi(m)==8 || stoi(m)==10 || stoi(m)==12) && stoi(d)>31){
                    validodata=false;
                    throw std::invalid_argument("Data inexistente, digite novamente\n");
                }
                else if((stoi(m)==4 || stoi(m)==6 || stoi(m)==9 || stoi(m)==11) && stoi(d)>31){
                    validodata=false;
                    throw std::invalid_argument("Data inexistente, digite novamente\n");
                }
                else if(stoi(m)==2 && stoi(d)>28){
                    validodata=false;
                    throw std::invalid_argument("Data inexistente, digite novamente\n");
                }
                //verifica se o ano é válido
                else if(stoi(a)>2023 || stoi(a)<1907){
                    validodata=false;
                    throw std::invalid_argument("Ano inválido, digite novamente\n");
                }
                validodata=true;
            } catch(std::invalid_argument& e){
                std::cerr << e.what();
                if(!validodata){
                    goto t;
                }
            } 
            std::cout << "Digite seu número do coren: ";
            try { //verifica se o valor digitado é válido
                std::cin >> coren;
                //verifica se já está cadastrado
                for(int i=0;i<_aplicador.size();i++){
                    if(coren==_aplicador[i]->get_coren()){
                        validocoren=false;
                        throw std::invalid_argument("Coren já cadastrado\n");
                    }
                }
                //verifica só contem números
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
            std::cout << "---------------------------------------- " << std::endl;
            //construtor de aplicador
            _aplicador.push_back(new Aplicador(login,senha,nome,telefone,email,cpf,data_nascimento,coren));
            //guarda o indice do aplicador que está acessando o sistema para uso nas funções
            for(int i=0; i<_aplicador.size(); i++){
                if(_aplicador[i]->get_login() == login){
                    aux = i;
                    break;
                }
            }
        }

        while(true){
            // operações do aplicador
            std::cout << "\nQual operação deseja realizar?\n";
            std::cout << "(1) Registrar vacina aplicada\n(2) Verificar data de retorno do paciente\n(3) Visualizar dados\n(4) Modificar dados\n(5) Encerrar Sessão\n";
            //tratamento de exceção das opções digitadas
            try{ 
                std::cin >> opcao3;
                if(opcao3!="1" || opcao3!="2" || opcao3!="3" || opcao3!="4" || opcao3!="5"){
                    throw std::invalid_argument ("Opção inexistente, digite novamente!\n");
                }
            } catch(std::invalid_argument &e){
                while(opcao3!="1" && opcao3!="2" && opcao3!="3" && opcao3!="4" && opcao3!="5"){
                    std::cerr << e.what();
                    std::cin >> opcao3;
                }
            }

            if(opcao3!="5"){ // agrupa as funções que exigem identificação do aplicador
                for(int i=0;i<_aplicador.size();i++){ 
                    if(login==_aplicador[i]->get_login()){ // confere se o login do usuário é igual ao login de um aplicador
                        aux = i; // identifica o aplicador
                        break;
                    }
                }
                if(opcao3 == "1" || opcao3 == "2"){ // agrupa as funções que exigem identificação do paciente
                    digitar_cns_do_paciente:
                    bool existe=false;
                    std::cout << "Digite o número do CNS do paciente: ";
                    std::cin >> cns;
                    for(int i=0;i<_paciente.size();i++){ 
                        if(cns==_paciente[i]->get_cns()){ // confere se o cns digitado é igual a um cns registrado no sistema
                            aux1 = i;
                            existe=true;
                            break;
                        }
                    }
                    //tratamento de exceção caso o cns digitado não exista
                    if(!existe){
                        std::cout << "CNS não cadastrado no sistema, deseja (1) tentar novamente ou (2) encerrar a sessão?" << std::endl;
                        try{ 
                            std::cin >> opcao3;
                            if(opcao3!="1" || opcao3!="2"){
                                throw std::invalid_argument ("Opção inexistente, digite novamente!\n");
                            }
                        } catch(std::invalid_argument &er){
                            while(opcao3!="1" && opcao3!="2"){
                                std::cerr << er.what();
                                std::cin >> opcao3;
                            }
                        }
                        if(opcao3=="1")
                            goto digitar_cns_do_paciente; // volta ao cin >> cns
                        if(opcao3=="2")
                            std::cout << std::endl;
                            goto inicio;
                    }
                    if(opcao3=="1"){
                        _aplicador[aux] -> registrar_vacina(cns, _gerente); // registrar vacina que foi aplicada num paciente
                    }
                    if(opcao3=="2"){
                        _aplicador[aux] -> verificar_retorno(cns); // verifica as datas em que o paciente deve retornar, caso existam
                    }
                }
                if(opcao3=="3")
                    _aplicador[aux] -> visualizar_dados(_aplicador,aux); // aplicador visualiza dados pessoais
                if(opcao3=="4")
                    _aplicador[aux] -> editar_dados(_aplicador,aux); // aplicador edita dados pessoais
            }
            //retorna ao menu inicial
            else{
                std::cout << std::endl;
                goto inicio;
            }
        } 
    }
    //encerra a execução do programa
    else if(opcao1=="4"){
        exit(0);
    }
    std::cout << "------------------------------------- " << std::endl;
    //destrutor dos vectors
    _paciente.clear();
    _gerente.clear();
    _aplicador.clear();
}