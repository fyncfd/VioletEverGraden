/*
* @Author: AlgoStruggler
* @Create Time: 2026-02-12 00:00:24
* "To the Splendor of ACM-ICPC, We Consecrate Our AC Triumphs."
*/
#define  _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize("O2")
#include "bits/stdc++.h"
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using ldb = long double;
typedef __int128 i128;
typedef unsigned __int128 u128;

const double eps = 1e-9;
constexpr int INF = 0x3f3f3f3f;
constexpr i64 LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr i64 mod = 998244353;
constexpr i64 MOD = 1e9 + 7;
constexpr int MAXN = 0;

static inline void VioletEverGraden() {
    int n;
    std::cin >> n;
    
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++) {
        std::cin >> a[i];
    }

    int S = sqrt(n);
    i64 ans = 0;
    for (int x = 1; x <= S; x ++) {
        for (int j = 1; j <= n; ++j) {
            i64 p = (i64)a[j] * x;
            if (p < j) {
                int i = j - (int)p;
                if (a[i] == x) {
                    ans++;
                }
            }
        }
    }

    for (int y = 1; y <= S; y ++) {
        for (int i = 1; i <= n; i ++) {
            if (a[i] > S) {
                i64 p = (i64)a[i] * y;
                if (i + p <= n) {
                    int j = i + (int)p;
                    if (a[j] == y) {
                        ans++;
                    }
                }
            }
        }
    }

    std::cout << ans << '\n';
    
    /* 愿幸运女神与最纯粹的前行者同在。 */
/*
Test Sample

4
5
1 1 2 100 4
6
2 2 1 1 2 2
10
1 1 2 3 4 1 1 7 3 9
2
1000000000 1000000000

3
7
10
0


*/
}

signed main() {
#ifdef Algostruggler
    freopen("A.in", "r", stdin);
#endif // Algostruggler

    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

    /*std::cout << std::fixed << std::setprecision(9);
    std::cerr << std::fixed << std::setprecision(9);*/

    int _ = 1;
    for (std::cin >> _; _; _--)
        VioletEverGraden();

    return 0;
}