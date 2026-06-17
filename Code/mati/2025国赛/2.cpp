#include <bits/stdc++.h>

using ll = long long;
#define rep(i, l, r, x) for (int i = l; i <= r; i += x)

signed main() {
	int n, k;
	std::cin >> n >> k;

	std::vector<ll> a(n + 1, 0);
	rep(i, 1, n, 1) {
		std::cin >> a[i];
	}

	std::map<ll, ll> hash;
	rep(i, 1, n, 1) {
		hash[a[i]] ++;
	}

	ll num = 0; ll ans = 0;
	for (auto x : hash) {
		num ++;
		if (num == k) {
			ans = x.first;
		}
	}

	if (num >= k) {
		std::cout << ans << '\n';
	} else {
		std::cout << -1 << '\n';
	}
	return 0;
}