#include <bits/stdc++.h>

using ll = long long;

int n;

void solve() {
	std::cin >> n;

	if (400 % n == 0) {
		std::cout << 400 / n << '\n';
		return ;
	}
	std::cout << -1 << '\n';

}

signed main() {
	std::cin.tie(nullptr) -> 
	std::ios::sync_with_stdio(false);
	std::cout.tie(nullptr);

	int _ = 1;
	//std::cin >> _;

	while (_ --) {
		solve();
	}

	return 0;
}
/*
10

40

11

-1

400

1

*/