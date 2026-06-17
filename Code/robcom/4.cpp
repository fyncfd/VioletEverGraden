#include <bits/stdc++.h>

using ll = long long;

#define rep(i, l, r, x) for (int i = l; i <= r; i += x)
const ll LINF = 0x3f3f3f3f3f3f3f3f;

void violet() {
	int n, m;
	std::cin >> n >> m;

	std::vector<int> p(n + 1, 0);
	rep(i, 1, n, 1) {
		std::cin >> p[i];
	}

	struct edge {
		int to; int w;
	};
	std::vector<edge> g[n + 1];
	int __ = m;
	while (__ --) {
		int u, v, w;
		std::cin >> u >> v >> w;

		g[u].push_back({v, w});
	}

	int s, t;
	std::cin >> s >> t;


	struct node {
		int id; int d;
		bool operator < (const node &a) const {
			return d < a.d;
		}
	};
	bool vis[1005];
	std::vector<ll> dis(n + 1, 0);
	std::vector<ll> tim(n + 1, 0);

	auto dijkstra = [&](int s, int t) {
		std::memset(vis, false, sizeof vis);
		rep(i, 1, n, 1) {
			dis[i] = LINF;
		}
		rep(i, 1, n, 1) {
			tim[i] = p[i];
		}

		dis[s] = 0; tim[s] = 0;
		std::priority_queue<node> q;
		q.push({s, dis[s]});
		while (!q.empty()) {
			node pi = q.top();
			q.pop();

			if (vis[pi.id]) {
				continue;
			}

/*			if (pi.id == t) {
				break;
			}*/

			vis[pi.id] = true;

			for (auto x : g[pi.id]) {
				if (dis[x.to] > dis[pi.id] + x.w) {
					dis[x.to] = dis[pi.id] + x.w;
					tim[x.to] = std::min(tim[pi.id], tim[x.to]);
					q.push({x.to, dis[x.to]});
				}
			}
		}
	};

	dijkstra(s, t);

	std::cout << tim[t] << ' ' << dis[t] << '\n';
}

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int _ = 1;
	//for (std::cin >> _; _; _ --)
		violet();

	return 0;
}