/*
* @Author: AlgoStruggler
* @Create Time: 2025-04-26 19:43:11
* "To the Splendor of ACM-ICPC, We Consecrate Our AC Triumphs."
*/
#include <bits/stdc++.h>

using ll = long long;

int a, b, c, d, e;

void violet() {
	std::cin >> a >> b >> c >> d >> e;
	//std::cerr << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << '\n';

	auto C = [](int n, int m) {
		int odd = 1;
		for (int i = 2; i <= n; i ++) {
			odd *= i;
		}

		int ndd = 1;
		for (int i = 2; i <= m; i ++) {
			ndd *= i;
		}

		int edd = 1;
		for (int i = 2; i <= n - m ; i ++) {
			edd *= i;
		}

		return odd / (ndd * edd);
	};
	/*std::cerr << C(2, 1) << '\n';*/
	ll ans = 0;
	if (e == 0) {
		//std::cout << C(d - 1, 1) << '\n';
		ans += C(a, 1) * C(b, 1) * C(c, 1) * C(d, 1) * C(d - 1, 1);
	}
	else {
		ans += C(a, 1) * C(b, 1) * C(c, 1) * C(d, 1) * C(d - 1 + e, 1);
	}

	std::cout << ans << '\n';
}

signed main() {
	std::cin.tie(nullptr) ->
	std::ios::sync_with_stdio(false);
	std::cout.tie(nullptr);

	int _ = 1;

	for (std::cin >> _; _; _ --) 
		violet();

	return 0;
}