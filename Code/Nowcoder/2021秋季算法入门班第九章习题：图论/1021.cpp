/*
* @Author: AlgoStruggler
* @Create Time: 2026-05-07 20:21:38
* "To the Splendor of ACM-ICPC, We Consecrate Our AC Triumphs."
*/
/*
* @Author: AlgoStruggler
* @Create Time: 2026-05-07 14:57:52
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

constexpr int dx[] = {1, 0, -1, 0};
constexpr int dy[] = {0, 1, 0, -1};

static inline void VioletEverGraden() {
    int N;
    std::cin >> N;

    std::vector<std::vector<char>> g(N + 1, std::vector<char> (N + 1));
    for (int i = 1; i <= N; i ++) {
    	for(int j = 1; j <= N; j ++) {
    		std::cin >> g[i][j];
    	}
    }


    int sx = 0, sy = 0, ex = 0, ey = 0;
    for (int i = 1; i <= N; i ++) {
    	for (int j = 1; j <= N; j ++) {
    		if (g[i][j] == 'A') {
    			sx = i, sy = j;
    		}
    		if (g[i][j] == 'B') {
    			ex = i, ey = j;
    		}
    	}
    }

    std::vector<std::vector<bool>> vis(N + 1, std::vector<bool> (N + 1, false));
    auto check = [&](int x, int y) -> bool {
    	if (x < 1 || x > N || y < 1 || y > N || g[x][y] == 'x' || vis[x][y]) {
    		return true;
    	}
    	return false;
    };

    int ans = 0;
    [&](int x, int y) -> void {
    	struct Node {
    		int x, y;
    		int px, py;
    		int dis;
    		bool operator < (const Node &a) const {
    			return dis > a.dis;
    		};
    	};

    	std::priority_queue<Node> pq;
    	pq.push({sx, sy, sx, sy, 0});
    	vis[sx][sy] = true;

    	while (!pq.empty()) {
    		auto [x, y, px, py, cnt] = pq.top();
    		pq.pop();

    		if (x == ex && y == ey) {
    			ans = cnt;
    			return ;
    		}

    		vis[x][y] = true;
    		for (int i = 0; i < 4; i ++) {
    			int nx = x + dx[i], ny = y + dy[i];
    			if (check(nx, ny)) {
    				continue;
    			}
    			int add = 0;
    			if (px != nx && py != ny) {
    				add ++;
    			}
    			pq.push({nx, ny, x, y, cnt + add});
    		}
    	}
		ans = -1;
		return ;
    }(sx, sy);

    std::cout << ans << '\n';
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