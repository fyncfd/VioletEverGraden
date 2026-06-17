/*
* @Author: AlgoStruggler
* @Create Time: 2025-04-27 19:40:32
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
#define pb push_back
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
constexpr int MAXN = 1e6;
/*-------------------------------MY_CODE_BEGIN--------------------------------*/
static inline void VioletEverGraden() {
    std::vector<int> p(MAXN + 1);

    rep(i, 1, MAXN) {
        int cnt = 0;
        int tmp = i;
        while (tmp) {
            tmp >>= 1;
            cnt += tmp;
        }
        p[i] = cnt;
    }

    int max = 0;
    for (int i = 1; i <= MAXN; ++i) {
        int m = p[i] + 1;
        if (m > max) max = m;
    }

    std::vector<int> inv(max + 2);
    inv[1] = 1;
    rep(i, 2, max) {
        inv[i] = (mod - mod / i) * 1LL * inv[mod % i] % mod;
    }

    int T; std::cin >> T;
    std::vector<int> ns(T);
    rep(i, 0,  T - 1) {
        std::cin >> ns[i];
    }

    std::vector<int> ans(T);
    rep(i, 0, T - 1) {
        int n = ns[i];
        int m = p[n] + 1;
        ans[i] = inv[m];
    }

    rep(i, 0, T - 1) {
        std::cout << ans[i] << " \n"[i == T - 1];
    }
    /*return AC*/
/*
Test Sample

10
1 2 3 4 5 6 7 8 9 10

1 499122177 499122177 748683265 748683265 598946612 598946612 873463809 873463809 443664157


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