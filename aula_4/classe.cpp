#include <iostream>
#include <iomanip>

class triangulo {
    public:
        float b = 0;
        float h = 0;
        float a = 0; 

    double area(){
       return a = b * h /2;
    }
};

int main(){
    triangulo t;
    
    std::cout << "Digite a base do triangulo: \n";
    std::cin >> t.b;

    std::cout << "Digite a altura do triangulo: \n";
    std::cin >> t.h;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << t.area() << "\n";

    return 0;
}