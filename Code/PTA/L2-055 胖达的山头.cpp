/*
* @Author: AlgoStruggler
* @Create Time: 2026-04-16 14:45:00
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

    auto f = [&](int h, int m, int s) -> int {
    	return h * 60 * 60 + m * 60 + s;
    };

    std::vector<int> a(23 * 60 * 60 + 59 * 60 + 60 + 100, 0);
    for (int i = 1; i <= n; i ++) {
    	int hs, ms, ss, hf, mf, sf;
    	scanf("%d:%d:%d %d:%d:%d", &hs, &ms, &ss, &hf, &mf, &sf);
    	a[f(hs, ms, ss)] ++; a[f(hf, mf, sf) + 1] --;  
    }

    int sum = 0; int ans = -1;
    for (int i = 1; i <= 23 * 60 * 60 + 59 * 60 + 60 + 50; i ++) {
    	sum = sum + a[i - 1];
    	ans = std::max(sum, ans);
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

    // std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

    // std::cout << std::fixed << std::setprecision(12), std::cerr << std::fixed << std::setprecision(12);

    // for (int _ = [&]() -> int { int T; std::cin >> T; return T; }(); _; _ --)
        VioletEverGraden();

    return 0;
}