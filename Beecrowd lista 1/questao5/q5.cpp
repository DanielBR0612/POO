#include <iostream>

using namespace std;

int main(){
    int x;
    int resto;
    int cem;
    int cinquenta;
    int vinte;
    int dez;
    int cinco;
    int dois;
    int um;

    cin >> x;

    cem = x / 100;
    resto = x % 100;
    cinquenta = resto / 50;
    resto = resto % 50;
    vinte = resto / 20;
    resto = resto % 20;
    dez = resto / 10;
    resto = resto % 10;
    cinco = resto / 5;
    resto = resto % 5;
    dois = resto / 2;
    resto = resto % 2;
    um = resto / 1;


    cout << x << "\n";
    cout << cem << " nota(s) de R$ 100,00\n";
    cout << cinquenta << " nota(s) de R$ 50,00\n";
    cout << vinte << " nota(s) de R$ 20,00\n";
    cout << dez << " nota(s) de R$ 10,00\n";
    cout << cinco << " nota(s) de R$ 5,00\n";
    cout << dois << " nota(s) de R$ 2,00\n";
    cout << um << " nota(s) de R$ 1,00\n";

    return 0;
}