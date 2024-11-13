#include <iostream>

class viagem{
    private:
        double distancia;
        double tempo;
    public:
        void setDistancia(double d){
            if (d > 0){
                distancia = d;
            }
            else{
                throw std::invalid_argument("A distancia não pode ser negativa");
            }
        }
        void setTempo(double t){
            if (t > 0){
                tempo = t;
            }
            else{
                throw std::invalid_argument("O tempo não pode ser negativo");
            }
        }
        double getDistancia(){
            return distancia;
        }
        double getTempo(){
            return tempo;
        }
        double velocidadeMedia(){
            return distancia / tempo;
        }
};

class UI{
    public:
        void main(){
            std::cout << vM();
        }
        double vM(){
            viagem v;

            double minutos;
            double horas;
            double distancia;

            std::cout << "Digite o tempo da viagem: ";
            std::cin >> horas >> minutos;

            std::cout << "Digite a distancia em Km: ";
            std::cin >> distancia;

            double tempo = (minutos / 60) + horas;

            v.setDistancia(distancia);
            v.setTempo(tempo);

            double velocidadeMedia = v.velocidadeMedia();

            return velocidadeMedia;
        }
};

int main(){
    UI x;

    x.main();

    return 0;
}