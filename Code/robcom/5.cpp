#include <bits/stdc++.h>

using ll = long long;

#define rep(i, l, r, x) for (int i = l; i <= r; i += x)


void violet() {
	int n, k;
	std::cin >> n >> k;

	ll ans = 0;
	int __ = n;
	std::vector<int> c(n + 1, 0);
	int i = 0;
	while (__ --) {
		int t, p;
		std::cin >> t >> p >> c[i];
		i ++;

		ans += t * p;
	}

	int num = 0;
	std::sort(c.begin(), c.end());
	rep(i, 0, k - 1, 1) {
		num += c[i];
	}

	std::cout << ans << ' ' << num << '\n';
}

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int _ = 1;
	//for (std::cin >> _; _; _ --)
		violet();

	return 0;
}