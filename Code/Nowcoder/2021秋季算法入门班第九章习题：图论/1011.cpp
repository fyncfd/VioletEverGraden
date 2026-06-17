/*
* @Author: AlgoStruggler
* @Create Time: 2026-04-29 19:25:49
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

template <typename T>
class DisjointSetUnion {
private:
	int N;
	std::vector<int> Parent;
	std::vector<int> Size;
public:
    DisjointSetUnion(int n) : N(n), Parent(N + 1), Size(N + 1) {
        std::iota(Parent.begin() + 1, Parent.end(), 1);
        Size.assign(N + 1, 1);
    }

    int find(int x) {
    	while (x != Parent[x]) {
    		x = Parent[x] = Parent[Parent[x]];
    	}
    	return x;
    }

    bool same(int x, int y) {
    	return find(x) == find(y);
    }

    bool Merge(int x, int y) {
        int RootX = find(x);
        int RootY = find(y);
        
        if (RootX == RootY) {
            return false;
        }

        if (Size[RootX] < Size[RootY]) {
            std::swap(RootX, RootY);
        }
        
        Parent[RootY] = RootX;
        Size[RootX] += Size[RootY];
        
        return true;
    }

    int size(int x) {
        return Size[find(x)];
    }
};

#define int long long

static inline void VioletEverGraden() {
    int n;
    while (std::cin >> n) {
		int tot = 1;
		struct Edge {
			int to; int nxt; i64 w;
		};
		std::vector<int> head(n + 1, -1);
		std::vector<Edge> G(2 * n + 10);
		auto AddEdge = [&](int u, int v, int w = 0) -> void {
			G[tot].to = v;
			G[tot].nxt = head[u];
			G[tot].w = w;
			head[u] = tot ++;
		};

		int __ = n - 1;
		while (__ --) {
			int u, v, w;
			std::cin >> u >> v >> w;
			AddEdge(u, v, w); AddEdge(v, u, w);
		}

		int c = 0;
		std::vector<i64> dis(n + 1, 0);
		auto dfs = [&](auto &&dfs, int u, int fa) -> void {
			for (int i = head[u]; ~i; i = G[i].nxt) {
				int v = G[i].to, w = G[i].w;
				if (v == fa) {
					continue;
				}
				dis[v] = dis[u] + w;
				if (dis[v] > dis[c]) {
					c = v;
				}
				dfs(dfs, v, u);
			}
		};

		int A = 0;
		dfs(dfs, 1, 0);
		A = c;

		int B = 0;
		dis[c] = 0;
		dfs(dfs, c, 0);
		B = c;

		int L = dis[c];

		std::vector<i64> disA(n + 1, 0);
		auto dfs1 = [&](auto &&dfs1, int u, int fa) -> void {
			for (int i = head[u]; ~i; i = G[i].nxt) {
				int v = G[i].to, w = G[i].w;
				if (v == fa) {
					continue;
				}
				disA[v] = disA[u] + w;
				dfs1(dfs1, v, u);
			}
		};

		dfs1(dfs1, A, 0);

		std::vector<i64> disB(n + 1, 0);
		auto dfs2 = [&](auto &&dfs2, int u, int fa) -> void {
			for (int i = head[u]; ~i; i = G[i].nxt) {
				int v = G[i].to, w = G[i].w;
				if (v == fa) {
					continue;
				}
				disB[v] = disB[u] + w;
				dfs2(dfs2, v, u);
			}
		};

		dfs2(dfs2, B, 0);

		i64 ans = -L;
		for (int u = 1; u <= n; u ++) {
			ans += std::max(disA[u], disB[u]);
		}

		std::cout << ans << '\n';
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