/*
* @Author: AlgoStruggler
* @Create Time: 2026-02-14 20:11:01
* "To the Splendor of ACM-ICPC, We Consecrate Our AC Triumphs."
*/
#pragma GCC optimize("O3,unroll-loops,Ofast,inline")
#include "bits/stdc++.h"

using i64 = int64_t;
using i128 =  __int128_t;

using u32 = uint32_t;
using u64 = uint64_t;
using u128 = __uint128_t;

using f32 = float;
using f64 = double;
using f80 = long double;

constexpr int INF = 0x3f3f3f3f;
constexpr i64 LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr i64 mod = 998'244'353LL;
constexpr i64 MOD = 1e9 + 7;

static inline void VioletEverGraden() {
    int N;
    std::cin >> N;

    std::vector<int> A(N + 1);
    for (int i = 1; i <= N; i ++) {
    	std::cin >> A[i];
    }

    std::vector<int> ans(N + 1);
    for (int i = N; i >= 1; --i) {
        if (A[i] == i) {
            ans[i] = i;
        } else {
            ans[i] = ans[A[i]];
        }
    }

    for (int i = 1; i <= N; ++i) {
        std::cout << ans[i] << " \n"[i == N];
    }
/*
愿幸运女神与最纯粹的前行者同在。 
Test Sample

7
2 4 7 5 5 6 7

5 5 7 5 5 6 7

5
1 2 3 4 5

1 2 3 4 5

15
11 3 10 7 15 10 10 11 11 13 11 12 14 14 15

11 14 14 14 15 14 14 11 11 14 11 12 14 14 15


*/
}

signed main() {
#ifdef Algostruggler
    freopen("A.in", "r", stdin);
#endif // Algostruggler

    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

    // std::cout << std::fixed << std::setprecision(12), std::cerr << std::fixed << std::setprecision(12);

    // for (int _ = [&]() -> int { int T; std::cin >> T; return T; }(); _; _ --)
        VioletEverGraden();

    return 0;
}