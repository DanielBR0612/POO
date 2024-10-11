#include <iostream>

using namespace std;

int main(){
    int qtd;
    int num1 = 1;
    int num2 = 1;
    int aux;

    cin >> qtd;

    if (qtd >=3){
        cout << "0 " << num2 << " ";

        for (int i = 0; i < qtd - 2; i++){
            cout << num2 << " ";

            aux = num2;
            num2 = num2 + num1;
            num1 = aux;
        }


    }

    return 0;
}