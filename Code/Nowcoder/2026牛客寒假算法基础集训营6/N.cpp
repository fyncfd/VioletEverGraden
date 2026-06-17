/*
* @Author: AlgoStruggler
* @Create Time: 2026-02-13 14:20:23
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

constexpr static inline void VioletEverGraden() noexcept {
    int n;
    std::cin >> n;

    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++) {
    	std::cin >> a[i];
    }

    std::vector<int> b(n + 1);
    for (int i = 1; i <= n; i ++) {
    	std::cin >> b[i];
    }

    std::bitset<2050> cur;
    cur[0] = 1;

    for (int i = 1; i <= n; i ++) {
    	std::bitset<2050> nxt;

    	for (int j = cur._Find_first(); j < 2050; j = cur._Find_next(j)) {
    		int k = 0;
    		if (j >= a[i]) {
    			k = j - a[i];
    		} else {
    			k = 0;
    		}
    		nxt[k] = 1;
    	}

	    for (int j = cur._Find_first(); j < 2050; j = cur._Find_next(j)) {
	        int k = j ^ b[i];
	        nxt[k] = 1;
	    }
	    cur = nxt;
    }

    int ans = 0;
    for (int i = 2050 - 1; i >= 0; i --) {
        if (cur[i]) {
            ans = i;
            break;
        }
    }
    
    std::cout << ans << '\n';
/*
愿幸运女神与最纯粹的前行者同在。 
Test Sample

3
1 1 1
1 2 4

7

3
0 2 10
3 1 6

7


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