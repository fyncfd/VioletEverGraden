#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, l, r) for (int i = 1; i <= n; i ++)
#define red(i, l, r) for (int i = l; i >= n; i --)

void solve() {
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    std::cout << (a + b + c) * d;
}

auto __init__ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
};

signed main() {
    __init__();

    int _ = 1;
    // for (std::cin >> _; _; _ --) 
        solve();

    return 0;
}