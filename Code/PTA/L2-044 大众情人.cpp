/*
* @Author: AlgoStruggler
* @Create Time: 2026-04-15 13:17:11
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

    std::vector<int> f, m;
    std::vector<std::vector<int>> dp(N + 1, std::vector<int> (N + 1, INF));
    for (int i = 1; i <= N; i ++) {
    	char c;
    	std::cin >> c;
    	if (c == 'F') {
    		f.push_back(i);
    	} else {
    		m.push_back(i);
    	}

    	int K;
    	std::cin >> K;

    	for (int j = 1; j <= K; j ++) {
    		int v, w;
    		scanf("%d:%d", &v, &w);
    		dp[i][v] = w;
    		// dp[v][i] = w;
    	}
    }

    for (int k = 1; k <= N; k ++) {
    	for (int i = 1; i <= N; i ++) {
    		for (int j = 1; j <= N; j ++) {
    			dp[i][j] = std::min(dp[i][j], dp[i][k] + dp[k][j]);
    		}
    	}
    }

    struct pii {
    	int id, w;
    };

    std::vector<pii> ansf;
    for (int i = 0; i < f.size(); i ++) {
    	int sumf = 0;
    	for (int j = 0; j < m.size(); j ++) {
    		sumf = std::max(dp[m[j]][f[i]], sumf);
    	}
    	ansf.push_back({f[i], sumf});
    }

    std::vector<pii> ansm;
    for (int i = 0; i < m.size(); i ++) {
    	int sumf = 0;
    	for (int j = 0; j < f.size(); j ++) {
    		sumf = std::max(dp[f[j]][m[i]], sumf);
    	}
    	ansm.push_back({m[i], sumf});
    }

    std::sort(ansf.begin(), ansf.end(), [&](pii a, pii b) -> bool {
    	if (a.w == b.w) {
    		return a.id < b.id;
    	}
    	return a.w < b.w;
    });
    std::sort(ansm.begin(), ansm.end(), [&](pii a, pii b) -> bool {
    	if (a.w == b.w) {
    		return a.id < b.id;
    	}
    	return a.w < b.w;
    });

    std::vector<int> ans1;
    for (int i = 0; i < ansf.size(); i ++) {
    	if (ansf[i].w == ansf[0].w) {
    		ans1.push_back(ansf[i].id);
    	}
    }

    std::vector<int> ans2;
    for (int i = 0; i < ansm.size(); i ++) {
    	if (ansm[i].w == ansm[0].w) {
    		ans2.push_back(ansm[i].id);
    	}
    }

    for (int i = 0; i < ans1.size(); i ++) {
    	std::cout << ans1[i] << " \n"[i + 1 == ans1.size()];
    }
    for (int i = 0; i < ans2.size(); i ++) {
    	std::cout << ans2[i] << " \n"[i + 1 == ans2.size()];
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

    // std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

    // std::cout << std::fixed << std::setprecision(12), std::cerr << std::fixed << std::setprecision(12);

    // for (int _ = [&]() -> int { int T; std::cin >> T; return T; }(); _; _ --)
        VioletEverGraden();

    return 0;
}