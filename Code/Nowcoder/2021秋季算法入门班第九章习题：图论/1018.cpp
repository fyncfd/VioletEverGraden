/*
* @Author: AlgoStruggler
* @Create Time: 2026-05-07 14:32:21
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
    int N, M;
    std::cin >> N >> M;

    std::vector<int> a(M + 1);
    for (int i = 1; i <= M; i ++) {
    	std::cin >> a[i];
    }

    std::vector<std::vector<int>> f(N + 1, std::vector<int> (N + 1, INF));
    for (int i = 1; i <= N; i ++) {
    	for (int j = 1; j <= N; j ++) {
    		int x;
    		std::cin >> x;
    		f[i][j] = x;
    	}
    }

    for (int k = 1; k <= N; k ++) {
    	for (int i = 1; i <= N; i ++) {
    		for (int j = 1; j <= N; j ++) {
    			f[i][j] = std::min(f[i][j], f[i][k] + f[k][j]);
    		}
    	}
    }

    int ans = 0;
    for (int i = 2; i <= M; i ++) {
    	ans += f[a[i - 1]][a[i]];
    }

    std::cout << ans << '\n';
/*
愿幸运女神与最纯粹的前行者同在。 
Test Sample

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