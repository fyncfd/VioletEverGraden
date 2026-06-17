#include <bits/stdc++.h>

using ll = long long;
using namespace std;

#define rep(i, l, r, x) for (int i = l; i <= r; i += x)
#define red(i, l, r, x) for (int i = l; i >= r; i -= x)
//#define int long long

const int MAXN = 0;

void solve() {
    int n, k;
    std::cin >> n >> k;

    rep(i, 1, k, 1) {
        std::cout << 1;
    }
    rep(i, 1, n - k, 1) {
        std::cout << 4;
    }
    std::cout << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int _ = 1;
    //std::cin >> _;

    //for (std::cin >> _; _; _ --) 
        solve();
    
        return 0;
}