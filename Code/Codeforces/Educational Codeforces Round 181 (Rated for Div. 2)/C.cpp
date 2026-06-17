/*
* @Author: AlgoStruggler
* @Create Time: 2025-07-22 23:12:04
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
ll l, r;
/*-------------------------------MY_CODE_BEGIN--------------------------------*/
std::vector<int> p = {2, 3, 5, 7};
static inline void VioletEverGraden() {
    std::cin >> l >> r;

    auto comb = [&](ll n) -> ll {
        ll ans = 0;
        int k = p.size();
        for (int m = 1; m < (1 << k); m ++) {
            int bits = __builtin_popcount(m);
            ll temp = 1;
            rep(i, 0, k - 1, 1) {
                if (m & (1 << i)) {
                    temp *= p[i];
                    if (temp > n) {
                    	break;
                    }
                }
            }
            if (temp > n) {
            	continue;
            }
            if (bits % 2 == 1) {
                ans += n / temp;
            } else {
                ans -= n / temp;
            }
        }
        return ans;
    };

    ll hi = comb(r); ll lo = comb(l - 1);
    ll ans1 = r - l + 1; ll ans2 = hi - lo;
    ll ans = ans1 - ans2;
    
    std::cout << ans << '\n';
    /*return AC*/
/*
Test Sample

4
2 100
2 1000
13 37
2 1000000000000000000

21
227
7
228571428571428570


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