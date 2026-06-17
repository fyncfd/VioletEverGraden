#include "bits/stdc++.h"

using ll = long long;
using ull = unsigned long long;

#define rep(i, l, r) for (int i = l; i <= r; i ++)
#define red(i, l, r) for (int i = l; i >= r; i --)

//#deifne int long long;
int a[10];
int n;

void solve() {
	int b[10];
	rep(i, 1, 6) {
		std::cin >> a[i];
		b[i] = a[i];
	}
	std::cin >> n;

	rep(i, 1, 6) {
		if (a[i] == 6) {
			a[i] --;
		}
		else {
			a[i] = 6;
		}
	}

	rep(i, 1, n - 1) {
		rep(j, 1, 6) {
			if (a[j] - 1 != b[j]) {
				a[j] --;
			}
			else {
				a[j] -= 2;
			}
		}
	}

	rep(i, 1, 5) {
		std::cout << a[i] << ' ';
	}
	std::cout << a[6] << '\n';
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