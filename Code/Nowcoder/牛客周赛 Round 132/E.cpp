/*
* @Author: AlgoStruggler
* @Create Time: 2026-02-22 19:25:37
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

constexpr int MAXT = 2e6 + 12;

static inline void VioletEverGraden() {
    int a, b, k;
    std::cin >> a >> b >> k;

    auto rev = [&](int x) -> int {
		int res = 0;
		while (x > 0) {
		    res = res * 10 + x % 10;
		    x /= 10;
		}
		return res;
    };

    if (a == b) {
    	std::cout << 0 << '\n';
    	return ;
    }

    std::vector<int> dis(MAXT, -1);
    std::vector<int> vis;
	std::queue<int> q;
	q.push(a);
	dis[a] = 0;
	vis.push_back(a);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		int d = dis[cur];

        if (cur % 10 != 0) {
            int revx = rev(cur);
            if (revx == b) {
                std::cout << d + 1 << '\n';
                for (int v : vis) {
                	dis[v] = -1;
                }
                vis.clear();
                return ;
            }
            if (revx <= MAXT && dis[revx] == -1) {
                dis[revx] = d + 1;
                vis.push_back(revx);
                q.push(revx);
            }
        }

        int nxt = cur + k;
        if (nxt == b) {
            std::cout << d + 1 << '\n';
            for (int v : vis) {
            	dis[v] = -1;
            }
            vis.clear();
            return ;
        }
        if (nxt <= MAXT && dis[nxt] == -1) {
            dis[nxt] = d + 1;
            vis.push_back(nxt);
            q.push(nxt);
        }
    }

    std::cout << -1 << '\n';
/*
愿幸运女神与最纯粹的前行者同在。 
Test Sample

3
123 321 2
123 444 123
123 123 114514

1
2
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