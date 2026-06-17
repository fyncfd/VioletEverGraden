/*
* @Author: AlgoStruggler
* @Create Time: 2025-11-08 14:20:43
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
constexpr int MAXN = 1e5 + 5;
int n, m, s;
std::vector<int> a;
/*-------------------------------MY_CODE_BEGIN--------------------------------*/
static inline void VioletEverGraden() {
    std::cin >> n >> m >> s;

    std::vector<int> head(n + 1, -1);
    struct Edge {
        int to;
        int nxt;
    };
    std::vector<Edge> g(2 * n + 5);
    int ttt = 0;
    auto addEdge = [&](int u, int v) {
        g[ttt].to = v;
        g[ttt].nxt = head[u];
        head[u] = ttt++;
    };
    
    std::vector<int> h(n + 1, INF);
    std::vector<int> deg(n + 1, 0);
    
    std::queue<int> fq;
    rep(i, 1, m, 1) {
        int x;
        std::cin >> x;

        h[x] = 0;
        fq.push(x);
    }

    int __ = n - 1;
    while (__ --) {
        int u, v;
        std::cin >> u >> v;
        addEdge(u, v); addEdge(v, u);
        deg[u]++; deg[v]++;
    }
    
    if (h[s] == 0) {
        std::cout << -1 << '\n';
        return ;
    }
    
    auto bfs1 = [&]() {
        while (!fq.empty()) {
            int u = fq.front();
            fq.pop();
            
            for (int i = head[u]; i != -1; i = g[i].nxt) {
                int v = g[i].to;
                if (h[v] > h[u] + 1) {
                    h[v] = h[u] + 1;
                    fq.push(v);
                }
            }
        }
    };
    bfs1();

    auto bfs2 = [&]() -> int {
        std::vector<int> dis(n + 1, -1);
        std::queue<int> q;
        
        dis[s] = 0;
        q.push(s);
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            
            for (int i = head[u]; i != -1; i = g[i].nxt) {
                int v = g[i].to;
                if (dis[v] == -1 and dis[u] + 1 < h[v]) {
                    dis[v] = dis[u] + 1;
                    q.push(v);
                }
            }
        }

        int ans = INF;
        rep(i, 1, n, 1) {
            if (deg[i] == 1 and dis[i] != -1) {
                ans = std::min(ans, dis[i]);
            }
        }
        
        if (deg[s] == 1 and h[s] > 0) {
            ans = std::min(ans, 0);
        }
        
        return ans;
    };
    
    int ans = bfs2();
    
    if (ans == INF) {
        std::cout << -1 << '\n';
    } else {
        std::cout << ans << '\n';
    }
    /*太好了，这回只花998244353min就打完了！*/
/*
Test Sample

2 0 1

1 2

0

4 1 3
4
1 2
2 3
3 4

2

5 3 2
3 4 5
1 2
1 3
2 4
2 5

-1


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