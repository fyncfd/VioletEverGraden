#include "bits/stdc++.h"

using ll = long long;
using ull = unsigned long long;

#define rep(i, l, r) for (int i = l; i <= r; i ++)
#define red(i, l, r) for (int i = l; i >= r; i --)

//#deifne int long long;
int v1, v2, v3;
int a1, a2, a3;

void solve() {
	std::cin >> v1 >> v2 >> v3;
    std::cin >> a1 >> a2 >> a3;
    int p[6][3] = {
        {a1, a2, a3},
        {a1, a3, a2},
        {a2, a1, a3},
        {a2, a3, a1},
        {a3, a1, a2},
        {a3, a2, a1}
    };

    rep(i, 0, 5) {
        int win = 0;
        if (p[i][0] > v1) {
        	win++;
        }
        if (p[i][1] > v2) {
        	win++;
        }
        if (p[i][2] > v3) {
        	win++;
        }

        if (win >= 2) {
            std::cout << "Yes\n";
            return ;
        }
    }
    std::cout << "No\n";
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