/*
* @Author: AlgoStruggler
* @Create Time: 2026-02-22 19:14:37
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

    std::vector<i64> odd, even;
    i64 sum1 = 0, sum2 = 0;
    for (int i = 1; i <= n; i ++) {
    	int x;
    	std::cin >> x;

    	if (x & 1) {
    		odd.push_back(x);
    		sum1 += x;
    	} else {
    		even.push_back(x);
    		sum2 += x;
    	}
    }

    i64 cnt1 = odd.size();
    i64 cnt2 = even.size();

    i64 ans = 0;
    ans += sum2 * (cnt2 - 1);
    ans += sum1 * (cnt1 - 1);

    ans += sum1 * cnt2 + sum2 * cnt1 - cnt1 * cnt2;

    ans /= 2;

    std::cout << ans << '\n';
/*
愿幸运女神与最纯粹的前行者同在。 
Test Sample

3
3
1 2 3
4
5 5 5 5
2
100000 1

5
30
50000


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