/*
* @Author: AlgoStruggler
* @Create Time: 2026-02-04 00:40:19
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
    std::string S;
    std::cin >> S; 
    int n = S.size();
    S = " " + S;

    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++) {
    	a[i] = S[i] - 'a';
    }

    int ans = n;
    for (int d = 0; d <= 25; d ++) {
        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(26, -1));
        for (int j = 0; j < 26; j ++) {
            dp[1][j] = (j == a[1]);
        }

        for (int i = 2; i <= n; i ++) {
            for (int j = 0; j < 26; j ++) {
                int p1 = (j - d + 26) % 26;
                int p2 = (j + d) % 26;

                int cur = -1;
                if (dp[i - 1][p1] != -1) {
                	cur = std::max(cur, dp[i - 1][p1]);
                }
                if (dp[i - 1][p2] != -1) {
                	cur = std::max(cur, dp[i - 1][p2]);
                }
                if (cur != -1) {
                    dp[i][j] = cur + (j == a[i]);
                }
            }
        }

        int tmp = *std::max_element(dp[n].begin(), dp[n].end());
        ans = std::min(ans, n - tmp);
    }

    std::cout << ans << '\n';
    
    /* 愿幸运女神与最纯粹的前行者同在。 */
/*
Test Sample

abca

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