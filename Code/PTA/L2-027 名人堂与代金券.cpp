/*
* @Author: AlgoStruggler
* @Create Time: 2026-04-16 15:01:42
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
    int n, g, k;
    std::cin >> n >> g >> k;

    int sum = 0;
    struct pii {
    	std::string s;
    	int w;
    };
    std::vector<pii> f;
    for (int i = 1; i <= n; i ++) {
    	std::string s; int p;
    	std::cin >> s >> p;
    	f.push_back({s, p});
    	if (p >= 60 && p < g) {
    		sum += 20;
    	} else if (p >= g) {
    		sum += 50;
    	}
    }

    std::vector<pii> ans;
    for (int i = 0; i < f.size(); i ++) {
    	if (f[i].w >= k) {
    		ans.push_back(f[i]);
    	}
    }

    if (ans.empty()) {
        std::cout << sum << '\n';
        return;
    }

    std::sort(ans.begin(), ans.end(), [&](pii a, pii b) -> bool {
    	if (a.w == b.w) {
    		return a.s < b.s;
    	}
    	return a.w > b.w;
    });

    std::vector<int> rk; rk.push_back(1); int cnt = 1;
    for (int i = 1; i < ans.size(); i ++) {
    	if (ans[i].w < ans[i - 1].w) {
    		rk.push_back(++ cnt);
    	} else if (ans[i].w == ans[i - 1].w) {
    		rk.push_back(cnt);
    	}
    }

/*    int sz = ans.size();
    if (ans[sz - 1].w > ans[sz - 2].w) {
    	rk.push_back(++ cnt);
    } else if (ans[sz - 1].w == ans[sz - 2].w) {
    	rk.push_back(cnt);
    }*/

    std::cout << sum << '\n';
    for (int i = 0; i < ans.size(); i ++) {
    	std::cout << rk[i] << ans[i].s << ' ' << ans[i].w << '\n';
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