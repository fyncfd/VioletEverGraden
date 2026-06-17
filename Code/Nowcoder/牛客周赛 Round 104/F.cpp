/*
* @Author: AlgoStruggler
* @Create Time: 2025-08-10 19:30:08
* "To the Splendor of ACM-ICPC, We Consecrate Our AC Triumphs."
*/
#define  _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize("O2")
#include "bits/stdc++.h"
//#include <ext/pb_ds/assoc_container.hpp>

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef __int128 i128;
struct pii { int fi; int se; };
struct pll { ll fi; ll se; };

#define all(x) x.begin() + 1, x.end()
#define rep(i, l, r, x) for (decltype(l) i = (l); i <= (r); i += (x))
#define dep(i, l, r, x) for (decltype(l) i = (l); i >= (r); i -= (x))
#define lop(i, x) for (auto &i : x)

//using namespace std;
//using namespace __gnu_pbds;
template<class T> using matrix = std::vector<std::vector<T>>;
template <typename T> using pq = std::priority_queue<T>;
template<class T> using matrix = std::vector<std::vector<T>>;
template <class Key, class Value> using ump = std::unordered_map<Key, Value>;
template <typename T> using ust = std::unordered_set<T>;
//template <typename Key, typename Value> using hash = __gnu_pbds::gp_hash_table<Key, Value>;
template<class T> concept Signed = std::is_signed_v<T>;
template<class T> concept Unsigned = std::is_unsigned_v<T>;
template<class T> concept Arithmetic = std::is_arithmetic_v<T>;
template<class T> std::istream &operator >> (std::istream &cin, std::vector<T> &a) {
    rep(i, 1, a.size() - 1, 1) {
        std::cin >> a[i];
    }
    return cin;
}
template<class T> std::ostream &operator << (std::ostream &cout, std::vector<T> &a) {
    int n = a.size() - 1;
    if (!n) {
        return cout;
    }
    rep(i, 1, a.size() - 1, 1) {
        std::cout << a[i] << " \n"[i == a.size() - 1];
    }
    return cout;
}
template<class T> std::istream &operator >> (std::istream &cin, matrix<T> &a) {
    rep(i, 1, a.size() - 1, 1) {
        rep(j, 1, a[i].size() - 1, 1) {
            cin >> a[i][j];
        }
    }
    return cin;
}
template<class T> std::ostream &operator << (std::ostream &cout, const matrix<T> &a) {
    if (a.empty()) {
        return cout;
    }
    rep(i, 1, a.size() - 1, 1) {
        rep(j, 1, a[i].size() - 1, 1) {
            cout << a[i][j] << " \n"[j == a[i].size() - 1];
        }
    }
    return cout;
}
/*------------------------------SORT_AND_UNIQUE-------------------------------*/
//#define int long long
const double eps = 1e-9;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF = 0x3f3f3f3f3f3f3f3f;
constexpr ll mod = 998244353;
constexpr ll MOD = 1e9 + 7;
int dx[] = {0, 0, 1, 0, -1 };
int dy[] = {0, -1, 0, 1, 0 };
constexpr int MAXN = 2e5 + 10;
int n;
int u, v;
/*-------------------------------MY_CODE_BEGIN--------------------------------*/
std::vector<int> g[MAXN];
int dep[MAXN];
int fa[MAXN][20];
static inline void VioletEverGraden() {
    std::cin >> n;

    int __ = n - 1;
    while (__ --) {
    	std::cin >> u >> v;

    	g[u].push_back(v); g[v].push_back(u);
    }

    auto bfs = [&](int root, int n) -> void {
	    rep(i, 1, n, 1) {
	    	dep[i] = -1;
	    }

	    std::queue<int> q;
	    q.push(root);
	    dep[root] = 1; fa[root][0] = 0;
	    while (!q.empty()) {
	        int u = q.front();
	        q.pop();
	        lop(v, g[u]) {
	            if (dep[v] == -1) {
	                dep[v] = dep[u] + 1; fa[v][0] = u;
	                q.push(v);
	            }
	        }
	    }
    };

    auto f = [&](int n) -> void {
	    rep(j, 1, 19, 1) {
	        rep(i, 1, n, 1) {
	            if (fa[i][j-1] != 0) {
	                fa[i][j] = fa[fa[i][j-1]][j-1];
	            } else {
	                fa[i][j] = 0;
	            }
	        }
	    }
    };

    bfs(n, n); f(n);

    auto LCA = [&](int a, int b) -> int {
	    if (dep[a] < dep[b]) {
	    	std::swap(a, b);
	    }

	    int dif = dep[a] - dep[b];
	    rep(i, 0, 19, 1) {
	        if (dif & (1 << i)) {
	            a = fa[a][i];
	        }
	    }

	    if (a == b) {
	    	return a;
	    }

	    dep(i, 19, 0, 1) {
	        if (fa[a][i] != fa[b][i]) {
	            a = fa[a][i]; b = fa[b][i];
	        }
	    }
	    return fa[a][0];
    };

    ll ans = dep[1];
    int lca = 1;
    rep(i, 2, n, 1) {
    	lca = LCA(lca, i);
    	ans += dep[lca];
    }

    std::cout << ans << '\n';
    /*太好了，这回只花998244353min就打完了！*/
/*
Test Sample

4
3 4
2 4
1 2

7

4
1 3
2 3
4 3

8

4
1 4
2 4
4 3

5


*/
}
/*-------------------------------Author_Fd------------------------------------*/
static inline void VioletEverGraden();

auto __FAST_IO__ = []() -> int {
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
    return 0;
}();

signed main() {
#ifdef LOCAL
    freopen("A.in", "r", stdin);
#endif // LOCAL

    /*std::cout << std::fixed << std::setprecision(9);
    std::cerr << std::fixed << std::setprecision(9);*/

    int _ = 1;
    //for (std::cin >> _; _; _--)
        VioletEverGraden();

    return 0;
}