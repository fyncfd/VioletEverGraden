/*
* @Author: AlgoStruggler
* @Create Time: 2026-01-25 19:00:54
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
    int n;
    std::cin >> n;

    int tot = 1;
    std::vector<int> head(n + 1, -1);
    struct Edge {
    	int to; int nxt;
    };
    std::vector<Edge> G(2 * n + 100);
    auto AddEdge = [&](int u, int v) -> void {
    	G[tot].to = v;
    	G[tot].nxt = head[u];
    	head[u] = tot ++;
    };

    int __ = n - 1;
    while (__ --) {
    	int u, v;
    	std::cin >> u >> v;
    	AddEdge(u, v); AddEdge(v, u);
    }

    if (n == 1) {
    	std::cout << 1 << '\n';
    	return ;
    }

    std::vector<int> sz(n + 1, 0); std::vector<int> fa(n + 1, 0);
    auto dfs = [&](auto &&dfs, int u, int p) -> void {
    	fa[u] = p;
    	sz[u] = 1;
    	for (int i = head[u]; ~i; i = G[i].nxt) {
    		int v = G[i].to;
    		if (v == p) {
    			continue;
    		}
    		dfs(dfs, v, u);
    		sz[u] += sz[v];
    	}
    };

    dfs(dfs, 1, 0);

    int ans = 0;
    for (int u = 1; u <= n; u ++) {
    	bool ok = true;
    	for (int i = head[u]; ~i; i = G[i].nxt) {
    		int v = G[i].to;
    		int p = 0;
    		if (v == fa[u]) {
    			p = n - sz[u];
    		} else {
    			p = sz[v];
    		}

    		if (p % 2 == 0) {
    			ok = false;
    			break;
    		}
    	}

    	if (ok) {
    		ans ++;
    	}
    }

    std::cout << ans << '\n';
    
    /*太好了，这回只花998244353min就打完了!
    真好。记得多手造几组。ACM拍什么拍。 */
/*
Test Sample

3
3
1 2
2 3
5
1 2
1 3
3 4
3 5
4
1 2
1 3
1 4

1
1
4


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