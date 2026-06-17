#include <bits/stdc++.h>

using ll = long long;
using ull = unsigned long long;

#define rep(i, l, r) for (int i = l; i <= r; i ++)
#define red(i, l, r) for (int i = l; i >= r; i --)

//#define int long long
int n, m, k;
char s[200010];

void solve() {
	std::cin >> n >> m >> k;
	s[0] = 'L'; s[n + 1] = 'L';
	rep(i, 1, n) {
		std::cin >> s[i];
	}

	int pos = 0;
	rep(i, 1, n + 1) {
		if (s[i] =='L') {
			int temp = i;
			if (temp - pos <= m) {
				pos = temp;
			}
		}
		
	}
}

signed main() {
	std::cout.tie(nullptr)->std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t = 1;
	std::cin >> t;

	while (t --) {
		solve();
	}

	return 0;
}