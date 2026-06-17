#include <bits/stdc++.h>

using ll = long long;

int n, m;
char s[1003][1003];
int sx, sy, ex, ey;
bool ok;
int dx[] = {0, 0, 1, 0, -1 };
int dy[] = {0, -1, 0, 1, 0 };

void dfs(int x, int y) {
	if (x == ex and y == ey) {
		ok = true;
	}

	for (int i = 1; i <= 4; i ++) {
		int nx = x + dx[i]; int ny = y + dy[i];

		if (nx >= n or ny >= m or nx <= 0 or ny <= 0) {
			continue;
		}
	}
}

void solve() {
	std::cin >> n >> m;
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			std::cin >> s[i][j];
		}
	}
	std::cin >> sx >> sy >> ex >> ey;

	
}

signed main() {
	std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int _ = 1;
	//std::cin >> _;

	while (_ --) {
		solve();
	}

	return 0;
}