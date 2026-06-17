/*
* @Author: AlgoStruggler
* @Create Time: 2025-11-21 20:41:01
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
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
constexpr int MAXN = 2e5 + 10;
int n, m;
std::vector<std::string> g;
std::string s;
struct node {
    int num;
    ll time;
    int x, y;

    bool operator>(const node& other) const {
        if (num != other.num)
            return num > other.num;
        return time > other.time;
    }
};
pll dist[1005][1005];
int nxt[MAXN][4]; 
int mp[256];
/*-------------------------------MY_CODE_BEGIN--------------------------------*/
static inline void VioletEverGraden() {
    std::cin >> n >> m;
    std::cin >> s;

    g.resize(n);
    rep(i, 0, n - 1, 1) {
    	std::cin >> g[i];
    }

    int len = s.length();
    std::string ss = s + s;

    mp['U'] = 0; mp['D'] = 1;
    mp['L'] = 2; mp['R'] = 3;

    rep(k, 0, 3, 1) {
    	nxt[2 * len][k] = 2 * len + 1; 
    }

    dep(i, 2 * len - 1, 0, 1) {
        rep(k, 0, 3, 1) {
            nxt[i][k] = nxt[i + 1][k];
        }
        nxt[i][mp[ss[i]]] = i;
    }

    auto dijkstra = [&]() -> void {
        rep(i, 0, n - 1, 1) {
            rep(j, 0, m - 1, 1) {
                dist[i][j] = {INF, LINF};
            }
        }

        std::priority_queue<node, std::vector<node>, std::greater<node>> pq;
        dist[0][0] = {0, 0};
        pq.push({0, 0, 0, 0});

        auto relax = [&](int x, int y, int nnum, ll ntime) {
            if (nnum < dist[x][y].fi or (nnum == dist[x][y].fi and ntime < dist[x][y].se)) {
                dist[x][y] = {nnum, ntime};
                return true;
            }
            return false;
        };

        while (!pq.empty()) {
            node temp = pq.top();
            pq.pop();

            int c = temp.num; ll t = temp.time;
            int x = temp.x; int y = temp.y;

            if (c > dist[x][y].fi or (c == dist[x][y].fi and t > dist[x][y].se)) {
                continue;
            }

            if (x == n - 1 and y == m - 1) {
                std::cout << c << ' ' << t << '\n';
                return ;
            }

            rep(k, 0, 3, 1) {
                int nx = x + dx[k]; int ny = y + dy[k];

                if (nx >= 0 and nx < n and ny >= 0 and ny < m and g[nx][ny] == '.') {
                    if (relax(nx, ny, c + 1, t + 1)) {
                        pq.push({c + 1, t + 1, nx, ny});
                    }

                    int id = t % len; int nt = nxt[id][k];

                    if (nt < 2 * len) {
                        ll wait = nt - id; ll cnt = t + wait + 1;
                        if (relax(nx, ny, c, cnt)) {
                            pq.push({c, cnt, nx, ny});
                        }
                    }
                }
            }
        }
    };

    dijkstra();
    /*太好了，这回只花998244353min就打完了！*/
/*
Test Sample

5 6
DDDLDUUDLLL
.#..#.
..#...
#...#.
..#...
....#.

5 12

6 5
UUDRRDDRRDL
...#.
.#...
...#.
.#...
..#.#
#....

0 19


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