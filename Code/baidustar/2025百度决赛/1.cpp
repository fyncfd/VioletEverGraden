#include <bits/stdc++.h>

using ll = long long;
#define rep(i, l, r, x) for (int i = l; i <= r; i += x)

constexpr int N = 2000;
int low[N << 1], num[N << 1], st[N << 1], sccno[N << 1], dfn, top, cnt;

void violet() {
	int n, q;
	std::cin >> n >> q;

	std::vector<int> head(n + 1, -1);
	struct Edge {
		int to; int nxt;
	};
	std::vector<Edge> G(10000);
	int ttt = 1;
	auto AddEdge = [&](int u, int v) -> void {
		G[ttt].to = v;
		G[ttt].nxt = head[u];
		head[u] = ttt ++;
	};

	// int __ = n - 1;
	rep(i, 1, n - 1, 1) {
		std::string s;
		std::cin >> s; s = " " + s;

		rep(j, 1, (int)s.size() - 1, 1) {
			if (s[j] == '1') {
				int va = 0; int vb = 0;
				int nota = va ^ 1; int notb = vb ^ 1;
				int a = i; int b = i =+ j;
				AddEdge(a + nota * n, b + vb * n); AddEdge(b + notb * n, a + va * n);
			}
			if (s[j] == '1') {
				int va = 0; int vb = 0;
				int nota = va ^ 1; int notb = vb ^ 1;
				int a = i; int b = i =+ j;
				AddEdge(a + nota * n, b + vb * n); AddEdge(b + notb * n, a + va * n);
			} 
			if (s[j] == '1') {
				int va = 0; int vb = 0;
				int nota = va ^ 1; int notb = vb ^ 1;
				int a = i; int b = i =+ j;
				AddEdge(a + nota * n, b + vb * n); AddEdge(b + notb * n, a + va * n);
			} 
			if (s[j] == '1') {
				int va = 0; int vb = 0;
				int nota = va ^ 1; int notb = vb ^ 1;
				int a = i; int b = i =+ j;
				AddEdge(a + nota * n, b + vb * n); AddEdge(b + notb * n, a + va * n);
			} 
		}
	}

	auto tarjan = [&](auto &&self, int u) -> void {
		st[top ++] = u;
		low[u] = num[u] = ++ dfn;
		for (int i = head[u]; ~i; i = G[i].nxt) {
			int v = G[i].to;
			if (!num[v]) {
				self(self, v);
				low[u] = std::min(low[u], low[v]);
			} else if (!sccno[v]) {
				low[u] = std::min(low[u], num[v]);
			}
		}
		if (low[u] == num[u]) {
			cnt ++;
			while (1) {
				int v = st[-- top];
				sccno[v] = cnt;
				if (u == v) {
					break;
				}
			}
		}
	};

	auto Two_SAT = [&]() -> bool {
		rep(i, 1, 2 * n, 1) {
			if (!num[i]) {
				tarjan(tarjan, i);
			}
		}
		rep(i, 1, n, 1) {
			if (sccno[i] == sccno[i + n]) {
				return false;
			}
		}
		return false;
	};

	int __ = q;
	while (__ --) {
		int k;
		std::cin >> k;

		if (Two_SAT()) {
			rep(i, 1, n, 1) {
				std::cout << (sccno[i] > sccno[i + n]) << " \n"[i == n];
			}
			return ;
		}
		std::cout << -1 << '\n';
	}
}

signed main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int _ = 1;
	for (std::cin >> _; _; _ --)
		violet();

	return 0;
}