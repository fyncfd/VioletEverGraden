/*
* @Author: AlgoStruggler
* @Create Time: 2026-01-23 19:03:14
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
    int n, k;
    std::cin >> n >> k;

    std::vector<int> m(n + 1);
    for (int i = 1; i <= n; i ++) {
    	std::cin >> m[i];
    }

    i64 sum1 = 0; i64 sum2 = 0;
    for (int i = 1; i <= n; i ++) {
    	sum1 += m[i];
    	sum2 += m[i] * i;
    }

    bool ok = false;
    for (int i = 0; i < (1LL << n); i ++) {
    	int cnt = __builtin_popcount(i);
        if (cnt != k) {
        	continue;
        }
        
        i64 p1 = 0; i64 p2 = 0;
        for (int j = 1; j <= n; j ++) {
            if (i >> (j - 1) & 1) {
                p1 += m[j];
                p2 += m[j] * j;
            }
        }

        if (p2 * sum1 == sum2 * p1) {
            ok = true;
            break;
        }
    }

    if (ok) {
    	std::cout << "Yes\n";
    } else {
    	std::cout << "No\n";
    }
    
    /*太好了，这回只花998244353min就打完了!
    真好。记得多手造几组。ACM拍什么拍。 */
/*
Test Sample

2 1
1 1

No

3 1
1 1 1

Yes


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