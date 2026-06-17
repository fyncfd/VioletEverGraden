#include <bits/stdc++.h>

int n, m;
double p;

int main() {
    std::cin >> n >> m;
    while (n --) {
        std::cin>> p;
        std::cout << std::fixed << std::setprecision(1);
        if (p < m) {
            std::cout << "On Sale! " << p << std::endl;
        }
    }
    return 0;
}