/*
* @Author: AlgoStruggler
* @Create Time: 2025-06-13 19:28:40
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
std::vector<char> result;
int n; ll k;
std::vector<ll> a;
/*-------------------------------MY_CODE_BEGIN--------------------------------*/
static inline void VioletEverGraden() {
    std::cin >> n >> k;
    a.assign(n + 1, 0);
    ll sum = 0;
    rep(i, 1, n) {
        std::cin >> a[i];
        sum += a[i];
    }

    if (k == 0) {
        std::cout << sum << "\n";
        return;
    }

    auto chack = [&](ll x, int l, int r, int p) -> bool {
        if (p <= 0) {
        	return r < l;
        }
        if (r < l) {
        	return false;
        }
        if (p > 1 and (r - l + 1) < (2LL * p - 1)) {
        	return false;
        }
        if (p == 1 and (r - l + 1) < 1) {
        	return false;
        }

        int id = l;
        rep(t, 1, p - 1) {
            ll summ = 0;
            bool ok = false;
            while (id <= r) {
                summ += a[id];
                id ++;
                if (summ >= x) {
                    if (id > r) {
                    	return false;
                    }
                    id ++;
                    ok = true;
                    break;
                }
            }
            if (!ok) {
            	return false;
            }
        }

        ll sum = 0;
        while (id <= r) {
            sum += a[id];
            id ++;
        }
        return sum >= x;
    };
    
    auto check2 = [&](ll x) -> bool {
        if (chack(x, 1, n, k + 1)) {
        	return true;
        }
        if (k >= 1 and chack(x, 2, n, k)) {
        	return true;
        }
        if (k >= 1 and chack(x, 1, n - 1, k)) {
        	return true;
        }
        if (k >= 2 and chack(x, 2, n - 1, k - 1)) {
        	return true;
        }
        return false;
    };

    ll l = 1; ll r = sum;
    ll ans = 0;
    while (l <= r) {
        ll mid = l + (r - l) / 2;
        if (check2(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    std::cout << ans << "\n";
    /*return AC*/
/*
Test Sample

3
5 0
1 1 1 1 1
6 3
6 6 6 6 6 6
3 2
5 8 9

5
6
8


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

    /*cout << std::fixed << std::setprecision();
    cerr << std::fixed << std::setprecision();*/


    __INIT__();

    int _ = 1;

    for (std::cin >> _; _; _--)
        VioletEverGraden();

    return 0;
}