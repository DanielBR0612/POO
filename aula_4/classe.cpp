#include <iostream>

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
    t.b = 3;
    t.h = 4;

    std::cout << t.area() << "\n";

    return 0;
}