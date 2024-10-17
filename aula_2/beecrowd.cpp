#include <iostream>

using namespace std;

int main(){
    string nome;
    double salario;
    double venda;
    double comissao;
    double total;

    cin >> nome;
    cin >> salario;
    cin >> venda;

    comissao = venda * 0.15;
    total = salario + comissao;

    cout << fixed << std::setprecision(2);

    cout << "TOTAl = R$" << total;

    return 0;
}