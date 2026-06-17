#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, l, r, x) for (int i = l; i <= r; i ++)

void solve() {
    int n, m, k, b;
    std::cin >> n >> m >> k >> b;

    int k1 = 0; int k2 = 0;
    rep(i, 1, n, 1) {
        ll sc = 0; ll f = 0;
        rep(j, 1, m, 1) {
            int x;
            std::cin >> x;
            sc += x;
            if (x >= 1) {
                x --;
            } else {
                x ++;
            }
            f += x;
        }
        if (sc >= k) {
            k1 ++;
        } else if (f >= k) {
            k2 ++;
        }
    }

    ll ans = k1 + std::min(b, k2);
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
5 3 2 1
-3 0 3
2 -2 -1
1 1 1
0 0 0
-1 -1 -1
3 2 -1 1
-1 -2
-3 -3
1 -3
*/