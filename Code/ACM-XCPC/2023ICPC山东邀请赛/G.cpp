#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, l, r) for (int i = l; i <= r; i ++)
#define red(i, l, r) for (int i = l; i >= r; i --)
#define FOR(i, l, r, x) for (int i = l; i <= r; i += x)
#define ROF(i, l, r, x) for (int i = l; i >= r; i -= x)
//define int long long;
const int MAXN = 5e5 + 5;

int n;
std::vector<int> a[MAXN];
int cnt = 1;
void solve() {
    std::cin >> n;
    std::map<int, int> hash;
    rep(i, 1, n) {
        ll x; std::cin >> x;
        ll temp = x - i;

        if (!hash[temp]) {
            hash[temp] = cnt ++;
        }
        a[hash[temp]].push_back(x);
    }

    ll ans = 0;
    rep(i, 0, cnt - 1) {
        if (a[i].size() == 1) {
            continue;
        }
        
        std::sort(a[i].begin(), a[i].end(), [&](ll a, ll b) {
            return a < b;
        });

        ROF(j, a[i].size() - 1, 0, 2) {
            if (j - 1 < 0) {
                // std::cout << 1 << '\n';
                break;
                //return ;
            }

            int temp = a[i][j] + a[i][j - 1];
            if (temp > 0) {
                ans += temp;
            }
            //a[i].clear();
        }
        a[i].clear();
    }
    std::cout << ans << "\n";
    hash.clear();
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
3
9
3 -5 5 6 7 -1 9 1 2
3
-5 -4 -3
3
1 10 100


30
0
0
*/