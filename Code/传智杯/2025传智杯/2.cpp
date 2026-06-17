#include <bits/stdc++.h>
using ll = long long;

#define rep(i, l, r, x) for (int i = l; i <= r; i += x)

const int N = 2e5 + 10;
ll tree[N] = { 0 };

int lowbit(int x) {
	return x & -x;
}

void update(int x, int d) {
	while (x <= N) {
		tree[x] += d;
		x += lowbit(x);
	}
}

ll query(int x) {
	ll ans = 0;
	while (x > 0) {
		ans += tree[x];
		x -= lowbit(x);
	}
	return ans;
}

void violet() {
	int n, m, x, y;
	std::cin >> n >> m >> x >> y;

	std::vector<int> p(n + 1, 1);
	rep(i, 1, n, 1) {
	}

	int sumx = x; int sumy = n - y + 1; 

	int __ = m;
	while (__ --) {
		int q;
		std::cin >> q;

		if (p[q] == 1) {
			p[q] = 0;
			if (q <= x) {
				sumx --;
			}
			if (q >= y) {
				sumy --;
			}
		} else {
			p[q] = 1;
			if (q <= x) {
				sumx ++;
			}
			if (q >= y) {
				sumy ++;
			}
		}
		std::cout << sumx << ' ' << sumy << '\n';
	}
}

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int _ = 1;
	for (std::cin >> _; _; _ --) 
		violet();

	return 0;
}