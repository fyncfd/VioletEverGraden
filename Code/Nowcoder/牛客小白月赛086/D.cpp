/*
* @Author: AlgoStruggler
* @Create Time: 2025-05-09 19:01:07
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
typedef std::pair<int, int> pii;
typedef std::pair<ll, ll> pll;

//using namespace std;
//using namespace __gnu_pbds;
template <typename T> 
using pq = std::priority_queue<T>;
template<class T> 
using matrix = std::vector<std::vector<T>>;
template <typename T>
using vec = std::vector<T>;
template <class Key, class Value>
using ump = std::unordered_map<Key, Value>;
template <typename T>
using ust = std::unordered_set<T>;
//template <typename Key, typename Value>
//using hash = __gnu_pbds::gp_hash_table<Key, Value>;

template<class T> concept Signed = std::is_signed_v<T>;
template<class T> concept Unsigned = std::is_unsigned_v<T>;
template<class T> concept Arithmetic = std::is_arithmetic_v<T>;

#define all(x) x.begin() + 1, x.end()
#define LLA(x) (x).rbegin(), (x).rend()
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define red(i, l, r) for (int i = l; i >= r; i--)
#define lop(i, x) for (auto i : x)
/*------------------------------SORT_AND_UNIQUE-------------------------------*/
//#define int long long
const double eps = 1e-9;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF = 0x3f3f3f3f3f3f3f3f;
constexpr ll mod = 998244353;
constexpr ll MOD = 1e9 + 7;
int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };
constexpr int MAXN = 1e3 + 3;
int n, m;
std::vector<std::vector<char>> g;
/*-------------------------------MY_CODE_BEGIN--------------------------------*/
static inline void VioletEverGraden() {
    std::cin >> n >> m;
    g.resize(n + 1);
    rep(i, 1, n) {
        g[i].resize(m + 1);
        rep(j, 1, m) {
            std::cin >> g[i][j];
        }
    }

    struct pii {
        int fi; 
        int se;
    };
    bool vis[MAXN][MAXN] = { false };
    auto bfs = [&](int x, int y) -> int {
        std::queue<pii> q;
        q.push(pii(x, y));
        vis[x][y] = true;

        pii ma = {pii(x, y)}; pii mi = {pii(x, y)};
        int num = 1;
        while (!q.empty()) {
            auto [sx, sy] = q.front();
            q.pop();

            rep(i, 0, 3) {
                int nx = sx + dx[i]; int ny = sy + dy[i];

                if (nx > n or nx < 1 or ny > m or ny < 1 or vis[nx][ny] or g[nx][ny] == '*') {
                    continue;
                }

                ma.fi = std::max(ma.fi, nx); ma.se = std::max(ma.se, ny);
                mi.fi = std::min(mi.fi, nx); mi.se = std::min(mi.se, ny);
                num ++; 
                vis[nx][ny] = true;
                q.push(pii(nx, ny));
            }
        }

        int sq = (ma.fi - mi.fi + 1) * (ma.se - mi.se + 1);
        if (sq == num) {
            return 1;
        }
        else {
            return 0;
        }
    };

    int ans = 0;
    rep(i, 1, n) {
        rep(j, 1, m) {
            if (g[i][j] == '.' and !vis[i][j]) {
                ans += bfs(i, j);
            }
            vis[i][j] = true;
        }
    }

    std::cout << ans << '\n';
    /*return AC*/
/*
Test Sample

*/
}
/*-------------------------------Author_Fd------------------------------------*/
static inline void VioletEverGraden();

auto __INIT__ = []() {
    std::cin.tie(nullptr) ->
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
};

signed main() {
#ifdef LOCAL
    freopen("A.in", "r", stdin);
#endif // LOCAL

    /*cout << fixed << setprecision();
    cerr << fixed << setprecision();*/


    __INIT__();

    int _ = 1;

    //for (std::cin >> _; _; _--)
        VioletEverGraden();

    return 0;
}