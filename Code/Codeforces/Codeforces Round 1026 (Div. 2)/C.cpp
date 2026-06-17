/*
* @Author: AlgoStruggler
* @Create Time: 2025-05-24 22:37:31
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
//typedef std::pair<int, int> pii;
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
int dx[] = {0, 0, 1, 0, -1 };
int dy[] = {0, -1, 0, 1, 0 };
constexpr int MAXN = 0;
int n;
std::vector<int> d;
struct pii {
    int l; int r;
};
std::vector<pii> p;
/*-------------------------------MY_CODE_BEGIN--------------------------------*/
static inline void VioletEverGraden() {
    std::cin >> n;
    d.resize(n + 1);
    rep(i, 1, n) {
        std::cin >> d[i];
    }
    p.resize(n + 1);
    rep(i, 1, n) {
        std::cin >> p[i].l >> p[i].r;
    }

    std::vector<int> max(n + 1, 0); std::vector<int> min(n + 1, 0);
    rep(i, 1, n) {
        if (d[i] != -1) {
            min[i] = min[i - 1] + d[i];
            max[i] = max[i - 1] + d[i];
        } else {
            max[i] = max[i - 1] + 1;
            min[i] = min[i - 1];
        }

        max[i] = std::min(max[i], p[i].r);
        min[i] = std::max(min[i], p[i].l);
    }

    int cur = max[n];
    red(i, n, 1) {
        if (d[i] != -1) {
            cur -= d[i];
        } else {
            int le = min[i - 1]; int ri = max[i - 1];

            if (le <= cur and ri >= cur) {
                d[i] = 0;
            } else if (le <= cur - 1 and ri >= cur - 1) {
                d[i] = 1; cur --;
            } else {
                std::cout << -12138 << '\n';
                return ;
            }
        }
    }

    if (cur != 0) {
        std::cout << 114514 << '\n';
    } else {
        rep(i, 1, n) {
            std::cout << d[i] << " \n"[i == n];
        }
        //std::cerr << '?' << '\n';
    }
    /*return AC*/
/*
Test Sample

5
4
0 -1 -1 1
0 4
1 2
2 4
1 4
3
0 -1 -1
0 1
2 2
0 3
2
-1 -1
0 0
2 2
8
-1 -1 1 -1 -1 0 0 -1
0 0
0 1
0 2
0 2
1 3
0 4
2 5
4 5
1
0
1 1

0 1 1 1
-1
-1
0 0 1 1 1 0 0 1
-1


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

    for (std::cin >> _; _; _--)
        VioletEverGraden();

    return 0;
}