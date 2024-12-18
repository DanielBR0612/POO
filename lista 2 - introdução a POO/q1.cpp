#include <iostream>

class circulo{
    private:
        double raio;
    public:
        void setRaio(double v){
            if (v > 0){
                raio = v;
            }
            else{
                throw std::invalid_argument("O raio nao pode ser negativo");
            }
        }
        double getRaio(){
            return raio;
        }
        double calcArea(){
            return (raio * raio) * 3.14;
        }
        double calcCirculo(){
            return 2 * 3.14 * raio;
        }
};

class UI{
    public:
        void main(){
            int op = menu();
            circulo x;
            x.setRaio(novoCirculo());
            while (op != 0){
                if (op == 1) {
                    calcCircunferencia(x);
                    break;
                }
                if (op == 2) calcA(x);
            }
        }
        int menu(){
            int op;
            
            std::cout << "1-Calcular circunferencia 2-Calcular area 0-sair";
            std::cin >> op;
            return op;
        }
        double novoCirculo(){
        
            double raio;

            std::cout << "Digite o raio do circulo: ";
            std::cin >> raio;

            return raio;
        }
        void calcCircunferencia(circulo x){
            std::cout << x.calcCirculo();
        }
        void calcA(circulo x){
            std::cout << x.calcArea();
        }
};

int main(){
    UI ui;

    ui.main();

    return 0;
}