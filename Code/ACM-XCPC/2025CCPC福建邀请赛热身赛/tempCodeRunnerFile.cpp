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

    std::vector<int> pos;
    rep(i, 1, n) {
        if (a[i] == 2) {
            pos.push_back(i);
        }
    }

    ll ans = -1;
    for (int i = 0; i < pos.size(); i ++) {
        int j = i + 1;
        while (pos[j] + 1 != pos[j + 1]) {
            j ++;
        }
        
        ll temp = 0;
        if (i == 0) {
            temp = pos[j + 1] - 1;
        } else {
            temp = pos[j + 1] - (pos[i] + 1);
        }

        ans = std::max(ans, temp);
    }

    std::cout << ans + 1 << '\n';
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
5
1 2 1 2 2

5
*/