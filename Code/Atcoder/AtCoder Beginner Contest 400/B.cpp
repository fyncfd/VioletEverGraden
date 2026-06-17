#include <bits/stdc++.h>

using ll = long long;

ll n; int m;

namespace ksm {
    template <typename T = ll>
    class ksm {
        public:
            T fastpow(T a, T b) {//迭代法求快速幂，避免溢出
                T res = 1;
                while (b > 0) {
                    if (b & 1) {
                        res *= a;
                    }
                    a *= a;
                    b >>= 1;
                }
                return res;
            }
            T powmod(T a, T b, T m) {//迭代法求取模快速幂
                a %= m;//先取模，确保a < m;
                T res = 1;
                while (b > 0) {
                    if (b & 1) {
                        res = (res * a) % m; 
                    }
                    a = (a * a) % m;//平方后取模
                    b >>= 1;
                }
                return res;
            }
    };
}

void solve() {
	ksm::ksm<ll> i63;

	std::cin >> n >> m;
	
	ll ans = 0;
	for (int i = 0; i <= m; i ++) {
		ans += i63.fastpow(n, i);

		if (ans > 1e9) {
			std::cout << "inf" << '\n';
			return ;
		}
	}
	std::cout << ans << '\n';

}

signed main() {
	std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int _ = 1;
	//std::cin >> _;

	while (_ --) {
		solve();
	}

	return 0;
}
/*

7 3

400

1000000 2

inf

999999999 1

1000000000

998244353 99

inf

*/