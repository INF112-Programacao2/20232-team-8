#include "aplicador.h"
#include <iostream>
#include <cctype>

Gerente g;

Aplicador::Aplicador(std::string login, std::string senha, std::string nome, std::string telefone, std::string email, std::string cpf, std::string data_vacina, std::string coren):
    Usuario(login,senha,nome,telefone,email,cpf,data_vacina), _coren(coren){}

Aplicador::~Aplicador() {}

std::string Aplicador::get_coren(){
    return _coren;
}

void Aplicador::set_coren(std::string coren){
    _coren = coren;
}

void Aplicador::registrar_vacina(std::string cns){
    std::string numvac, nome_vacina, lote, data_vacina, dose, opcao1, data_retorno, fabricante;
    bool valido_data_vacina, opcao_retorno, valido_data_retorno;
    std::cout << "Qual o nome da vacina aplicada?" << std::endl;
    std::cout << "(1) Coronavac\n(2) Astrazeneca\n(3) Pfizer\n (4) Janssen\n";
    try{ 
        std::cin >> numvac;
        if(numvac!="1" || numvac!="2" || numvac!="3" || numvac!="4"){
            throw std::invalid_argument ("Opção inexistente, digite novamente!");
        }
    } catch(std::invalid_argument& e){
        while(numvac!="1" && numvac!="2" && numvac!="3" && numvac!="4"){
            std::cerr << e.what();
            std::cin >> numvac;
        }
    }
    if(numvac == "1"){ // através das opções, grava o nome da vacina
        nome_vacina = "Coronavac"; 
    }
    if(numvac == "2"){
        nome_vacina = "Astrazeneca";
    }
    if(numvac == "3"){
        nome_vacina = "Pfizer";
    }
    if(numvac == "4"){
        nome_vacina = "Janssen";
    }
    std::cout << "Qual o lote da vacina?\n";
    try{
        std::cin >> lote;
        if(g.verificar_lote(nome_vacina,lote) == false)
            throw std::invalid_argument ("Lote da vacina digitado não corresponde a um lote existente, digite novamente. ");
    } catch(std::invalid_argument &d){
        while(g.verificar_lote(nome_vacina,lote) == false){
            std::cerr << d.what();
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
    fabricante = g.visualizar_fabricante(lote);
    _historico.push_back(new Historico(cns,_coren,data_vacina,dose,opcao_retorno,data_retorno,fabricante,lote));
}

void Aplicador::verificar_retorno(){
    
}

void Aplicador::definir_retorno(){

}