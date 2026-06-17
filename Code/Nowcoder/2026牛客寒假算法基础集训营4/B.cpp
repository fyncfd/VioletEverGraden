/*
* @Author: AlgoStruggler
* @Create Time: 2026-02-09 14:05:56
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
    int n, q; i64 s;
    std::cin >> n >> q >> s;

    std::vector<int> t(n + 1);
    for (int i = 1; i <= n; i ++) {
    	std::cin >> t[i];
    }

    std::vector<i64> pre(n + 1, 0);
    for (int i =1; i <= n; i ++) {
    	pre[i] = pre[i - 1] + t[i];
    }

    int __ = q;
    while (__ --) {
    	int x, y;
    	std::cin >> x >> y;
    	i64 ans = s + pre[x - 1] + (y - 1);
    	std::cout << ans << '\n';
    }
    
    /* 愿幸运女神与最纯粹的前行者同在。 */
/*
Test Sample

6 3 0
1 1 4 5 1 4
1 1
3 3
4 4

0
4
9

6 4 8
1 1 4 5 1 4
1 1
3 3
4 4
4 5

8
12
17
18


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