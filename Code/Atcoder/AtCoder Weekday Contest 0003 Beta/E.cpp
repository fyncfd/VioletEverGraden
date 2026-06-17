/*
* @Author: AlgoStruggler
* @Create Time: 2026-02-11 19:56:30
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
    int N, M;
    std::cin >> N >> M;

    std::vector<i64> W(N);
    for (int i = 0; i < N; i++) {
    	std::cin >> W[i];
    }

    std::vector<i64> C(M);
    for (int i = 0; i < M; i++) {
    	std::cin >> C[i];
    }

    std::sort(C.rbegin(), C.rend());

    std::vector<i64> wei(1 << N, 0);
    for (int mask = 0; mask < (1 << N); mask++) {
        for (int i = 0; i < N; i++) {
            if (mask >> i & 1) {
            	wei[mask] += W[i];
            }
        }
    }

    int lo = 0, hi = M;
    int ans = -1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (mid == 0) {
            lo = mid + 1;
            continue;
        }

        std::vector<bool> dp(1 << N, false);
        dp[0] = true;
        for (int k = 0; k < mid; k ++) {
            std::vector<bool> ndp = dp;
            i64 cap = C[k];
            
            for (int mask = 0; mask < (1 << N); mask++) {
                if (!dp[mask]) {
                	continue;
                }
                int ret = ((1 << N) - 1) ^ mask;
                for (int sub = ret; ; sub = (sub - 1) & ret) {
                    if (wei[sub] <= cap) {
                        ndp[mask | sub] = true;
                    }
                    if (sub == 0) break;
                }
            }
            dp.swap(ndp);
        }

        if (dp[(1 << N) - 1]) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    if (ans != -1) {
    	std::cout << "Yes\n";
    } else {
    	std::cout << "No\n";
    }
    
    /* 愿幸运女神与最纯粹的前行者同在。 */
/*
Test Sample

3 2
3 5 2
6 4

No

4 2
10 20 30 40
50 50

Yes

8 3
15 25 30 10 20 35 5 40
80 60 50

Yes


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