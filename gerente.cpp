#include <iostream>
#include <string>
#include <exception>
#include "gerente.h"
#include "usuario.h"

//variaveis genericas
std::string opcao1;
bool existe = false;

//dados do estoque
std::string nome, validade, data_recebimento, lote;
int quantidade, aux;

//dados especificos de vacina
std::string fabricante, tipo;

Gerente::Gerente(std::string login, std::string senha, std::string nome, std::string telefone, std::string email,
                std::string cpf, std::string  data_nascimento) :
    Usuario(login,senha,nome,telefone,email,cpf, data_nascimento), vacina(_vacina) {}

//funcao que adiciona um novo estoque
void Gerente::adicionar_estoque(){
    std::cout << "\nQual o tipo de produto do estoque?\n";
    std::cout << "(1) Material\n(2) Vacina\n";
    try{ //tratamento de exceção caso a opção seja inválida
        std::cin >> opcao1;
        if(opcao1!="1" || opcao1!="2"){
            throw std::invalid_argument ("Opção inexistente, digite novamente!\n");
        }
    } catch(std::invalid_argument& e){
        while(opcao1!="1" && opcao1!="2"){
            std::cerr << e.what();
            std::cin >> opcao1;
        }
    }
    //adicionar material
    if(opcao1 == "1"){
        //leitura dos dados do material
        int i=0;
        //nome do material
        std::cout << "\nDigite o nome do material: ";
        std::cin.ignore();
        getline(std::cin,nome);
        //data de validade
        i=0;
        bool validodata = true;
        std::string d,m,a;
        teste1:
        //tratamento de excecao para data de validade
        try{
            std::cout << "Digite a data de validade no formato dd/mm/aaaa: ";
            std::cin >> validade;
            if(validade.length()!=10){
                validodata=false;
                throw std::invalid_argument("Digite a data de validade no formato especificado\n");
            }
            d[0]=validade[0]; d[1]=validade[1];
            m[0]=validade[3]; m[1]=validade[4];
            a[0]=validade[6]; a[1]=validade[7]; a[2]=validade[8]; a[3]=validade[9];
            if(stoi(d)<=0){
                validodata=false;
                throw std::invalid_argument("Dia inválido, digite novamente\n");
            }
            if(stoi(m)>12 || stoi(m)<0){
                validodata=false;
                throw std::invalid_argument("Mês inválido, digite novamente\n");
            }
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
            else if(stoi(a)<2023){
                validodata=false;
                throw std::invalid_argument("Ano inválido, digite novamente\n");
            }
            validodata=true;
        }catch(std::invalid_argument& e){
            std::cerr << e.what();
            if(!validodata){
                goto teste1;
            }
        } 
        //data de recebimento
        i=0;
        validodata = true;
        d = " ";
        m = " ";
        a = " ";
        teste2:
        //tratamento de excecao para data de recebimento
        try{
            std::cout << "Digite a data de recebimento no formato dd/mm/aaaa: ";
            std::cin >> data_recebimento;
            if(data_recebimento.length()!=10){
                validodata=false;
                throw std::invalid_argument("Digite a data de recebimento no formato especificado\n");
            }
            d[0]=data_recebimento[0]; d[1]=data_recebimento[1];
            m[0]=data_recebimento[3]; m[1]=data_recebimento[4];
            a[0]=data_recebimento[6]; a[1]=data_recebimento[7]; a[2]=data_recebimento[8]; a[3]=data_recebimento[9];
            if(stoi(d)<=0){
                validodata=false;
                throw std::invalid_argument("Dia inválido, digite novamente\n");
            }
            if(stoi(m)>12 || stoi(m)<0){
                validodata=false;
                throw std::invalid_argument("Mês inválido, digite novamente\n");
            }
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
            else if(stoi(a)>2023 || stoi(a)<1907){
                validodata=false;
                throw std::invalid_argument("Ano inválido, digite novamente\n");
            }
            validodata=true;
        }catch(std::invalid_argument& e){
            std::cerr << e.what();
            if(!validodata){
                goto teste2;
            }
        } 
        //lote do material
        std::cout << "Digite o lote do material: ";
        std::cin >> lote;
        //quantidade do material
        std::cout << "Digite a quantidade do material: ";
        bool invalida = false;
        std::string q;
        try{ //tratamento de exceção caso a quantidade seja inválida
            invalida = false;
            std::cin >> q;
            for(int i=0; i<q.size(); i++){
                //não pode ser letra e nem digito especial
                if(((q[i] >= 'a' && q[i] <= 'z') || (q[i] >= 'A' && q[i] <= 'Z')) || !(q[i] >= '0' && q[i] <= '9')){
                    invalida = true;
                    break;
                }
            }
            if(invalida){
                throw std::invalid_argument ("Quantidade invalida, digite novamente!\n");
            }
            if(!invalida){
                quantidade = (stoi(q));
            }
        } catch(std::invalid_argument& e){
            while(invalida || quantidade < 1){
                std::cerr << e.what();
                invalida = false;
                std::cin >> q;
                for(int i=0; i<q.size(); i++){
                    //não pode ser letra e nem digito especial
                    if(((q[i] >= 'a' && q[i] <= 'z') || (q[i] >= 'A' && q[i] <= 'Z')) || !(q[i] >= '0' && q[i] <= '9')){
                        invalida = true;
                        break;
                    }
                }
                if(!invalida){
                    quantidade = (stoi(q));
                }
            }
        }
        //construtor de estoque
        _estoque.push_back(new Estoque(nome, quantidade, validade, data_recebimento, lote));
    }
    //adicionar vacina
    if(opcao1 == "2"){
        //leitura dos dados da vacina
        int i=0;
        //nome da vacina
        std::cout << "\nDigite o nome da vacina: ";
        try{
            std::cin >> nome;
            if(nome!= "Coronavac" || nome!= "Astrazeneca" || nome!= "Pfizer" || nome!= "Janssen"){
                throw std::invalid_argument("\nNome de vacina inválido! Digite novamente: ");
            }
        }catch(std::invalid_argument& e){
            while(nome!= "Coronavac" && nome!= "Astrazeneca" && nome!= "Pfizer" && nome!= "Janssen"){
                std::cerr << e.what();
                std::cin >> nome;
            }
        }
        //data de validade
        bool validodata = true;
        std::string d,m,a;
        teste3:
        //tratamento de excecao para data de validade
        try{
            std::cout << "Digite a data de validade no formato dd/mm/aaaa: ";
            std::cin >> validade;
            if(validade.length()!=10){
                validodata=false;
                throw std::invalid_argument("Digite a data de recebimento no formato especificado\n");
            }
            d[0]=validade[0]; d[1]=validade[1];
            m[0]=validade[3]; m[1]=validade[4];
            a[0]=validade[6]; a[1]=validade[7]; a[2]=validade[8]; a[3]=validade[9];
            if(stoi(d)<=0){
                validodata=false;
                throw std::invalid_argument("Dia inválido, digite novamente\n");
            }
            if(stoi(m)>12 || stoi(m)<0){
                validodata=false;
                throw std::invalid_argument("Mês inválido, digite novamente\n");
            }
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
            else if(stoi(a)<2023){
                validodata=false;
                throw std::invalid_argument("Ano inválido, digite novamente\n");
            }
            validodata=true;
        }catch(std::invalid_argument& e){
            std::cerr << e.what();
            if(!validodata){
                goto teste3;
            }
        } 
        //data de recebimento
        i=0;
        validodata = true;
        d = " ";
        m = " ";
        a = " ";
        teste4:
        //tratamento de excecao para data de recebimento
        try{
            std::cout << "Digite a data de recebimento no formato dd/mm/aaaa: ";
            std::cin >> data_recebimento;
            if(data_recebimento.length()!=10){
                validodata=false;
                throw std::invalid_argument("Digite a data de recebimento no formato especificado\n");
            }
            d[0]=data_recebimento[0]; d[1]=data_recebimento[1];
            m[0]=data_recebimento[3]; m[1]=data_recebimento[4];
            a[0]=data_recebimento[6]; a[1]=data_recebimento[7]; a[2]=data_recebimento[8]; a[3]=data_recebimento[9];
            if(stoi(d)<=0){
                validodata=false;
                throw std::invalid_argument("Dia inválido, digite novamente\n");
            }
            if(stoi(m)>12 || stoi(m)<0){
                validodata=false;
                throw std::invalid_argument("Mês inválido, digite novamente\n");
            }
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
            else if(stoi(a)>2023 || stoi(a)<1907){
                validodata=false;
                throw std::invalid_argument("Ano inválido, digite novamente\n");
            }
            validodata=true;
        }catch(std::invalid_argument& e){
            std::cerr << e.what();
            if(!validodata){
                goto teste4;
            }
        } 
        //lote da vacina
        std::cout << "Digite o lote da vacina: ";
        std::cin >> lote;
        //quantidade da vacina
        quantidade = 0;
        std::cout << "Digite a quantidade da vacina: ";
        bool invalida = false;
        std::string q;
        try{ //tratamento de exceção caso a quantidade seja inválida
            invalida = false;
            std::cin >> q;
            for(int i=0; i<q.size(); i++){
            //não pode ser letra e nem digito especial
                if(((q[i] >= 'a' && q[i] <= 'z') || (q[i] >= 'A' && q[i] <= 'Z')) || !(q[i] >= '0' && q[i] <= '9')){
                    invalida = true;
                    break;
                }
            }
            if(invalida){
                throw std::invalid_argument ("Quantidade invalida, digite novamente!\n");
            }
            if(!invalida){
                quantidade = (stoi(q));
            }
        } catch(std::invalid_argument& e){
            while(invalida || quantidade < 1){
                std::cerr << e.what();
                invalida = false;
                std::cin >> q;
                for(int i=0; i<q.size(); i++){
                    if(((q[i] >= 'a' && q[i] <= 'z') || (q[i] >= 'A' && q[i] <= 'Z')) || !(q[i] >= '0' && q[i] <= '9')){
                        invalida = true;
                    }
                }
                if(!invalida){
                    quantidade = (stoi(q));
                }
            }
        }
        //fabricante
        std::cout << "Digite o nome do fabricante: ";
        std::cin.ignore();
        getline(std::cin,fabricante);
        //tipo
        std::cout << "Digite o tipo da vacina: ";
        std::cin >> tipo;
        
        //construtor de estoque
        _vacina.push_back(new Vacina(fabricante, tipo, nome, quantidade, validade, data_recebimento, lote));
    }
}

