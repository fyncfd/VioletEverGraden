#include <bits/stdc++.h>

using ll = long long;
#define rep(i, l, r, x) for (int i = l; i <= r; i += x)

void violet() {
	int n, m;
	std::cin >> n >> m;

	std::vector<int> a(n + 1);
	rep(i, 1, n, 1) {
		std::cin >> a[i];
	}

	struct info {
		ll sum;
	};
	std::vector<info> seg(n << 2 + 10);
	std::vector<ll> tag(n << 2 + 10);

	auto update = [&](ll id) -> void {
		seg[id].sum = seg[id << 1].sum + seg[id << 1 | 1].sum;
	};

	auto build = [&](auto &&self, ll id, ll l, ll r) -> void {
		if (l == r) {
			seg[id].sum = a[l];
		} else {
			int mid = l + r >> 1;
			self(self, id << 1, l, mid); self(self, id << 1 | 1, mid + 1, r);
			update(id);
		}
	};

	
}

signed main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int _ = 1;
	// for (std::cin >> _; _; _ --)
		violet();

	return 0;
}