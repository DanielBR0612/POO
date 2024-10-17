#include <iostream>
#include <string>

class conta_bancaria{
    public: 
        std::string nome;
        int num;
        double sal = 3000;
        double din;
    double deposito(){
        sal = sal + din;
        return sal;
    }
    double saque(){
        sal = sal - din;
        return sal;
    }
};

int main(){
    conta_bancaria cb;
    int aux;
    
    std::cout << "Digite seu nome: ";
    std::cin >> cb.nome;

    std::cout << "DIgite o numero da sua conta: ";
    std::cin >> cb.num;

    std::cout << "Bem vindo a sua conta, " << cb.nome << "!\n";

    std::cout << "Para fazer um deposito, digite 1, para fazer um saque, digite 2: ";
    std::cin >> aux;

    if(aux == 1){
        std::cout << "Digite a quantidade de dinheiro que quer depositar: ";
        std::cin >> cb.din;

        std::cout << "O seu saldo atualizado eh de: R$" << cb.deposito();
    }
    else if(aux == 2){
        std::cout << "Digite a quantidade de dinheiro que quer retirar: ";
        std::cin >> cb.din;

        std::cout << "O seu saldo atualizado eh de: R$" << cb.saque();
    }
    return 0;
}