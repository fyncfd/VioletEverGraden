/*
* @Author: AlgoStruggler
* @Create Time: 2026-02-11 00:01:30
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
constexpr int MAXN = 2e5 + 10;

static inline void VioletEverGraden() {
    int n;
    std::cin >> n;

/*
* @Author: AlgoStruggler
* 链式前向星建图，AddEdge函数默认构造无边权的边。
* @Create Time: 2025-02-03 13:10:02
* "To the Splendor of ACM-ICPC, We Consecrate Our AC Triumphs."
* 愿幸运女神与最纯粹的前行者同在。
*/
	int tot = 1;
	struct Edge {
		int to; int nxt; int w;
	};
	std::vector<int> head(n + 1, -1);
	std::vector<Edge> G(2 * n + 10);
	auto AddEdge = [&](int u, int v, int w = 0) -> void {
		G[tot].to = v;
		G[tot].nxt = head[u];
		G[tot].w = w;
		head[u] = tot ++;
	};

	int __ = n;
	std::vector<int> deg(n + 1, 0);
	while (__ --) {
		int u, v, w;
		std::cin >> u >> v;
		// std::cin >> u >> v >> w;
		AddEdge(u, v); AddEdge(v, u);
		deg[u] ++; deg[v] ++;
		// AddEdge(u, v, w); AddEdge(v, u, w);
	}

	std::vector<bool> vis(n + 1, false);
	auto toposort = [&]() -> void {
		std::queue<int> q;
		for (int i = 1; i <= n; i ++) {
			if (deg[i] == 1) {
				q.push(i);
			}
		}

		while (!q.empty()) {
			auto u = q.front();
			q.pop();
			vis[u] = true;

			for (int i = head[u]; ~i; i = G[i].nxt) {
				int v = G[i].to;
				if (deg[v] > 1) {
					deg[v] --;
					if (deg[v] == 1) {
						q.push(v);
					}
				}
			}
		}
	};

	toposort();

	std::vector<int> cyc;
	int st = 0;
	for (int i = 1; i <= n; i ++) {
		if (!vis[i]) {
			st = i;
			// cyc.push_back(st);
			break;
		}
	}

	int cur = st;
	std::vector<bool> vis2(n + 1, false);
	while (true) {
		int u = cur;
		cyc.push_back(cur);
		vis2[u] = true;
		int nxt = -1;
		for (int i = head[u]; ~i; i = G[i].nxt) {
			int v = G[i].to;
			if (!vis[v] and !vis2[v]) {
				nxt = v;
				vis[v] = true;
				break;
			}
		}
		if (nxt != -1) {
			cur = nxt;
		} else {
			break;
		}
	}

/*	for (auto x : cyc) {
		std::cerr << "x : " << x << '\n';
	}*/

	std::vector<int> ans(n + 1, 0);
	int k = cyc.size();
	for (int i = 0; i < k; i ++) {
		int u = cyc[i];
		if (i < k - 1) {
			ans[u] = (i % 2) + 1;
		} else {
			for (int c = 1; c <= 3; c ++) {
				if (c != ans[cyc[i - 1]] and c != ans[cyc[0]]) {
					ans[u] = c;
					break;
				}
			}
		}
	}

	auto bfs = [&]() -> void {
		std::queue<int> q;
		for (auto u : cyc) {
			q.push(u);
		}

		bool vis1[MAXN] = {false};
		std::memset(vis1, false, sizeof vis1);
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			vis1[u] = true;

			for (int i = head[u]; ~i; i = G[i].nxt) {
				int v = G[i].to;
				if (!vis1[v] and ans[v] == 0) {
					ans[v] = ans[u] % 3 + 1;
					q.push(v);
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
    // for (std::cin >> _; _; _--)
        VioletEverGraden();

    return 0;
}