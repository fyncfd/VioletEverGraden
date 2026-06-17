#include <bits/stdc++.h>

using ll = long long;

#define rep(i, l, r, x) for (int i = l; i <= r; i += x)
#define rep(i, l, r, x) for (int i = l; i >= r; i -= x)

ll l, r;
void violet() {
	std::cin >> l >> r;

	if (l == r) {
		std::cout << "infty\n";
		return ;
	}

	if (l == 1 or r == 1) {
		std::cout << 0 << '\n';
		return ;
	}

	ll ans = 0;
	ans += l - 1;
	ans *= 2;
	if (2 * l < l + r) {
		ans --;
	}

	std::cout << ans << '\n';
}

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int _ = 1;
	for (std::cin >> _; _; _ --) 
		violet();

	return 0;
}