/*
* @Author: AlgoStruggler
* @Create Time: 2025-08-21 23:21:44
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
struct pii { int fi; int se; };
struct pll { ll fi; ll se; };

#define all(x) x.begin() + 1, x.end()
#define rep(i, l, r, x) for (decltype(l) i = (l); i <= (r); i += (x))
#define dep(i, l, r, x) for (decltype(l) i = (l); i >= (r); i -= (x))
#define lop(i, x) for (auto &i : x)

//using namespace std;
//using namespace __gnu_pbds;
template<class T> using matrix = std::vector<std::vector<T>>;
template <typename T> using pq = std::priority_queue<T>;
template<class T> using matrix = std::vector<std::vector<T>>;
template <class Key, class Value> using ump = std::unordered_map<Key, Value>;
template <typename T> using ust = std::unordered_set<T>;
//template <typename Key, typename Value> using hash = __gnu_pbds::gp_hash_table<Key, Value>;
template<class T> concept Signed = std::is_signed_v<T>;
template<class T> concept Unsigned = std::is_unsigned_v<T>;
template<class T> concept Arithmetic = std::is_arithmetic_v<T>;
template<class T> std::istream &operator >> (std::istream &cin, std::vector<T> &a) {
    rep(i, 1, a.size() - 1, 1) {
        std::cin >> a[i];
    }
    return cin;
}
template<class T> std::ostream &operator << (std::ostream &cout, std::vector<T> &a) {
    int n = a.size() - 1;
    if (!n) {
        return cout;
    }
    rep(i, 1, a.size() - 1, 1) {
        std::cout << a[i] << " \n"[i == a.size() - 1];
    }
    return cout;
}
template<class T> std::istream &operator >> (std::istream &cin, matrix<T> &a) {
    rep(i, 1, a.size() - 1, 1) {
        rep(j, 1, a[i].size() - 1, 1) {
            cin >> a[i][j];
        }
    }
    return cin;
}
template<class T> std::ostream &operator << (std::ostream &cout, const matrix<T> &a) {
    if (a.empty()) {
        return cout;
    }
    rep(i, 1, a.size() - 1, 1) {
        rep(j, 1, a[i].size() - 1, 1) {
            cout << a[i][j] << " \n"[j == a[i].size() - 1];
        }
    }
    return cout;
}
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
ll n, k;
/*-------------------------------MY_CODE_BEGIN--------------------------------*/
ll f[55];

void calc() {
    std::vector<ll> pow3(50 + 2, 1);
    rep(i, 1, 51, 1) {
        pow3[i] = pow3[i - 1] * 3;
    }
    rep(i, 0, 49, 1) {
        if (i == 0) {
            f[i] = 3;
        } else {
            f[i] = pow3[i + 1] + i * pow3[i - 1];
        }
    }
}
static inline void VioletEverGraden() {
    std::cin >> n >> k;

    std::vector<int> d(55, 0);
    ll tn = n; int l = 0;
    for (int i = 0; tn > 0; i ++) {
        d[i] = tn % 3;
        tn /= 3;
        l = i+1;
    }

    ll cnt = 0; ll ans = 0;
    rep(i, 0, 49, 1) {
        cnt += d[i];
        ans += d[i] * f[i];
    }
    if (cnt > k) {
        std::cout << -1 << '\n';
        return ;
    }


    dep(i, 49, 1, 1) {
        while (d[i] > 0 and cnt + 2 <= k) {
            d[i] --;
            d[i - 1] += 3;
            cnt += 2;
            ans = ans - f[i] + 3 * f[i - 1];
        }
    }

    std::cout << ans << '\n';
    /*太好了，这回只花998244353min就打完了！*/
/*
Test Sample

8
1 1
3 3
8 3
2 4
10 10
20 14
3 2
9 1

3
9
-1
6
30
63
10
33


*/
}
/*-------------------------------Author_Fd------------------------------------*/
static inline void VioletEverGraden();

auto __FAST_IO__ = []() -> int {
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
    return 0;
}();

signed main() {
#ifdef LOCAL
    freopen("A.in", "r", stdin);
#endif // LOCAL

    /*std::cout << std::fixed << std::setprecision(9);
    std::cerr << std::fixed << std::setprecision(9);*/
    calc();

    int _ = 1;
    for (std::cin >> _; _; _--)
        VioletEverGraden();

    return 0;
}