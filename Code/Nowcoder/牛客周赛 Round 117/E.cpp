/*
* @Author: AlgoStruggler
* @Create Time: 2025-11-09 19:41:14
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
int dx[] = {1, 1, -1, -1, 2, 2, -2, -2};
int dy[] = {2, -2, 2, -2, 1, -1, 1, -1};
constexpr int MAXN = 0;
int n, m, k;
int a1, b1, a2, b2;
/*-------------------------------MY_CODE_BEGIN--------------------------------*/
static inline void VioletEverGraden() {
    std::cin >> n >> m >> k;
    std::cin >> a1 >> b1 >> a2 >> b2;

    auto check = [&](int r, int c) -> bool {
        return r >= 1 and r <= n and c >= 1 and c <= m;
    };
    auto bfs = [&](int sx, int sy) -> matrix<int> {
        matrix<int> dis(n + 1, std::vector<int>(m + 1, -1));
        std::queue<std::pair<int, int>> q;
        q.push({sx, sy});
        dis[sx][sy] = 0;


        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int i = 0; i < 8; i++) {
                int nr = r + dx[i];
                int nc = c + dy[i];
                if (check(nr, nc) and dis[nr][nc] == -1) {
                    dis[nr][nc] = dis[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }
        return dis;
    };

    auto dis = bfs(a2, b2);
    int min = dis[a1][b1];

    if (min == -1 or k < min or (k - min) % 2 != 0) {
        std::cout << "No\n";
        return ;
    }

    if (min == 0 and k > 0) {
        bool ok1 = false;
        rep(i, 0, 7, 1) {
            int nr = a1 + dx[i];
            int nc = b1 + dy[i];
            if (check(nr, nc)) {
                ok1 = true;
                break;
            }
        }
        if (!ok1) {
            std::cout << "No\n";
            return;
        }
    }

    std::cout << "Yes\n";
    int xx = a1; int yy = b1;
    int res = k;

    auto f = [&]() {
        while (res > 0) {
            bool ok = false;
            rep(i, 0, 7, 1) {
                int nx = xx + dx[i];
                int ny = yy + dy[i];
                if (!check(nx, ny) or dis[nx][ny] == -1) {
                    continue;
                }
                int p = dis[nx][ny];
                int ans = res - 1;
                if (ans >= p and (ans - p) % 2 == 0) {
                    std::cout << nx << " " << ny << "\n";
                    xx = nx; yy = ny;
                    res --;
                    ok = true;
                    break;
                }
            }
            if (!ok) {
                break;
            }
        }
    };

    f();
    /*太好了，这回只花998244353min就打完了！*/
/*
Test Sample

3 3 3
1 1 1 2

Yes
2 3
3 1
1 2


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