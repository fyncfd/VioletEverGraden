/*
* @Author: AlgoStruggler
* @Create Time: 2026-02-01 19:32:12
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
/*----------------------------------SORT_AND_UNIQUE-----------------------------------*/
const double eps = 1e-9;
constexpr int INF = 0x3f3f3f3f;
constexpr i64 LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr i64 mod = 998244353;
constexpr i64 MOD = 1e9 + 7;
constexpr int MAXN = 0;
/*-----------------------------------MY_CODE_BEGIN------------------------------------*/
i64 ksm(i64 a, i64 b, i64 p) {
    i64 res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

i64 inv(i64 a) {
    return ksm(a, MOD - 2, MOD);
}
static inline void VioletEverGraden() {
    int n;
    std::cin >> n;

    int tot = 0;
    std::vector<int> head(n + 1, -1);
    struct Edge {
    	int to; int nxt;
    };
    std::vector<Edge> G(2 * n + 10);
    auto AddEdge = [&](int u, int v) -> void {
    	G[tot].to = v;
    	G[tot].nxt = head[u];
    	head[u] = tot ++;
    };

    int __ = n - 1;
    std::vector<int> deg(n + 1, 0);
    while (__ --) {
    	int u, v;
    	std::cin >> u >> v;
    	AddEdge(u, v); AddEdge(v, u);
    	deg[u] ++; deg[v] ++;
    }

    i64 ans = 0;
    std::vector<int> fa(n + 1);
    auto dfs = [&](auto &&dfs, int u, int p) -> void {
    	ans = (ans + fa[u]) % MOD;
    	for (int i = head[u]; ~i; i = G[i].nxt) {
    		int v = G[i].to;
    		if (v == p) {
    			continue;
    		}
	        fa[v] = fa[u] * inv(deg[u]) % MOD;
	        dfs(dfs, v, u);
    	}
    };
    
    fa[1] = 1;
    dfs(dfs, 1, 0);

    std::cout << ans << '\n';
    /* 愿幸运女神与最纯粹的前行者同在。 */
/*
Test Sample

3
1 2
2 3

500000006

4
1 2
1 3
2 4

250000004

4
2 3
2 4
2 1

666666674


*/
}
/*---------------------------------Algostruggler--------------------------------------*/
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