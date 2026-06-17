/*
* @Author: AlgoStruggler
* @Create Time: 2025-12-17 17:10:23
* "To the Splendor of ACM-ICPC, We Consecrate Our AC Triumphs."
*/
#include "bits/stdc++.h"

using ll = long long;
using ull = unsigned long long;

//define int long long

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> b(n + 1);
	std::map<int, int> hash;
	for (int i = 1; i <= n; i ++) {
		std::cin >> b[i];
		hash[b[i]] ++;
	}

	for (auto [x, y] : hash) {
		if (y % x != 0) {
			std::cout << -1 << '\n';
			return ;
		}
	}

/*	int p = 1;
	std::vector<int> num(n + 1, 0);
	std::map<int, std::vector<int>> mp;
	for (auto [x, y] : hash) {
		if (y % x != 0) {
			std::cout << -1 << '\n';
			return ;
		}
		if (num[x] < x) {
			mp[x].push_back(p);
			num[x] ++;
		} else {
			mp[x].push_back(p);
			num[x] = 0;
		}
		p ++;
	}

	for (auto [x, y] : mp) {
		std::cout << "x______: " << x << '\n';
		for (auto d : y) {
			std::cout << "d: " << d << '\n';
		}
	}*/

/*	std::vector<int> a(n + 1, 0);
	for (int i = 1; i <= n; i ++) {
		if ()
	}

	for (int i = 1; i <= n; i ++) {
		std::cout << a[i] << " \n"[i == n];
	}*/
	std::map<int, std::vector<int>> mp;
	for (int i = 1; i <= n; i ++) {
		mp[b[i]].push_back(i);
	}

	std::vector<int> a(n + 1, 0);
	int p = 1;
	for (auto [x, y] : mp) {
		int num = 0;
		for (auto pos : y) {
			if (num == x) {
				num = 0;
				p ++;
			}
			a[pos] = p;
			num ++;
		}
		p ++;
	}

	for (int i = 1; i <= n; i ++) {
		std::cout << a[i] << " \n"[i == n];
	}
/*



4
4
1 2 3 4
6
1 2 2 3 3 3
6
6 6 6 6 6 6
6
2 1 2 3 3 3

0
1 2 2 3 3 3
1 1 1 1 1 1
2 1 2 3 3 3


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