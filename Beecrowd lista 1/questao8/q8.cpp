#include <iostream>

using namespace std;

int main() {
    double n = 0;
    double soma = 0;
    int qtd = 0; 

    while (qtd < 2) {
        cin >> n;

        if (n >= 0 && n <= 10) {
            soma += n;
            qtd++;
        } else {
            cout << "nota invalida" << "\n";
        }
    }

    double media = soma / 2;
    cout << "media = " << media << "\n";

    return 0;
}
