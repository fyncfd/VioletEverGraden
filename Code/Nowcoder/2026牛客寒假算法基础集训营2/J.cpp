/*
* @Author: AlgoStruggler
* @Create Time: 2026-02-05 16:23:11
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
	int n, m;
	std::cin >> n >> m;

/*
* @Author: AlgoStruggler
* 链式前向星建图，AddEdge函数默认构造无边权的边。
* @Create Time: 2025-02-03 13:10:02
* "To the Splendor of ACM-ICPC, We Consecrate Our AC Triumphs."
* 愿幸运女神与最纯粹的前行者同在。
*/
	int tot = 1;
	std::vector<int> head(n + 1, -1);
	struct Edge {
		int to; int nxt; int w;
	};
	std::vector<Edge> G(2 * m + 10);
	auto AddEdge = [&](int u, int v, int w = 0) -> void {
		G[tot].to = v;
		G[tot].nxt = head[u];
		G[tot].w = w;
		head[u] = tot ++;
	};

	int __ = m;
	std::vector<int> deg(n + 1, 0);
	while (__ --) {
		int u, v, w;
		std::cin >> u >> v;
		// std::cin >> u >> v >> w;
		AddEdge(u, v); AddEdge(v, u);
		// AddEdge(u, v, w); AddEdge(v, u, w);
		deg[u] ++; deg[v] ++;
	}

	std::map<int, std::deque<int>> mp;
	for (int i = 1; i <= n; i ++) {
		mp[deg[i]].push_back(i);
	}

	std::vector<int> ans(n + 1), dis(n + 1, INF);
	auto bfs = [&]() -> void {
		for (auto &[x, q] : mp | std::views::reverse) {
			for (auto &i : q) {
				if (dis[i] == INF) {
					dis[i] = -1;
				}
				ans[i] = dis[i];
				dis[i] = 0;
			}
			while (q.size()) {
				int u = q.front();
				q.pop_front();

				for (int i = head[u]; ~i; i = G[i].nxt) {
					int v = G[i].to;
					if (deg[v] > x) {
						continue;
					}
					if (dis[v] > dis[u] + 1) {
						if (dis[v] > dis[u] + 1) {
							dis[v] = dis[u] + 1;
							q.push_back(v);
						}
					}
				}
			}
		}
	};

	bfs();

	for (int i = 1; i <= n; i ++) {
		std::cout << ans[i] << " \n"[i == n];
	}
    
    /* 愿幸运女神与最纯粹的前行者同在。 */
/*
Test Sample

5 4
2 3
3 4
4 5
3 5

-1 1 -1 1 1

5 6
1 2
2 3
3 4
4 5
1 5
2 4

1 -1 1 -1 1


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