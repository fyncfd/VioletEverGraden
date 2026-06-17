/*
* @Author: AlgoStruggler
* @Create Time: 2026-04-14 19:56:57
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

    std::vector<std::vector<int>> dp(N + 1, std::vector<int> (N + 1, INF));
    for (int i = 1; i <= M; i ++) {
    	int u, v, w;
    	std::cin >> u >> v >> w;
    	dp[u][v] = w; dp[v][u] = w;
    }

    for (int k = 1; k <= N + 1; k ++) {
    	for (int i = 0; i <= N; i ++) {
    		for (int j = 0; j <= N; j ++) {
    			dp[i][j] = std::min(dp[i][j], dp[i][k] + dp[k][j]);
    		}
    	}
    }

    int K;
    std::cin >> K;

    for (int i = 1; i <= K; i ++) {
    	int n;
    	// std::vector<int> V(n + 1);
    	std::vector<int> vis(N + 1, 0);
    	std::vector<int> ans;
    	int pre = 0; int sum = 0;
    	for (int i = 1; i <= n; i ++) {
    		int V;
    		std::cin >> V;
    		if (!vis[V]) {
    			vis[V] ++;
    			sum += dp[pre][V];
    			pre = V;
    			
    		} else {
    			break;
    		}
    	}
    }
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