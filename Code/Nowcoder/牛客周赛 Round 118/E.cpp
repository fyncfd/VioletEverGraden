/*
* @Author: AlgoStruggler
* @Create Time: 2025-11-16 19:22:58
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
constexpr int MAXN = 0;
int n;
int a, b;
int u, v;
/*-------------------------------MY_CODE_BEGIN--------------------------------*/
static inline void VioletEverGraden() {
    std::cin >> n;
    std::cin >> a >> b;

    std::vector<int> head(n + 1, -1);
    struct Edge {
    	int to; int nxt;
    };
    std::vector<Edge> g(2 * n + 10);
    int ttt = 1;
    auto AddEdge = [&](int u, int v) -> void {
    	g[ttt].to = v;
    	g[ttt].nxt = head[u];
    	head[u] = ttt ++;
    };

    std::vector<int> deg(n + 1, 0);
    int __ = n - 1;
    while (__ --) {
    	std::cin >> u >> v;
    	AddEdge(u, v); AddEdge(v, u);
    	deg[u] ++; deg[v] ++;
    }

    auto bfs = [&](int s) -> std::vector<int> {
        std::vector<int> dis(n + 1, -1);
        std::queue<int> q;
        q.push(s);
        dis[s] = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int i = head[u]; ~i; i = g[i].nxt) {
            	int v = g[i].to;
                if (dis[v] == -1) {
                    dis[v] = dis[u] + 1;
                    q.push(v);
                }
            }
        }
        return dis;
    };

    std::vector<int> disa = bfs(a); std::vector<int> disb = bfs(b);

    auto dfs = [&](auto &&self, int u, int fa) -> bool {
        if (deg[u] == 1) {
            return disb[u] > 2 * (disa[u] - 1);
        }
        for (int i = head[u]; ~i; i = g[i].nxt) {
        	int v = g[i].to;
            if (v == fa) {
            	continue;
            }
            if (deg[v] == 1) { 
                if (disb[v] > 2 * (disa[v] - 1)) {
                    return true;
                }
            } else { 
                if (disb[v] > 2 * disa[v]) {
                    if (self(self, v, u)) {
                        return true;
                    }
                }
            }
        }
        return false;
    };

    if (deg[a] == 1) {
        if (disb[a] > 2 * (disa[a] - 1)) {
            std::cout << "red\n";
            return ;
        }
    }
        
    bool ok = false;
    for (int i = head[a]; ~i; i = g[i].nxt) {
    	int v = g[i].to;
        if (deg[v] == 1) {
            if (disb[v] > 2 * (disa[v] - 1)) {
                ok = true;
                break;
            }
        } else {
            if (disb[v] > 2 * disa[v]) {
                if (dfs(dfs, v, a)) {
                    ok = true;
                    break;
                }
            }
        }
    }
    if (ok) {
    	std::cout << "red\n";
    } else {
    	std::cout << "purple\n";
    }
    /*太好了，这回只花998244353min就打完了！*/
/*
Test Sample

2
4
2 3
1 2
2 3
3 4
4
2 1
1 2
2 3
3 4

red
purple


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
    for (std::cin >> _; _; _--)
        VioletEverGraden();

    return 0;
}
