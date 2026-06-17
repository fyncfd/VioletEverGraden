/*
* @Author: AlgoStruggler
* @Create Time: 2026-04-15 14:54:01
* "To the Splendor of ACM-ICPC, We Consecrate Our AC Triumphs."
*/
#pragma GCC optimize("O3,unroll-loops,Ofast,inline")
#include "bits/stdc++.h"

using i64 = int64_t;
using i128 =  __int128_t;

using u32 = uint32_t;
using u64 = uint64_t;
using u128 = __uint128_t;

using f32 = float;
using f64 = double;
using f80 = long double;

constexpr int INF = 0x3f3f3f3f;
constexpr i64 LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr i64 mod = 998'244'353LL;
constexpr i64 MOD = 1e9 + 7;

static inline void VioletEverGraden() {
    int n, m, k;
    std::cin >> n >> m >> k;

    int __ = k;
    while (__ --) {
    	int p = 1;
    	std::vector<int> st;
    	bool ok = true;
    	for (int i = 1; i <= n; i ++) {
    		int x;
    		std::cin >> x;

    		if (p == x) {
    			p ++;
				while (!st.empty() && st.back() == p) {
					st.pop_back();
					p ++;
				}
    		} else {
				while (!st.empty() && st.back() == p) {
					st.pop_back();
					p ++;
				}
                if (x == p) {
                    p ++;
                    while (!st.empty() && st.back() == p) {
                        st.pop_back();
                        p ++;
                    }
                } else {
                    st.push_back(x);
                    if (st.size() > m) {
                        ok = false;
                    }
                }
    		}
    	}

		if (!st.empty()) {	
			while (!st.empty()) {
				int x = st.back();
				st.pop_back();
				if (x == p) {
					p ++;
					continue;
				} else {
					ok = false;
					break;
				}
			}
		}

		if (!st.empty()) {
			ok = false;
		}

		if (ok) {
			std::cout << "YES\n";
		} else {
			std::cout << "NO\n";
		}
    }
/*
愿幸运女神与最纯粹的前行者同在。 
Test Sample

*/
}

signed main() {
#ifdef Algostruggler
    freopen("A.in", "r", stdin);
#endif // Algostruggler

    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

    // std::cout << std::fixed << std::setprecision(12), std::cerr << std::fixed << std::setprecision(12);

    // for (int _ = [&]() -> int { int T; std::cin >> T; return T; }(); _; _ --)
        VioletEverGraden();

    return 0;
}