/*
* @Author: AlgoStruggler
* @Create Time: 2026-01-30 19:36:59
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
    int n; i64 m;
    std::cin >> n >> m;

    std::vector<i64> a(n + 1);
    for (int i = 1; i <= n; i ++) {
        std::cin >> a[i];
    }

    i64 sum = std::accumulate(a.begin() + 1, a.end(), 0LL);

    std::vector<pll> b(n + 1);
    for (int i = 1; i <= n; i ++) {
        b[i] = {a[i], i};
    }
    std::sort(b.begin() + 1, b.end(), [&](pll a, pll b) -> bool {
        if (a.fi == b.fi) {
            return a.se < b.se;
        } else {
            return a.fi < b.fi;
        }
    });
    
    std::vector<i64> pre(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        pre[i] = pre[i - 1] + b[i].fi;
    }
    
    std::vector<i64> ans(n + 1);
    for (int i = 1; i <= n; i ++) {
        i64 x = b[i].fi;
        i64 p = m - x;
        
        int pos = std::upper_bound(b.begin() + 1, b.end(), pll{p, n + 1}, [&](const pll &p1, const pll &p2) {
                return p1.fi < p2.fi;
            }) - b.begin() - 1;
        
        i64 f1 = 0, f2 = 0;
        if (pos >= 1) {
            f1 = pos;
            f2 = pre[pos];
            if (i <= pos) {
                f1 --;
                f2 -= x;
            }
        }
        
        i64 res = x * (f1 + 1) + f2 - sum;
        ans[b[i].se] = res;
    }
    
    for (int i = 1; i <= n; i ++) {
        std::cout << ans[i] << " \n"[i == n];
    }
    
    /*太好了，这回只花998244353min就打完了!
    真好。记得多手造几组。ACM拍什么拍。 */
/*
Test Sample

3
4 9
3 4 5 6
6 20
1 15 6 3 10 0
7 1
1 1 1 1 1 1 1

9 2 4 -3
5 29 9 15 25 0
-6 -6 -6 -6 -6 -6 -6


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