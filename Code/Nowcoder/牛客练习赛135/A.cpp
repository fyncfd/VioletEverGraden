#include "bits/stdc++.h"

using ll = long long;
using ull = unsigned long long;

#define rep(i, l, r) for (int i = l; i <= r; i ++)
#define red(i, l, r) for (int i = l; i >= r; i --)

//#deifne int long long;
ll x, y, n;

void solve() {
	std::cin >> x >> y >> n;

	if (n >= x) {
		std::cout << x - 1 << '\n';
		return ;
	}
	std::cout << n << '\n';
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