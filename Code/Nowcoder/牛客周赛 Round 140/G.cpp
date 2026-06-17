/*
* @Author: AlgoStruggler
* @Create Time: 2026-04-19 20:36:32
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

static inline void VioletEverGraden() {
    int n, m;
    std::cin >> n >> m;

    std::string s;
    std::cin >> s;

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
        AddEdge(u, v); 
        AddEdge(v, u);
    }

    DisjointSetUnion<int> DSU1(n);
    for (int u = 1; u <= n; u ++) {
        if (s[u-1] == 'C' || s[u-1] == 'D') {
            continue;
        }
        for (int i = head[u]; ~i; i = G[i].nxt) {
            int v = G[i].to;
            if (s[v-1] == 'C' || s[v-1] == 'D') {
                continue;
            }
            DSU1.Merge(u, v);
        }
    }

    DisjointSetUnion<int> DSU2(n);
    for (int u = 1; u <= n; u ++) {
        if (s[u-1] == 'A' || s[u-1] == 'B') {
            continue;
        }
        for (int i = head[u]; ~i; i = G[i].nxt) {
            int v = G[i].to;
            if (s[v-1] == 'A' || s[v-1] == 'B') {
                continue;
            }
            DSU2.Merge(u, v);
        }
    }

    std::vector<int> node1;
    for (int i = 1; i <= n; i ++) {
        if (s[i-1] == 'A' || s[i-1] == 'B') {
            node1.push_back(i);
        }
    }
    if (node1.empty()) {
        std::cout << "No\n";
        return ;
    }

    int rt1 = DSU1.find(node1[0]);
    for (int u : node1) {
        if (DSU1.find(u) != rt1) {
            std::cout << "No\n";
            return ;
        }
    }

    std::vector<int> node2;
    for (int i = 1; i <= n; i ++) {
        if (s[i-1] == 'C' || s[i-1] == 'D') {
            node2.push_back(i);
        }
    }
    if (node2.empty()) {
        std::cout << "No\n";
        return ;
    }

    int rt2 = DSU2.find(node2[0]);
    for (int u : node2) {
        if (DSU2.find(u) != rt2) {
            std::cout << "No\n";
            return ;
        }
    }

    int e1 = -1, e2 = -1;
    for (int u = 1; u <= n; ++u) {
        for (int i = head[u]; ~i; i = G[i].nxt) {
            int v = G[i].to;
            if ((s[u-1] == 'A' || s[u-1] == 'B') && (s[v-1] == 'C' || s[v-1] == 'D')) {
                e1 = u;
                e2 = v;
                break;
            }
        }
        if (e1 != -1) {
            break;
        }
    }
    if (e1 == -1) {
        std::cout << "No\n";
        return ;
    }

    std::cout << "Yes\n";
    DisjointSetUnion<int> DSU(n);
    DSU.Merge(e1, e2);
    std::cout << e1 << ' ' << e2 << '\n';

    for (int u : node1) {
        for (int i = head[u]; ~i; i = G[i].nxt) {
            int v = G[i].to;
            if ((s[v-1] == 'A' || s[v-1] == 'B') && DSU.Merge(u, v)) {
                std::cout << u << ' ' << v << '\n';
            }
        }
    }

    for (int u : node2) {
        for (int i = head[u]; ~i; i = G[i].nxt) {
            int v = G[i].to;
            if ((s[v-1] == 'C' || s[v-1] == 'D') && DSU.Merge(u, v)) {
                std::cout << u << ' ' << v << '\n';
            }
        }
    }
/*
愿幸运女神与最纯粹的前行者同在。 
Test Sample

4 4
ABCD
1 2
2 3
3 4
4 1

Yes
1 4
1 2
3 4

4 3
ACBD
1 2
2 3
3 4

No

10 23
AACDBDDBDB
2 1
3 2
4 1
4 2
4 3
5 1
5 2
5 3
6 1
6 2
6 3
7 1
7 2
7 3
8 1
8 2
8 3
9 1
9 2
9 3
10 1
10 3
10 4

Yes
1 9
1 10
1 8
1 5
1 2
3 9
3 7
3 6
3 4


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