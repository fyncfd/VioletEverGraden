/*
* @Author: AlgoStruggler
* @Create Time: 2026-04-19 16:24:15
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
constexpr i64 Mod = 10007;

static inline void VioletEverGraden() {
    i64 n, m;
    std::cin >> n >> m;

    std::vector<i64> x(n + 1);
    for (int i = 1; i <= n; i ++) {
    	std::cin >> x[i];
    }

    std::sort(x.begin() + 1, x.end(), [&](i64 a, i64 b) -> bool {
    	return a < b;
    });

    int ofs = x[1] - 1;

    std::vector<int> dif(n + 2, 0);
    int __  = m;
    while (__ --) {
    	i64 l, r;
    	std::cin >> l >> r;
    	l -= ofs, r -= ofs;
    	l = std::max(1LL, l);
    	r = std::min(n, r);
    	if (l > r) {
    		continue;
    	}
    	dif[l] ++; dif[r + 1] --;
    }

    i64 sum = 0; i64 ans = 0;
    for (int i = 1; i <= n; i ++) {
    	sum = (sum + dif[i]);
    	ans += sum;
    	// ans %= Mod;
    }

    std::cout << (n * m - ans + Mod) % Mod << '\n';
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