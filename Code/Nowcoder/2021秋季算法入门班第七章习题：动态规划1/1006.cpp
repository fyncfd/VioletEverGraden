/*
* @Author: AlgoStruggler
* @Create Time: 2026-02-13 01:08:13
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
    int W, H;
    std::cin >> W >> H;

    std::vector<std::vector<i64>> f(W + 1, std::vector<i64> (2006, 0));
    int st, pos, v, w;
    int ed = -1;
    while (std::cin >> st >> pos >> v >> w) {
    	if ((H - 1) % v) {
    		continue;
    	}
    	int t = st + (H - 1) / v;
    	f[pos][t] += w;
    	ed = std::max(ed, t);
    }

    std::vector<std::vector<i64>> dp(W + 1, std::vector<i64> (2006, 0));
    std::vector<std::vector<i64>> path(W + 1, std::vector<i64> (2006, 0));
    for (int i = ed; i >= 0; i --) {
    	for (int j = 1; j <= W; j ++) {
    		for (int k = -2; k <= 2; k ++) {
    			int cur = j + k;
    			if (cur < 1 || cur > W) {
    				continue;
    			}
    			if (dp[j][i] < dp[cur][i + 1] + f[j][i]) {
    				dp[j][i] = dp[cur][i + 1] + f[j][i];
    				path[j][i] = k;
    			}
    		}
    	}
    }

    int bg = W / 2 + (W % 2 != 0);
    std::cout << dp[bg][0] << '\n';
    for (int i = 0; i < ed; i ++) {
    	std::cout << path[bg][i] << '\n';
    	bg += path[bg][i];
    }
    
    /* 愿幸运女神与最纯粹的前行者同在。 */
/*
Test Sample

3 3
0 1 2 5 
0 2 1 3
1 2 1 3
1 3 1 4

12
-1
1
1

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