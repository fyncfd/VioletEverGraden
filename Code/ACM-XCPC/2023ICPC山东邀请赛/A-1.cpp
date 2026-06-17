#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define reo(i, l, r) for (int i = l; i <= r; i ++)
#define red(i, l, r) for (int i = l; i >= r; i --)
#define int long long
const int MAXN = 0;


void solve() {
    int n, k;
    std::cin >> n >> k;
    std::map<int, ll> mp;
    for (int i = 0; i < n; i++) {
        int a, b;
        std::cin >> a >> b;
        mp[a] += b;
    }
    ll ans = 0;
    bool op = false;
    for (auto x : mp) {
        int y = x.first * k;
        y -= ans ;
        if (y < x.second) {
            op = true;
        }
        ans += x.second;
    }
    if (op) {
        std::cout << "No\n";
    } else {
        std::cout << "Yes\n";
    }

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
4 5
6 12
1 3
6 15
8 1
3 100
3 200
4 300
6 100

Yes
No


*/