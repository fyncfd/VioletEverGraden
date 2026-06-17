/*
* @Author: AlgoStruggler
* @Create Time: 2026-02-13 16:57:42
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

constexpr int dx[] = {1, -1, 0, 0};
constexpr int dy[] = {0, 0, 1, -1};

static inline void VioletEverGraden() {
    int n, m, a, b;
    std::cin >> n >> m >> a >> b;

    std::vector<std::vector<int>> dis(n + 2, std::vector<int>(m + 2, INF));
    std::vector<std::vector<int>> dfn(n + 2, std::vector<int>(m + 2, 0));
    using tii = std::tuple<int, int, int>;
    std::priority_queue<tii, std::vector<tii>, std::greater<tii>> heap;

    for (int i = 1; i <= a; i ++) {
    	int x, y;
    	std::cin >> x >> y;
    	dis[x][y] = 0;
    	heap.push({0, x, y});
    }

    for (int i = 1; i <= b; i ++) {
    	int x, y, t;
    	std::cin >> x >> y >> t;
    	dfn[x][y] = t;
    }

    while (!heap.empty()) {
    	auto [t, x, y] = heap.top();
    	heap.pop();

    	for (int i = 0; i < 4; i ++) {
    		int nx = x + dx[i]; int ny = y + dy[i];
    		if (nx < 1 || nx > n || ny < 1 || ny > m) {
    			continue;
    		}
    		int nt = t + 1;

    		if (dfn[nx][ny] > 0) {
    			if (nt < dfn[nx][ny]) {
    				nt = dfn[nx][ny];
    			}
    		}

    		if (nt < dis[nx][ny]) {
    			dis[nx][ny] = nt;
    			heap.push({nt, nx, ny});
    		}
    	}
    }

    int ans = 0;
    for (int i = 1; i <= n; i ++) {
    	for (int j = 1; j <= m; j ++) {
    		ans = std::max(ans, dis[i][j]);
    	}
    }

    std::cout << ans << '\n';
/*
愿幸运女神与最纯粹的前行者同在。 
Test Sample

3 3 1 1
1 1
1 2 5

5

2 4 2 1
1 1
2 4
1 2 100

100

2 4 1 1
1 1
1 2 4

5


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