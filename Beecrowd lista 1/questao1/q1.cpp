#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    string nome;
    double salario;
    double vendas;
    double comissao;
    double total;

    cin >> nome;
    cin >> salario;
    cin >> vendas;

    comissao = vendas * 0.15;
    total = comissao + salario;

    cout << fixed << setprecision(2);
    cout << "TOTAL = R$ " << total << "\n";

    return 0;
}