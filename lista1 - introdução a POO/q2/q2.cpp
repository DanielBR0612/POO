#include <iostream>

class velo_media{
    public:
        int km = 0;
        int h = 0;
        double m = 0;
        double t = 0;
    int vm(){
        t = (m / 60) + h;
        return km / t;
    }
};

int main(){
    velo_media vm;

    std::cout << "Digite a distancia em km: \n";
    std::cin >> vm.km;

    std::cout << "Digite as horas e os minutos, respectivamente: \n";\
    std::cin >> vm.h >> vm.m;

    std::cout << "A velocidade media desta viagem foi de: " << vm.vm() << "km/h\n";

    return 0;
}