/*
* @Author: AlgoStruggler
* @Create Time: 2026-04-05 19:13:34
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

    std::vector<i64> a(n + 1);
    for (int i = 1; i <= n; i ++) {
    	std::cin >> a[i];
    }

    bool ok = true;
    for (int i = 1; i < n; i ++) {
    	if (a[i] > a[i + 1]) {
    		ok = false;
    	}
    }

    if (ok) {
    	std::cout << 0 << '\n';
    	return ;
    }

    auto f = [&](i64 x) -> i64 {
        i64 res = 0;
        while (x) {
            res += x % 10;
            x /= 10;
        }
        return res;
    };

    int ans = 0;
    for (int i = n - 1; i >= 1; i --) {
        int cnt = 0;
        while (a[i] > a[i + 1] && cnt <= 10) {
            a[i] = f(a[i]);
            cnt ++;
        }
        
        if (a[i] > a[i + 1]) {
            std::cout << -1 << '\n';
            return ;
        }
        ans += cnt;
    }

    std::cout << ans << '\n';
/*
愿幸运女神与最纯粹的前行者同在。 
Test Sample

4
4
99 10 10 10
3
100 19 10
2
29 1
5
1 2 3 3 9

2
2
-1
0


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