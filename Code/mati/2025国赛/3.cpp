#include <bits/stdc++.h>

using ll = long long;
#define rep(i, l, r, x) for (int i = l; i <= r; i += x)

void violet() {
	int n; ll m;
	std::cin >> n >> m;

	std::vector<int> a(n + 1);
	rep(i, 1, n, 1) {
		std::cin >> a[i];
	}

	auto check = [&](ll mid) -> bool {
		ll ans = 0;
		rep(i, 1, n, 1) {
			ans += a[i] / mid;
		}

		return ans <= m;
	};

	ll l = 1; ll r = 1e9;
	ll ans = 0;
	while (l <= r) {
		ll mid = (l + r) >> 1;
		if (check(mid)) {
			r = mid - 1;
			ans = mid;
		} else {
			l = mid + 1;
		}
	}

	std::cout << ans << '\n';
}

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int _ = 1;
	for (std::cin >> _; _; _ --) 
		violet();

	return 0;
}