void Gerente::visualizar_estoque(){
    std::cout << "\nQual o tipo de produto do estoque?\n";
    std::cout << "(1) Material\n(2) Vacina\n";
    try{ //tratamento de exceção caso a opção seja inválida
        std::cin >> opcao1;
        if(opcao1!="1" || opcao1!="2"){
            throw std::invalid_argument ("Opção inexistente, digite novamente!\n");
        }
    } catch(std::invalid_argument& e){
        while(opcao1!="1" && opcao1!="2"){
            std::cerr << e.what();
            std::cin >> opcao1;
        }
    }
    if(opcao1 == "1"){
        std::cout << "\n--------------- Materiais --------------- " << std::endl;
        for(int i=0; i<_estoque.size(); i++){
            std::cout << "Tipo: " << _estoque[i]->get_nome();
            std::cout << "\nQuantidade: " << _estoque[i]->get_quantidade();
            std::cout << "\nValidade: " << _estoque[i]->get_validade();
            std::cout << "\nData de recebimento: " << _estoque[i]->get_data_recebimento();
            std::cout << "\nLote: " << _estoque[i]->get_lote();
            std::cout << "\n----------------------------------------- " << std::endl;
        }
    }
    if(opcao1 == "2"){
        std::cout << "\n--------------- Vacinas --------------- " << std::endl;
        for(int i=0; i<_vacina.size(); i++){
            std::cout << "Nome: " << _vacina[i]->get_nome();
            std::cout << "\nQuantidade: " << _vacina[i]->get_quantidade();
            std::cout << "\nValidade: " << _vacina[i]->get_validade();
            std::cout << "\nData de recebimento: " << _vacina[i]->get_data_recebimento();
            std::cout << "\nLote: " << _vacina[i]->get_lote();
            std::cout << "\nFabricante: " << _vacina[i]->get_fabricante();
            std::cout << "\nTipo: " << _vacina[i]->get_tipo();
            std::cout << "\n----------------------------------------- " << std::endl;
        }
    }
}


