/*
* @Author: AlgoStruggler
* @Create Time: 2026-01-17 20:53:39
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
constexpr int MAXN = 0;
/*-------------------------------MY_CODE_BEGIN--------------------------------*/
static inline void VioletEverGraden() {
    int N, M, L, S, T;
    std::cin >> N >> M >> L >> S >> T;

    int tot = 1;
    std::vector<int> head(N + 1, -1);
    struct Edge {
        int to; int nxt; int w;
    };
    std::vector<Edge> G(M + 10);
    auto AddEdge = [&](int u, int v, int w) -> void {
        G[tot].to = v;
        G[tot].nxt = head[u];
        G[tot].w = w;
        head[u] = tot ++;
    };

    int __ = M;
    while (__ --) {
        int u, v, w;
        std::cin >> u >> v >> w;
        AddEdge(u, v, w);
    }

    std::set<int> ans;
    auto dfs = [&](auto &&dfs, int u, int p, i64 sum) -> void {
        if (sum > T) {
            return ;
        }

        if (p == L) {
            if (sum >= S and sum <= T) {
                ans.insert(u);
            }
            return ;
        }

        for (int i = head[u]; ~i; i = G[i].nxt) {
            int v = G[i].to ; int w = G[i].w;
            if (sum + w > T) {
                continue;
            }
            dfs(dfs, v, p + 1, sum + w);
        }
    };

    dfs(dfs, 1, 0, 0);

    if (ans.empty()) {
        std::cout << '\n';
    } else {
        for (auto x : ans) {
            std::cout << x << ' ';
        }
        std::cout << '\n';
    }
    
    /*太好了，这回只花998244353min就打完了!
    真好。记得多手造几组。ACM拍什么拍。 */
/*
Test Sample

5 8 3 80 100
1 2 20
1 3 70
2 1 30
2 5 10
3 2 10
3 4 30
3 5 20
5 1 70


1 5

10 1 1 1 100
2 3 1



2 5 3 1 100
1 1 1
2 2 100
1 2 1
1 2 1
1 2 100

1 2


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
    //for (std::cin >> _; _; _--)
        VioletEverGraden();

    return 0;
}