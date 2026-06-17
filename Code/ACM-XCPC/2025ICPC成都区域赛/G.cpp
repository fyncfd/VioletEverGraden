#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, l, r, x) for (int i = l; i <= r; i ++)

void solve() {
    ll n, k, m;
    std::cin >> n >> k >> m;

    ll cntk = 1;
    ll nk = n / k - cntk;
    ll ott = n - cntk - nk;

    ll min = std::min(m, ott);
    m -= min;
    ott -= min;
    cntk += min;

    min = std::min(m, nk);
    m -= min;
    nk -= min;
    cntk += min;

    ll ans = (cntk + nk / 2);

    std::cout << ans << '\n';

}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int _ = 1;
    for (std::cin >> _; _; _ --)
        solve();

    return 0;
}

/*
2
4 1 0
5 3 1

1
6 2 1
*/