/*
* @Author: AlgoStruggler
* @Create Time: 2025-05-26 23:15:14
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
std::vector<int> x, y;
/*-------------------------------MY_CODE_BEGIN--------------------------------*/
static inline void VioletEverGraden() {
    std::cin >> n;
    x.resize(n); y.resize(n);
    std::vector<pii> doc(n);
    rep(i, 0, n - 1) {
        std::cin >> x[i] >> y[i];
        doc[i] = {x[i], y[i]};
    }

    if (n == 1) {
        std::cout << "1\n";
        return ;
    }

    std::vector<int> sx = x;
    std::vector<int> sy = y;
    std::sort(sx.begin(), sx.end(), [&](int a, int b) {
    	return a < b;
    });
    sort(sy.begin(), sy.end(), [&](int a, int b) {
    	return a < b;
    });
    
    std::vector<int> minx(n); std::vector<int> maxx(n);
    std::vector<int> miny(n); std::vector<int> maxy(n);
    
    rep(i, 0, n - 1) {
        int xi = x[i], yi = y[i];

        if (sx[0] == xi) {
            minx[i] = sx[1];
        } else {
            minx[i] = sx[0];
        }

        if (sx.back() == xi) {
            maxx[i] = sx[n - 2];
        } else {
            maxx[i] = sx.back();
        }

        if (sy[0] == yi) {
            miny[i] = sy[1];
        } else {
            miny[i] = sy[0];
        }

        if (sy.back() == yi) {
            maxy[i] = sy[n - 2];
        } else {
            maxy[i] = sy.back();
        }
    }
    
    ll temp = (ll)(sx.back() - sx[0] + 1) * (sy.back() - sy[0] + 1);
    ll ans = temp;
    
    rep(i, 0, n - 1) {
        int xi = x[i], yi = y[i];
        int cnt1 = minx[i]; int cnt2 = maxx[i];
    	int cnt3 = miny[i]; int cnt4 = maxy[i];
        
        ll cur = (ll)(cnt2 - cnt1 + 1) * (cnt4 - cnt3 + 1);
        ll p = (ll)(cnt2 - cnt1 + 1) * (cnt4 - cnt3 + 1);
        if (p > (n - 1)) {
            ans = std::min(ans, cur);
        } else {
            ll ans0 = 0;
            ans0 = (ll)(cnt2 - (cnt1 - 1) + 1) * (cnt4 - cnt3 + 1);
            ans = std::min(ans, ans0);

            ans0 = (ll)((cnt2 + 1) - cnt1 + 1) * (cnt4 - cnt3 + 1);
            ans = std::min(ans, ans0);

            ans0 = (ll)(cnt2 - cnt1 + 1) * (cnt4 - (cnt3 - 1) + 1);
            ans = std::min(ans, ans0);

            ans0 = (ll)(cnt2 - cnt1 + 1) * ((cnt4 + 1) - cnt3 + 1);
            ans = std::min(ans, ans0);
        }
    }

    std::cout << ans << '\n';
    /*return AC*/
/*
Test Sample

7
3
1 1
1 2
2 1
5
1 1
2 6
6 4
3 3
8 2
4
1 1
1 1000000000
1000000000 1
1000000000 1000000000
1
1 1
5
1 2
4 2
4 3
3 1
3 2
3
1 1
2 5
2 2
4
4 3
3 1
4 4
1 2

3
32
1000000000000000000
1
6
4
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

    /*cout << fixed << setprecision();
    cerr << fixed << setprecision();*/


    __INIT__();

    int _ = 1;

    for (std::cin >> _; _; _--)
        VioletEverGraden();

    return 0;
}