/*
* @Author: AlgoStruggler
* @Create Time: 2026-03-27 21:44:05
* "To the Splendor of ACM-ICPC, We Consecrate Our AC Triumphs."
*/
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

    std::vector<int> x(n + 1);
    for (int i = 0; i < n; i ++) {
    	std::cin >> x[i];
    }

    std::vector<int> pre(n + 1, 0);
    for (int i = 1; i <= n; i ++) {
    	pre[i] = pre[i - 1] ^ x[i - 1];
    }

    i64 cnt20 = 0;
    std::array<std::unordered_map<int, int>, 2> hash;
    // std::unordered_map<int, int> hash[2];
    for (int i = 0; i <= n; i ++) {
    	int p = i & 1;
    	int val = pre[i];
    	cnt20 += hash[p][val];
    	hash[p][val] ++;
    }

    i64 tot = 1LL * n * (n + 1) / 2;
    i64 c0 = (n + 2) / 2;
    i64 c1 = n + 1 - c0;
    i64 sum = 1LL * c0 * (c0 - 1) / 2 + 1LL * c1 * (c1 - 1) / 2;

    i64 ans1 = sum - cnt20;
    i64 ans2 = tot - ans1;

    std::cout << ans1 << ' ' << ans2 << '\n';

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