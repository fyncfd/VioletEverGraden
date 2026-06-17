/*
* @Author: AlgoStruggler
* @Create Time: 2026-05-10 19:46:55
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
	int n, k;
	std::cin >> n >> k;

	std::vector<std::pair<int, int>> seg(n + 1);
	std::vector<int> Len;
	for (int i = 1; i <= n; i ++) {
		i64 l, r;
		std::cin >> l >> r;
		seg[i] = {l, r};
        Len.push_back(l - k);
        Len.push_back(r);
        Len.push_back(l);
        Len.push_back(r + 1);
	}

    std::sort(Len.begin(), Len.end());
    Len.erase(std::unique(Len.begin(), Len.end()), Len.end());
    int m = Len.size();
    std::vector<int> dif(m + 2, 0);

    for (auto [l, r] : seg) {
        int L = std::lower_bound(Len.begin(), Len.end(), l - k) - Len.begin();
        int R = std::lower_bound(Len.begin(), Len.end(), r) - Len.begin();
        dif[L] += 1;
        dif[R + 1] -= 1;
    }
    int ans = 0, cur = 0;
    for (int i = 0; i < m; ++i) {
        cur += dif[i];
        ans = std::max(ans, cur);
    }
    std::cout << ans << '\n';
/*
愿幸运女神与最纯粹的前行者同在。 
Test Sample

5 2
1 3
2 4
5 7
6 8
9 9

3


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