/*
* @Author: AlgoStruggler
* @Create Time: 2026-01-15 11:26:37
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
#define debug(x) std::cerr << #x << " = " << x << '\n'
#define debug2(x, y) std::cerr << #x << " = " << x << ", " << #y << " = " << y << '\n'


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
std::string op;
int t;
ll n, m;
int u, v;
int q;
std::string s; 
int dv;
/*-------------------------------MY_CODE_BEGIN--------------------------------*/
static inline void VioletEverGraden() {
    auto test_A = [&]() -> void {
        std::cin >> n >> m;

        std::vector<int> head(n + 1, -1);
        struct Edge {
            int to; int nxt; int w;
        };
        std::vector<Edge> G(2 * m + 10);
        int tot = 1;
        auto AddEdge = [&](int u, int v, int w) -> void {
            G[tot].to = v;
            G[tot].nxt = head[u];
            G[tot].w = w;
            head[u] = tot ++;
        };

        int __ = m;
        while (__ --) {
            std::cin >> u >> v;
            AddEdge(u, v, 1); AddEdge(v, u, 1);
        }

        std::vector<int> dis(n + 1, INF);
        auto Dijkstra = [&](int s) -> void {
            dis[s] = 0;

            struct node {
                int id; int d;
                bool operator < (const node &a) const {
                    return d > a.d;
                }
            };
            std::priority_queue<node> heap;

            heap.push({s, 0});
            while (!heap.empty()) {
                node p = heap.top();
                heap.pop();

                int u = p.id;
                for (int i = head[u]; ~i; i = G[i].nxt) {
                    int v = G[i].to; int w = G[i].w;
                    if (dis[v] > dis[u] + w) {
                        dis[v] = dis[u] + w;
                        heap.push({v, dis[v]});
                    }
                }
            }
        };

        Dijkstra(1);

/*        rep(i, 1, n, 1) {
            debug(dis[i]);
        }*/

        rep(i, 1, n, 1) {
            std::cout << "rgb"[dis[i] % 3];
        }
        std::cout << '\n';
    };

    auto test_B = [&]() -> void {
        std::cin >> dv;
        std::cin >> s;

        bool fr = false, fg = false, fb = false;
        for (char c : s) {
            if (c == 'r') {
                fr = true;
            }
            if (c == 'g') {
                fg = true;
            }
            if (c == 'b') {
                fb = true;
            }
        }
        
        if ((int)fr + (int)fg + (int)fb == 1) {
            std::cout << 1 << "\n";
            return ;
        }
        
        char target;
        if (fr and fg) {
            target = 'g';
        }
        if (fg and fb) {
            target = 'b';
        }
        if (fb and fr) {
            target = 'r';
        }
        
        rep(i, 0, dv - 1, 1) {
            if (s[i] == target) {
                std::cout << i + 1 << "\n";
                return ;
            }
        }
    };

    std::cin >> op;
    if (op == "first") {
        std::cin >> t;
        while (t --) {
            test_A();
        }
    } else {
        std::cin >> t;
        while (t --) {
            std::cin >> q;
            while (q --) {
                test_B();
            }
        }
    }
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

