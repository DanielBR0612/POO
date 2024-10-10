#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    int x;
    double y;
    double total;

    cin >> x;
    cin >> y;

    total = x/y;

    cout << fixed << setprecision(3);
    cout << total << " km/l\n";

    return 0;
}