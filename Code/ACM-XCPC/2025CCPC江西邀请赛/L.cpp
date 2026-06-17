#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, l, r, x) for (int i = l; i <= r; i += x)

void solve() {
    int a, b;
    std::cin >> a >> b;

    if (a == 30) {
        std::cout << "Alice\n";
        return ;
    } 
    if (b == 30) {
        std::cout << "Bob\n";
        return ;
    }

    if (a >= 21 or b >= 21) {
        if (a - b >= 2) {
            std::cout << "Alice\n";
            return ;
        } 
        if (b - a >= 2) {
            std::cout << "Bob\n";
            return ;
        }
    }

    std::cout << "Underway\n";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int _ = 1;
    // for (std::cin >> _; _; _ --)
        solve();

    return 0;
}