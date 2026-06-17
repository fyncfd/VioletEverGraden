#include <bits/stdc++.h>

using ll = long long;

#define rep(i, l, r) for (int i = l; i <= r; i ++) 
#define red(i, l, r) for (int i = l; i >= r; i --)

//#define int long long
const int MAXN = 1e9;
// struct pii {
//     int x,y;
// };
int n, m;

void solve() {
    std::cin >> n >> m;
    
    std::unordered_map<int, std::vector<int>> hash1, hash2;
    rep(i, 1, n) {
        rep(j, 1, m) {
            int c; std::cin >> c;
            hash1[c].emplace_back(i);
            hash2[c].emplace_back(j);
        }
    }

    for (auto &[clo, v] : hash1) {
        std::sort(v.begin(), v.end(), [&](int a, int b) {
            return a < b;
        });
    }
    for (auto &[clo, v] : hash2) {
        std::sort(v.begin(), v.end(), [&](int a, int b) {
            return a < b;
        });
    }

    ll ans = 0;
    for (auto &[clo, v] : hash1) {
        ll pre = 0; ll cnt = 0;
        for (auto &c : v) {
            cnt ++;
            pre += c;
            ans += cnt * c - pre;
        }
    }
    for (auto &[clo, v] : hash2) {
        ll pre = 0; ll cnt = 0;
        for (auto &c : v) {
            cnt ++;
            pre += c;
            ans += cnt * c - pre;
        }
    }

    std::cout << ans + ans << '\n';
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
1 1
2 2

4


4 4
1 3 2 4
2 1 2 3
1 3 3 2
3 2 1 4

152


*/