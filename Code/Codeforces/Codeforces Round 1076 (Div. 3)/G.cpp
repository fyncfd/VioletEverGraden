/*
* @Author: AlgoStruggler
* @Create Time: 2026-01-26 00:10:50
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
constexpr int MAXN = 200005; 
/*-------------------------------MY_CODE_BEGIN--------------------------------*/
static inline void VioletEverGraden() {
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> adj(n + 1);
    std::vector<bool> rem(n + 1, false);
    std::vector<int> sz(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    auto dfs = [&](auto&& dfs, int u, int p) -> void {
        sz[u] = 1;
        for (int v : adj[u]) {
            if (v != p && !rem[v]) {
                dfs(dfs, v, u);
                sz[u] += sz[v];
            }
        }
    };

    auto find = [&](auto&& find, int u, int p, int tot) -> int {
        for (int v : adj[u]) {
            if (v != p and !rem[v] and sz[v] > tot / 2) {
                return find(find, v, u, tot);
            }
        }
        return u;
    };

    auto query = [&](int a, int b) -> int {
        std::cout << "? " << a << " " << b << std::endl;
        std::cout.flush();
        int res;
        std::cin >> res;
        return res;
    };

    std::vector<int> f;
    for (int i = 1; i <= n; i ++) {
        f.push_back(i);
    }

    while (f.size() > 1) {
        int root = f[0];
        dfs(dfs, root, -1);
        int res = find(find, root, -1, sz[root]);

        if (query(res, res) == 1) {
            std::cout << "! " << res << std::endl;
            std::cout.flush();
            return ;
        }
    	rem[res] = true;

        int cop = -1;
        for (int v : adj[res]) {
            if (!rem[v]) {
                if (query(res, v) == 1) {
                    cop = v;
                    break;
                }
            }
        }

        if (cop == -1) {
            for (int v : adj[res]) {
                if (!rem[v]) {
                    if (query(v, v) == 1) {
                        std::cout << "! " << v << std::endl;
                        std::cout.flush();
                        return ;
                    }
                }
            }
            std::cout << "! " << res << std::endl;
            std::cout.flush();
            return ;
        }

        std::vector<bool> vis(n + 1, false);
        vis[res] = true;

        for (int v : adj[res]) {
            if (v != cop and !rem[v]) {
                std::queue<int> q;
                q.push(v);
                vis[v] = true;
                while (!q.empty()) {
                    int cur = q.front(); q.pop();
                    rem[cur] = true;
                    for (int nb : adj[cur]) {
                        if (!vis[nb] and !rem[nb]) {
                            vis[nb] = true;
                            q.push(nb);
                        }
                    }
                }
            }
        }

        f.clear();
        for (int i = 1; i <= n; i ++) {
            if (!rem[i]) {
                f.push_back(i);
            }
        }

        if (f.size() <= 2) {
            for (int node : f) {
                if (query(node, node) == 1) {
                    std::cout << "! " << node << std::endl;
                    std::cout.flush();
                    return ;
                }
            }
        }
    }

    std::cout << "! " << f[0] << std::endl;
    std::cout.flush();

    /*太好了，这回只花998244353min就打完了!
    真好。记得多手造几组。ACM拍什么拍。 */
/*
Test Sample

4
1 2 3 5 2
4
4
3 1 3 5 2
3 4 3
5 4 1
6 1 2 7 3
5 2 3 5 5 3
6 4 3 1 4 1
5 6 9 8 6
7 7 7 7 7
3 1 8 8 3

6
13
19
15


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