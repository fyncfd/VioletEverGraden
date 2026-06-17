/*
* @Author: AlgoStruggler
* @Create Time: 2026-03-06 19:12:54
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
    std::string a, b;
    std::cin >> a >> b;

    if (a.size() != b.size()) {
    	std::cout << -1 << '\n';
    	return ;
    }

    for (int i = 0; i < a.size(); i ++) {
    	int x = a[i] - '0'; int y = b[i] - '0';
    	int t = x * y;
    	std::cout << t;
    }

    std::cout << '\n';
/*
愿幸运女神与最纯粹的前行者同在。 
Test Sample

3
123 456
1000000000 1000000000
1 23

41018
1000000000
-1


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