void Gerente::alterar_estoque(){
    std::cout << "\nQual o tipo de produto do estoque? \n";
    std::cout << "(1) Material\n(2) Vacina\n";
    try{ //tratamento de exceção caso a opção seja inválida
        std::cin >> opcao1;
        if(opcao1!="1" || opcao1!="2"){
            throw std::invalid_argument ("Opção inexistente, digite novamente!\n");
        }
    } catch(std::invalid_argument& e){
        while(opcao1!="1" && opcao1!="2"){
            std::cerr << e.what();
            std::cin >> opcao1;
        }
    }
    //alterar dados de materiais
    if(opcao1 == "1"){
        existe = false;
        std::cout << "\nDigite o lote do material que deseja alterar: ";
        //verificacao do lote
        try{
            std::cin >> lote;
            for(int i=0; i<_estoque.size(); i++){
                if(lote == _estoque[i]->get_lote()){
                    existe = true;
                    break;
                }
            }
            if(!existe){
                throw std::invalid_argument ("Lote invalido! Digite novamente: ");
            }
        }catch(std::invalid_argument& e){
            while(!existe){
                std::cerr << e.what();
                std::cin >> lote;
                for(int i=0; i<_estoque.size(); i++){
                    if(lote == _estoque[i]->get_lote()){
                        existe = true;
                        break;
                    }
                }  
            }
        }
         //area de alteracao
        std::cout << "\nNova quantidade: ";
        bool invalida = false;
        std::string q;
        try{ //tratamento de exceção caso a quantidade seja inválida
            invalida = false;
            std::cin >> q;
            for(int i=0; i<q.size(); i++){
                //não pode ser letra e nem digito especial
                if(((q[i] >= 'a' && q[i] <= 'z') || (q[i] >= 'A' && q[i] <= 'Z')) || !(q[i] >= '0' && q[i] <= '9')){
                    invalida = true;
                    break;
                }
            }
            if(invalida){
                throw std::invalid_argument ("Quantidade invalida, digite novamente!\n");
            }
            if(!invalida){
                quantidade = (stoi(q));
            }
        }catch(std::invalid_argument& e){
            while(invalida || quantidade < 1){
                std::cerr << e.what();
                invalida = false;
                std::cin >> q;
                for(int i=0; i<q.size(); i++){
                    //não pode ser letra e nem digito especial
                    if(((q[i] >= 'a' && q[i] <= 'z') || (q[i] >= 'A' && q[i] <= 'Z')) || !(q[i] >= '0' && q[i] <= '9')){
                        invalida = true;
                        aux = i;
                        break;
                    }
                }
                if(!invalida){
                    quantidade = (stoi(q));
                }
            }
        }
        //alterando a quantidade
        _estoque[aux]->set_quantidade(quantidade);
    }
    //alterar dados de vacinas
    if(opcao1 == "2"){
        existe = false;
        std::cout << "\nDigite o lote do material que deseja alterar: ";
        //verificacao do lote
        try{
            std::cin >> lote;
            for(int i=0; i<_vacina.size(); i++){
                if(lote == _vacina[i]->get_lote()){
                    existe = true;
                    break;
                }
            }
            if(!existe){
                throw std::invalid_argument ("Lote invalido! Digite novamente: ");
            }
        }catch(std::invalid_argument& e){
            while(!existe){
                std::cerr << e.what();
                std::cin >> lote;
                for(int i=0; i<_vacina.size(); i++){
                    if(lote == _vacina[i]->get_lote()){
                        existe = true;
                        aux = i;
                        break;
                    }
                }  
            }
        }
        //area de alteracao
        std::cout << "\nNova quantidade: ";
        bool invalida = false;
        std::string q;
        try{ //tratamento de exceção caso a quantidade seja inválida
            invalida = false;
            std::cin >> q;
            for(int i=0; i<q.size(); i++){
                //não pode ser letra e nem digito especial
                if(((q[i] >= 'a' && q[i] <= 'z') || (q[i] >= 'A' && q[i] <= 'Z')) || !(q[i] >= '0' && q[i] <= '9')){
                    invalida = true;
                    break;
                }
            }
            if(invalida){
                throw std::invalid_argument ("Quantidade invalida, digite novamente!\n");
            }
            if(!invalida){
                quantidade = (stoi(q));
            }
        }catch(std::invalid_argument& e){
            while(invalida || quantidade < 1){
                std::cerr << e.what();
                invalida = false;
                std::cin >> q;
                for(int i=0; i<q.size(); i++){
                    //não pode ser letra e nem digito especial
                    if(((q[i] >= 'a' && q[i] <= 'z') || (q[i] >= 'A' && q[i] <= 'Z')) || !(q[i] >= '0' && q[i] <= '9')){
                        invalida = true;
                        aux = i;
                        break;
                    }
                }
                if(!invalida){
                    quantidade = (stoi(q));
                }
            }
        }
        //alterando a quantidade
        _vacina[aux]->set_quantidade(quantidade);
    }
}

