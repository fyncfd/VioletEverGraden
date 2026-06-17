/*
* @Author: AlgoStruggler
* @Create Time: 2026-02-15 19:03:22
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

    std::string t;
    std::cin >> t;
    t = "0" + t + "0";

    for (int i = 1; i + 1 < t.size(); i ++) {
    	if (t[i] == '1' && t[i + 1] == '0' && t[i - 1] == '0') {
    		std::cout << "NO\n";
    		return ;
    	}
    }

    std::cout << "YES\n";
/*
愿幸运女神与最纯粹的前行者同在。 
Test Sample

3
3
110
2
01
5
01111

YES
NO
YES


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