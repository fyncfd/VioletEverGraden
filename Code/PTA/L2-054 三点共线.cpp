/*
* @Author: AlgoStruggler
* @Create Time: 2026-04-15 21:48:31
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

    std::vector<std::vector<bool>> vis(3, std::vector<bool> (2000012, false));
    std::vector<std::vector<int>> p(3);
    for (int i = 1; i <= n; i ++) {
    	int x, y;
    	std::cin >> x >> y;
    	x += 1000000;
    	if (!vis[y][x]) {
    		p[y].push_back(x);
    		vis[y][x] = true;
    	}
    }

    if (p[0].size() == 0 || p[1].size() == 0 || p[2].size() == 0) {
    	std::cout << -1 << '\n';
    	return ;
    }

    std::vector<bool> Vis(2000012, false);
    for (int i = 0; i < p[1].size(); i ++) {
    	Vis[p[1][i]] = true;
    }

    struct pii {
    	int x1, x2, x3;
    };
    std::vector<pii> ans;
    for (int i = 0; i < p[0].size(); i ++) {
    	for (int j = 0; j < p[2].size(); j ++) {
    		int x1 = p[0][i]; int y1 = 0;
    		int x3 = p[2][j]; int y3 = 2;
    		if ((x1 + x3) & 1) {
    			continue;
    		} else {
    			int x2 = (x1 + x3) / 2;
    			if (Vis[x2]) {
    				ans.push_back({x1, x2, x3});
    			}
    		}
    	}
    }

    if (ans.size() == 0) {
    	std::cout << -1 << '\n';
    	return ;
    }

    std::sort(ans.begin(), ans.end(), [&](pii a, pii b) -> bool {
    	if (a.x2 == b.x2) {
    		return a.x1 < b.x1;
    	}
    	return a.x2 < b.x2;
    });

    for (int i = 0; i < ans.size(); i ++) {
    	std::cout << '[' << ans[i].x1 - 1000000 << ", " << 0 << "] " << '[' << ans[i].x2 - 1000000 << ", " << 1 << "] " << '[' << ans[i].x3 - 1000000 << ", " << 2 << "]\n";
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