void Gerente::editar_dados(std::vector <Gerente*> g, int aux){
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
            for(int i=0;i<g.size();i++){
                if(login==g[i]->get_login()){
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
        if(valido==true){//chama a função do usuário para mudar o login
            g[aux]->set_login(login);
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
        g[aux]->set_senha(senha);//chama a função do usuário para mudar a senha
        std::cout << "Senha modificada com sucesso.\n";
    }
    //modificar nome
    if(opcao1 == "3"){
    std::string nome;
    bool valido = true;
        std::cout << "Digite o novo nome desejado: ";
        try{ //verifica se é válido
            std::cin >> nome;
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
            g[aux]->set_nome(nome);
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
                g[aux]->set_telefone(telefone);
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
                g[aux]->set_email(email);
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
                g[aux]->set_data_nascimento(data_nascimento);
                std::cout << "Data de nascimento modificada com sucesso.\n";
            }

    }
}

void Gerente::visualizar_dados(std::vector <Gerente*> g, int aux){
    std::cout << "\n--------------- Dados Pessoais --------------- " << std::endl;
    std::cout << "\n---------------------------------------------- " << std::endl;
    std::cout << "Login: " << g[aux]->get_login() << std::endl;
    std::cout << "Nome: " << g[aux]->get_nome() << std::endl;
    std::cout << "Telefone: " << g[aux]->get_telefone() << std::endl;
    std::cout << "E-mail: " << g[aux]->get_email() << std::endl;
    std::cout << "CPF: " << g[aux]->get_cpf() << std::endl;
    std::cout << "Data de nascimento: " << g[aux]->get_data_nascimento() << std::endl;
}

bool Gerente::verificar_lote(std::string nome, std::string lote){
    std::vector <std::string> lote_referente;
    int j = 0;
    bool valido = false;
    //guarda todas as referencias de lote que batem com o nome da vacina
    for(int i=0; i<_vacina.size(); i++){
        if(nome == _vacina[i]->get_nome()){
            lote_referente[j] = _vacina[i]->get_lote();
            j++;
        }
    }
    //verifica se alguma referencia bate
    for(int i=0; i<lote_referente.size(); i++){
        if(lote == lote_referente[i]){
            valido = true;
        }
    }
    return valido;
}

std::string Gerente::visualizar_fabricante(std::string lote){
    std::string f;
    for(int i=0; i<vacina.size(); i++){
        if(lote == vacina[i]->get_lote()){
            f = vacina[i]->get_fabricante();
        }
    }
    return f;
}