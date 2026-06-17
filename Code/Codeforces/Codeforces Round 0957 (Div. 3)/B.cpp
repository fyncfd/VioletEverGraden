#include <bits/stdc++.h>

using ll = long long;
using ull = unsigned long long;

#define rep(i, l, r) for (int i = l; i <= r; i ++)
#define red(i, l, r) for (int i = l; i >= r; i --)

//#define int long long
int n, k;
int a[200010];

void solve() {
	std::cin >> n >> k;
	rep(i, 1, k) {
		std::cin >> a[i];
	}

	ll ans = 0;
	std::sort(a + 1, a + 1 + k);
	rep(i, 1, k - 1) {
		ans += a[i] - 1 + a[i];
	}

	std::cout << ans << '\n';
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