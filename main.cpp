#include <iostream>
#include "internet.h"

int main() {
    internet::model_Barabashi_Alberta *model_one;
    int n, m;
    std::cout << "Input N: ";
    std::cin >> n;
    std::cout << "Input M: ";
    std::cin >> m;
    if(n <= 0) return 0;
    model_one = new internet::model_Barabashi_Alberta(n, m);
    model_one->show();
    std::cout << "\n";
    std::cout << "diametr = "<<  model_one->getDiam() << "\n";
    delete model_one;
    return 0;
}
