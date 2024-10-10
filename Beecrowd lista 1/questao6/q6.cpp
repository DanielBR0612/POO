#include <iostream>

using namespace std;

int main(){
    int l;
    int d;
    int k;
    int p;
    int gasolina;
    int qtd;
    int pedagio;
    int total;

    cin >> l >> d;
    cin >> k >> p;

    gasolina = l * k;
    qtd = l/d;
    pedagio = qtd * p;

    total = gasolina + pedagio;

    cout << total << "\n";


    return 0;
}