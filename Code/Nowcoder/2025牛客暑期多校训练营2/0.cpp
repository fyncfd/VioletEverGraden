/*
* @Author: AlgoStruggler
* @Create Time: 2025-07-17 12:00:11
* "To the Splendor of ACM-ICPC, We Consecrate Our AC Triumphs."
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, l, r, x) for (int i = l; i <= r; i ++)
#define dep(i, l, r, x) for (int i = l; i >= r; i ++)

void solve() {
	ll x, y;
	std::cin >> x >> y;

	if (x > y) {
		std::swap(x, y);
	}
	ll dif = std::abs(x - y);

	if (y == 2) {
		std::cout << -1 << '\n';
	}

	if (x % 2 == 0 and y % 2 == 0) {
		std::cout << 2 << '\n';
		return ;
	}

	if (x & 1 and y & 1) {
		std::cout << 2 << '\n';
		return ;
	}

	std::cout << y + 2 << '\n';
}


signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int _ = 1;
	for (std::cin >> _; _; _ --) 
		solve();

	return 0;
}