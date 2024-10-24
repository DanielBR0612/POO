#include <iostream>
#include <string>
#include <cctype> 

class banco {
    private:
        std::string nome;
        std::string num;
        double saldo = 1000;
        double din;
    public:
        void setNome(const std::string& n) {
            if (n.size() > 0) {
                nome = n;
            } else {
                throw std::invalid_argument("Nome invalido.");
            }
        }

        void setNum(const std::string& numero) {
            int qtd = 0;

            for (char c : numero) {
                if (isdigit(c)) { 
                    qtd++;
                }
            }

            if (qtd == 8) {
                num = numero;
            } else {
                throw std::invalid_argument("O numero da conta tem que ter 8 digitos.");
            }
        }

        void setSaldo(double s){
            saldo = s;
        }

        void setDin(double d){
            if(d > 0){
                din = d;
            }
            else{
                throw std::invalid_argument("O valor é invalido");
            }       
        }

        std::string getNome(){
            return nome;
        }
        std::string getNum(){
            return num;
        }
        double getSaldo(){
            return saldo;
        }
        double getDin(){
            return din;
        }

        double deposito(){
            saldo = saldo + din;
            return saldo;
        }
        double saque(){
            saldo = saldo - din;
            return saldo;
        }
};

class UI {
    private:
        Banco banco;  // Agora temos uma instância única de Banco na UI

    public:
        void main() {
            definirNome();  // Define o nome antes de começar as operações
            
            int op = menu();
            while (op != 0) {
                if (op == 1) {
                    deposito();
                    std::cout << "O seu saldo eh de: " << banco.getSaldo() << "\n"; 
                } else if (op == 2) {
                    saque();
                    std::cout << "O seu saldo eh de: " << banco.getSaldo() << "\n";
                } else {
                    break;
                }
                op = menu();
            }
        }

        void definirNome() {
            std::string nome;
            std::cout << "Digite o seu nome: ";
            std::cin >> nome;

            banco.setNome(nome);
            std::cout << "Nome registrado com sucesso: " << banco.getNome() << "\n";
        }

        int menu() {
            int op;
            std::cout << "\nEscolha a operacao que deseja fazer: \n";
            std::cout << "1 - Deposito 2 - Saque 0 - Sair\n";
            std::cin >> op;
            
            return op;
        }

        void deposito() {
            double valor;
            std::cout << "Digite o valor que deseja depositar: ";
            std::cin >> valor;

            banco.setDin(valor);
            banco.deposito();
        }

        double saq(){
            banco x;
            int v;

            std::cout << "Digite o valor que deseja sacar: ";
            std::cin >> v;

            x.setDin(v);

            double dep = x.saque();

            return dep;
        }

};

int main(){
    UI x;

    x.main();

    return 0;
}