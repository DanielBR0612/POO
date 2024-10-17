#include <iostream>
#include <string>

class cinema{
    public:
        std::string dia;
        int h;
        double i = 16;
    double noite(){
        i = i + (i*0.5);
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

int main(){
    cinema c;
    double ingresso;

    std::cout << "Digite o dia da sessao: ";
    std::cin >> c.dia; 
    std::cout << "Digite a hora da sessao: ";
    std::cin >> c.h;

    if (c.dia == "quarta"){
        ingresso = c.quarta();
    }
    else if(c.dia == "sexta" || c.dia == "sabado" || c.dia == "domingo"){
        ingresso = c.SexSabDom();
    }
    else{
        ingresso = c.i;
    }

    if(c.h >= 17){
        ingresso = c.noite();
    }


    std::cout << "O ingresso vai custar: R$" << ingresso;

    return 0;
}