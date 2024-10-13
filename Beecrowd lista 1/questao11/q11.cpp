#include <iostream>
#include <algorithm>

int main(){
    int n = 0;
    int testecase = 1;

    while (std::cin >> n && n != 0){
        int x, y, u, v;

        int inter_x1 = -10000, inter_y1 = 10000, inter_x2 = 10000, inter_y2 = -10000;

        for(int i = 0; i < n; i++){
            std::cin >> x >> y >> u >> v;

            inter_x1 = std::max(inter_x1, std::min(x, u));
            inter_y1 = std::min(inter_y1, std::max(y, v));
            inter_x2 = std::min(inter_x2, std::max(x, u));
            inter_y2 = std::max(inter_y2, std::min(y, v));

        }

        std::cout << "Teste " << testecase++ << "\n";

        if (inter_x1 <= inter_x2 && inter_y1 >= inter_y2){
            std::cout << inter_x1 << " " << inter_y1 << " " << inter_x2 << " " << inter_y2 << "\n";
        }
        else{
            std::cout << "nenhum" << "\n";
        }

        std::cout << "\n";

    }

    return 0;
}