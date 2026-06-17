#include <bits/stdc++.h>
using ll = long long;

#define rep(i, l, r, x) for (int i = l; i <= r; i += x)

void violet() {
	int n, k;
	std::cin >> n >> k;

	std::string s;
	std::cin >> s; s = " " + s;

	int numa = 0; int numA = 0;
	rep(i, 1, n, 1) {
		if (s[i] >= 'a' and s[i] <= 'z') {
			numa ++;
		} 
		if (s[i] >= 'A' and s[i] <= 'Z') {
			numA ++;
		}
	}

	k -= numa; ll ans = numA;
	if (k >= 0) {
		if (k % 2 == 0) {
			ans += numa;
		} else {
			ans += numa - 1;
		}
	} else {
		ans += numa + k;
	}

	std::cout << ans << '\n';
}

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int _ = 1;
	// for (std::cin >> _; _; _ --) 
		violet();

	return 0;
}