#include <bits/stdc++.h>

using ll = long long;
#define int long long
#define rep(i, l, r, x) for (int i = l; i <= r; i += x)
#define dep(i, l, r, x) for (int i = l; i >= r; i -= x)

void violet() {
	int n;
	std::cin >> n;
	std::string s[1000006];
	rep(i, 1, n, 1) {
		std::cin >> s[i];
	}

	ll ans = 0;
	rep(i, 1, n, 1) {
		rep(j, 1, n, 1) {
			int p = 0;
			std::string s1 = s[i]; std::string s2 = s[j];
			while (p < std::min(s1.size(), s2.size()) - 1) {
				if (s1[p] == s2[p]) {
					p ++;
				} else {
					ans += p;
					break;
				}
			}
		}
	}

	std::cout << ans << '\n';
}

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int _ = 1;
	//for (std::cin >> _; _; _ --) 
		violet();

	return 0;
}
