/*
* @Author: AlgoStruggler
* @Create Time: 2025-07-19 22:54:41
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
ll a, b, c, d;
/*-------------------------------MY_CODE_BEGIN--------------------------------*/
static inline void VioletEverGraden() {
    std::cin >> n;

    int __ = n;
    ll p1 = 0; ll p2 = 0;
    ll ans = 0;
/*    ll p3 = 0; ll p4 = 0;*/
    while (__ --) {
    	std::cin >> a >> b >> c >> d;

/*    	if (a - c > 0) {
    		p1 += a - c;
    	} else {
    		p2 += c - a;
    	}

    	if (b - d > 0) {
    		p3 += b - d;
    	} else {
    		p4 += d - b;
    	}*/

    	ll temp1 = a - c; ll temp2 = b - d;
    	if (temp1 > 0) {
    		if (p1 < 0) {
    			if (std::abs(p1) > temp1) {
    				ans += std::abs(temp1);
    				p1 += std::abs(temp1);
    			} else {
    				ans += std::abs(p1);
    				p1 
    			}
    	}
    		} else {

    		}
    	}

    }

/*    ll ans = 0;
    ans += std::abs(p1 - p2) + std::abs(p3 - p4);

    std::cout << ans << '\n';*/

    ll ans = 0;
    ans = std::abs(p1) + std::abs(p2);

    std::cout << ans << '\n';

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

    /*cout << std::fixed << std::setprecision(9);
    cerr << std::fixed << std::setprecision(9);*/


    __INIT__();

    int _ = 1;

    for (std::cin >> _; _; _--)
        VioletEverGraden();

    return 0;
}