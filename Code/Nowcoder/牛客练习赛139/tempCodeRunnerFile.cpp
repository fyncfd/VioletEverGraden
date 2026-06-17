#include <bits/stdc++.h>

using ll = long long;

ll n, m;
int p;

void violet() {
    std::cin >> n >> m;

    ll l = -1; ll r = -1;
    for (int i = 1; i <= m; i ++) {
        std::cin >> p;

        if (i % 2 == 1) {
            l = p;
        }
        else {
            r = p;
        }
    }

    ll cnt = 2 * n;
    ll ans = (r - 1 + cnt) % cnt;
    if (ans == 0) {
        ans = cnt;
    }

    std::cout << l << ' ' << ans << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int _ = 1;
    //std::cin >> _;

    //for (std::cin >> _; _; _ --)
        violet();

    return 0;
}

/*

8 2
7
5

*/