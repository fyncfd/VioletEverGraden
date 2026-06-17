/*
* @Author: AlgoStruggler
* @Create Time: 2026-04-06 15:38:50
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

	int q;
	std::cin >> q;

    std::vector<std::vector<int>> a(n + 1, std::vector<int>(n + 1));
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            a[i][j] = (i - 1) * n + j;
        }
    }

    int __ = q;
    while (__ --) {
        int op, x, y, len;
        std::cin >> op >> x >> y >> len;

        std::vector<std::vector<int>> sub(len + 1, std::vector<int>(len + 1));
        for (int i = 1; i <= len; i ++) {
            for (int j = 1; j <= len; j ++) {
                sub[i][j] = a[x + i - 1][y + j - 1];
            }
        }

        if (op == 1) {
            for (int i = 1; i <= len; i ++) {
                for (int j = 1; j <= len; j ++) {
                    a[x + j - 1][y + len - i] = sub[i][j];
                }
            }
        } else {
            for (int i = 1; i <= len; i ++) {
                for (int j = 1; j <= len; j ++) {
                    a[x + len - j][y + i - 1] = sub[i][j];
                }
            }
        }
    }

    int d;
    std::cin >> d;

    __ = d;
    while (__ --) {
        int dx, dy;
        std::cin >> dx >> dy;

        std::cout << a[dx][dy] << '\n';
    }
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