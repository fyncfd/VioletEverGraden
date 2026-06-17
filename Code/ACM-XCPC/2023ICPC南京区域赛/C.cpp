#include <bits/stdc++.h>

using ll = long long;
using namespace std;

#define rep(i, l, r) for (int i = l; i <= r; i ++)
#define red(i, l, r) for (int i = l; i >= r; i --)
#define int long long

const int MAXN = 0;
ll p, m;

void solve() {
    std::cin >> p >> m;

    ll ans = m / p;
    rep(i, m / p, m / p + 1) {
        if (((1 + i * p) ^ (p - 1)) <= m) {
            ans ++;
        }
    }

    std::cout << ans << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int _ = 1;
    //std::cin >> _;

    for (std::cin >> _; _; _ --) 
        solve();
    
        return 0;
}


/*
3
2 0
7 11
1145141 998244353





1
2   
872

*/