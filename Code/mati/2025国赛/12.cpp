#include <bits/stdc++.h>

using ll = long long;
#define int long long
#define rep(i, l, r, x) for (int i = l; i <= r; i += x)
#define dep(i, l, r, x) for (int i = l; i >= r; i -= x)

void violet() {
	int n, m , q;
	std::cin >> n >> m >> q;

	std::vector<std::vector<char>> c(m + 10, std::vector<char> (m + 10, 0));
	rep(i, 1, m, 1) {
		rep(j, 1, m, 1) {
			std::cin >> c[i][j];
		}
	}

	std::vector<std::vector<int>> g(m + 10, std::vector<int> (m + 10, 0));
	rep(i, 1, m, 1) {
		rep(j, 1, m, 1) {
			if (c[i][j] == '#') {
				g[i][j] = 1;
			}
		}
	}

	std::vector<std::vector<int>> ans(n + 10, std::vector<int> (n + 10, 0));
	ll num = 0;
	int __ = q;
	while (__ --) {
		int op;
		std::cin >> op;
		if (op == 1) {
			num ++;
		} else {
			int x, y;
			std::cin >> x >> y;
			if (num % 4 == 0 ) {
				int nx = 1;
				//std::cout << num << "???\n";
				for (int i = x; i <= x + m - 1; i ++) {
					int ny = 1;
					for (int j = y; j <= y + m - 1; j ++) {
						ans[i][j] += g[nx][ny];
						//std::cout << g[nx][ny] << ' ';
						ny ++;
					}
					//std::cout << '\n';
					nx ++;
				}
			} else if (num % 4 == 3) {
				int ny = m;
				//std::cout << num << "???\n";
				for (int i = x; i <= x + m - 1; i ++) {
					int nx = 1;
					for (int j = y; j <= y + m - 1; j ++) {
						ans[i][j] += g[nx][ny];
						//std::cout << g[nx][ny] << ' ';
						nx ++;
					}
					//std::cout << '\n';
					ny --;
				}
			} else if (num % 4 == 2) {
				int nx = m;
				//std::cout << num << "???\n";
				for (int i = x; i <= x + m - 1; i ++) {
					int ny = m;
					for (int j = y; j <= y + m - 1; j ++) {
						ans[i][j] += g[nx][ny];
						//std::cout << g[nx][ny] << ' ';
						ny --;
					}
					//std::cout << '\n';
					nx --;
				}
			} else if (num % 4 == 1) {
				int ny = 1;
				//std::cout << num << "???\n";
				for (int i = x; i <= x + m - 1; i ++) {
					int nx = m;
					for (int j = y; j <= y + m - 1; j ++) {
						ans[i][j] += g[nx][ny];
						//std::cout << g[nx][ny] << ' ';
						nx --;
					}
					//std::cout << '\n';
					ny ++;
				}
			}
		}
		//std::cout << num << "???\n";
	}

	//std::cout << num << '\n';

	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			std::cout << ans[i][j] << ' ';
		}
		std::cout << '\n';
	}
}

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int _ = 1;
	//for (std::cin >> _; _; _ --) 
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
*/