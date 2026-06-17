/*
* @Author: AlgoStruggler
* @Create Time: 2026-02-22 19:40:33
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
    int n, m;
    std::cin >> n >> m;

    std::vector<std::string> s(n);
    std::vector<int> cnt1(m, 0);
    for (int i = 0; i < n; i ++) {
    	std::cin >> s[i];
    	for (int j = 0; j < s[i].size(); j ++) {
    		if (s[i][j] == '1') {
    			cnt1[j] ++;
    		}
    	}
    }

    for (int i = 0; i < n; i ++) {
    	i64 d = 0;
    	for (int j = 0; j < s[i].size(); j ++) {
    		if (s[i][j] == '0') {
    			d += cnt1[j];
    		} else {
    			d += (n - cnt1[j]);
    		}
    	}

    	i64 max = 0; i64 cur = 0;
    	for (int j = 0; j < s[i].size(); j ++) {
    		i64 p = 0;
    		if (s[i][j] == '0') {
    			p = 2LL * cnt1[j] - n + 1;
    		} else {
    			p = n + 1 - 2LL * cnt1[j];
    		}
    		cur = std::max(p, cur + p);
    		if (cur > max) {
    			max = cur;
    		}
    	}

    	i64 ans = d - max;

    	std::cout << ans << '\n';
    }
/*
愿幸运女神与最纯粹的前行者同在。 
Test Sample

1
3 4
0000
1111
0101

2
2
4


*/
}

signed main() {
#ifdef Algostruggler
    freopen("A.in", "r", stdin);
#endif // Algostruggler

    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

    // std::cout << std::fixed << std::setprecision(12), std::cerr << std::fixed << std::setprecision(12);

    for (int _ = [&]() -> int { int T; std::cin >> T; return T; }(); _; _ --)
        VioletEverGraden();

    return 0;
}