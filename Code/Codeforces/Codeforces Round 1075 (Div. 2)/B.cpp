/*
* @Author: AlgoStruggler
* @Create Time: 2026-01-23 22:46:16
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
struct pii { int a; int b; int c; };
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
    int n; i64 x;
    std::cin >> n >> x;

    i64 ans = LINF;
    for (int i = 1; i <= n; i ++) {
        i64 a, b, c;
        std::cin >> a >> b >> c;

        if (a * (b - 1) >= x) {
            ans = std::min(ans, 0LL);
            continue;
        }

        if (a * b <= c) {
            continue;
        }

        i64 num = x - a * (b - 1);
        i64 den = a * b - c;
        i64 r = (num + den - 1) / den;
        ans = std::min(ans, r);
    }

    if (ans == LINF) {
        std::cout << -1 << '\n';
    } else {
        std::cout << ans << '\n';
    }

    /*太好了，这回只花998244353min就打完了!
    真好。记得多手造几组。ACM拍什么拍。 */
/*
Test Sample

6
1 1
3 3 3
1 7
4 2 5
2 4
1 2 3
2 2 4
5 8
12 1 11
10 1 4
1 1 3
1 2 5
2 1 7
1 1000000000000000000
1000000 4 654321
1 10
2 2 1

0
1
-1
2
298892990032
3

1
1 7
4 2 5

1

1
1 1000000000000000000
1000000 4 654321

298892990032


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