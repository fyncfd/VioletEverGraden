/*
* @Author: AlgoStruggler
* @Create Time: 2026-01-20 15:22:52
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
    int N;
    std::cin >> N;

    struct pii {
    	i64 W; i64 P;
    };
    std::vector<pii> f(N + 1);
    for (int i = 1; i <= N; i ++) {
    	std::cin >> f[i].W >> f[i].P;
    }

    std::sort(f.begin() + 1, f.end(), [&](pii a, pii b) -> bool {
    	return a.W + a.P < b.W + b.P;
    });

    i64 ans = 0; i64 sum = 0;
    for (int i = 1; i <= N; i ++) {
    	sum += f[i].P;
    }

    i64 tmp = 0;
    for (int i = 1; i <= N; i ++) {
    	tmp += (f[i].P + f[i].W);
    	if (tmp <= sum) {
    		ans ++;
    	}
    }

    std::cout << ans << '\n';
    
    /*太好了，这回只花998244353min就打完了!
    真好。记得多手造几组。ACM拍什么拍。 */
/*
Test Sample

3
3
3 1
4 1
5 9
5
1000000000 1
1000000000 1
1000000000 1
1000000000 1
1000000000 1
10
133180711 458704923
531424946 225863856
141986070 637075158
500770732 289806469
502866767 408857335
559714289 569084545
287444582 992432993
559747907 753133304
432846188 949871298
727072164 756020367

2
0
6


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