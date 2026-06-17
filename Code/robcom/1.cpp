#include <bits/stdc++.h>

using ll = long long;

#define rep(i, l, r, x) for (int i = l; i <= r; i += x)
#define int long long

void violet() {
	int n, m;
	std::cin >> n >> m;

	int a1, a2, b1, b2, b3;
	std::cin >> a1 >> a2 >> b1 >> b2 >> b3;

	std::vector<std::vector<int>> p1(1e5 + 500, std::vector<int> (10, 0));
	std::vector<std::vector<int>> p2(1e5 + 500, std::vector<int> (10, 0));
	int __ = n;
	while (__ --) {
		int d, op;
		std::cin >> d >> op;

		if (op == 1) {
			p1[d][op] += a1;
			p2[d][op] -= b1;
		} else if (op == 2) {
			p2[d][op] -= b2;
		} else if (op == 3) {
			p2[d][op] -= b3;
			p1[d][op] -= a2;
		}
	}

	int ___ = m;
	while (___ --) {
		int t, op;
		std::cin >> t >> op;

		p2[t][op] /= 2;
	}
 
	ll ans1 = 0; ll ans2 = 0;
	rep(i, 1, 100000, 1) {
		rep(j, 1, 3, 1) {
			ans1 += p1[i][j];
		}
	}
	rep(i, 1, 100000, 1) {
		rep(j, 1, 3, 1) {
			ans2 += p2[i][j];
		}
	}

	std::cout << ans1 << ' ' << ans2 << '\n';

	//std::cout << -27 / 2 << "???\n";

}

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int _ = 1;
	//for (std::cin >> _; _; _ --)
		violet();

	return 0;
}