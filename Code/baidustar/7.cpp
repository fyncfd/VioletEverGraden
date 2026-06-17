#include <bits/stdc++.h>

using ll = long long;

#define rep(i, l, r, x) for (int i = l; i <= r; i += x)
#define dep(i, l, r, x) for (int i = l; i >= r; i -= x)

int n; ll s;
std::vector<ll> a;
void violet() {
	std::cin >> n >> s;
	a.resize(n + 1);
	rep(i, 1, n, 1) {
		std::cin>> a[i];
		//std::cout << 1 << '\n';
	}

	ll p1 = s; ll p2 = s;
	rep(i, 1, n, 1) {
		if ((p1 + a[i] + 1) / 2 >= p1) {
			p1 = (p1 + a[i] + 1) / 2;
		} else {
			p2 = (p2 + a[i] + 1) / 2;
		}
	}

	ll ans = std::max(p1, p2);
	std::cout << ans << '\n';
}

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int _ = 1;
	for (std::cin >> _; _; _ --) 
		violet();

	return 0;
}