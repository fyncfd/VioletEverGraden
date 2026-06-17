/*
* @Author: AlgoStruggler
* @Create Time: 2026-04-17 10:43:23
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
    int N;
    std::cin >> N;

    while (N --) {
    	int n = 9;
    	std::vector<std::vector<int>> g(n + 1, std::vector<int> (n + 1));

    	for (int i = 1; i <= n; i ++) {
    		for (int j = 1; j <= n; j ++) {
    			std::cin >> g[i][j];
    		}
    	}

    	bool ok = true;
    	for (int i = 1; i <= n; i ++) {
    		for (int j = 1; j <= n; j ++) {
    			if (g[i][j] < 1 || g[i][j] > 9) {
    				ok = false;
    			}
    		}
    	}

    	std::vector<std::map<int, bool>> vish(10);
    	for (int i = 1; i <= n; i ++) {
    		for (int j = 1; j <= n; j ++) {
    			if (!vish[i][g[i][j]]) {
    				vish[i][g[i][j]] = true;
    			} else {
    				ok = false;
    			}
    		}
    	}

    	std::vector<std::map<int, bool>> visl(10);
    	for (int j = 1; j <= n; j ++) {
    		for (int i = 1; i <= n; i ++) {
    			if (!visl[j][g[i][j]]) {
    				visl[j][g[i][j]] = true;
    			} else {
    				ok = false;
    			}
    		}
    	}

    	std::vector<std::map<int, bool>> visg(10);
    	int cnt = 1;
    	for (int i = 1; i <= 7; i += 3) {
    		for (int j = 1; j <= 7; j += 3) {
    			for (int k = i; k <= i + 2; k ++) {
    				for (int l = j; l <= j + 2; l ++) {
		    			if (!visg[cnt][g[k][l]]) {
		    				visg[cnt][g[k][l]] = true;
		    			} else {
		    				ok = false;
		    			}
    				}
    			}
    			cnt ++;
    		}
    	}

    	if (ok) {
    		std::cout << 1 << '\n';
    	}else {
    		std::cout << 0 << '\n';
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