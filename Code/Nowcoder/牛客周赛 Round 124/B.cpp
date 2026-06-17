/*
* @Author: AlgoStruggler
* @Create Time: 2026-02-06 02:18:07
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
    int a, b, c, d, e, f;
    std::cin >> a >> b >> c >> d >> e >> f;

    auto dist2 = [](i64 x1, i64 y1, i64 x2, i64 y2) {
        return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    };
    
    i64 ab2 = dist2(a, b, c, d);
    i64 bc2 = dist2(c, d, e, f);
    i64 ca2 = dist2(e, f, a, b);

    if (ab2 == bc2 and bc2 == ca2) {
    	std::cout << "YES\n";
    } else {
    	std::cout << "NO\n";
    }
    
    /* 愿幸运女神与最纯粹的前行者同在。 */
/*
Test Sample

1 2 3 4 5 6

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
    //for (std::cin >> _; _; _--)
        VioletEverGraden();

    return 0;
}