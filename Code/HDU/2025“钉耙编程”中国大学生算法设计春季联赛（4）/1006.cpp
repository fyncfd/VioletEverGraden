#include <bits/stdc++.h>

#define rep(i, l, r) for(int i = l; i <= r; i ++)
#define int long long

using ll = long long;

const int MAXN = 2e5 + 10;

int n, q;
int a[MAXN];
int op;
int x, y;
ll tree[MAXN];

int lowbit(int x) {
	return x & -x;
}

void update(int x, int d) {
	while (x <= MAXN) {
		tree[x] += d;
		x += lowbit(x);
	}
}

ll getsum(int x) {
	ll ans = 0;
	while (x > 0) {
		ans += tree[x];
		x -= lowbit(x);
	} 
	return ans;
}

void solve() {
	std::cin >> n >> q;

	memset(tree, 0, sizeof tree);

	rep(i, 1, n) {
		std::cin >> a[i];
		update(i, a[i]);
	}

	ll ans = 0;
	ll num = 0;
	while (q --) {
		std::cin >> op;

		if (op == 1) {
			std::cin >> x >> y;
			update(x, -a[x]);
			a[x] = y;
			update(x, a[x]);
		}
		else {
			std::cin >> x >> y;
			num ++;
			ll cnt = 1LL * num *  (getsum(y) / 100LL - getsum(x - 1) / 100LL);
			ans ^= cnt;
		}
	}

	std::cout << ans << '\n';
}

signed main() {
	std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);
	std::cout.tie(nullptr);

	int _ = 1;
	std::cin >> _;

	while (_ --) {
		solve();
	}

	return 0;
}