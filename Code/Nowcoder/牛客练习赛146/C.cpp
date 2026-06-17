/*
* @Author: AlgoStruggler
* @Create Time: 2025-11-21 19:38:12
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
int n, m;
std::vector<pii> f;
/*-------------------------------MY_CODE_BEGIN--------------------------------*/
static inline void VioletEverGraden() {
    std::cin >> n >> m;
    f.resize(m + 1);
    rep(i, 1, m , 1) {
        std::cin >> f[i].fi >> f[i].se;
    }
    std::sort(f.begin(), f.end(), [&](pii a, pii b) -> bool {
    	if (a.fi == b.fi) {
    		return a.se < b.se;
    	}
    	return a.fi < b.fi;
    });

    ll min = 0; ll max1 = 0;
    int pre = 0; int temp = 0;
    rep(i, 1, m, 1) {
        int t = f[i].fi; int x = f[i].se;
        int L = t - pre; int d = 1 - x;
        int mi = (temp == d ? 0 : 1);
        min += mi;
        
        int ma = 0;
        if (L % 2 == mi % 2) {
            ma = L;
        } else {
            ma = L - 1;
        }
        max1 += ma; temp = d; pre = t;
    }
    
    int p = n - pre; ll sum = max1 + p;

    int T;
    std::cin >> T;
    while (T--) {
        ll s;
        std::cin >> s;
        if (s < min or s > sum) {
            std::cout << "No\n";
        } else {
            if (p > 0) {
                std::cout << "Yes\n";
            } else {
                if ((s - min) % 2 == 0) {
                    std::cout << "Yes\n";
                } else {
                    std::cout << "No\n";
                }
            }
        }
    }
    /*太好了，这回只花998244353min就打完了！*/
/*
Test Sample

10 5
3 0
4 1
6 1
8 1
10 0
5
2
3
7
9
10

No
Yes
Yes
Yes
No

7 3
1 0
3 0
7 1
2
2
3

Yes
No


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