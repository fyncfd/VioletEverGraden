/*
* @Author: AlgoStruggler
* @Create Time: 2026-04-28 19:07:16
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

constexpr int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
constexpr int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};

static inline void VioletEverGraden() {
    int Q, N, M;
    std::cin >> Q >> N >> M;

    while (Q --) {
    	std::vector<std::vector<i64>> g(N + 1, std::vector<i64> (M + 1));
    	for (int i = 1; i <= N; i ++) {
    		for (int j = 1; j <= M; j ++) {
    			std::cin >> g[i][j];
    			// if (g[i][j] == 0 && !(i==1 && j==1) && !(i==N && j==M)) {
    			// 	g[i][j] = LINF;
    			// }
    		}
    	}

    	std::vector<std::vector<i64>> dis(N + 1, std::vector<i64> (M + 1, LINF));
        auto Dijkstra = [&](int x, int y) -> void {
            struct pii {
                i64 x, y, d;
                bool operator < (const pii& other) const {
                    return d > other.d;
                }
            };
            std::priority_queue<pii> q;
            dis[x][y] = 0;
            q.push({x, y, 0});

            while(!q.empty()) {
                auto [x, y, d] = q.top();
                q.pop();
                if (d != dis[x][y]) continue;

                for (int i = 0; i < 8; i ++) {
                    int nx = x + dx[i]; 
                    int ny = y + dy[i];

                    if (nx < 1 || nx > N || ny < 1 || ny > M) continue;

                    if (g[nx][ny] == -1) continue;

                    if (g[nx][ny] == 0 && !(nx == N && ny == M)) continue;

                    i64 w = (g[nx][ny] == 0 ? 0 : g[nx][ny]);

                    if (dis[nx][ny] > dis[x][y] + w) {
                        dis[nx][ny] = dis[x][y] + w;
                        q.push({nx, ny, dis[nx][ny]});
                    }
                }
            }
        };

        Dijkstra(1, 1);

        if (dis[N][M] >= LINF / 2) {
            std::cout << -1 << '\n';
        } else {
            std::cout << dis[N][M] << '\n';
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

    // for (int _ = [&]() -> int { int T; std::cin >> T; return T; }(); _; _ --)
        VioletEverGraden();

    return 0;
}