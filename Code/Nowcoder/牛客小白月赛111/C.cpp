#include "bits/stdc++.h"

using ll = long long;
using ull = unsigned long long;

#define rep(i, l, r) for (int i = l; i <= r; i ++)
#define red(i, l, r) for (int i = l; i >= r; i --)

//#deifne int long long;
int n;

void solve() {
	std::cin >> n;

    std::vector<std::string> s(n);
    rep(i, 0, n - 1) {
        std::cin >> s[i];
    }

    if (n == 1) {
    	std::cout << 1 << '\n';
    }

    std::vector<int> l(n, 1);
    rep(i, 1, n - 1) {
        if (s[i] == s[i - 1]) {
            l[i] = l[i - 1] + 1;
        }
    }

    std::vector<int> r(n, 1);
    red(i, n - 2, 0) {
        if (s[i] == s[i + 1]) {
            r[i] = r[i + 1] + 1;
        }
    }

    int ans = 1;
    for (int i = 0; i < n; ++i) {
        ans = std::max(ans, l[i]);
        if (i > 0 && i < n - 1 && s[i - 1] == s[i + 1]) {
            ans = std::max(ans, l[i - 1] + r[i + 1]);
        }
    }

    std::cout << ans << '\n';
}


signed main() {
	std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);
	std::cout.tie(nullptr);

	int _ = 1;
	//std::cin >> _;

	while (_ --) {
		solve();
	}

	return 0;
}