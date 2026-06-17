#include <bits/stdc++.h>
using ll = long long;

#define rep(i, l, r, x) for (int i = l; i <= r; i += x)

const int mod = 10007;

void violet() {
	std::string s;
	std::cin >> s; s = " " + s;

	std::vector<int> k; k.push_back(-1);
	rep(i, 1, s.size() - 1 - 1, 1) {
		if (s[i] == '+') {
			k.push_back(s[i + 1] - '0');
		} else if (s[i] == '-') {
			k.push_back(-(s[i + 1] - '0'));
		}
	}

	int n = k.size() - 1;

	// rep(i, 1, n, 1) {
	// 	std::cout << k[i] << "?\n"[i == n];
	// }
	ll sum = 1;
	rep(i, 1, n, 1) {
		sum *= k[i];
		//std::cout << "sum=" << sum << '\n';
		sum %= mod;
	}
	//sum += mod;
	sum %= mod;
	//std::cout << "sum=" << sum << '\n';''

	ll ans = 0;
	rep(i, 1, n, 1) {
		ll t = sum / k[i];
		// t %= mod;
		//std::cout << "temp=" << t << '\n';
		ans += t;
		ans %= mod;
	}

	std::cout << ans % mod << '\n';


}

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int _ = 1;
	// for (std::cin >> _; _; _ --) 
		violet();

	return 0;
}