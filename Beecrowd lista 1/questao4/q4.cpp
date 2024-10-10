#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int main(){
    double x1;
    double y1;
    double x2;
    double y2;
    double total;

    cin >> x1;
    cin >> y1;
    cin >> x2;
    cin >> y2;

    total = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));

    cout << fixed << setprecision(4);
    cout << total << "\n";


    return 0;
}

