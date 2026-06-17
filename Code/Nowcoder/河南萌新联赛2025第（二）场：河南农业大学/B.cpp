/*
* @Author: AlgoStruggler
* @Create Time: 2025-07-23 13:28:00
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
ll l, r, y;
/*-------------------------------MY_CODE_BEGIN--------------------------------*/
ll ksm(ll base, ll exp) {
    ll result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exp /= 2;
    }
    return result;
}

ll inv(ll x) {
    return ksm(x, MOD - 2);
}

static inline void VioletEverGraden() {
    std::cin >> l >> r >> y;

	auto calc = [&](ll n, int k) -> ll {
	    ll p = (n + 1) / (1LL << (k + 1));
	    ll res = (n + 1) % (1LL << (k + 1));

	    ll ans = p * (1LL << k);
	    ans += std::max(0LL, res - (1LL << k));

	    return ans;
	};

	auto f = [&](ll l, ll r, int k) -> ll {
	    return calc(r, k) - calc(l - 1, k);
	};

    ll sum = r - l + 1; ll invs = inv(sum);

    ll ans = 0;
    rep(k, 0, 29, 1) {
        ll m = 1LL << k;

        int bity = 0;
        if (y & m) {
        	bity = 1;
        } else {
        	bity = 0;
        }

        ll dif = 0;
        if (bity == 1) {
            dif = sum - f(l, r, k);
        } else {
            dif = f(l, r, k);
        }

        ll temp = (dif % MOD) * ksm(2, k) % MOD;
        temp = temp * invs % MOD;
        ans = (ans + temp) % MOD;
    }

    ans = 0;
    rep(k, 0, 29, 1) {
        ll m = 1LL << k;

        int bity = 0;
        if (y & m) {
        	bity = 1;
        } else {
        	bity = 0;
        }

        ll dif = 0;
        if (bity == 1) {
            dif = sum - f(l, r, k);
        } else {
            dif = f(l, r, k);
        }

        ans = (ans + dif % MOD * invs % MOD) % MOD;
    }
    
    std::cout << ans << '\n';
    /*return AC*/
/*
Test Sample

3
1 1 1
1 1 0
1 10 5

0
1
300000004


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