/*
* @Author: AlgoStruggler
* @Create Time: 2026-03-29 15:00:41
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
	int n;
	std::cin >> n;
/*
* 倍增法求LCA。
* @Author: AlgoStruggler
* @Create Time: 2026-02-04 17:50:48
* "To the Splendor of ACM-ICPC, We Consecrate Our AC Triumphs."
* 愿幸运女神与最纯粹的前行者同在。
*/
	int tot = 1;
	std::vector<int> head(n + 1, -1);
	struct Edge {
		int to; int nxt; int w;
	};
	std::vector<Edge> G(2 * n + 10);
	auto AddEdge = [&](int u, int v, int w = 0) -> void {
		G[tot].to = v;
		G[tot].nxt = head[u];
		G[tot].w = w;
		head[u] = tot ++;
	};

	int __ = n - 1;
	while (__ --) {
		int u, v;
		std::cin >> u >> v;
		AddEdge(u, v); AddEdge(v, u);
	}

	std::vector<int> p(n + 1);
	for (int i = 1; i <= n; i ++) {
		std::cin >> p[i];
	}

	std::vector<std::vector<int>> fa(31, std::vector<int> (n + 1, 0));
	std::vector<int> dep(n + 1, 0);
	auto dfs = [&](auto &&dfs, int u, int p) -> void {
		fa[0][u] = p;
		dep[u] = dep[p] + 1;

		for (int i = 1; i <= 30; i ++) {
			fa[i][u] = fa[i - 1][fa[i - 1][u]];
		}

		for (int i = head[u]; ~i; i = G[i].nxt) {
			int v = G[i].to;
			if (v == p) {
				continue;
			}
			dfs(dfs, v, u);
		}
	};

	dfs(dfs, 1, 0);

	auto LCA = [&](int u, int v) -> int {
		if (dep[u] > dep[v]) {
			std::swap(u, v);
		}
		int dif = dep[v] - dep[u];
		for (int i = 0; dif; dif >>= 1, i ++) {
			if (dif & 1) {
				v = fa[i][v];
			}
		}

		if (u == v) {
			return u;
		}

		for (int i = 30; i >= 0; i --) {
			if (fa[i][u] != fa[i][v]) {
				u = fa[i][u];
				v = fa[i][v];
			}
		}

		return fa[0][u];
	};

    auto dist = [&](int u, int v) -> int {
        int l = LCA(u, v);
        return dep[u] + dep[v] - 2 * dep[l];
    };

    int L = p[1], R = p[1];
    int ans = 1;
    for (int i = 2; i <= n; i ++) {
        int x = p[i];
        if (L == R) {
            R = x;
            ans = i;
        } else {
            if (dist(L, x) + dist(x, R) == dist(L, R)) {
                ans = i;
            } else if (dist(x, L) + dist(L, R) == dist(x, R)) {
                L = x;
                ans = i;
            } else if (dist(x, R) + dist(R, L) == dist(x, L)) {
                R = x;
                ans = i;
            } else {
                break;
            }
        }
    }
    
    std::cout << ans << "\n";
/*
愿幸运女神与最纯粹的前行者同在。 
Test Sample

3
5
1 2
2 3
2 4
4 5
1 3 2 5 4
5
1 2
2 3
3 4
4 5
2 4 1 5 3
6
1 2
1 3
1 4
1 5
1 6
2 3 1 4 5 6

3
5
3


*/
}

signed main() {
#ifdef Algostruggler
    freopen("A.in", "r", stdin);
#endif // Algostruggler

    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

    // std::cout << std::fixed << std::setprecision(12), std::cerr << std::fixed << std::setprecision(12);

    for (int _ = [&]() -> int { int T; std::cin >> T; return T; }(); _; _ --)
        VioletEverGraden();

    return 0;
}