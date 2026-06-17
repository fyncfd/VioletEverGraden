#include "bits/stdc++.h"

using ll = long long;
using ull = unsigned long long;

#define rep(i, l, r) for (int i = l; i <= r; i ++)
#define red(i, l, r) for (int i = l; i >= r; i --)

//#deifne int long long;
int ans[300];
int n, k, s;

void solve() {
	std::cin >> n >> k >> s;
	
	int cnt = 0;
	while (n --) {
		int x, y;
		std::cin >> x >> y;

		if (x >= 175) {
			if (y >= s) {
				cnt ++;
			}
			else {
				ans[x] ++;
				if (ans[x] <= k) {
					cnt ++;
				}
			}
		}
	}
	std::cout << cnt;
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