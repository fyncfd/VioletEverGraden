/*
* @Author: AlgoStruggler
* @Create Time: 2026-05-15 18:57:34
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
#define int long long
static inline void VioletEverGraden() {
    std::string s;
    std::cin >> s;
    s = s + "!";

    struct pii {
    	char num; int len;
    };
    std::vector<pii> p;

    int l = 0;
    int len = 1;
    while (l < s.size()) {
    	if (l < s.size() && l + 1 < s.size()) {
    		if (s[l] == s[l + 1]) {
    			len ++;
    		} else {
    			p.push_back({s[l], len});
    			len = 1;
    		}
    	}
    	l ++;
    }

/*    for (int i = 0; i < p.size(); i ++) {
    	std::cout << p[i].num << ' ' << p[i].len << '\n';
    }*/

    int n = s.size(); n --;
    i64 ans = n * (n + 1);
    // std::cout << ans << "??\n";
    for (int i = 0; i < p.size(); i ++) {
    	char num = p[i].num;
    	int len = p[i].len;
    	if (num == '1') {
    		int f = (len * (len + 1)) / 2;
    		ans -= (f * 2);
    	} else {
    		int f = (len * (len + 1)) / 2;
    		ans -= (f * 1);
    	}
    }

    std::cout << ans << '\n';
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

    for (int _ = [&]() -> int { int T; std::cin >> T; return T; }(); _; _ --)
        VioletEverGraden();

    return 0;
}