#include "bits/stdc++.h"

using ll = long long;
using ull = unsigned long long;

#define rep(i, l, r) for (int i = l; i <= r; i ++)
#define red(i, l, r) for (int i = l; i >= r; i --)
#define lop(i, x) for (auto i : x)

//#deifne int long long;
int n;
std::string s;

void solve() {
	std::cin >> n;
	std::cin >> s;

	ll ans = 0;
	rep(i, 0, n - 1) {
		if (s[i] == 'y') {
			ans ++;
		}
		if (s[i] == 'n' and s[i + 1] == 'n') {
			ans ++;
			i ++;
		}
	}
	std::cout << ans << '\n';
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