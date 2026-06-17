#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, l, r) for (int i = l; i <= r; i ++)
#define red(i, l, r) for (int i = l; i >= r; i --)
#define FOR(i, l, r, x) for (int i = l; i <= r; i += x)
#define ROF(i, l, r, x) for (int i = l; i >= r; i -= x)

int n;
std::vector<int> a;
void solve() {
    std::cin >> n;
    a.resize(n + 1);
    rep(i, 1, n) {
        std::cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] == 1) {
            
        }
    }
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