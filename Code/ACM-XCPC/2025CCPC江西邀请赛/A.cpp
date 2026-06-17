#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i64 = long long;

#define rep(i, l, r, x) for (int i = l; i <= r; i += x)

void solve() {
    i64 n, k;
    std::cin >> n >> k;
    std::vector<i64> a(n);
    for (auto &x : a) {
        std::cin >> x;
    }
    sort(a.begin(), a.end(), std::greater<i64>());
    i64 ans = 0;
    for (i64 i = 0; i < n; i++) {
        ans += 1;
        i64 x = ans - i - 1;
        i64 y = n - i - 1;
        if (x / k >= y) {
            std::cout << ans << "\n";
            return ;
        } else if (x / k < y){
            int z = 0;
            if (x % k == 0) {
                z = 0;
            } else {
                z = x % k;
            }
            if ((a[i] - 1 + z) / k < y - x / k) {
                ans += a[i] - 1;
            } else {
                std::cout << ans + (y - x / k) * k - z << "\n";
                return ;
            }
        }
    }
    std::cout << ans << "\n";
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
2
2 2
1 4
4 3
8 7 6 5

3
9

*/