#include "bits/stdc++.h"

using ll = long long;
using ull = unsigned long long;

#define rep(i, l, r) for (int i = l; i <= r; i ++)
#define red(i, l, r) for (int i = l; i >= r; i --)

#define int long long
int n, m, q;
int a[100005];
int l, r;

void solve() {
	std::cin >> n >> m >> q;
	rep(i, 1, n) {
		std::cin >> a[i];
	}

	bool ok = false;
	if (m & 1) {
		ok = true;
	}
	while (q --) {
		std::cin >> l >> r;
		if (l != r) {
			ok = !ok;
		}
		if (ok) {
			std::cout << "odd\n";
		}
		else {
			std::cout << "even\n";
		}
	}
}

signed main() {
	std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);
	std::cout.tie(nullptr);

	int _ = 1;
	//std::cin >> _;

	while (_ --) {
		solve();
	}

	return 0;
}