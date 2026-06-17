#include <bits/stdc++.h>

using ll = long long;
using ull = unsigned long long;

#define rep(i, l, r) for (int i = l; i <= r; i ++)
#define red(i, l, r) for (int i = l; i >= r; i --)

//#define int long long
int a, b, c;

void solve() {
	std::cin >> a >> b >> c;

	int ma = 0;
	rep(i, 0, 5) {
		rep(j, 0, 5 - i) {
			rep(k, 0, 5 - i - j) {
				ma = std::max(ma, (a + i) * (b + j) * (c + k));
			}
		}
	}

	std::cout << ma << '\n';
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