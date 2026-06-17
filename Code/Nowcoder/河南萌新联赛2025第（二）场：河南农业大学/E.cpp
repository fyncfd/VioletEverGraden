/*
* @Author: AlgoStruggler
* @Create Time: 2025-07-23 15:05:56
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
constexpr int MAXN = 5e3 + 15;
int n, m;
/*-------------------------------MY_CODE_BEGIN--------------------------------*/
ll comb[MAXN][MAXN];
ll f[MAXN];
static inline void VioletEverGraden() {
    std::cin >> n >> m;

	auto init = [&]() -> void {
	    comb[0][0] = 1;
	    rep(i, 1, n, 1) {
	        comb[i][0] = 1;
	        rep(j, 1, i, 1) {
	            comb[i][j] = (comb[i-1][j-1] + comb[i-1][j]) % MOD;
	        }
	    }
	};

	init();

    ll ans = 0;
    dep(d, n, 2, 1) {
        int cnt = n / d;
        if (cnt < m) {
            f[d] = 0;
            continue;
        }
        f[d] = comb[cnt][m];
        rep(i, 2 * d, n, d) {
            f[d] = (f[d] - f[i] + MOD) % MOD;
        }
        ans = (ans + f[d]) % MOD;
    }
    
    std::cout << ans << '\n';
    /*return AC*/
/*
Test Sample

5 2

1

6 3

1

85 25

661928654


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

    //for (std::cin >> _; _; _--)
        VioletEverGraden();

    return 0;
}