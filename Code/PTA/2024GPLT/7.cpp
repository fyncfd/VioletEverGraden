/*
* @Author: AlgoStruggler
* @Create Time: 2026-04-17 10:33:49
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
    i64 a, b;
    std::cin >> a >> b;

    std::map<int, int> cnt;
    for (int i = a; i <= b; i ++) {
   		std::string x = std::to_string(i);
   		int ct = 0;
    	while (x.size() > 1) {
    		int y = 1;
    		for (auto c : x) {
    			y *= (c - '0');
    		}
    		x = std::to_string(y);
    		ct ++;
    	}
    	cnt[i] = ct;
    }

    int max = -1, f = 0;
    for (auto [x, y] : cnt) {
    	if (max < y) {
    		max = y;
    		f = x;
    	}
    }

    std::vector<int> ans;
    for (auto [x, y] : cnt) {
    	if (y == max) {
    		ans.push_back(x);
    	}
    }

    std::sort(ans.begin(), ans.end(), [&](int a, int b) -> bool {
    	return a < b;
    });

    std::cout << max << '\n';
    for (int i = 0; i < ans.size(); i ++) {
    	std::cout << ans[i] << " \n"[i + 1 == ans.size()];
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