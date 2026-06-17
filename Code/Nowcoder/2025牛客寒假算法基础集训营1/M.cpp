/*
* @Author: AlgoStruggler
* @Create Time: 2026-01-31 15:28:22
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
    int n;
    std::cin >> n;

    struct pii { i64 num; int pos; };
    std::vector<pii> a(n + 2, { LINF, 0 });
    std::vector<i64> b(n + 1);
    for (int i = 1; i <= n; i ++) {
        std::cin >> a[i].num;
        b[i] = a[i].num;
        a[i].pos = i;
    }

    std::sort(a.begin() + 1, a.end(), [&](pii a, pii b) -> bool {
            return a.num < b.num;
    });

    int L = a[1].pos; int R = a[1].pos;
    i64 max = std::max(a[1].num * 2, a[n].num);
    i64 ans = max - std::min(a[1].num * 2, a[2].num);
    for (int i = 2; i <= n; i ++) {
        while (a[i].pos < L) {
            L --;
            max = std::max(max, b[L] * 2);
        }
        while (a[i].pos > R) {
            R ++;
            max = std::max(max, b[R] * 2);
        }

        ans = std::min(ans, max - std::min(a[1].num * 2, a[i + 1].num));
    }

    std::cout << ans << '\n';
    
    /*太好了，这回只花998244353min就打完了!
    真好。记得多手造几组。ACM拍什么拍。 */
/*
Test Sample

2
3 4

2

4
1 2 4 3

2


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
    //for (std::cin >> _; _; _--)
        VioletEverGraden();

    return 0;
}