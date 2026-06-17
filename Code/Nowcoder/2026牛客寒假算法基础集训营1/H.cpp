/*
* @Author: AlgoStruggler
* @Create Time: 2026-02-03 15:09:27
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
/*----------------------------------SORT_AND_UNIQUE-----------------------------------*/
const double eps = 1e-9;
constexpr int INF = 0x3f3f3f3f;
constexpr i64 LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr i64 mod = 998244353;
constexpr i64 MOD = 1e9 + 7;
constexpr int MAXN = 0;
/*-----------------------------------MY_CODE_BEGIN------------------------------------*/
static inline void VioletEverGraden() {
    int n;
    std::cin >> n;

    std::vector<i64> a(n + 1);
    for (int i = 1; i <= n; i ++) {
    	std::cin >> a[i];
    }

    std::vector<i64> dp(n + 1, 0);
    std::vector<i64> pre(n + 1, 0);
    dp[0] = 1;pre[0] = 1;
    
    int cnt[32] = {0};
    int bit = 0;
    int L = 1;

    for (int R = 1; R <= n; R ++) {
        for (int i = 0; i < 31; i ++) {
            if ((a[R] >> i) & 1) {
                cnt[i] ++;
                if (cnt[i] == 2) {
                    bit ++;
                }
            }
        }

        while (bit > 0) {
            for (int j = 0; j < 31; j ++) {
                if ((a[L] >> j) & 1) {
                    cnt[j]--;
                    if (cnt[j] == 1) {
                        bit --;
                    }
                }
            }
            L ++;
        }

        int cur = pre[R - 1];
        if (L - 2 >= 0) {
            cur = (cur - pre[L - 2] + mod) % mod;
        }

        dp[R] = cur;
        pre[R] = (pre[R - 1] + dp[R]) % mod;
    }

    std::cout << dp[n] << '\n';
    
    /* 愿幸运女神与最纯粹的前行者同在。 */
/*
Test Sample

3
2
1 2
3
1 2 3
4
1 2 0 4

2
2
8


*/
}
/*---------------------------------Algostruggler--------------------------------------*/
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