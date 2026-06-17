/*
* @Author: AlgoStruggler
* @Create Time: 2026-02-06 17:27:36
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
    int n, d, k;
    std::cin >> n >> d >> k;

    int __ = k;
    std::vector<int> dif(n + 2, 0);
    while (__ --) {
    	i64 L, R;
    	std::cin >> L >> R;
        L = std::max(1LL, L - d + 1LL);
        R = std::min(R, n - d + 1LL);
    	dif[L] ++; dif[R + 1] --;
    }


    std::vector<int> seg(n + 1, 0);
    for (int i = 1; i <= n - d + 1; i ++) {
    	seg[i] = seg[i - 1] + dif[i];
    }

    int max = 0; int min = INF;
    int ans1 = 0; int ans2 = 0;
    for (int i = n - d + 1; i >= 1; i --) {
    	if (seg[i] >= max) {
    		max = seg[i];
    		ans1 = i;
    	}
    	if (seg[i] <= min) {
    		min = seg[i];
    		ans2 = i;
    	}
    }

    std::cout << ans1 << ' ' << ans2 << '\n';
    
    /* 愿幸运女神与最纯粹的前行者同在。 */
/*
Test Sample

6
2 1 1
1 2
4 1 2
1 2
2 4
7 2 3
1 2
1 3
6 7
5 1 2
1 2
3 5
9 2 1
2 8
9 2 4
7 9
4 8
1 3
2 3

1 1
2 1
1 4
1 1
1 1
3 4


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