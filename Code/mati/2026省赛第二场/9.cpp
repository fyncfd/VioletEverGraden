#include <bits/stdc++.h>

using i64 = long long;
constexpr i64 LINF = 0x3f3f3f3f3f3f3f3f;

#define int long long

void violet() {
	int n, m;
	std::cin >> n >> m;

	struct pii {
		int w, id;
	};
	std::vector<pii> v(n + 1);
	for (int i = 1; i <= n; i ++) {
		std::cin >> v[i].w;
		v[i].id = i;
	}

	std::sort(v.begin() + 1, v.end(), [&](pii a, pii b) -> bool {
		if (a.id == b.id) {
			return a.w > b.w;
		}
		return a.id < b.id;
	});

	std::vector<paa> f(m + 1);
	std::vector<bool> vis(n + 1, false);
	for (int i = 1; i <= m; i ++) {
		int t, z;
		std::cin >> t >> z;
		int L = t, R = n + 1;
		while (L <= R) {
			if ()
		}
	}
}

signed main() {
	int _ = 1;
	std::cin >> _;
	while (_ --) {
		violet();
	}

	return 0;
}