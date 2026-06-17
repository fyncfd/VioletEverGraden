/*
* @Author: AlgoStruggler
* @Create Time: 2026-02-14 20:07:03
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
    int N;
    std::cin >> N;

    std::vector<std::string> S(N + 1);
    int max = -1;
    for (int i = 1; i <= N; i ++) {
    	std::cin >> S[i];
    	int sz = S[i].size();
    	max = std::max(max, sz);
    }

    for (int i = 1; i <= N; i ++) {
    	int dif = max - S[i].size();
    	for (int i = 1; i <= dif / 2; i ++) {
    		std::cout << '.';
    	}
    	std::cout << S[i];
    	for (int i = 1; i <= dif / 2; i ++) {
    		std::cout << '.';
    	}
    	std::cout << '\n';
    }
/*
愿幸运女神与最纯粹的前行者同在。 
Test Sample

4
apple
blueberry
coconut
dragonfruit

...apple...
.blueberry.
..coconut..
dragonfruit

6
abc
d
efghi
jkl
mnopq
r

.abc.
..d..
efghi
.jkl.
mnopq
..r..


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