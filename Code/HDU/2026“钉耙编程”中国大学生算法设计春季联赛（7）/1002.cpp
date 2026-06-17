/*
* @Author: AlgoStruggler
* @Create Time: 2026-05-08 18:33:06
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

    std::vector<std::vector<int>> g(n + 1, std::vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            std::cin >> g[i][j];
        }
    }

    std::vector<std::map<int, bool>> visl(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            visl[i][g[i][j]] = true;
        }
    }

    std::vector<std::map<int, bool>> visc(n + 1);
    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= n; i++) {
            visc[j][g[i][j]] = true;
        }
    }

    std::vector<int> ans;

    for (int val = 1; val <= n * n; val++) {
        bool ok = true;
        for (int i = 1; i <= n; i++) {
            if (!visl[i][val]) {
                ok = false;
                break;
            }
        }

        if (ok) {
            for (int j = 1; j <= n; j++) {
                if (!visc[j][val]) {
                    ok = false;
                    break;
                }
            }
        }
        
        if (ok) {
            ans.push_back(val);
        }
    }

    std::cout << ans.size() << '\n';
    if (!ans.empty()) {
        for (int i = 0; i < ans.size(); i ++) {
            std::cout << ans[i] << " \n"[i + 1 == ans.size()];
        }
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

    for (int _ = [&]() -> int { int T; std::cin >> T; return T; }(); _; _ --)
        VioletEverGraden();

    return 0;
}