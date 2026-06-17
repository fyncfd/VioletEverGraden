#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, l, r) for (int i = l; i <= r; i ++)
#define red(i, l, r) for (int i = l; i >= r; i --)
#define FOR(i, l, r, x) for (int i = l; i <= r; i += x)
#define ROF(i, l, r, x) for (int i = l; i >= r; i -= x)

ll ksm(ll a, ll n, ll p) {
    ll ans = 1;
    a %= p;
    while (n) {
        if (n & 1) {
            ans = (ans * a) % p;
            a = (a * a) % p;
            n >>= 1;
        }
    }

    return ans;
}
ll inv(ll x, ll p) {
    return ksm(x, mod - 2, mod);
}
void solve() {
    
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