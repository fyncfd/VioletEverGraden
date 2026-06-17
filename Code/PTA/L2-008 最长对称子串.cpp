/*
* @Author: AlgoStruggler
* @Create Time: 2026-04-13 14:56:18
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
    std::string s;
    getline(std::cin, s);

    auto change = [&](std::string s) -> std::string {
        std::string res;
        res.push_back('^');
        for (int i = 0; i < s.size(); i++) {
            res.push_back(s[i]);
            res.push_back('#');
        }
        res.push_back('$');

        return res;
    };

    std::string S = change(s);

    std::vector<int> P(S.size(), 0);
    auto manacher = [&]() {
    	int R = 0, C = 0;
    	for (int i = 1; i + 1 < S.size(); i ++) {
    		if (i < R) {
    			P[i] = std::min(P[(C << 1) - i], P[C] + C - i);
    		} else {
    			P[i] = 1;
    		}

    		while (S[i + P[i]] == S[i - P[i]]) {
    			P[i] ++;
    		}

    		if (P[i] + i > R) {
    			R = P[i] + i;
    			C = i;
    		}
    	}
    };

    manacher();

    int ans = 0;
    for (int i = 0; i < S.size(); i ++) {
    	ans = std::max(ans, P[i]);
    }

    std::cout << ans - 1 << '\n';
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