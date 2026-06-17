#include <bits/stdc++.h>

using ll = long long;
#define rep(i, l, r, x) for (int i = l; i <= r; i += x)

void violet() {
	ll n, d, l;
	std::cin >> n >> d >> l;

	ll max = (l - n - 1) * n + 1;
	ll min = std::max(l - d, 1LL);

	if (n + d < l) {
		ll k = l / d;
		if (k * d + 1 >= l) {
			k --;
		}

		// std::cout << "k: " << k << '\n';
		ll x = l - k * d;
		if (x > d) {
			x %= d;
			ll ans = k * n + x;
			std::cout << ans << ' ' << max << '\n';
		} else {
			ll ans = k * n + 1;
			std::cout << ans << ' ' << max << '\n';
		}
/*		std::cout << "x: " << x << '\n';
		ll t = (l - x) % n;
		std::cout << "t: " << t << '\n';*/
		return ;

	}
	
		// return ;


	// if (d + 1 >= l) {
	// 	std::cout << 1 << ' ' << max << '\n';
	// 	return ;
	// }

	std::cout << min << ' ' << max << '\n';


}

signed main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int _ = 1;
	for (std::cin >> _; _; _ --)
		violet();

	return 0;
}