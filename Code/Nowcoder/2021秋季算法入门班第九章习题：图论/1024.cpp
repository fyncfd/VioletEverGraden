/*
* @Author: AlgoStruggler
* @Create Time: 2026-05-09 19:19:19
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

    // std::cout << N << M << '\n';

    std::vector<std::vector<int>> G(N + 1);

	int __ = M;
	std::vector<int> deg(N + 1, 0);
	while (__ --) {
		int u, v;
		std::cin >> u >> v;
		G[u].push_back(v);
		deg[v] ++;
	}

	std::vector<int> topo;
	[&]() -> void {
		std::queue<int> q;
		for (int i = 1; i <= N; i ++) {
			if (deg[i] == 0) {
				q.push(i);
			}
		}

		while (!q.empty()) {
			auto u = q.front();
			q.pop();
			topo.push_back(u);
			for (auto v : G[u]) {
				deg[v] --;
				if (deg[v] == 0) {
					q.push(v);
				}
			}
		}
	}();

	std::vector<std::bitset<1005>> f(N + 1);
	for (int i = (int)topo.size() - 1; i >= 0; i --) {
		auto u = topo[i];
		f[u].set(u);
		for (auto v : G[u]) {
			f[u] |= f[v];
		}
	}

	i64 ans = N * (N - 1) / 2;
	for (int i = 1; i <= N; i ++) {
		ans -= (f[i].count() - 1);
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