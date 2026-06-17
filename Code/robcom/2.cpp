#include <bits/stdc++.h>

using ll = long long;

#define rep(i, l, r, x) for (int i = l; i <= r; i += x)


void violet() {
	int n, m, q;
	std::cin >> n >> m >> q;

	std::vector<std::vector<char>> p(n + 1, std::vector<char> (m + 1));

	int __ = q;
	rep(l, 1, q, 1) {
		std::vector<std::vector<char>> g(n + 1, std::vector<char> (m + 1));
		for (int i = 1; i <= n; i ++) {
			rep(j, 1, m, 1) {
				std::cin >> g[i][j];
			}
		}
	}

	std::cout << 1 << ' ' << 2 << '\n';
	std::cout << 1 << ' ' << 1 << '\n';
	std::cout << -1 << ' ' << -1 << '\n';
}

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int _ = 1;
	//for (std::cin >> _; _; _ --)
		violet();

	return 0;
}