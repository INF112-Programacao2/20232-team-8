#include <iostream>
#include <string>
#include <exception>
#include "gerente.h"
#include "usuario.h"

std::string opcao1;

Gerente::Gerente(std::string login, std::string senha, std::string nome, std::string telefone, std::string email,
                std::string cpf, std::string data_nascimento,std::string nome2, std::string endereco):
    Usuario(login,senha,nome,telefone,email,cpf,data_nascimento), _posto(nome2,endereco){}

//funcao que adiciona um novo estoque
void Gerente::adicionar_estoque(){
    //dados do estoque
    std::string nome, validade, data_recebimento, lote;
    int quantidade;
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
        //leitura dos dados do material
        int i=0;
        bool validade_valida = false;
        //nome do material
        std::cout << "\nDigite o nome do material: ";
        std::cin >> nome;
        //data de validade
        std::cout << "Digite a validade do material (ddmmaaaa): ";
        try{ //tratamento de exceção caso a data seja inválida
            std::cin >> validade;
            if(validade.size() == 8 )
                validade_valida = true;
            for(i=0; i<validade.size(); i++){
                if(isalpha(validade[i]) || validade_valida == false){
                    throw std::invalid_argument ("Data invalida, digite novamente!\n");
                }
            }
        } catch(std::invalid_argument& e){
            while(isalpha(validade[i]) || validade_valida == false){
                std::cerr << e.what();
                std::cin >> validade;
                if(validade.size() == 8 )
                    validade_valida = true;
            }
        }
        //data de recebimento
        i=0;
        bool data_valida = false;
        std::cout << "Digite a data de recebimento (ddmmaaaa): ";
        try{ //tratamento de exceção caso a data seja inválida
            std::cin >> data_recebimento;
            if(data_recebimento.size() == 8 )
                data_valida = true;
            for(i=0; i<data_recebimento.size(); i++){
                if(isalpha(data_recebimento[i]) || data_valida == false){
                    throw std::invalid_argument ("Data invalida, digite novamente!\n");
                }
            }
        } catch(std::invalid_argument& e){
            while(isalpha(data_recebimento[i]) || data_valida == false){
                std::cerr << e.what();
                std::cin >> data_recebimento;
                if(data_recebimento.size() == 8 )
                    data_valida = true;
            }
        }
        //lote do material
        std::cout << "Digite o lote do material: ";
        std::cin >> lote;
        //quantidade do material
        std::cout << "Digite a quantidade do material: ";
        try{ //tratamento de exceção caso a quantidade seja inválida
            std::cin >> quantidade;
            if(quantidade < 1 || std::cin.fail()){
                throw std::invalid_argument ("Quantidade invalida, digite novamente!\n");
            }
        } catch(std::invalid_argument& e){
            while(quantidade < 1 || std::cin.fail()){
                std::cerr << e.what();
                std::cin >> quantidade;
            }
        }
        //construtor de estoque
        _estoque.push_back(new Estoque(nome, quantidade, validade, data_recebimento, lote));
    }
    if(opcao1 == "2"){
        //leitura dos dados da vacina
        int i=0;
        bool validade_valida = false;
        std::string fabricante, tipo, aplicacao;
        //nome do material
        std::cout << "\nDigite o nome da vacina: ";
        std::cin >> nome;
        //data de validade
        std::cout << "Digite a validade da vacina (ddmmaaaa): ";
        try{ //tratamento de exceção caso a data seja inválida
            std::cin >> validade;
            if(validade.size()==8)
                validade_valida = true;
            for(i=0; i<validade.size(); i++){
                if(isalpha(validade[i]) || validade_valida == false){
                    throw std::invalid_argument ("Data invalida, digite novamente!\n");
                }
            }
        } catch(std::invalid_argument& e){
            while(isalpha(validade[i]) || validade_valida == false){
                std::cerr << e.what();
                std::cin >> validade;
                if(validade.size() == 8 )
                    validade_valida = true;
            }
        }
        //data de recebimento
        i=0;
        bool data_valida = false;
        std::cout << "Digite a data de recebimento (ddmmaaaa): ";
        try{ //tratamento de exceção caso a data seja inválida
            std::cin >> data_recebimento;
            if(data_recebimento.size() == 8)
                data_valida = true;
            for(i=0; i<data_recebimento.size(); i++){
                if(isalpha(data_recebimento[i]) || data_valida == false){
                    throw std::invalid_argument ("Data invalida, digite novamente!\n");
                }
            }
        } catch(std::invalid_argument& e){
            while(isalpha(data_recebimento[i]) || data_valida == false){
                std::cerr << e.what();
                std::cin >> data_recebimento;
                if(data_recebimento.size() == 8 )
                    data_valida = true;
            }
        }
        //lote do material
        std::cout << "Digite o lote da vacina: ";
        std::cin >> lote;
        //quantidade do material
        std::cout << "Digite a quantidade da vacina: ";
        try{ //tratamento de exceção caso a quantidade seja inválida
            std::cin >> quantidade;
            if(quantidade < 1 || std::cin.fail())
                throw std::invalid_argument ("Quantidade invalida, digite novamente!\n");
        } catch(std::invalid_argument& e){
            while(quantidade < 1 && std::cin.fail()){
                std::cerr << e.what();
                std::cin >> quantidade;
            }
        }
        //fabricante
        std::cout << "Digite o nome do fabricante: ";
        std::cin >> fabricante;
        //tipo
        std::cout << "Digite o tipo da vacina: ";
        std::cin >> tipo;
        //aplicacao
        std::cout << "Digite a forma de aplicacao da vacina: ";
        std::cin >> aplicacao;
        
        //construtor de estoque
        _vacina.push_back(new Vacina(fabricante, tipo, aplicacao, nome, quantidade, validade, data_recebimento, lote));
    }
}

void Gerente::alterar_estoque(){
    std::cout << "Qual o tipo de produto do estoque? ";
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
}