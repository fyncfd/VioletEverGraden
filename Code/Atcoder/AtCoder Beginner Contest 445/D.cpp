/*
* @Author: AlgoStruggler
* @Create Time: 2026-02-14 20:22:05
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
    int H, W, N;
    std::cin >> H >> W >> N;

    std::vector<std::array<int, 3>> f(N + 1);
    for (int i = 1; i <= N; i ++) {
        std::cin >> f[i][0] >> f[i][1];
        f[i][2] = i;
    }

    std::sort(f.begin() + 1, f.end(), [&](const auto &a, const auto &b) {
        if (a[0] != b[0]) return a[0] > b[0];
        return a[1] > b[1];
    });

    std::set<std::pair<int, int>, std::greater<std::pair<int, int>>> st;
    st.insert({W, H});

    std::vector<std::pair<int, int>> ans(N + 1);

    for (int i = 1; i <= N; i ++) {
        const auto& p = f[i];
        int nh = p[0], nw = p[1];
        auto it = st.lower_bound({nw, nh});
        int w = it->first, h = it->second;
        st.erase(it);

        ans[p[2]] = {H - h + 1, W - w + 1};

        if (h > nh) {
            st.insert({w, h - nh});
        }
        if (w > nw) {
            st.insert({w - nw, nh});
        }
    }

    for (int i = 1; i <= N; i ++) {
        std::cout << ans[i].first << " " << ans[i].second << "\n";
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