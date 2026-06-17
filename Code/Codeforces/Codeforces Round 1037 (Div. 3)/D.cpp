/*
* @Author: AlgoStruggler
* @Create Time: 2025-12-18 11:01:25
* "To the Splendor of ACM-ICPC, We Consecrate Our AC Triumphs."
*/
#include "bits/stdc++.h"

using ll = long long;
using ull = unsigned long long;

//define int long long


void solve() {
	int n, k;
	std::cin >> n >> k;

	struct pii {
		int l; int r; int w;
	};
	std::vector<pii> q; q.push_back({0, 0, 0});
	int __ = n;
	while (__ --) {
		int l, r, d;
		std::cin >> l >> r >> d;
		q.push_back({l, r, d});
	}

	std::sort(q.begin() + 1, q.end(), [&](pii a, pii b) -> bool {
		if (a.l == b.l) {
			return a.w > b.w;
		}
		return a.l < b.l;
	});
	std::vector<std::vector<int>> dp(n + 1, std::vector<int> (2, -1000000000));
	dp[0][0] = dp[0][1] = k;
	for (int i = 1; i <= n; i ++) {
		int k1 = std::max(dp[i - 1][0], dp[i - 1][1]);
		int k2 = std::min(dp[i - 1][0], dp[i - 1][1]);
		if ((k1 >= q[i].l and k1 <= q[i].r) or (k2 >= q[i].l and k2 <= q[i].r)) {
			dp[i][1] = q[i].w;
		}
		dp[i][0] = k1;
	}

	ll ans = std::max(dp[n][0], dp[n][1]);
	std::cout << ans << '\n';
/*

5
3 1
2 3 3
1 2 2
3 10 10
1 0
1 2 2
1 2
1 2 2
2 2
1 3 2
2 4 4
2 5
1 10 5
3 6 5

10
0
2
4
5


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