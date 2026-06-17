#include <bits/stdc++.h>
using ll = long long;
signed main() {
	int n, q;
	std::cin >> n >> q;

	std::vector<ll> a(n + 1);
	for (int i = 1; i <= n; i ++) {
		std::cin >> a[i];
	}

	while (q --) {
		int op, pos, v;
		std::cin >> op;

		if (op == 1) {
			std::cin >> pos >> v;
			a[pos] += v;
		} else {
			std::cin >> pos >> v;
			a[pos] -= v;	
		}
	}

	for (int i = 1; i <= n; i ++) {
		std::cout << a[i] << " \n"[i == n];
	}

	std::cout << 2518 * 0.6 << '\n';

	return 0;
}