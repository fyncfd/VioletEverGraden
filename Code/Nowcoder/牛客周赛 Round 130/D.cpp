/*
* @Author: AlgoStruggler
* @Create Time: 2026-02-04 00:20:32
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

const double eps = 1e-9;
constexpr int INF = 0x3f3f3f3f;
constexpr i64 LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr i64 mod = 998244353;
constexpr i64 MOD = 1e9 + 7;
constexpr int MAXN = 0;

static inline void VioletEverGraden() {
    i64 a, b;
    std::cin >> a >> b;

    int x = b; int y = 9;
    int fac = std::gcd(x, y);

	if (b == 0) {
	    if (a == 1) {
	        std::cout << "1 100\n";
	    } else {
	        std::cout << "1 10\n";
	    }
	    return;
	}

	if (b == 9) {
		if (a & 1) {
			std::cout << "10 11\n";
		} else {
			std::cout << "1 11\n";
		}
		return ;
	}

    std::cout << x / fac << ' ' << y / fac << '\n';
    
    /* 愿幸运女神与最纯粹的前行者同在。 */
/*
Test Sample

3
1 5
2 3
5 7

5 9
1 3
7 9


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