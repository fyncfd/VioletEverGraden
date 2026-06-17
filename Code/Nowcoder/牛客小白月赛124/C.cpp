/*
* @Author: AlgoStruggler
* @Create Time: 2025-11-28 19:09:09
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
// struct pll { ll fi; ll se; };

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
const int dx1[8] = {1, 1, -1, -1, 2, 2, -2, -2};
const int dy1[8] = {2, -2, 2, -2, 1, -1, 1, -1};
const int dx2[8] = {1, 1, 1, 0, 0, -1, -1, -1};
const int dy2[8] = {1, 0, -1, 1, -1, 1, 0, -1};
constexpr int MAXN = 0;
ll x, y, n;
/*-------------------------------MY_CODE_BEGIN--------------------------------*/
static inline void VioletEverGraden() {
    std::cin >> x >> y >> n;

    std::unordered_set<ll> ma;
    std::vector<std::pair<ll, ll>> mal(n);
    rep(i, 0, n - 1, 1) {
        ll hx, hy;
        std::cin >> hx >> hy;
        ma.insert((hx << 32) | (hy & 0xFFFFFFFFLL));
        mal[i] = {hx, hy};
    }

    bool ok = false;
    rep(k, 0, 7, 1) {
        ll nx = x + dx1[k]; ll ny = y + dy1[k];
        if (ma.count((nx << 32) | (ny & 0xFFFFFFFFLL))) {
            ok = true;
            break;
        }
    }

    bool ok2 = false;
    rep(k, -1, 7, 1) {
        ll nx, ny;
        if (k == -1) {
            continue;
        } else {
            nx = x + dx2[k]; ny = y + dy2[k];
        }

        bool ok3= true;
        bool ok4 = ma.count((nx << 32) | (ny & 0xFFFFFFFFLL));
        rep(m, 0, 7, 1) {
            ll hx = nx + dx1[m]; ll hy = ny + dy1[m];
            if (ma.count((hx << 32) | (hy & 0xFFFFFFFFLL))) {
                if (ok4 and hx == nx and hy == ny) {
                	;
                }
                ok3= false;
                break;
            }
        }

        if (ok3) {
            ok2 = true;
            break;
        }
    }

    if (!ok2) {
        if (ok) {
            std::cout << "B\n";
        } else {
            std::cout << "A\n";
        }
    } else {
        std::cout << "C\n";
    }
    /*太好了，这回只花998244353min就打完了！*/
/*
Test Sample

3
1 1 1
2 2
5 5 4
5 4
5 6
7 7
3 3
5 5 5
5 4
5 6
7 7
3 3
6 7

C
A
B


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