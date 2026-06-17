#include <bits/stdc++.h>
using ll = long long;

#define rep(i, l, r, x) for (int i = l; i <= r; i += x)

void violet() {
	int n;
	std::cin >> n;
	struct pii {
		ll fi; ll se;
	};
	std::vector<pii> a(n + 1);
	rep(i, 1, n, 1) {
		std::cin >> a[i].fi >> a[i].se;
		//std::cout << 1 << '\n';
	}

	std::sort(a.begin() + 1, a.end(), [&](pii a, pii b) -> bool {
		if (a.fi == b.fi) {
			return a.se > b.se;
		} else {
			return a.fi < b.fi;
		}
	});

	std::vector<ll> pre(n + 1, -1);
	rep(i, 1, n, 1) {
		pre[i] = std::max(pre[i - 1], a[i].se);
	}


	int q;
	std::cin >> q;
	//std::cout << ">>>>\n";

	int __ = q;
	while (__ --) {
		ll x;
		std::cin >> x;

		int l = 1; int r = n;
		//ll ans = 0;
		while (l < r) {
			int mid = l + r + 1 >> 1;
			if (a[mid].fi <= x) {
				l = mid;
				//ans = mid;
			} else {
				r = mid - 1;
			}
			//std::cout << "?\n"; 
		}
		if (a[l].fi <= x) {
			std::cout << pre[l] << '\n';
		} else {
			std::cout << -1 << '\n';
		}
	}
}

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int _ = 1;
	// for (std::cin >> _; _; _ --) 
		violet();

	return 0;
}