#include <bits/stdc++.h>

using ll = long long;

#define rep(i, l, r) for (int i = l; i <= r; i ++) 
#define red(i, l, r) for (int i = l; i >= r; i --)

//#define int long long
const int MAXN = 0;
int n;
std::string s;

void solve() {
    std::cin >> n;
    //std::cout << n << '\n';

    std::map<std::string, int> hash;
    rep(i, 1, n) {
        std::cin >> s;
        hash[s] ++;
    }

    bool ok = false;
    for (auto x : hash) {
        auto [p, q] = x;    
        if (q > 1.0 * n / 2) {
            std::cout << p << '\n';
            ok = true;
        }
    }

    if (!ok) {
        std::cout << "uh-oh" << '\n';
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int _ = 1;

    //for (std::cin >> _; _; _ --) 
        solve();
    
    return 0;
}



/*
5
red
green
red
red
blue

red




3
red
blue
yellow

uh-oh


*/