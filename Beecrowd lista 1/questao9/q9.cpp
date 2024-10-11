#include <iostream>

using namespace std;

int main(){
    int n;
    int x;
    int qtd = 2;
    int qtd2 = 0;

    cin >> x;
    cin >> n;

    for (int i = 0; i <= x; i++){
        while(n % qtd != 0){
            if (n % qtd != 0){
                qtd2++;
            }
        }
    }

    if (qtd2 == 1){
        cout << "é primo";
    }

    return 0;
}