/*
* @Author: AlgoStruggler
* @Create Time: 2025-12-17 20:12:42
* "To the Splendor of ACM-ICPC, We Consecrate Our AC Triumphs."
*/
#include "bits/stdc++.h"

using ll = long long;
using ull = unsigned long long;

//define int long long


void solve() {
	int n;
	std::cin >> n;

	std::vector<ll> a(n + 10, 0);
	for (int i = 1; i <= n; i ++) {
		std::cin >> a[i];
	}

	ll ans = 0;
	for (int i = 2; i <= n; i += 2) {
		ll max = std::max({a[i - 1], a[i + 1], a[i - 1] + a[i + 1]});
		// std::cout << "max: " << max << '\n';
		if (a[i] < max) {
			int op = max - a[i];
			ans += max - a[i];
			a[i + 1] = std::max(a[i + 1] - op, 0LL);
			max -= a[i + 1];
			if (max > 0) {
				a[i - 1] = std::max(a[i - 1] - op, 0LL);
			}
		}
		// std::cout << "ans: " << ans << '\n';
		// std::cout << "___________\n";
/*		for (int i = 1; i <= n; i ++) {
			std::cout << a[i] << " \n"[i == n];
		}*/
	}

	std::cout << ans << '\n';
/*

*/
}

signed main() {
	std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);
	std::cout.tie(nullptr);

	int _ = 1;
	std::cin >> _;

	while (_ --) {
		solve();
	}

	return 0;
}