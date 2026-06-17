#include "bits/stdc++.h"

using ll = long long;
using ull = unsigned long long;

#define rep(i, l, r) for (int i = l; i <= r; i ++)
#define red(i, l, r) for (int i = l; i >= r; i --)

//#deifne int long long;
std::string s1, s2;

std::string check(std::string a) {
	std::string s = "";
	rep(i, 1, a.size() - 1) {
		if (a[i] % 2 == a[i - 1] % 2) {
			s += std::max(a[i], a[i - 1]);
		}
	}
	return s;
}

void solve() {
	std::cin >> s1 >> s2;

	std::string ans1, ans2;

	ans1 = check(s1);
	ans2 = check(s2);

	if (ans1 == ans2) {
		std::cout << ans1 << '\n';
	}
	else {
		std::cout << ans1 << '\n';
		std::cout << ans2 << '\n';
	}
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