#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, l, r) for (int i = l; i <= r; i ++)
#define red(i, l, r) for (int i = l; i >= r; i --)
#define FOR(i, l, r, x) for (int i = l; i <= r; i += x)
#define ROF(i, l, r, x) for (int i = l; i >= r; i -= x)

int n, m;
std::vector<ll> a;
std::vector<ll> b;
void solve() {
    std::cin >> n >> m;
    a.resize(n + 1);
    rep(i, 1, n) {
        std::cin >> a[i];
    }
    b.resize(m + 1);
    rep(i, 1, m) {
        std::cin >> b[i];
    }

    if (n == m and a[n] == b[m - 1]) {
        std::cout << "YES\n";
        return ;
    } 
    std::cout << "NO\n";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int _ = 1;
    //for (std::cin >> _; _; _ --)
        solve();

    return 0;
}

/*
2 2
2 3
4 5

NO

*/