/*
* @Author: AlgoStruggler
* @Create Time: 2025-05-14 23:19:04
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
int n; ll k;
std::vector<ll> a;
/*-------------------------------MY_CODE_BEGIN--------------------------------*/
static inline void VioletEverGraden() {
    std::cin >> n >> k;
    a.resize(n + 1);
    rep(i, 1, n) {
    	std::cin >> a[i];
    }

    std::sort(a.begin() + 1, a.end(), [&](int a, int b) {
    	return a > b;
    });
    int ans = 0; int cnt = 0;
    if (n & 1) {
    	ans += a[n];
    	for (int i = 1; i <= n - 2; i += 2) {
    		ans += a[i] - a[i + 1];
    		if (cnt < k) {
    			int dif = k - cnt;
    			if (dif < a[i] - a[i + 1]) {
    				ans -= dif;
    				cnt = k;
    			} else {
    				ans -= a[i] - a[i + 1];
    				cnt += a[i] - a[i + 1];
    			}
    		}
    	}
    } else {
    	for (int i = 1; i <= n - 1; i += 2) {
    		ans += a[i] - a[i + 1];
    		if (cnt < k) {
    			int dif = k - cnt;
    			if (dif <= a[i] - a[i + 1]) {
    				ans -= dif;
    				cnt = k;
    			} else {
    				ans -= a[i] - a[i + 1];
    				cnt += a[i] - a[i + 1];
    			}
    		}
    	}
    }

    std::cout << ans << '\n';
    /*return AC*/
/*
Test Sample

4
2 5
1 10
3 0
10 15 12
4 6
3 1 2 4
2 4
6 9

4
13
0
0


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