#include <bits/stdc++.h>

using ll = long long;
using namespace std;

#define rep(i, l, r, x) for (int i = l; i <= r; i += x)
#define red(i, l, r, x) for (int i = l; i >= r; i -= x)
//#define int long long

const int MAXN = 0;
int n;
std::vector<int> a;
void solve() {
    std::cin >> n;
    a.resize(n + 1);
    std::map<int, int> hash;
    rep(i, 1, n, 1) {
        std::cin >> a[i];
        hash[a[i]] ++;
    }

    int ans = 1e9;
    rep(i, 0, 3, 1) {
        int s = hash[(i + 1) % 4] + 2 * hash[(i + 2) % 4] + 3 * hash[(i + 3) % 4];
        int p = (i + s) % 4;
        if (p != 0) {
            s += (4 - p);
        }
        ans = std::min(ans, s);
    }

    std::cout << ans << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int _ = 1;
    //std::cin >> _;

    //for (std::cin >> _; _; _ --) 
        solve();
    
        return 0;
}

/*
4
0 1 2 3

6
*/