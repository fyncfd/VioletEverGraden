/*
* @Author: AlgoStruggler
* @Create Time: 2026-03-20 19:31:56
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

#define int long long

static inline void VioletEverGraden() {
    int N;
    std::cin >> N;

    std::vector<i64> A(N + 1);
    for (int i = 1; i <= N; i ++) {
        std::cin >> A[i];
    }

    int tot = 1;
    std::vector<int> head(N + 1, -1);
    struct Edge {
        int to; int nxt;
    };
    std::vector<Edge> G(2 * N + 10);
    auto AddEdge = [&](int u, int v) {
        G[tot].to = v;
        G[tot].nxt = head[u];
        head[u] = tot ++;
    };

    int __ = N - 1;
    while (__ --) {
        int u, v;
        std::cin >> u >> v;
        AddEdge(u, v);
        AddEdge(v, u);
    }

    std::vector<int> sz(N + 1, 1);
    std::vector<int> sum(N + 1, 0);
    std::vector<int> fa(N + 1, -1);
    std::vector<int> f(N + 1, 0);

/*    auto check = [&](int u, i64 x) -> bool {
    	i64 SUM = A[u];
    	i64 SZ = 1;
    	for (int i = head[u]; ~i; i = G[i].nxt) {
    		int v = G[i].to;
    		if (v == fa[u]) {
    			continue;
    		}
	        i64 sup = sum[v] - sz[v] * x;
	        if (sup > 0) {
	        	SUM += sup;
	        }
	        SZ += sz[v];
    	}
    	return SUM >= x * SZ;
    };

    post(post, 1, -1);

    std::vector<int> f(N + 1, 0);
    for (int u : order) {
        i64 lo = 0; i64 hi = sum[u] / sz[u];
        while (lo < hi) {
            i64 mid = (lo + hi + 1) >> 1;
            if (check(u, mid)) {
    			lo = mid;
            } else {
            	hi = mid - 1;
            }
        }
        f[u] = lo;
    }*/

    auto dfs = [&](auto &&dfs, int u, int p) -> void {
        fa[u] = p;
        sz[u] = 1;
        sum[u] = A[u];
        i64 mSon = LINF;
        
        for (int i = head[u]; ~i; i = G[i].nxt) {
            int v = G[i].to;
            if (v == p) {
                continue;
            }
            dfs(dfs, v, u);
            sz[u] += sz[v];
            sum[u] += sum[v];
            mSon = std::min(mSon, (i64)f[v]);
        }

        i64 avg = sum[u] / sz[u];
        if (mSon == LINF) {
            f[u] = avg;
        } else {
            f[u] = std::min(avg, mSon);
        }
    };

    dfs(dfs, 1, -1);

    for (int i = 1; i <= N; i ++) {
        std::cout << f[i] << " \n"[i == N];
    }
/*
愿幸运女神与最纯粹的前行者同在。 
Test Sample

1
5
0 10 2 4 6
1 2
1 3
2 4
2 5

2 4 2 4 6


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