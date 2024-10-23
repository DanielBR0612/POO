#include <iostream>

class triangulo{
    private:
        double b;
        double h;
    public:
        void setBase(double v){
            if (v > 0){
                b = v;
            }
        }
        void setAltura(double v){
            if(v > 0){
                h = v;
            }
        }
        double getBase(){
            return b;
        }
        double getAltura(){
            return h;
        }
        double calcArea(){
            return (b * h) / 2;
        }
};

int main(){
    triangulo x;
    double base;
    double altura;

    std::cout << "Digite a base do triangulo: ";
    std::cin >> base;

    std::cout << "Digite a altura do triangulo: ";
    std::cin >> altura;

    x.setBase(base);
    x.setAltura(altura);

    double area = x.calcArea();

    std::cout << area << "\n";

    return 0;
}