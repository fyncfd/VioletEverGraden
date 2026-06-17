/*
* @Author: AlgoStruggler
* @Create Time: 2026-02-13 14:33:11
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
    int n, m; i64 l;
    std::cin >> n >> m >> l;

    std::vector<i64> x(n + 1);
    for (int i = 1; i <= n; i ++) {
    	std::cin >> x[i];
    }

    std::vector<i64> y(m + 1);
    for (int i = 1; i <= m; i ++) {
    	std::cin >> y[i];
    }

    std::vector<i64> pre(n + 1, 0);
    for (int i = 1; i <= n; i ++) {
    	pre[i] = pre[i - 1] + x[i];
    }

    auto check = [&](i64 L, i64 R) -> bool {
    	auto it = std::upper_bound(pre.begin() + 1, pre.end(), L);
    	if (it != pre.end() && *it < R) {
    		return true;
    	}
    	return false;
    };

    i64 pos = 0; bool ok = false;
    if (check(pos, pos + l)) {
    	ok = true;
    }

    for (int i = 1; i <= m && !ok; i ++) {
    	pos = y[i];
    	if (check(pos, pos + l)) {
    		ok = true;
    	}
    }

    if (ok) {
    	std::cout << "YES\n";
    } else {
    	std::cout << "NO\n";
    }
/*
愿幸运女神与最纯粹的前行者同在。 
Test Sample

3 2 3
2 3 4
1 2

YES

2 2 2
3 3
3 3

NO


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