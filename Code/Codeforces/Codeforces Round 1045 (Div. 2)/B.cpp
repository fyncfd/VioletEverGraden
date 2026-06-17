/*
* @Author: AlgoStruggler
* @Create Time: 2025-12-17 20:35:41
* "To the Splendor of ACM-ICPC, We Consecrate Our AC Triumphs."
*/
#include "bits/stdc++.h"

using ll = long long;
using ull = unsigned long long;

//define int long long


void solve() {
	ll n, k;
	std::cin >> n >> k;

	std::vector<ll> a(n + 1);
	for (int i = 1; i <= n; i ++) {
		std::cin >> a[i];
	}

	ll p = k * (k + 1);
	for (int i = 1; i <= n; i ++) {
		a[i] += (a[i] * k) % p;
		if (a[i] == 1) {
			a[i] += k;
		}
	}

	for (int i = 1; i <= n; i ++) {
		std::cout << a[i] << " \n"[i == n];
	}
/*

8
3 3
2 7 1
4 5
2 9 16 14
4 1
1 2 3 4
5 2
5 6 7 8 9
2 10
7 9
1 1000000000
1
1 371
1000000000
3 6
1 3 5

8 16 4
12 24 36 24
2 2 4 4
9 6 9 12 9
77 99
1000000001
1000005936
7 21 35


*/
}

signed main() {
	std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);
	std::cout.tie(nullptr);

	int _ = 1;
	std::cin >> _;

	while (_ --) {
		solve();
	}

	return 0;
}