/*
* @Author: AlgoStruggler
* @Create Time: 2026-04-06 14:07:11
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
    int n;
    std::cin >> n;

    std::vector<std::string> s(n + 1);
    for (int i = 1; i <= n; i ++) {
    	std::cin >> s[i];
    }

    std::map<std::string, std::map<char, int>> cnt;
    for (int i = 1; i <= n; i ++) {
    	for (auto c : s[i]) {
    		cnt[s[i]][c] ++;
    	}
    }

	std::sort(s.begin() + 1, s.end(), [&](const std::string& a, const std::string& b) -> bool {
	    for (char c = 'a'; c <= 'z'; c++) {
	        if (cnt[a][c] != cnt[b][c]) {
	            return cnt[a][c] > cnt[b][c];
	        }
	    }
	    return a < b;
	});

    for (int i = 1; i <= n; i ++) {
    	std::cout << s[i] << " \n"[i == n];
    }
/*
愿幸运女神与最纯粹的前行者同在。 
Test Sample

10
a c ab ba aabb bbaa abc cba aaaaab bbbbb

aaaaab aabb bbaa abc cba ab ba a bbbbb c

5
aab aac adc baa cab

aab baa aac cab adc


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