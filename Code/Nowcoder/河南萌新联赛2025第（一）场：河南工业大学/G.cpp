/*
* @Author: AlgoStruggler
* @Create Time: 2025-07-16 13:41:17
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
#define rep(i, l, r, x) for (decltype(l) i = (l); i <= (r); i += (x))
#define dep(i, l, r, x) for (decltype(l) i = (l); i >= (r); i -= (x))
#define lop(i, x) for (auto &i : x)
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
std::vector<ll> a;
/*-------------------------------MY_CODE_BEGIN--------------------------------*/
static inline void VioletEverGraden() {
    std::cin >> n;
    a.resize(n + 1);
    rep(i, 1, n, 1) {
    	std::cin >> a[i];
    }

    std::vector<ll> pre(n + 1);
    ll p1 = a[1]; ll p2 = a[1]; pre[1] = a[1];
    rep(i, 2, n, 1) {
        p1 = std::max(a[i], p1 + a[i]); p2 = std::max(p2, p1);
        pre[i] = p2;
    }

    std::vector<ll> suf(n + 1);
    p1 = a[n]; p2 = a[n]; suf[n] = a[n];
    dep(i, n - 1, 1, 1) {
        p1 = std::max(a[i], p1 + a[i]); p2 = std::max(p2, p1);
        suf[i] = p2;
    }

    ll ans = -LINF;
    rep(i, 1, n - 1, 1) {
        ans = std::max(ans, pre[i] + suf[i + 1]);
    }

    if (ans == -LINF) {
        ll min1 = LINF, min2 = LINF;
        rep(i, 1, n, 1) {
            if (a[i] <= min1) {
                min2 = min1; min1 = a[i];
            } else if (a[i] < min2) {
                min2 = a[i];
            }
        }

        ans = min1 + min2;
    }

    std::cout << ans << '\n';
    /*return AC*/
/*
Test Sample

2
5
2 -1 3 -4 5
4
-1 -2 -3 -4

9
-3


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

    /*cout << std::fixed << std::setprecision(9);
    cerr << std::fixed << std::setprecision(9);*/


    __INIT__();

    int _ = 1;

    for (std::cin >> _; _; _--)
        VioletEverGraden();

    return 0;
}