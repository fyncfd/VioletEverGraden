/*
* @Author: AlgoStruggler
* @Create Time: 2026-01-10 20:47:01
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
int N, Q;
std::vector<int> A;
ll X, Y;
/*-------------------------------MY_CODE_BEGIN--------------------------------*/
static inline void VioletEverGraden() {
    std::cin >> N >> Q;
    A.resize(N + 1);
    rep(i, 1, N, 1) {
    	std::cin >> A[i];
    }

    std::sort(A.begin() + 1, A.end(), [&](ll a, ll b) -> bool {
    	return a < b;
    });

    int __ = Q;
    while (__ --) {
        std::cin >> X >> Y;

        ll p1 = std::lower_bound(A.begin() + 1, A.end(), X) - A.begin();
        ll L = X; ll R = 1e18;
        ll ans = 0;
        while (L <= R) {
            ll mid = L + R >> 1;
            ll p2 = std::upper_bound(A.begin() + 1, A.end(), mid) - A.begin();
            ll dif = mid - X + 1;
            dif -= p2 - p1;
            if (dif >= Y) {
                ans = mid;
                R = mid - 1;
            } else {
                L = mid + 1;
            }
        }

        std::cout << ans << '\n';
    }
    /*太好了，这回只花998244353min就打完了！*/
/*
Test Sample

5 4
16 9 2 3 1
6 10
12 4
1 1
1000000000 1000000000

17
15
4
1999999999

10 10
284008711 658403910 982178205 50598815 694147827 230009803 763277509 509451676 821970166 284008710
740250292 159734720
255870361 8400028
23659634 718117163
697334729 301140741
698853172 270344164
713418715 285312509
50065000 52368934
46642556 591869945
607623561 273664826
482426028 265015448

899985013
264270388
741776803
998475472
969197337
998731226
102433934
638512505
881288390
747441478


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

    int _ = 1;
    //for (std::cin >> _; _; _--)
        VioletEverGraden();

    return 0;
}