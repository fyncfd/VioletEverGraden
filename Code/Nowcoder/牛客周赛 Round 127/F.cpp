/*
* @Author: AlgoStruggler
* @Create Time: 2026-02-08 23:31:45
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
typedef __int128 i128;
typedef unsigned __int128 u128;

const double eps = 1e-9;
constexpr int INF = 0x3f3f3f3f;
constexpr i64 LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr i64 mod = 998244353;
constexpr i64 MOD = 1e9 + 7;
constexpr int MAXN = 2e3 + 6;

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
    int n;
    std::cin >> n;

    std::vector<std::string> g(n);
    for (int i = 0; i < n; i ++) {
    	std::cin >> g[i];
    }

    const int dx[] = {1, -1, 0, 0}; const int dy[] = {0, 0, 1, -1};
	const int ddx[] = {-1, -1, -1, 0, 0, 1, 1, 1}; const int ddy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    auto id = [&](int x, int y) -> int {
    	return x * n + y;
    };

    auto check = [&](int x, int y) -> bool {
    	return x >= 0 and x < n and y >= 0 and y < n;
    };

    DisjointSetUnion<int> DSU(n * n);
   	for (int x = 0; x < n; x ++) {
   		for (int y = 0; y < n; y ++) {
   			if (g[x][y] == '1') {
   				for (int i = 0; i < 8; i ++) {
   					int nx = x + ddx[i]; int ny = y + ddy[i];
   					if (check(nx, ny) and g[nx][ny] == '1') {
   						DSU.Merge(id(x, y), id(nx, ny));
   					}
   				}
   			}
   		}
   	}
    
    std::queue<std::array<int, 2>> q;
    bool vis[MAXN][MAXN];
    std::memset(vis, false, sizeof vis);
    for (int x = 0; x < n; x ++) {
    	for (int y = 0; y < n; y ++) {
    		if (g[x][y] == '0') {
    			std::vector<std::array<int, 2>> p;
    			for (int i = 0; i < 4; i ++) {
    				int nx = x + dx[i]; int ny = y + dy[i];
    				if (check(nx, ny) and g[nx][ny] == '1') {
    					p.push_back({nx, ny});
    				}
    			}

    			bool ok = false;
    			if (p.size() >= 3) {
    				ok = true;
    			} else if (p.size() == 2) {
    				int x1 = p[0][0]; int y1 = p[0][1];
    				int x2 = p[1][0]; int y2 = p[1][1];
    				if (DSU.same(id(x1, y1), id(x2, y2))) {
    					ok = true;
    				}
    			}

    			if (ok) {
    				q.push({x, y});
    				vis[x][y] = 1;
    			}
    		}
    	}
    }

    auto bfs = [&]() -> void {
    	while (!q.empty()) {
	    	std::vector<std::array<int, 2>> p;
	    	while (!q.empty()) {
	    		auto [x, y] = q.front();
	    		q.pop();
	    		vis[x][y] = false;

	    		if (g[x][y] == '1') {
	    			continue;
	    		}

	    		std::vector<std::array<int, 2>> cur;
	    		for (int i = 0; i < 4; i ++) {
	    			int nx = x + dx[i]; int ny = y + dy[i];
	    			if (check(nx, ny) and g[nx][ny] == '1') {
	    				cur.push_back({nx, ny});
	    			}
	    		}

	    		bool ok = false;
	    		if (cur.size() >= 3) {
	    			ok = true;
	    		} else if (cur.size() == 2) {
	    			int x1 = cur[0][0]; int y1 = cur[0][1];
	    			int x2 = cur[1][0]; int y2 = cur[1][1];
	    			int id1 = id(x1, y1); int id2 = id(x2, y2);
	    			if (DSU.same(id1, id2)) {
	    				ok = true;
	    			}
	    		}

	    		if (ok) {
	    			p.push_back({x, y});
	    		}
	    	}

	    	if (p.empty()) {
	    		break;
	    	}

	    	for (auto [x, y] : p) {
	    		g[x][y] = '1';
	    	}

	    	for (auto [x, y] : p) {
	    		for (int i = 0; i < 8; i ++) {
	    			int nx = x + ddx[i]; int ny = y + ddy[i];
	    			if (check(nx, ny) and g[nx][ny] == '1') {
	    				int id1 = id(x, y); int id2 = id(nx, ny);
	    				DSU.Merge(id1, id2);
	    			}
	    		}
	    	}

	    	for (auto [x, y] : p) {
	    		for (int i = 0; i < 4; i ++) {
	    			int nx = x + dx[i]; int ny = y + dy[i];
	    			if (check(nx, ny) and g[nx][ny] == '0' and !vis[nx][ny]) {
	    				std::vector<std::array<int, 2>> to;
	    				for (int j = 0; j < 4; j ++) {
	    					int nnx = nx + dx[j]; int nny = ny + dy[j];
	    					if (check(nnx, nny) and g[nnx][nny] == '1') {
	    						to.push_back({nnx, nny});
	    					}
	    				}

	    				bool ok = false;
	    				if (to.size() >= 3) {
	    					ok = true;
	    				} else if (to.size() == 2) {
	    					int x1 = to[0][0]; int y1 = to[0][1];
	    					int x2 = to[1][0]; int y2 = to[1][1];
	    					int id1 = id (x1, y1); int id2 = id(x2, y2);
	    					if (DSU.same(id1, id2)) {
	    						ok = true;
	    					}
	    				}

	    				if (ok) {
	    					q.push({nx, ny});
	    					vis[nx][ny] = true;
	    				}
	    			}
	    		}
	    	}
	    }
    };

    bfs();

    for (int i = 0; i < n; i ++) {
    	std::cout << g[i] << '\n';
    }

    /* 愿幸运女神与最纯粹的前行者同在。 */
/*
Test Sample

2
3
010
101
010
5
00000
01110
01000
01010
01110

111
111
111
00000
01110
01110
01110
01110

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
    for (std::cin >> _; _; _--)
        VioletEverGraden();

    return 0;
}