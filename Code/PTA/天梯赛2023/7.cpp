#include "bits/stdc++.h"

using ll = long long;
using ull = unsigned long long;

#define rep(i, l, r) for (int i = l; i <= r; i ++)
#define red(i, l, r) for (int i = l; i >= r; i --)

//#deifne int long long;
int n, m, q;
int op, x;

void solve() {
	std::cin >> n >> m >> q;

	bool visl[100005] = {0}, visc[100005] = {0};
	ll ans = n * m;
	int numl = 0, numc = 0;
	while (q --) {
		std::cin >> op;
		if (op == 1) {
			std::cin >> x;
			if (!visc[x]) {
				visc[x] = 1;
				ans -= n - numl;
				numc ++;
			}
		}
		else {
			std::cin >> x;
			if (!visl[x]) {
				visl[x] = 1;
				ans -= m - numc;
				numl ++;
			}
		}
	}

	std::cout << ans;
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