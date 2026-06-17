/*
* @Author: AlgoStruggler
* @Create Time: 2026-02-13 00:17:54
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
    i64 n;
    std::cin >> n;

    auto dfs = [&](auto &&dfs, i64 x) -> i64 {
    	if (x <= 1) {
    		return 0;
    	}
    	if (x % 2 == 0) {
    		return dfs(dfs, x / 2) * 2;
    	}
    	return dfs(dfs, x / 2) + dfs(dfs, x / 2 + 1) + 1;
    };

    i64 ans =  dfs(dfs, n);
    std::cout << ans << '\n';
    
    /* 愿幸运女神与最纯粹的前行者同在。 */
/*
Test Sample

1
5

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
    for (std::cin >> _; _; _--)
        VioletEverGraden();

    return 0;
}