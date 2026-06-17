#include "bits/stdc++.h"

using i64 = long long;

void VioletEverGraden() {
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
	struct Edge {
		int to; int nxt; int w;
	};
	std::vector<int> head(n + 1, -1);
	std::vector<Edge> G(2 * m + 10);
	auto AddEdge = [&](int u, int v, int w = 0) -> void {
		G[tot].to = v;
		G[tot].nxt = head[u];
		G[tot].w = w;
		head[u] = tot ++;
	};

	int __ = m;
	while (__ --) {
		int u, v, w;
		std::cin >> u >> v;
		// std::cin >> u >> v >> w;
		AddEdge(u, v); AddEdge(v, u);
		// AddEdge(u, v, w); AddEdge(v, u, w);
	}

	for (int u = 1; u <= n; u ++) {
		std::vector<int> tmp;
		for (int i = head[u]; ~i; i = G[i].nxt) {
			int v = G[i].to;
			tmp.push_back(v);
		}
		if (tmp.empty()) {
			std::cout << "None\n";
		} else {
			std::sort(tmp.begin(), tmp.end(), [&](int a, int b) -> bool {
				return a < b;
			});
			for (int i = 0; i < tmp.size(); i ++) {
				std::cout << tmp[i] << " \n"[i == tmp.size() - 1];
			}
		}
	}

/*
Test Sample

3 3
1 2
2 3
3 1

2 3
1 3
1 2


*/
}

signed main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

	int _ = 1;
    // for (std::cin >> _; _; _--)
        VioletEverGraden();

    return 0;
}