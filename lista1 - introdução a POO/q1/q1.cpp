#include <iostream>

class circulo {
    public:
        double raio = 0;
        double area = 0;
        double circunferencia = 0;
    double a(){
        area = 3.14 * (raio * raio);

        return area;
    }
    double c(){
        circunferencia = 2 * (3.14 * raio);

        return circunferencia;
    }    
};

int main(){
    circulo c;

    std::cout << "Digite o raio do circulo: \n";
    std::cin >> c.raio;

    std::cout << "A area e a Circunferencia do circulo sao, respectivamente: " << c.c() << " " << c.a() << "\n"; 

    return 0;
}