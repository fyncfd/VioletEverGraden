#include "bits/stdc++.h"

using ll = long long;
using ull = unsigned long long;

#define rep(i, l, r) for (int i = l; i <= r; i ++)
#define red(i, l, r) for (int i = l; i >= r; i --)

//#deifne int long long;
const int MAXN = 1e2 + 2;
int n;
int a[MAXN];

void solve() {
	std::cin >> n;
	rep(i, 1, n) {
		std::cin >> a[i];
	}

	int b[MAXN - 1];
	rep(i, 1, n - 1) {
		b[i] = a[i] * a[i + 1];
		std::cout << b[i] << ' ';
	}
	std::cout << '\n';
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