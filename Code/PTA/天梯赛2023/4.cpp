#include "bits/stdc++.h"

using ll = long long;
using ull = unsigned long long;

#define rep(i, l, r) for (int i = l; i <= r; i ++)
#define red(i, l, r) for (int i = l; i >= r; i --)

//#deifne int long long;
int a, b;

ll fun(ll x) {
	ll ans = 1;
	rep(i, 1, x) {
		ans *= i;
	}
	return ans;
}

void solve() {
	std::cin >> a >> b;

	std::cout << fun(a + b) << '\n';
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