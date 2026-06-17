/*
* @Author: AlgoStruggler
* @Create Time: 2026-01-31 20:35:42
* "To the Splendor of ACM-ICPC, We Consecrate Our AC Triumphs."
*/
#define  _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize("O2")
#include "bits/stdc++.h"
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;

using i64 = long long;
using ldb = long double;
typedef unsigned long long u64;
typedef __int128 i128;
struct pii { int fi; int se; };
struct pll { i64 fi; i64 se; };
#define debug(x) std::cerr << #x << " = " << x << '\n'
#define debug2(x, y) std::cerr << #x << " = " << x << ", " << #y << " = " << y << '\n'
/*------------------------------SORT_AND_UNIQUE-------------------------------*/
const double eps = 1e-9;
constexpr int INF = 0x3f3f3f3f;
constexpr i64 LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr i64 mod = 998244353;
constexpr i64 MOD = 1e9 + 7;
constexpr int MAXN = 3e5 + 15;
/*-------------------------------MY_CODE_BEGIN--------------------------------*/
static inline void VioletEverGraden() {
    int N, C;
    std::cin >> N >> C;

    std::vector<std::string> S(N + 1);
    for (int i = 1; i <= N; i ++) {
        std::cin >> S[i];
        S[i] = " " + S[i];
    }

    std::vector<std::vector<int>> w(N + 1);
    for (int i = 1; i <= N; i ++) {
        for (int j = N; j >= 1; j --) {
            if (S[j][i] == '#') {
                w[i].push_back(j);
            }
        }
    }

    std::vector<int> nxt(N + 1, INF);
    std::vector<int> id(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
        if (!w[i].empty()) {
            nxt[i] = w[i][0];
        }
    }

    std::vector<std::vector<bool>> vis(N + 1, std::vector<bool>(N + 1, false));
    std::queue<pii> q;
    q.emplace(N, C);
    vis[N][C] = true;

    auto bfs = [&]() {
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            if (r == 1) {
            	continue;
            }
            for (int nc : {c - 1, c, c + 1}) {
                if (nc < 1 || nc > N) {
                	continue;
                }
                int nr = r - 1;
                if (vis[nr][nc]) {
                	continue;
                }

                if (S[nr][nc] == '.') {
                    vis[nr][nc] = true;
                    q.emplace(nr, nc);
                } else if (S[nr][nc] == '#' and nr == nxt[nc]) {
                    vis[nr][nc] = true;
                    q.emplace(nr, nc);
                    id[nc] ++;
                    if (id[nc] < static_cast<int>(w[nc].size())) {
                        nxt[nc] = w[nc][id[nc]];
                    } else {
                        nxt[nc] = INF;
                    }
                }
            }
        }
    };

    bfs();

    for (int i = 1; i <= N; i ++) {
        std::cout << (vis[1][i] ? '1' : '0');
    }
    std::cout << '\n';
    
    /*太好了，这回只花998244353min就打完了!
    真好。记得多手造几组。ACM拍什么拍。 */
/*
Test Sample

5
5 3
.###.
..#..
#.#.#
#...#
##..#
2 2
##
..
4 1
####
####
####
.###
3 3
...
...
...
10 3
##.##.##.#
.####..#..
...#.#..#.
.#.#.#.#..
...####...
#.#.##....
.##...#...
#.##.....#
#....###.#
.#..#.#...

10111
11
1000
111
0011010010


*/
}
/*-----------------------------Algostruggler----------------------------------*/
signed main() {
#ifdef LOCAL
    freopen("A.in", "r", stdin);
#endif // LOCAL

    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

    /*std::cout << std::fixed << std::setprecision(9);
    std::cerr << std::fixed << std::setprecision(9);*/

    int _ = 1;
    for (std::cin >> _; _; _--)
        VioletEverGraden();

    return 0;
}