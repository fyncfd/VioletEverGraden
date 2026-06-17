/*
* @Author: AlgoStruggler
* @Create Time: 2026-05-08 18:58:25
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

/*template <typename T>
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
};*/

static inline void VioletEverGraden() {
    int n;
    std::cin >> n;

    std::vector<i64> a(n + 1);
    for (int i = 1; i <= n; i ++) {
    	std::cin >> a[i];
    }

/*    struct Edge {
    	i64 u, v, w;
    };
    std::vector<Edge> g;

    int odd = n + 1, even = 0;
    for (int i = 1; i <= n; i ++) {
    	if (i & 1) {
    		g.push_back({i, odd, a[i]});
    	} else {
    		g.push_back({i, even, a[i]});
    	}
    }

    for (int i = 1; i + 2 <= n; i ++) {
    	g.push_back({i, i + 2, 2 * a[i + 1]});
    }*/

/*    for (int u = 1; u <= n; u ++) {
    	for (int v = u + 1; v <= n; v ++) {
    		int w = 0;
    		if ((u + v) & 1) {
    			w = a[u] + a[v];
    		} else {
    			w = 2 * a[(u + v) / 2];
    		}
    		g.push_back({u, v, w});
    		g.push_back({v, u, w});
    	}
    }*/
    // [&]() -> void {
	// 	std::sort(g.begin(), g.end(), 
	// 		[&](Edge a, Edge b) -> bool {
	// 			return a.w < b.w;
	// 		});

	// 	DisjointSetUnion<int> DSU(n + 100);
	// 	for (auto [u, v, w] : g) {
	// 		if (DSU.Merge(u, v)) {
	// 			ans += w;
	// 			cnt ++;
	// 			if (cnt == n + 1) {
	// 				break;
	// 			}
	// 		}
	// 	}
    // }();

    std::vector<i64> dis(n + 1, LINF);
    std::vector<bool> vis(n + 1, false);
    dis[1] = 0; i64 ans = 0;
    
    for (int i = 1; i <= n; i ++) {
        int u = -1;
        i64 min = LINF;
        for (int v = 1; v <= n; v ++) {
            if (!vis[v] && dis[v] < min) {
                min = dis[v];
                u = v;
            }
        }
        vis[u] = true;
        ans += min;
        for (int v = 1; v <= n; v ++) {
            if (!vis[v]) {
                i64 w;
                int s = u + v;
                if (s % 2 == 0) {
                    int mid = s / 2;
                    w = 2 * a[mid];
                } else {
                    int l = s / 2;
                    w = a[l] + a[l + 1];
                }
                if (w < dis[v]) {
                	dis[v] = w;
                }
            }
        }
    }

/*    for (int i = 1; i < n; i ++) {
    	ans += std::min(a[i] + a[i + 1], 2 * a[i + 1]);
    }*/

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

    for (int _ = [&]() -> int { int T; std::cin >> T; return T; }(); _; _ --)
        VioletEverGraden();

    return 0;
}