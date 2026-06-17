/*
* @Author: AlgoStruggler
* @Create Time: 2026-01-31 18:54:44
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
    int n;
    std::cin >> n;

    std::vector<i64> a(n + 1);
    for (int i = 1; i <= n; i ++) {
    	std::cin >> a[i];
    }

    std::sort(a.begin() + 1, a.end(), [&](i64 a, i64 b) -> bool {
    	return a < b;
    });

    i64 avg1 = 0; i64 avg2 = 0;
    if (n % 4 == 0) {
    	avg1 = (a[n / 4] + a[n / 4 + 1]) / 2;
    	avg2 = (a[(3 * n) / 4] + a[(3 * n) / 4  + 1]) / 2;
   	} else {
   		avg1 = a[n / 4 + 1];
   		avg2 = a[(3 * n) / 4 + 1];
   	}

   	i64 ans = 0;
   	i64 ans1 = 0; i64 ans2 = 0;
   	if (avg1 == avg2) {
   		int tmp1 = avg1 - 1;
   		for (int i = 1; i <= n / 2; i ++) {
            ans1 += abs(a[i] - tmp1);
            ans1 += abs(a[i + n / 2] - avg2);
   		}

   		int tmp2 = avg2 + 1;
   		for (int i = 1; i <= n / 2; i ++) {
            ans2 += abs(a[i] - avg1);
            ans2 += abs(a[i + n / 2] - tmp2);
   		}

   		ans = std::min(ans1, ans2);
   		std::cout << ans << '\n';
   	} else {
        for (int i = 1; i <= n / 2; i ++) {
            ans += abs(a[i] - avg1);
            ans += abs(a[i + n / 2] - avg2);
        }
 
        std::cout << ans << '\n';
   	}
    
    /*太好了，这回只花998244353min就打完了!
    真好。记得多手造几组。ACM拍什么拍。 */
/*
Test Sample

3
4
1 1 3 1
4
6 6 6 6
6
1 1 4 4 1 4

2
2
0


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