#include <bits/stdc++.h>

using i64 = long long;
constexpr i64 LINF = 0x3f3f3f3f3f3f3f3f;

#define int long long

void violet() {
	int n;
	std::cin >> n;

	struct pii {
		i64 x, y;
	};
	std::vector<pii> a(n + 1);
	for (int i = 1; i <= n; i ++) {
		std::cin >> a[i].x >> a[i].y;
	}

	std::vector<std::vector<i64>> dis(n + 1, std::vector<i64> (n + 1, 0));
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			dis[i][j] = std::abs(a[i].x - a[j].x) + std::abs(a[i].y - a[j].y);
		}
	}

/*	for (int i = 1; i <= n; i ++) {
		std::cout << dis[1][i] << '\n';
	}*/

	i64 ans = LINF; 
	for (int i = 1; i <= n; i ++) {
		i64 tmp = 0;
		for (int j = 1; j <= n; j ++) {
			tmp = std::max(dis[i][j], tmp);
		}
		ans = std::min(ans, tmp);
	}

	std::cout << ans << '\n';

}

signed main() {
	int _ = 1;
	// std::cin >> _;
	while (_ --) {
		violet();
	}

	return 0;
}