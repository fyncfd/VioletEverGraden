/*
* @Author: AlgoStruggler
* @Create Time: 2026-02-06 22:54:38
* "To the Splendor of ACM-ICPC, We Consecrate Our AC Triumphs."
*/
#define  _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize("O2")
#include "bits/stdc++.h"
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using ldb = long double;
typedef unsigned long long u64;
typedef __int128 i128;
typedef unsigned __int128 u128;

const double eps = 1e-9;
constexpr int INF = 0x3f3f3f3f;
constexpr i64 LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr i64 mod = 998244353;
constexpr i64 MOD = 1e9 + 7;
constexpr int MAXN = 3e5 + 15;

static inline void VioletEverGraden() {
    int N, M;
    std::cin >> N >> M;

/*
* @Author: AlgoStruggler
* 链式前向星建图，AddEdge函数默认构造无边权的边。
* @Create Time: 2025-02-03 13:10:02
* "To the Splendor of ACM-ICPC, We Consecrate Our AC Triumphs."
* 愿幸运女神与最纯粹的前行者同在。
*/
	int tot = 1;
	struct Edge {
		int to; int nxt; int w;
	};
	std::vector<int> head(N + 1, -1);
	std::vector<Edge> G(M + 10);
	auto AddEdge = [&](int u, int v, int w = 0) -> void {
		G[tot].to = v;
		G[tot].nxt = head[u];
		G[tot].w = w;
		head[u] = tot ++;
	};

	int __ = M;
	while (__ --) {
		int u, v, w;
		std::cin >> u >> v;
		AddEdge(v, u);
	}
    
    // std::map<int, bool> mp;
    bool vis[MAXN] = {false};
    auto dfs = [&](auto &&dfs, int u) -> void {
    	vis[u] = true;
    	for (int i = head[u]; ~i; i = G[i].nxt) {
    		int v = G[i].to;
    	// mp[u] = true;
    		if (!vis[v]) {
    			vis[v] = true;
    			dfs(dfs, v);
    		}
    	}
    };

    int Q;
    std::cin >> Q;
    __ = Q;
    while (__ --) {
    	int op;
    	std::cin >> op;

    	if (op == 1) {
    		int u;
    		std::cin >> u;
    		if (!vis[u]) {
    			dfs(dfs, u);
    		}
    	} else {
    		int u;
    		std::cin >> u;
    		if (vis[u]) {
    			std::cout << "Yes\n";
    		} else {
    			std::cout << "No\n";
    		}
    	}
    }

    /* 愿幸运女神与最纯粹的前行者同在。 */
/*
Test Sample

5 6
1 2
2 3
3 1
4 5
1 4
2 5
5
1 3
2 1
2 4
1 5
2 4

Yes
No
Yes


*/
}

signed main() {
#ifdef Algostruggler
    freopen("A.in", "r", stdin);
#endif // Algostruggler

    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

    /*std::cout << std::fixed << std::setprecision(9);
    std::cerr << std::fixed << std::setprecision(9);*/

    int _ = 1;
    //for (std::cin >> _; _; _--)
        VioletEverGraden();

    return 0;
}