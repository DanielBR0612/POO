#include <iostream>

using namespace std;

int main(){
    int a;
    int b;
    int c;
    int maior;

    cin >> a;
    cin >> b;
    cin >> c;

    maior = a;

    if(b > maior){
        maior = b;
    }
    if (c > maior){
        maior = c;
    }
    
    cout << maior << " eh o maior\n";

    return 0;
}