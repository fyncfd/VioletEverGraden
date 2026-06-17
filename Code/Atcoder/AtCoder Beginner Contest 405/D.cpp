/*
* @Author: AlgoStruggler
* @Create Time: 2025-05-10 20:19:55
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
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
constexpr int MAXN = 0;
int n, m;
matrix<char> g;
/*-------------------------------MY_CODE_BEGIN--------------------------------*/
static inline void VioletEverGraden() {
    std::cin >> n >> m;
    g.resize(n);
    rep(i, 0, n - 1) {
    	g[i].resize(m);
    	rep(j, 0, m - 1) {
    		std::cin >> g[i][j];
    	}
    }

    matrix<int> d(n, std::vector<int>(m, -1));

    auto bfs = [&]() {
        std::queue<std::pair<int, int>> q;

        rep(i, 0, n - 1) {
            rep(j, 0, m - 1) {
                if (g[i][j] == 'E') {
                    d[i][j] = 0;
                    q.emplace(i, j);
                }
            }
        }

        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            rep(dir, 0, 3) {
                int ni = i + dx[dir]; int nj = j + dy[dir];
                if (ni >= 0 and ni < n and nj >= 0 and nj < m) {
                    if (g[ni][nj] == '.' and d[ni][nj] == -1) {
                        d[ni][nj] = d[i][j] + 1;
                        q.emplace(ni, nj);
                    }
                }
            }
        }
    }();

    std::vector<std::string> op(n, std::string(m, '#'));
    rep(i, 0, n - 1) {
        rep(j, 0, m - 1) {
            if (g[i][j] == '#') {
                op[i][j] = '#';
            } 
            else if (g[i][j] == 'E') {
                op[i][j] = 'E';
            } 
            else {
                char ch = ' ';
                for (int dir = 0; dir < 4; ++dir) {
                    int ni = i + dx[dir];
                    int nj = j + dy[dir];
                    if (ni < 0 || ni >= n || nj < 0 || nj >= m) {
                    	continue;
                    }
                    if (d[ni][nj] == d[i][j] - 1) {
                        if (dir == 0) {
                        	ch = '^';
                        }
                        else if (dir == 1) {
                        	ch = 'v';
                        }
                        else if (dir == 2) {
                        	ch = '<';
                        }
                        else {
                        	ch = '>';
                        }
                        break;
                    }
                }
                op[i][j] = ch;
            }
        }
    }

    for (const auto& row : op) {
        std::cout << row << '\n';
    }
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