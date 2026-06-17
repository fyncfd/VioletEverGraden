#include <bits/stdc++.h>

using ll = long long;
using ull = unsigned long long;

#define rep(i, l, r) for (int i = l; i <= r; i ++)
#define red(i, l, r) for (int i = l; i >= r; i --)

//#define int long long
int n, m, k;

void solve() {
	std::cin >> n >> m >> k;

	red(i, n, m + 1) {
		std::cout << i << ' ';
	}
	rep(i, 1, m) {
		std::cout << i << ' ';
	}
	std::cout << '\n';
}

signed main() {
	std::cout.tie(nullptr)->std::ios::sync_with_stdio(false);

	int t = 1;
	std::cin >> t;

	while (t --) {
		solve();
	}

	return 0;
}