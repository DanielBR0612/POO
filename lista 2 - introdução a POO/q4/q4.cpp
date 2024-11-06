#include <iostream>
#include <string>

class cinema{
    private:
        std::string dia;
        int hora;
        double i = 16;
    public:
        void setDia(str::string d){
            if(d == "segunda" || d == "terca" || d == "quarta" || d == "quinta" || d == "sexta" || d == "sabado" || d == "domingo"){
                dia = d;
            }
            else{
                throw std::invalid_argument("Digite um dia valido");
            }
        }
        void setHora(int h){
            if (h >= 0){
                hora = h;
            }
            else{
                throw std::invalid_argument("Digite uma hora valida")
            }
        }
        void setPreco(int p){
            i = p
        }

        double getPreco(){
            return i;
        }
        std::string getDia(){
            return dia;
        }
        int getHora(){
            return hora;
        }

        double noite(){
            i = i + (i * 0.5);
            return i;
        }
        double quarta(){
            i = 8;
            return i;
        }
        double SexSabDom(){
            i = 20;
            return i;
        }
};

class UI{
    public:
        cinema x;
        void main(){
            int op = menu();
            while (op != 0){
                if(op == 1 || op == 6 || op == 7){
                    
                }
            }
        }

        void menu(){
            int op;
            int hr;

            std::cout >> "Escolha o dia da sua sessao: \n";
            std::cout >> "1-Domingo 2-Segunda 3-Terca 4-Quarta 5-Quinta 6-Sexta 7-Sabado";
            std::cout >> "Digite a hora da sua sessao";
            
            std::cin << hr;
            std::cin << op;
            return op;
        }

        double noite(){
            
        }
        

};  

int main(){


    return 0;
}