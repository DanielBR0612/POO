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

class circulo{
    private:
        double raio;
    public:
        void setRaio(double v){
            if(v > 0){
                raio = v;
            }
        }
        double getRaio(){
            return raio;
        }
        double calcCirculo(){
            return (raio * raio) * 3.14;
        }
};

class UI{
    public:
    void prin(){
        int op = menu();
        while (op != 0){
            if (op == 1){
                double area = novoTriangulo();
                std::cout << "A area do triangulo eh: " << area << "\n";
            }
            if (op == 2){
                double areaC = novoCirculo();
                std::cout << "A area do circulo eh: " << areaC << "\n";
            }
            op = menu();
        }
    }
    int menu(){
        int op = 0;
        std::cout << "1-Triangulo 2-Circulo 0-Sair\n";
        std::cin >> op;
        return op;
    }
    double novoTriangulo(){
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

        return area;
    }

    double novoCirculo(){
        circulo y;
        double raio;
        
        std::cout << "Digite o raio do circulo: ";
        std::cin >> raio;

        y.setRaio(raio);

        double areaC = y.calcCirculo();

        return areaC;
    }
};

int main(){
    UI x;

    x.prin();

    return 0;
}