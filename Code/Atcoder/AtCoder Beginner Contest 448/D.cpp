/*
* @Author: AlgoStruggler
* @Create Time: 2026-03-07 20:37:36
* "To the Splendor of ACM-ICPC, We Consecrate Our AC Triumphs."
*/
#pragma GCC optimize("O3,unroll-loops,Ofast,inline")
#include "bits/stdc++.h"

using i64 = long long;
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
#define int long long
static inline void VioletEverGraden() {
    int N;
    std::cin >> N;

    std::vector<i64> A(N + 1);;
    for (int i = 1; i <= N; i ++) {
    	std::cin >> A[i];
    }

/*
* @Author: AlgoStruggler
* 链式前向星建图，AddEdge函数默认构造无边权的边。
* @Create Time: 2025-02-03 13:10:02
* "To the Splendor of ACM-ICPC, We Consecrate Our AC Triumphs."
* 愿幸运女神与最纯粹的前行者同在。
*/
/*	int tot = 1;
	struct Edge {
		int to; int nxt; int w;
	};
	std::vector<int> head(N + 1, -1);
	std::vector<Edge> G(2 * N + 10);
	auto AddEdge = [&](int u, int v, int w = 0) -> void {
		G[tot].to = v;
		G[tot].nxt = head[u];
		G[tot].w = w;
		head[u] = tot ++;
	};*/

	std::vector<std::vector<int>> G(N + 1);

	int __ = N - 1;
	while (__ --) {
		int u, v, w;
		std::cin >> u >> v;
		// std::cin >> u >> v >> w;
		// AddEdge(u, v); AddEdge(v, u);
		// AddEdge(u, v, w); AddEdge(v, u, w);

		G[u].push_back(v); G[v].push_back(u);
	}

	std::vector<bool> ans(N + 1, false);
	std::unordered_map<int, int> pre;
	std::vector<int> dep(N + 1, 0);

	auto dfs = [&](auto &&dfs, int u, int fa, bool ok) -> void {
		int V = A[u];
		if (pre.count(V)) {
			ok = true;
		}

		int prev = pre[V];
		pre[V] = dep[u];
		ans[u] = ok;

/*		for (int i = head[u]; ~i; i = G[i].nxt) {
			int v = G[i].to;
			if (v == fa) {
				continue;
			}
			dep[v] = dep[u] + 1;
			dfs(dfs, v, u, ok);
		}*/

		for (auto v : G[u]) {
			if (v == fa) {
				continue;
			}
			dep[v] = dep[u] + 1;
			dfs(dfs, v, u, ok);
		}

		if (prev = -1) {
			pre.erase(V);
		} else {
			pre[V] = prev;
		}
	};

	dep[1] = 1;
	dfs(dfs, 1, -1, false);

	for (int i = 1; i <= N; i ++) {
		if (ans[i]) {
			std::cout << "Yes\n";
		} else {
			std::cout << "No\n";
		}
	}
/*
愿幸运女神与最纯粹的前行者同在。 
Test Sample

5
1 3 2 1 2
1 2
1 3
3 4
3 5

No
No
No
Yes
Yes

2
1000000000 1000000000
2 1

No
Yes

10
10 7 3 9 1 3 8 5 7 10
3 6
8 6
6 1
9 7
7 10
5 4
4 2
10 2
1 9

No
Yes
Yes
Yes
Yes
No
No
No
No
Yes


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