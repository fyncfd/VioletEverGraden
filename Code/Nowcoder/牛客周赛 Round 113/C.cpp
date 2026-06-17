/*
* @Author: AlgoStruggler
* @Create Time: 2026-02-11 15:59:30
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

template <typename T>
constexpr T ksm(T a, u64 b) {
    T res = 1;
    while (b) {
        if (b & 1) {
            res *= a;
        }
        a *= a;
        b >>= 1;
    }
    return res;
}

static inline void VioletEverGraden() {
    int n;
    std::cin >> n;

    int f2 = 0; int f3 = 0; int f5 = 0;
    for (int i = 1; i <= n; i ++) {
    	int x;
    	std::cin >> x;

    	while (x % 2 == 0) {
    		f2 ++;
    		x /= 2;
    	}

    	while (x % 3 == 0) {
    		f3 ++;
    		x /= 3;
    	}

    	while (x % 5 == 0) {
    		f5 ++;
    		x /= 5;
    	}
    }

    int ans = std::min({f2, f3, f5});

    std::cout << ans << '\n';
    
    /* 愿幸运女神与最纯粹的前行者同在。 */
/*
Test Sample

4
30 15 2 7

2


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
    //for (std::cin >> _; _; _--)
        VioletEverGraden();

    return 0;
}