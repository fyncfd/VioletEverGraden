/*
* @Author: AlgoStruggler
* @Create Time: 2025-05-24 16:21:27
* "To the Splendor of ACM-ICPC, We Consecrate Our AC Triumphs."
*/
#define  _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize("O2")
#include "bits/stdc++.h"
//#include <ext/pb_ds/assoc_container.hpp>

typedef long long i64;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef __int128 i128;
typedef std::pair<int, int> pii;
typedef std::pair<i64, i64> pll;

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
constexpr i64 LINF = 0x3f3f3f3f3f3f3f3f;
constexpr i64 mod = 998244353;
constexpr i64 MOD = 1e9 + 7;
int dx[] = {0, 0, 1, 0, -1 };
int dy[] = {0, -1, 0, 1, 0 };
constexpr int MAXN = 0;
/*-------------------------------MY_CODE_BEGIN--------------------------------*/
void solve() {
    i64 n, k;
    std::cin >> n >> k;
    std::string s;
    std::cin >> s;
    s = "?" + s;
    std::vector<i64> a(n + 10), dp(n + 10), ndp(n + 20);
    i64 max = -LINF;
    bool ex = false;
    for (int i = 1; i <= n; i++) {
        bool f = (s[i] == '1');
        std::cin >> a[i];
 
        if (f) {
            dp[i] = std::max(0ll, dp[i - 1] + a[i]);
        } else {
            dp[i] = 0;
        }
        max = std::max(max, dp[i]);
 
        if (!f) ex = true;
    }
 
    for (int i = n; i >= 1; i --) {
        bool f = s[i] == '1';
        if (f) {
            ndp[i] = std::max(0ll, ndp[i + 1] + a[i]);
        } else {
            ndp[i] = 0;
        }
        max = std::max(max, ndp[i]);
    }
 
    if ((max != k && !ex) || max > k) {
        std::cout << "NO\n";
        return ;
    }
 
    std::cout << "YES\n";
 
    for (int i = 1; i <= n; i ++) if (s[i] == '0') {
        a[i] = k - dp[i - 1] - ndp[i + 1];
        s[i] = '1';
        break;
    }
 
    for (int i = 1; i <= n; i ++) if (s[i] == '0') a[i] = -LINF;
 
    for (int i = 1; i <= n; i ++) std::cout << a[i] << " ";
    std::cout << '\n';
}
/*-------------------------------Author_Fd------------------------------------*/
//static inline void VioletEverGraden();

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
        solve();

    return 0;
}