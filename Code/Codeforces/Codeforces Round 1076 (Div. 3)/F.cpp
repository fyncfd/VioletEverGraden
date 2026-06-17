/*
* @Author: AlgoStruggler
* @Create Time: 2026-01-25 23:34:15
* "To the Splendor of ACM-ICPC, We Consecrate Our AC Triumphs."
*/
#define  _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize("O2")
#include "bits/stdc++.h"
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;

using i64 = long long;
using ldb = long double;
typedef unsigned long long u64;
typedef __int128 i128;
struct pii { int fi; int se; };
struct pll { i64 fi; i64 se; };
#define debug(x) std::cerr << #x << " = " << x << '\n'
#define debug2(x, y) std::cerr << #x << " = " << x << ", " << #y << " = " << y << '\n'
/*------------------------------SORT_AND_UNIQUE-------------------------------*/
const double eps = 1e-9;
constexpr int INF = 0x3f3f3f3f;
constexpr i64 LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr i64 mod = 998244353;
constexpr i64 MOD = 1e9 + 7;
constexpr int MAXN = 0;
/*-------------------------------MY_CODE_BEGIN--------------------------------*/
static inline void VioletEverGraden() {
    i64 n, Ax, Ay, Bx, By;
    std::cin >> n >> Ax >> Ay >> Bx >> By;

    std::vector<i64> x(n + 1);
    for (int i = 1; i <= n; i ++) {
        std::cin >> x[i];
    }

    std::vector<i64> y(n + 1);
    for (int i = 1; i <= n; i ++) {
        std::cin >> y[i];
    }

    std::vector<pll> h(n);
    for (int i = 1; i <= n; i ++) {
        h[i - 1] = {x[i], y[i]};
    }

    std::sort(h.begin(), h.end(), [&](pll& a, pll& b) {
        return a.fi == b.fi ? a.se < b.se : a.fi < b.fi;
    });

    std::vector<pll> g;
    i64 cur = h[0].fi; i64 min = h[0].se; i64 max = h[0].se;

    for (int i = 1; i < n; i ++) {
        if (h[i].fi == cur) {
            min = std::min(min, h[i].se);
            max = std::max(max, h[i].se);
        } else {
            g.push_back({min, max});
            cur = h[i].fi;
            min = h[i].se;
            max = h[i].se;
        }
    }
    g.push_back({min, max});

    i64 dp0 = std::abs(Ay - g[0].se) + (g[0].se - g[0].fi);
    i64 dp1 = std::abs(Ay - g[0].fi) + (g[0].se - g[0].fi);

    for (int i = 1; i < (int)g.size(); i ++) {
        i64 f0 = g[i].fi; i64 f1 = g[i].se;
        i64 pre0 = g[i - 1].fi; i64 pre1 = g[i - 1].se;

        i64 cost0 = std::min(dp0 + std::abs(pre0 - f1), dp1 + std::abs(pre1 - f1)) + (f1 - f0);
        i64 cost1 = std::min(dp0 + std::abs(pre0 - f0), dp1 + std::abs(pre1 - f0)) + (f1 - f0);

        dp0 = cost0;
        dp1 = cost1;
    }

    i64 tot = std::min(dp0 + std::abs(g.back().fi - By), dp1 + std::abs(g.back().se - By));
    i64 ans = (Bx - Ax) + tot;

    std::cout << ans << '\n';
    
    /*太好了，这回只花998244353min就打完了!
    真好。记得多手造几组。ACM拍什么拍。 */
/*
Test Sample

4
1 2 3 5 2
4
4
3 1 3 5 2
3 4 3
5 4 1
6 1 2 7 3
5 2 3 5 5 3
6 4 3 1 4 1
5 6 9 8 6
7 7 7 7 7
3 1 8 8 3

6
13
19
15


*/
}
/*-----------------------------Algostruggler----------------------------------*/
signed main() {
#ifdef LOCAL
    freopen("A.in", "r", stdin);
#endif // LOCAL

    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

    /*std::cout << std::fixed << std::setprecision(9);
    std::cerr << std::fixed << std::setprecision(9);*/

    int _ = 1;
    for (std::cin >> _; _; _--)
        VioletEverGraden();

    return 0;
}