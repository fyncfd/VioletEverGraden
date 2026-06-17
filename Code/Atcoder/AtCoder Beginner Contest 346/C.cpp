#include "bits/stdc++.h"

using ll = long long;
using ull = unsigned long long;

#define rep(i, l, r) for (int i = l; i <= r; i ++)
#define red(i, l, r) for (int i = l; i >= r; i --)

#define int long long
const int MAXN = 2e5 + 10;
int n, k;
int a[MAXN];

namespace fio {
    template <typename T>
    class fio {
        public:
            inline void write(ll x, char end = '\0') {//快写，超过1e6用起来很快
                if (x < 0) {
                    putchar('-');
                    x = -x;
                }
                if (x > 9) {
                    write(x / 10);
                }
                putchar(x % 10 + '0');
                if (end != '\0') {
                    putchar(end);
                }
            }
            inline T read() {
                ll x = 0;
                short flag = 1;
                char c = getchar();
                while (c < '0' || c > '9') {//快写，超过1e6用起来很快
                    if (c == '-') {
                        flag = -1;
                    }
                    c = getchar();
                }
                while (c >= '0' && c <= '9') {
                    x = (x << 3) + (x << 1) + (c ^ 48);
                    c = getchar();
                }
                return x * flag;
            }
    };
}

void solve() {
	std::cin >> n >> k;
	std::map<int, int> mp;
	rep(i, 1, n) {
		std::cin >> a[i];
	}

	ll sum = (k + 1) * k >> 1;
	rep(i, 1, n) {
		if (a[i] <= k) {
			if (!mp[a[i]]) {
				sum -= a[i];
				mp[a[i]] = 1;
			}
		}
	}

	std::cout << sum << '\n';
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