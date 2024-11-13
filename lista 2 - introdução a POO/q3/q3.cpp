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

class UI{
    public:
        banco x;
        void main(){
            name();
            std::string nome = x.getNome();
            number();
            std::string numero = x.getNum();
            std::cout << "Bem vindo a sua conta: " << nome << "\n";
            int op = menu();
            while (op != 0){
                if(op == 1){
                    double deposito = deposi();
                    std::cout << "O seu saldo eh de: " << deposito << "\n"; 
                }
                else if(op == 2){
                    double saque = saq();
                    std::cout << "O seu saldo eh de: " << saque << "\n";
                }
                else{
                    break;
                }
            op = menu();
            }
        }

        void name(){

            std::string namae;

            std::cout << "Digite o seu nome: ";
            std::cin >> namae;

            x.setNome(namae);
        }

        void number(){

            std::string num;

            std::cout << "Digite o numero da sua conta: ";
            std::cin >> num;

            x.setNum(num);
        }

        int menu(){
            int op;

            std::cout << "Escolha a operacao que deseja fazer: \n";
            std::cout << "1-Deposito 2-Saque 0-Sair: ";
            std::cin >> op;
            
            return op;
        }

        double deposi(){
            int v;

            std::cout << "Digite o valor que deseja depositar: ";
            std::cin >> v;

            x.setDin(v);

            double dep = x.deposito();

            return dep;
        }

        double saq(){
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