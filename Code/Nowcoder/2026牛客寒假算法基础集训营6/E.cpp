/*
* @Author: AlgoStruggler
* @Create Time: 2026-02-13 16:27:19
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

/*
* DSU封装类，启发式合并，根据集合大小去合并，带路径压缩。
* @Author: AlgoStruggler
* @Create Time: 2026-02-04 15:53:13
* "To the Splendor of ACM-ICPC, We Consecrate Our AC Triumphs."
* 愿幸运女神与最纯粹的前行者同在。
*/
template <typename T>
class DisjointSetUnion {
private:
	int N;
    int SZ;
    int cnt;  
	std::vector<int> Parent;
	std::vector<int> Size;
public:
    DisjointSetUnion(int n, int d) : N(n), SZ(d), cnt(0) {
        Parent.resize(N + 1);
        std::iota(Parent.begin() + 1, Parent.end(), 1);
        Size.assign(N + 1, 0);
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

    void add(int x) {
        if (Size[x] != 0) {
        	return;
        }
        Size[x] = 1;
        if (1 >= SZ) {
        	cnt++;
        }
    }

    bool Merge(int x, int y) {
        int RootX = find(x);
        int RootY = find(y);
        if (RootX == RootY) {
        	return false;
        }
        bool ok1 = (Size[RootX] >= SZ);
        bool ok2 = (Size[RootY] >= SZ);

        if (Size[RootX] < Size[RootY]) {
            std::swap(RootX, RootY);
            std::swap(ok1, ok2);
        }

        Parent[RootY] = RootX;
        Size[RootX] += Size[RootY];
        if (ok1 && ok2) {
            cnt --; 
        } else if (!ok1 && !ok2) {
            if (Size[RootX] >= SZ) {
            	cnt ++;
            }
        }
        return true;
    }

    int getcnt() const {
        return cnt;
    }

    int size(int x) {
        return Size[find(x)];
    }
};

static inline void VioletEverGraden() {
    int n, m, x, d;
    std::cin >> n >> m >> x >> d;

    std::vector<i64> h(n + 1);
    using pii = std::pair<int, int>;
    std::vector<pii> C;
    for (int i = 1; i <= n; i ++) {
    	std::cin >> h[i];
    	C.push_back({h[i], i});
    }

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
	std::vector<int> head(n + 1, -1);
	std::vector<Edge> G(2 * m + 10);
	auto AddEdge = [&](int u, int v, int w = 0) -> void {
		G[tot].to = v;
		G[tot].nxt = head[u];
		G[tot].w = w;
		head[u] = tot ++;
	};

	int __ = m;
	while (__ --) {
		int u, v;
		std::cin >> u >> v;
		AddEdge(u, v); AddEdge(v, u);
	}

    std::vector<int> H(x + 1);
    for (int i = 1; i <= x; i ++) {
        std::cin >> H[i];
    }

    std::sort(C.begin(), C.end(), [&](pii a, pii b) -> bool {
    	if (a.first == b.first) {
    		return a.second < b.second;
    	} else {
    		return a.first > b.first;
    	}
    });

    DisjointSetUnion<int> DSU(n, d);
    std::vector<bool> vis(n + 1, false);
    std::vector<int> ans(x + 1);

    int p = 0;
    for (int i = x; i >= 1; i --) {
    	while (p < C.size()	&& C[p].first > H[i]) {
    		int id = C[p].second;
    		vis[id] = true;
    		DSU.add(id);

    		int u = id;
    		for (int i = head[u]; ~i; i = G[i].nxt) {
    			int v = G[i].to;
    			if (vis[v]) {
    				DSU.Merge(u, v);
    			}
    		}
    		p ++;
    	}
    	ans[i] = DSU.getcnt();
    }

    for (int i = 1; i <= x; i ++) {
    	std::cout << ans[i] << '\n';
    }
/*
愿幸运女神与最纯粹的前行者同在。 
Test Sample

5 5 2 2
10 5 8 3 12
1 2
2 3
3 4
4 5
1 5
4
7

1
1

4 3 3 2
5 5 5 5
1 2
2 3
3 4
4
5
6

1
0
0


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