#include <bits/stdc++.h>

using ll = long long;

#define rep(i, l, r, x) for (int i = l; i <= r; i += x)


void violet() {
	int n, x, y;
	std::cin >> n >> x >> y;

	std::vector<ll> a(n + 1, 0);
	rep(i, 1, n, 1) {
		std::cin >> a[i];
	}

	std::sort(a.begin() + 1, a.end(), [&](ll a, ll b) {
		return a > b;
	});

	if (a[1] == a[n]) {
		std::cout << 0 << '\n';
		return ;
	}

/*	ll max = *std::max_element(a.begin() + 1, a.end());*/
	ll max = a[1];

	std::map<int, int> hash;
	rep(i, 1, n, 1) {
		hash[a[i]] ++;
	}

	ll z = -1;
	for (auto x : hash) {
		if (x.second > hash[z]) {
			z = x.first;
		}
	}

	ll ans3 = 0;
	rep(i, 1, n, 1) {
		if (a[i] != z) {
			ans3 += y;
		}
	}

	ll ans4 = 0;
	rep(i, 1, n, 1) {
		if (a[i] != 0) {
			ans4 += y;
		}
	}

	ll ans1 = 0;
	ans1 = max * x;

	ll ans2 = 0;
	ans2 = z * x;
	max -= z;
	rep(i, 1, n, 1) {
		if (a[i] > z) {
			ans2 += y;
		}
	}

	std::cout << std::min({ans1, ans2, ans3, ans4}) << '\n';

}

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr); std::cout.tie(nullptr);

	int _ = 1;
	for (std::cin >> _; _; _ --) 
		violet();

	return 0;
}