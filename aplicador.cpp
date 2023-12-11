#include "aplicador.h"
#include "gerente.h"
#include "vacina.h"
#include <iostream>
#include <cctype>

Aplicador::Aplicador(std::string login, std::string senha, std::string nome, std::string telefone, std::string email, std::string cpf, std::string data_nascimento, std::string coren):
    Usuario(login,senha,nome,telefone,email,cpf,data_nascimento), _coren(coren){}

std::string Aplicador::get_coren(){
    return _coren;
}

void Aplicador::set_coren(std::string coren){
    _coren = coren;
}

void Aplicador::registrar_vacina(std::string cns, std::vector <Gerente*> _gerente){ // recebe o cns do paciente atendido e o vector gerente da main 
    std::string numvac, nome_vacina, lote, data_vacina, dose, opcao1, data_retorno, fabricante, tipo_vacina;
    bool valido_data_vacina, opcao_retorno, valido_data_retorno, lote_valido = false;
    int aux; //indice do gerente
    std::cout << "\nQual o nome da vacina aplicada?" << std::endl;
    std::cout << "(1) Coronavac\n(2) Astrazeneca\n(3) Pfizer\n(4) Janssen\n";
    try{ 
        std::cin >> numvac;
        if(numvac!="1" || numvac!="2" || numvac!="3" || numvac!="4"){
            throw std::invalid_argument ("Opção inexistente, digite novamente.\n");
        }
    } catch(std::invalid_argument& e){
        while(numvac!="1" && numvac!="2" && numvac!="3" && numvac!="4"){
            std::cerr << e.what();
            std::cin >> numvac;
        }
    }
    if(numvac == "1"){ // através das opções, grava o nome da vacina para que ele possa ser conferido entre as vacinas registradas na classe gerente
        nome_vacina = "Coronavac"; 
        fabricante = "Instituto Butantan";
        tipo_vacina = "Vírus inativado";
    }
    if(numvac == "2"){
        nome_vacina = "Astrazeneca";
        fabricante = "Astrazeneca";
        tipo_vacina = "Vetor viral";
    }
    if(numvac == "3"){
        nome_vacina = "Pfizer";
        fabricante = "Pfizer";
        tipo_vacina = "RNA mensageiro";
    }
    if(numvac == "4"){
        nome_vacina = "Janssen";
        fabricante = "Janssen Farmacêutica";
        tipo_vacina = "Vetor viral";
    }
    std::cout << "Qual o lote da vacina? ";
    try{
        std::cin >> lote;
        for(int i=0; i<_gerente.size(); i++){
            if(_gerente[i]->verificar_lote(nome_vacina,lote) == true){
                lote_valido = true;
                break;
            }
        }
        if(lote_valido == false)
            throw std::invalid_argument ("Lote da vacina digitado não corresponde a um lote existente, digite novamente.\n");
    } catch(std::invalid_argument &e){
        for(int i=0; i<_gerente.size(); i++){
            if(_gerente[i]->verificar_lote(nome_vacina,lote) == true){
                lote_valido = true;
                break;
            }
        }
        while(lote_valido == false){
            std::cerr << e.what();
            std::cin >> lote;
        }
    }
    cin_data_vacina:
    try{
        std::string d,m,a;
        std::cout << "Digite a data de aplicação da vacina no formato dd/mm/aaaa: ";
        std::cin >> data_vacina;
        if(data_vacina.length()!=10){
            valido_data_vacina=false;
            throw std::invalid_argument("Digite a data no formato especificado.\n");
        }
        d[0]=data_vacina[0]; d[1]=data_vacina[1];
        m[0]=data_vacina[3]; m[1]=data_vacina[4];
        a[0]=data_vacina[6]; a[1]=data_vacina[7]; a[2]=data_vacina[8]; a[3]=data_vacina[9];
        if(stoi(d)<=0){
            valido_data_vacina=false;
            throw std::invalid_argument("Dia inválido, digite novamente.\n");
        }
        if(stoi(m)>12 || stoi(m)<0){
            valido_data_vacina=false;
            throw std::invalid_argument("Mês inválido, digite novamente.\n");
        }
        if((stoi(m)==1 || stoi(m)==3 || stoi(m)==5 || stoi(m)==7 || stoi(m)==8 || stoi(m)==10 || stoi(m)==12) && stoi(d)>31){
            valido_data_vacina=false;
            throw std::invalid_argument("Data inexistente, digite novamente.\n");
        }
        else if((stoi(m)==4 || stoi(m)==6 || stoi(m)==9 || stoi(m)==11) && stoi(d)>31){
            valido_data_vacina=false;
            throw std::invalid_argument("Data inexistente, digite novamente.\n");
        }
        else if(stoi(m)==2 && stoi(d)>28){
            valido_data_vacina=false;
            throw std::invalid_argument("Data inexistente, digite novamente.\n");
        }
        else if(stoi(a)!=2023){
            valido_data_vacina=false;
            throw std::invalid_argument("Ano inválido, digite novamente.\n");
        }
        valido_data_vacina=true;
    } catch(std::invalid_argument &f){
        std::cerr << f.what();
        if(!valido_data_vacina){
            goto cin_data_vacina;
        }
    } 
    std::cout << "Qual a dose da vacina? ";
    try{ 
        std::cin >> dose;
        if(dose!="1" || dose!="2" || dose!="3" || dose!="4" || dose!="5"){ // número máximo de doses é 5
            throw std::invalid_argument ("Opção inválida, digite novamente.\n");
        }
    } catch(std::invalid_argument &g){
        while(dose!="1" && dose!="2" && dose!="3" && dose!="4" && dose!="5"){
            std::cerr << g.what();
            std::cin >> dose;
        }
    }
    std::cout << "Há necessidade de retorno para essa vacina?\n";
    std::cout << "(1) Sim (2) Não\n";
    try{ 
        std::cin >> opcao1;
        if(opcao1!="1" || opcao1!="2"){
            throw std::invalid_argument ("Opção inválida, digite novamente.\n");
        }
    } catch(std::invalid_argument &h){
        while(opcao1!="1" && opcao1!="2"){
            std::cerr << h.what();
            std::cin >> opcao1;
        }
    }
    if(opcao1=="1")
        opcao_retorno = true;
    if(opcao1=="2")
        opcao_retorno = false;
    if(opcao_retorno){
        std::cout << "Qual a data de retorno? ";
        cin_data_retorno:
        try{
            std::string dia,mes,ano;
            std::cout << "Digite a data de retorno no formato dd/mm/aaaa: ";
            std::cin >> data_retorno;
            if(data_retorno.length()!=10){
                valido_data_retorno=false;
                throw std::invalid_argument("Digite a data no formato especificado.\n");
            }
            dia[0]=data_retorno[0]; dia[1]=data_retorno[1];
            mes[0]=data_retorno[3]; mes[1]=data_retorno[4];
            ano[0]=data_retorno[6]; ano[1]=data_retorno[7]; ano[2]=data_retorno[8]; ano[3]=data_retorno[9];
            if(stoi(dia)<=0){
                valido_data_retorno=false;
                throw std::invalid_argument("Dia inválido, digite novamente.\n");
            }
            if(stoi(mes)>12 || stoi(mes)<0){
                valido_data_retorno=false;
                throw std::invalid_argument("Mês inválido, digite novamente.\n");
            }
            if((stoi(mes)==1 || stoi(mes)==3 || stoi(mes)==5 || stoi(mes)==7 || stoi(mes)==8 || stoi(mes)==10 || stoi(mes)==12) && stoi(dia)>31){
                valido_data_retorno=false;
                throw std::invalid_argument("Data inexistente, digite novamente.\n");
            }
            else if((stoi(mes)==4 || stoi(mes)==6 || stoi(mes)==9 || stoi(mes)==11) && stoi(dia)>31){
                valido_data_retorno=false;
                throw std::invalid_argument("Data inexistente, digite novamente.\n");
            }
            else if(stoi(mes)==2 && stoi(dia)>28){
                valido_data_retorno=false;
                throw std::invalid_argument("Data inexistente, digite novamente.\n");
            }
            else if(stoi(ano)<2023){
                valido_data_retorno=false;
                throw std::invalid_argument("Ano inválido, digite novamente.\n");
            }
            valido_data_retorno=true;
        } catch(std::invalid_argument &k){
            std::cerr << k.what();
            if(!valido_data_retorno){
                goto cin_data_retorno;
            }
        }
    }
    _historico.push_back(new Historico(nome_vacina,cns,_coren,data_vacina,dose,opcao_retorno,data_retorno,fabricante,lote,tipo_vacina));
}

