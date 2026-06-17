/*
* @Author: AlgoStruggler
* @Create Time: 2026-02-05 14:01:30
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
    i64 a, b, c;
    std::cin >> a >> b >> c;

    int max = std::max({a, b, c});
    int min = std::min({a, b, c});

    if (max <= min + 1) {
    	std::cout << "YES\n";
    } else {
    	std::cout << "NO\n";
    }
    
    /* 愿幸运女神与最纯粹的前行者同在。 */
/*
Test Sample

4
1 1 1
1 1 2
1 1 3
2025 114514 1000000000

YES
YES
NO
NO


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