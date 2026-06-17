/*
* @Author: AlgoStruggler
* @Create Time: 2026-03-20 18:32:18
* "To the Splendor of ACM-ICPC, We Consecrate Our AC Triumphs."
*/
#include <bits/stdc++.h>

#define rep(i, l, r) for (int i = l; i <= r; i ++)

using i64 = long long;
#define ll i64

template <typename T>
constexpr T ksm(T a, i64 b) {
    T res = 1;
    while (b) {
        if (b & 1) {
            res *= a;
        }
        a *= a;
        b >>= 1;
    }
    return res;
}

void solve() {
	int N, K;
	std::cin >> N >> K;
	// std::cin >> K;

/*	auto dfs = [&](auto &&dfs, int xn) -> void {
		int xn1 = ((n - 1) * xn) / n + 
	}*/

	// for (int i = 1; i <= 100; i ++) {
	// 	std::cout << i << ":" << pow(i, 1.0 / K) << '\n';
	// }

/*	int t = 0;
	for (int i = 3; i <= 100000; i += 2) {
		i64 res = ((i + 3) * (i - 1)) / 4;
		if (res > N) {
			t = i;
			break;
		}
	}

	t --;
	int ans = t + 2;

	std::cout << ans << '\n';*/

	// int ans = std::pow(N, 1.0 / K);
	// double f = 1.0 * std::pow(N, 1.0 / K);
	// std::cerr << f << '\n';

	for (int i = 1; i <= 100000; i ++) {
		if (ksm(i, K) == N) {
			std::cout << i << '\n';
			return ;
		}
	}

	int ans = std::pow(N, 1.0 / K);

	std::cout << ans << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int _ = 1;
	std::cin >> _;
	while (_ --) {
		solve();
	}

	return 0;
}

/*
1
1
1
2
2
2
2
2
3
3
3
3
3
3
3
4
4
4
4
4
*/