void Aplicador::verificar_retorno(std::string cns){
    int cont = 0; // contador de datas de retorno, se não houver nenhuma, vale 0 
    std::vector <std::string> datas;
    for(int i=0; i<_historico.size(); i++){
        if(cns==_historico[i]->get_cns()){
            if(_historico[i]->get_retorno()){ // se houver necessidade de retorno 
                datas.push_back(_historico[i]->get_data_retorno());
                cont++;
            }
        }
    } // não é possível dar break, porque um paciente pode ter mais que um historico

    if(cont!=0){
        std::cout << "A(s) data(s) de retorno do paciente são: ";
        for(int i=0; i<datas.size(); i++){
            std::cout << datas[i] << " ";
        }
        std::cout << std::endl;
    }
    else
        std::cout << "Nenhuma vacina do paciente exige seu retorno.\n";
}

void Aplicador::visualizar_dados(std::vector <Aplicador*> apli, int aux){
    std::cout << "\n--------------- Dados Pessoais --------------- " << std::endl;
    std::cout << "Login: " << apli[aux]->get_login() << std::endl;
    std::cout << "Nome: " << apli[aux]->get_nome() << std::endl;
    std::cout << "Telefone: " << apli[aux]->get_telefone() << std::endl;
    std::cout << "E-mail: " << apli[aux]->get_email() << std::endl;
    std::cout << "CPF: " << apli[aux]->get_cpf() << std::endl;
    std::cout << "Data de nascimento: " << apli[aux]->get_data_nascimento() << std::endl;
    std::cout << "Cadastro no Coren (Conselho Regional de Enfermagem): " << apli[aux]->get_coren() << std::endl;
    std::cout << "\n---------------------------------------------- " << std::endl;
}

