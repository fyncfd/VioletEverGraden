#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define int long long

#define rep(i, l, r) for (int i = l; i <= n; i ++)
#define red(i, l, r) for (int i = l; i >= n; i --)

int n;
std::vector<int> a;
void solve() {
    std::cin >> n;
    a.resize(n + 1);
    std::map<int, int> hash;
    rep(i, 1, n) {
        std::cin >> a[i];
        hash[a[i]] ++;
    }

    // rep(i, 1, n) {
    //     std::cout << a[i] << " \n"[i == n];
    // }

    ll ans = 2e18;
    for (int i = 0; i < 4; i ++) {
        ll s = hash[(i + 1) % 4] + 2 * hash[(i + 2) % 4] + 3 * hash[(i + 3) % 4];
        ll p = (i + s) % 4;
        if (p != 0) {
            s += (4 - p);
        }
        ans = std::min(ans, s);
    }

    // int ans = 0;
    // std::sort(a.begin() + 1, a.end(), [&](int a, int b) {
    //     return a > b;
    // });
    // if (a[1] == a[n]) {
    //     if (a[1] == 0) {
    //         ans = 0;
    //     } else {
    //         ans = 4 - a[1];
    //     }
    // } else {
    //     rep(i, 1, n) {
    //         if (a[i] != 0) {
    //             ans += (4 - a[i]);
    //         }
    //     }
    // }



    std::cout << ans << '\n';

}

auto __init__ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
};

signed main() {
    __init__();

    int _ = 1;
    //for (std::cin >> _; _; _ --) 
        solve();

    return 0;
}

/*
4
0 1 2 3

4
0 0 0 0

4 
2 2 2 2
*/