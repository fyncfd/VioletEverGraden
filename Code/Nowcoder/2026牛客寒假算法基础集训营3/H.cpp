/*
* @Author: AlgoStruggler
* @Create Time: 2026-02-07 14:45:21
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
typedef unsigned long long u64;
typedef __int128 i128;
typedef unsigned __int128 u128;

const double eps = 1e-9;
constexpr int INF = 0x3f3f3f3f;
constexpr i64 LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr i64 mod = 998244353;
constexpr i64 MOD = 1e9 + 7;
constexpr int MAXN = 0;

static inline void VioletEverGraden() {
    double xa, ya;
    std::cin >> xa >> ya;

    double xb, yb;
    std::cin >> xb >> yb;

    double C = xa * yb - xb * ya;
    double D = ya - yb;

    if (D == 0) {
    	if (std::fabs(C) == 4) {
    		double x = 0;
    		if (xa == xb) {
    			x = xa + 100;
    		} else {
    			x = xa + 1;
    		}
    		std::cout << x << '\n';
    	} else {
    		std::cout << "no answer\n";
    	}
    } else {
    	double x = (4 - C) / D;
    	std::cout << x << '\n';
    }
    
    /* 愿幸运女神与最纯粹的前行者同在。 */
/*
Test Sample

5 5
-9 -7

-0.500000000


*/
}

signed main() {
#ifdef Algostruggler
    freopen("A.in", "r", stdin);
#endif // Algostruggler

    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

    std::cout << std::fixed << std::setprecision(9);
    std::cerr << std::fixed << std::setprecision(9);

    int _ = 1;
    //for (std::cin >> _; _; _--)
        VioletEverGraden();

    return 0;
}