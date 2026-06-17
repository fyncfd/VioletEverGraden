/*
* @Author: AlgoStruggler
* @Create Time: 2025-09-21 18:28:16
* "To the Splendor of ACM-ICPC, We Consecrate Our AC Triumphs."
*/
#include <bits/stdc++.h>
using ll = long long;
#define rep(i, l, r, x) for (int i = l; i <= r; i += x)


void solve() {
	std::set<int> hash;
	std::map<int, int> hash2;


	int n;
	std::cin >> n;
	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i ++) {
		std::cin >> a[i];
	}
	std::deque<int> dq;
	for (int i = 1; i <= n; i ++) {
		dq.push_back(a[i]);
	}

	int x = dq.back();
	dq.pop_back();
	dq.push_front(x);

	while (!dq.empty()) {
		std::cout << dq.front();
		dq.pop_front();
	}
} 



int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int _ = 1;
	//for (std::cin >> _; _; _ --)
		solve();

	return 0;
}