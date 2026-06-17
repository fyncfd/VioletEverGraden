#include <bits/stdc++.h>

using ll = long long;

#define rep(i, l, r, x) for (int i = l; i <= r; i += x)


void violet() {
	int n;
	std::cin >> n;
	
	std::vector<int> p(n + 1, 0);

	if (n & 1) {
		rep(i, 1, n, 1) {
			std::cout << i << " \n"[i == n];
		}
	} else {
		rep(i, 1, n, 2) {
			std::cout << i + 1 << " " << i << " \n"[i == n];
		}
	}
}

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr); std::cout.tie(nullptr);

	int _ = 1;
	//for (std::cin >> _; _; _ --) 
		violet();

	return 0;
}