void Aplicador::editar_dados(std::vector <Aplicador*> apli, int aux){
    std::string opcao1;
    std::cout << "\nEscolha o dado que deseja editar:\n";
    std::cout << "(1) Login\n(2) Senha\n(3) Nome\n(4) Telefone\n(5) Email\n(6) Data de nascimento\n";
    try{ //tratamento de exceção caso a opção seja inválida
        std::cin >> opcao1;
        if(opcao1!="1" || opcao1!="2" || opcao1!="3" || opcao1!="4" || opcao1!="5" || opcao1!="6"){
            throw std::invalid_argument ("Opção inexistente, digite novamente!\n");
        }
    } catch(std::invalid_argument& e){
        while(opcao1!="1" && opcao1!="2" && opcao1!="3" && opcao1!="4" && opcao1!="5" && opcao1!="6"){
            std::cerr << e.what();
            std::cin >> opcao1;
        }
    }
    //alterar login
    if(opcao1 == "1"){
        bool valido = true;
        std::string login;
        std::cout << "Digite o novo login desejado: ";
        try{ //verifica se é válido
            std::cin >> login;
            for(int i=0;i<login.length();i++){
                if(ispunct(login[i])){
                    valido=false;
                    throw std::invalid_argument ("O login só pode conter letras e números, digite novamente\n");
                }
            }
            for(int i=0;i<apli.size();i++){
                if(login==apli[i]->get_login()){
                    valido=false;
                    throw std::invalid_argument ("Login já existente\n");
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
        if(valido==true){ //chama a função do usuário para mudar o login
            apli[aux]->set_login(login);
            std::cout << "\nLogin modificado com sucesso.\n";
        }
    }
    if(opcao1 == "2"){
        std::string senha;
        std::cout << "\nDigite a nova senha desejada: ";
        try{ //verifica se é válida
                std::cin >> senha;
                if(senha.length()<8){
                    throw std::invalid_argument("A senha deve ter no mínimo 8 caracteres\n");
                }
            } catch(std::invalid_argument& e){
                while(senha.length()<8){
                    std::cerr << e.what();
                    std::cin >> senha;
                }
            }
        apli[aux]->set_senha(senha);//chama a função do usuário para mudar a senha
        std::cout << "Senha modificada com sucesso.\n";
    }
    //modificar nome
    if(opcao1 == "3"){
    std::string nome;
    bool valido = true;
        std::cout << "Digite o novo nome desejado: ";
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
            apli[aux]->set_nome(nome);
            std::cout << "Nome modificado com sucesso.\n";
        }
    }
    //modificar telefone
    if(opcao1=="4"){
    std::string telefone;
    bool valido = true;
        std::cout << "Digite o novo número de telefone desejado: ";
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
                apli[aux]->set_telefone(telefone);
                std::cout << "Número de telefone modificado com sucesso.\n";
            }
    }
    //modificar o email
    if(opcao1=="5"){
    std::string email;
    bool valido = true;
        std::cout << "Digite o novo e-mail desejado: ";
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
                apli[aux]->set_email(email);
                std::cout << "E-mail modificado com sucesso.\n";
            }
    }

    //modificar data de nascimento
    if(opcao1=="6"){
        std::string data_nascimento;
        bool valido = true;
        std::string d,m,a;
            s:
            try{
                std::cout << "Digite a nova data de nascimento no formato dd/mm/aaaa: ";
                std::cin >> data_nascimento;
                if(data_nascimento.length()!=10){
                    valido=false;
                    throw std::invalid_argument("Digite a data de nascimento no formato especificado\n");
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
                apli[aux]->set_data_nascimento(data_nascimento);
                std::cout << "Data de nascimento modificada com sucesso.\n";
            }

    }
}

void Aplicador::visualizar_historico(std::string cns){
    for(int i=0; i<_historico.size(); i++){
        std::cout << "\n--------------- Cartão de Vacinas --------------- " << std::endl;
        if(cns==_historico[i]->get_cns()){
            std::cout << "Coren: " << _historico[i]->get_coren() << std::endl;
            std::cout << "Nome da vacina: " << _historico[i]->get_nome_vacina() << std::endl;
            std::cout << "Tipo da vacina: " << _historico[i]->get_tipo_vacina() << std::endl;
            std::cout << "Data: " << _historico[i]->get_data() << std::endl;
            std::cout << "Dose: " << _historico[i]->get_dose() << std::endl;
            if(_historico[i]->get_retorno())
                std::cout << "Data de retorno: " << _historico[i]->get_data_retorno() << std::endl;
            std::cout << "Fabricante: " << _historico[i]->get_fabricante() << std::endl;
            std::cout << "Lote: " << _historico[i]->get_lote() << std::endl;
            std::cout << "------------------------------------------------- " << std::endl;
        }
    }
}

//destrutor
Aplicador::~Aplicador(){
    _historico.clear();
}