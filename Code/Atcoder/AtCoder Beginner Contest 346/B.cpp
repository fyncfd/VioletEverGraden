#include "bits/stdc++.h"

using ll = long long;
using ull = unsigned long long;

#define rep(i, l, r) for (int i = l; i <= r; i ++)
#define red(i, l, r) for (int i = l; i >= r; i --)

//#deifne int long long;
int w, b;

void solve() {
	std::cin >> w >> b;
	if (w > 14) {
		w %=14;
	}
	if (b > 10) {
		b %= 10;
	}
	std::string s = "wbwbwwbwbwbw";
	s += s;

	rep(i, 0, s.size() - 1) {
		int numw = 0; int numb = 0;
		rep(j, i, s.size() - 1) {
			if (numw == w and numb == b) {
				std::cout << "Yes\n";
				return ;
			}
			if (s[j] == 'w') {
				numw ++;
			}
			else {
				numb ++;
			}
		}
	}
	std::cout << "No\n";
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