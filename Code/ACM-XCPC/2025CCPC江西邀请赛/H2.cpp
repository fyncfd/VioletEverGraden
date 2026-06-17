#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, l, r, x) for (ll i = l; i <= r; i += x)
#define dep(i, l, r, x) for (ll i = l; i >= r; i -= x)

void solve() {
    int n;
    std::cin >> n;

    std::vector<ll> a(n + 10, 0);
    rep(i, 1, n, 1) {
        std::cin >> a[i];
    }

    rep(i, 1, n, 1) {
        if (a[i] < i) {
            std::cout << -1 << '\n';
            return ;
        }
    }

    std::vector<ll> suf(n + 10, 3e12);
    suf[n] = a[n] - n;
    dep(i, n - 1, 1, 1) {
        suf[i] = std::min(suf[i + 1], a[i] - i);
    }

    rep(i, 1, n, 1) {
        if (suf[i] < 0) {
            std::cout << -1 << '\n';
        }
    }

    ll cnt = 0; ll temp = 0; ll ans = n;
    std::vector<ll> t(n + 10, 0);
    rep(i, 1, n, 1) {
        if (suf[i] > temp) {
            ll k = temp;
            temp = std::min(cnt + temp, suf[i]);
            cnt += k - temp;
        }
        t[i] = temp + i;
        cnt += a[i] - t[i];
        ans += a[i] - t[i];
    }

    std::cout << ans << '\n';


    // std::cout << res << '\n';
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

3
5
1 2 4 5 6
8
1 2 4 5 5 8 10 9
3
3 2 1

6
13
-1

*/