/*
* @Author: AlgoStruggler
* @Create Time: 2025-05-13 23:15:28
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
int n;
std::vector<ll> a;
/*-------------------------------MY_CODE_BEGIN--------------------------------*/
static inline void VioletEverGraden() {
    std::cin >> n;
    a.resize(n + 1);
    rep(i, 1, n) {
    	std::cin >> a[i];
    }

    auto check = [&](ll mid) -> bool {
    	/*int num = 0;
    	for (int i = 1; i <= n; ) {
    		if (a[i] + mid < a[i + 1]) {
    			i ++;
    			num ++;
    		} else {
    			i += 2;
    		}
    	}

    	if (num <= 1) {
    		return true;
    	} else {
    		return false;
    	}*/
    	if (n & 1) {
    		int num = 0;
    		rep(i, 1, n) {
    			std::vector<ll> p(n + 1);
    			int cnt = 0;
    			int res = 0;
    			rep(j, 1, n) {
    				if (j != i) {
    					cnt ++;
    					p[cnt] = a[j];
    				}
    			}
    			for (int j = 2; j <= n - 1; j += 2) {
    				if (p[j] - p[j - 1] > mid) {
    					num ++;
    					break;
    				}
    			}
    		}

    		if (num == n) {
    			return false;
    		}
    	} else {
    		for (int i = 2; i <= n; i += 2) {
    			if (a[i] - a[i - 1] > mid) {
    				return false;
    			}
    		}
    	}

    	return true;
    };

    ll l = 1; ll r = 2e18;
    ll ans = 0;
	while (l <= r) {
        ll mid = (l + r) / 2;
        if (check(mid)) {
            r = mid - 1;
            ans = r;
        } else {
            l = mid + 1;
        }
    }


    std::cout << ans + 1 << '\n';
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

    /*cout << fixed << setprecision();
    cerr << fixed << setprecision();*/


    __INIT__();

    int _ = 1;

    for (std::cin >> _; _; _--)
        VioletEverGraden();

    return 0;
}