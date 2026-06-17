#include <bits/stdc++.h>

using ll = long long;
#define int long long
#define rep(i, l, r, x) for (int i = l; i <= r; i += x)
#define dep(i, l, r, x) for (int i = l; i >= r; i -= x)

void violet() {
	int n, d;
	std::cin >> n >> d;

	std::vector<int> p(d - 1, 0);
	rep(i, 0, d - 1, 1) {
		p[i] = i;
	}

	std::vector<std::vector<int>> ans(d - 1);
	ans.push_back(p);

	while (next_permutation(p.begin(), p.end())) {
		ans.push_back(p);
	}

	rep(i, 0, d - 1, 1) {
		rep(j, 0, d - 1, 1) {
			std::cout << ans[i][j] << " \n"[j == d - 1];
		}
	}
}

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int _ = 1;
	//for (std::cin >> _; _; _ --) 
		violet();

	return 0;
}
