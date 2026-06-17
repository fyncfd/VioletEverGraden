#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, l, r, x) for (int i = l; i <= r; i += x)

void solve() {
    int n;
    std::cin >> n;

    if (n == 1 or n == 2 or n == 4) {
        std::cout << -1 << '\n';
        return ;
    }

    int k = n % 3;
    if (k == 0 or k == 2) {
        std::cout << n / 3 << '\n';
    } else  {
        std::cout << n / 3 - 1 << '\n';
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int _ = 1;
    for (std::cin >> _; _; _ --)
        solve();

    return 0;
}

/*
6
1
3
5
7
8
9
*/