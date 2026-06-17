#include <bits/stdc++.h>

using ll = long long;
#define int long long
#define rep(i, l, r, x) for (int i = l; i <= r; i += x)
#define dep(i, l, r, x) for (int i = l; i >= r; i -= x)
const int MAXN = 2e5 + 10;
const ll INF = 0x3f3f3f3f3f3f3f3f;
int fa[MAXN];
int find(int x) {
	if (fa[x] == x) {
		return fa[x];
	} else {
		return find(fa[x]);
	}
}
void merge(int x, int y) {
	int rx = find(x); int ry = find(y);

	if (rx != ry) {
		fa[ry] = rx;
	}
}

void violet() {
	int n, m, k, t;
	std::cin >> n >> m >> k >> t;

	std::vector<int> head(n + 1, -1);
	struct edge {
		int to; int nxt;
		int w;
	};
	std::vector<edge> g(2 * m + 1);
	int ttt = 1;
	auto addedge = [&](int u, int v, int w) -> void {
		g[ttt].to = v; g[ttt].nxt = head[u];
		g[ttt].w = w; head[u] = ttt ++;
	};

	int __ = m;
	while (__ --) {
		int u, v, w;
		std::cin >> u >> v >> w;

		addedge(u, v, w);
		addedge(v, u, w);
	}

	std::vector<int> topo; topo.push_back(-1);
	bool vis[MAXN] = {false};
	rep(i, 1, k, 1) {
		int d; 
		std::cin >> d;
		vis[d] = true;
	}

	std::vector<int> head1(n + 1, -1);
	std::vector<edge> g1(2 * m + 1);
	int ttt1 = 1;
	auto addedge1 = [&](int u, int v) -> void {
		g1[ttt1].to = v; g1[ttt1].nxt = head1[u];
		head1[u] = ttt1 ++;
	};
	std::vector<int> deg(n + 1, 0);

	int ___ = t;
	while (___ --) {
		int x, y;
		std::cin >> x >> y;
		merge(x, y);
/*		addedge1(x, y);
		deg[y] ++*/;
	}

	auto toposort = [&]() -> void {
		std::priority_queue<int> heap;
		rep(i, 1, n, 1) {
			if (!deg[i]) {
				heap.push(i);
			}
		}

		while (!heap.empty()) {
			auto node = heap.top();
			heap.pop();
			topo.push_back(node);
			for (int i = head1[node]; i != -1; i = g[i].nxt) {

				deg[g1[i].to] --;
				if (!deg[g[i].to]) {
					heap.push(g[i].to);
				}
			}
		}
	};

	toposort();

	rep(i, 1, k, 1) {
		std::cout << topo[i] << " \n"[i == k];
	}

	std::vector<ll> dis(n + 1, INF);
	auto dijkstra = [&](int s) {
		
	}

}

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int _ = 1;
	for (std::cin >> _; _; _ --) 
		violet();

	return 0;
}

/*
5 3 11
#..
...
...
2 1 1
1
2 1 1
1
2 1 1
1
2 1 1
1
2 1 1
1
2 1 1
*