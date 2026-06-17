#include <bits/stdc++.h>

using ll = long long;
#define int long long

const ll mod = 1e9 + 7;

#define rep(i, l, r, x) for (int i = l; i <= r; i += x)
#define dep(i, l, r, x) for (int i = l; i >= r; i -= x)

int n;
std::vector<ll> a;

void violet() {
    std::cin >> n;
    a.resize(n + 1, 0);
    rep(i, 1, n, 1) {
        std::cin >> a[i];
    }
    std::vector<ll> sum(n + 100, 0);
    sum[n] = a[n];


    dep(i, n - 1, 1, 1) {
        sum[i] = a[i] * (sum[i + 1] + (sum[i + 1] / a[i + 1]));
    }

    ll ans = 0;
    dep(i, n, 1, 1) {
        ans += sum[i];
        ans %= mod;
    }

    std::cout << ans % mod << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int _ = 1;
    //for (std::cin >> _; _; _ --) 
        violet();

    return 0;
}