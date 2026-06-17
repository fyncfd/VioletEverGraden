/*
* @Author: AlgoStruggler
* @Create Time: 2025-08-10 19:44:09
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
constexpr int MAXN = 5e2 + 10;
int n, m;
/*-------------------------------MY_CODE_BEGIN--------------------------------*/
static inline void VioletEverGraden() {
    std::cin >> n >> m;
    std::vector<std::vector<int>> a(n, std::vector<int>(m));
    rep(i, 0, n - 1, 1) {
        rep(j, 0, m - 1, 1) {
            std::cin >> a[i][j];
        }
    }

    std::vector<std::vector<int>> min(n, std::vector<int>(m));
    int pp = 0;
    rep(i, 0, n - 1, 1) {
        rep(j, 0, m - 1, 1) {
            min[i][j] = std::min(i + 1, j + 1);
            if (a[i][j] == min[i][j]) {
                pp ++;
            }
        }
    }

    std::vector<std::vector<bool>> flag(MAXN, std::vector<bool>(MAXN, false));
    rep(i, 0, n - 1, 1) {
        rep(j, 0, m - 1, 1) {
            int v0 = min[i][j];
            int w0 = a[i][j];
            if (v0 < MAXN and w0 < MAXN) {
                flag[v0][w0] = true;
            }
        }
    }

    bool ok2 = false;
    rep(x, 1, MAXN - 1, 1) {
        rep(y, 1, MAXN - 1, 1) {
            if (x != y and flag[x][y] and flag[y][x]) {
                ok2 = true;
                break;
            }
        }
        if (ok2) break;
    }
    if (ok2) {
        std::cout << pp + 2 << '\n';
        return ;
    }

    std::bitset<MAXN> B[MAXN];
    int cntB[MAXN] = { 0 };

    rep(i, 0, MAXN - 1, 1) {
        B[i].reset();
        cntB[i] = 0;
    }

    rep(i, 0, n - 1, 1) {
        rep(j, 0, m - 1, 1) {
            int v0 = min[i][j]; int w0 = a[i][j];
            if (w0 < MAXN) {
                B[w0].set(v0);
            }
        }
    }

    rep(w, 1, MAXN - 1, 1) {
        B[w].set(w, 0);
        cntB[w] = B[w].count();
    }

    bool ok1 = false;
    rep(i, 0, n - 1, 1) {
        rep(j, 0, m - 1, 1) {
            if (a[i][j] == min[i][j]) {
            	continue;
            }
            int v = min[i][j]; int valw = a[i][j];
            if (v >= MAXN or valw >= MAXN) {
            	continue;
            }
            if (cntB[v] > 0) {
                if (B[v].test(valw)) {
                    if (cntB[v] > 1) {
                        ok1 = true;
                        break;
                    }
                } else {
                    ok1 = true;
                    break;
                }
            }
        }
        if (ok1) break;
    }

    if (ok1) {
        std::cout << pp + 1 << '\n';
    } else {
        std::cout << pp << '\n';
    }
    /*太好了，这回只花998244353min就打完了！*/
/*
Test Sample

2 3
1 1 4
5 1 4

3

3 3
1 2 3
2 1 3
3 2 1

4


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