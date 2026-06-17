/*
* @Author: AlgoStruggler
* @Create Time: 2026-02-04 16:26:55
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

const double eps = 1e-9;
constexpr int INF = 0x3f3f3f3f;
constexpr i64 LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr i64 mod = 998244353;
constexpr i64 MOD = 1e9 + 7;
constexpr int MAXN = 0;

template <typename T>
class DisjointSetUnion {
private:
	int N;
	std::vector<int> Parent;
	std::vector<int> Siz;
public:
    DisjointSetUnion(int n) : N(n), Parent(N + 1), Siz(N + 1) {
        std::iota(Parent.begin() + 1, Parent.end(), 1);
        Siz.assign(N + 1, 1);
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

        if (Siz[RootX] < Siz[RootY]) {
            std::swap(RootX, RootY);
        }
        
        Parent[RootY] = RootX;
        Siz[RootX] += Siz[RootY];
        
        return true;
    }

    int size(int x) {
        return Siz[find(x)];
    }
};

static inline void VioletEverGraden() {
    int n, m;
    std::cin >> n >> m;

	struct Edge { i64 u; i64 v; i64 w; };
	std::vector<Edge> G;

	int __ = m;
	while (__ --) {
		i64 u, v, w;
		std::cin >> u >> v >> w;
		G.push_back({u, v, w});
	}

	int cnt = 0; i64 ans = 0;
	auto Kruskal = [&]() -> void {
		std::sort(G.begin(), G.end(), [&](Edge a, Edge b) -> bool {
			return a.w < b.w;
		});

		DisjointSetUnion<int> DSU(n);
		for (auto [u, v, w] : G) {
			if (DSU.Merge(u, v)) {
				ans += w;
				cnt ++;
				if (cnt == n - 1) {
					break;
				}
			}
		}
	};

	Kruskal();

	if (cnt != n - 1) {
		std::cout << "NO\n";
	} else {
		std::cout << ans << '\n';
	}
    
    /* 愿幸运女神与最纯粹的前行者同在。 */
/*
Test Sample

5 7
4 5 2
1 3 0
1 4 1
2 1 1
4 1 0
2 4 0
4 3 0

2

4 2
1 2 -12
3 4 2

NO


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