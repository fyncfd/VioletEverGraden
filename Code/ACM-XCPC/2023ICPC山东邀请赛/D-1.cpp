#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define reo(i, l, r) for (int i = l; i <= r; i ++)
#define red(i, l, r) for (int i = l; i >= r; i --)
//define int long long;
const int MAXN = 0;

struct pii{
    int v, w;
};
std::vector<pii> a;

void solve() {
    int n;
    std::cin >> n;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        int v, w;
        std::cin >> v >> w;
        a[i] = {v, w};
    }
    auto check = [&](int mid) -> bool {
        std::vector<int> x, y;
        for (int i = 1; i <= n; i++) {
            auto [v, w] = a[i];
            if (v >= mid) {
                x.push_back(v + w);
            } else {
                y.push_back(w);
            }
        }
        sort(x.begin(), x.end(), greater<int>());
        sort(y.begin(), y.end(), greater<int>());
        if (x.size() < y.size()) {
            return false;
        }
        for (int i = 0; i < (int)y.size(); i++) {
            if (x[i] - y[i] < mid) {
                return false;
            }
        }
        return true;
    };

    int ans = 0;
    ll l = 1; ll r = 1e9;
    while(l < r) {
        int mid = l + r + 1 >> 1;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }

    std::cout << l << "\n";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);

    int _ = 1;
    for (std::cin >> _; _; _ --)
        solve();
    
    return 0;
}

/*
2
5
10 5
1 102
10 100
7 4
9 50
2
1 100
10 1

8
1
*/