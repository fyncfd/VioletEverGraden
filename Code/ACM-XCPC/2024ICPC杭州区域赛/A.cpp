#include <bits/stdc++.h>
using namespace std;

#define rep(i, l, r) for(int i = l; i <= r; i ++)
string s1, s2, s3;
struct DSU {
    vector<int> fa;
    DSU() : fa(26) {
        iota(fa.begin(), fa.end(), 0);
    }

    int find(int x) {
        if (fa[x] == x) {
            return fa[x];
        }
        return find(fa[x]);
    }

    void merge(int x, int y) {
        x = find(x); y = find(y);
        if (x != y) {
            fa[x] = y;
        }
    }
};


void solve() {
    cin >> s1 >> s2 >> s3;

    if (s1.size() != s2.size()) {
        cout << "NO\n";
        return ;
    }

    if (s1.size() != s3.size()) {
        cout << "YES\n";
        return ;
    }

    int n = s1.size();
    DSU dsu;
    rep(i, 0, n - 1) {
        char c1 = s1[i], c2 = s2[i];
        if (c1 != c2) {
            int x = c1 - 'a', y = c2 - 'a';
            dsu.merge(x, y);
        }
    }

    rep(i, 0, n - 1) {
        char c1 = s1[i], c3 = s3[i];
        int x = c1 - 'a', y = c3 - 'a';
        if (dsu.find(x) != dsu.find(y)) {
            cout << "YES\n";
            return ;
        }
    }

    std::cout << "NO\n";
}
signed main() {
    cout.tie(nullptr) -> ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _ = 0;
    std::cin >> _;

    while (_ --) {
        solve();
    }

    return 0;
}