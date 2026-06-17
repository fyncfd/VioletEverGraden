#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, l, r, x) for (int i = l; i <= r; i += x)
#define dep(i, l, r, x) for (int i = l; i >= r; i += x)

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

    ll res = n; ll cnt = 0;
    std::vector<ll> ans; ans.push_back(-1);
    rep(i, 1, n, 1) {
        if (suf[i] == 0) {
            res ++; 
            ans.push_back(i);
        } else {
            res ++; cnt ++;
            ans.push_back(i - cnt);
        }
    }

    rep(i, 1, n, 1) {
        res += ans[i] - a[i];
    }

    std::cout << res << '\n';
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
*/