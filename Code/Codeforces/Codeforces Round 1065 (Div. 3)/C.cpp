/*
* @Author: AlgoStruggler
* @Create Time: 2025-11-20 23:21:39
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
int n;
std::vector<int> a;
std::vector<int> b;
/*-------------------------------MY_CODE_BEGIN--------------------------------*/
static inline void VioletEverGraden() {
    std::cin >> n;
    a.resize(n + 1); b.resize(n + 1);
    std::cin >> a;
    std::cin >> b;

    // int cnt1 = 0; int cnt2 = 0;
    // rep(i, 1, 1, n) {
    // 	cnt1 += a[i] == 0; cnt2 += b[i] == 0;
    // }

    // int num1 = 0; int num2 = 0;
    // rep(i, 1, n, 1) {
    // 	if (i & 1) {
    // 		if ((a[i] == 1 and b[i] == 0) or (a[i] == 0 and b[i] == 1)) {
    // 			num1 ++;
    // 		}
    // 	} else {
    // 		if ((a[i] == 1 and b[i] == 0) or (a[i] == 0 and b[i] == 1)) {
    // 			num2 ++;
    // 		}
    // 	}
    // }

    // if ((cnt1 + num1) & 1 and (cnt2 + num2) % 2 == 0) {
    // 	std::cout << "Ajisai\n";
    // } else if ((cnt1 + num1) % 2 == 0 and (cnt2 + num2) & 1) {
    // 	std::cout << "Mai\n";
    // } else if ((cnt1 + num1) & 1 and (cnt2 + num2) & 1) {
    // 	std::cout << "Tie\n";
    // } else if ((cnt1 + num1) % 2 == 0 and (cnt2 + num2) % 2 == 0) {
    // 	std::cout << "Tie\n";
    // }

    int xora = 0, xorb = 0;
    rep(i, 1, n, 1) {
        xora ^= a[i]; xorb ^= b[i];
    }
    
    int f = 0;
    rep(i, 1, n, 1) {
        if (a[i] != b[i]) {
        	f ++;
        }
    }
    
    if (f == 0) {
        if (xora > xorb) {
        	std::cout << "Ajisai\n";
        }
        else if (xora < xorb) {
        	std::cout << "Mai\n";
        }
        else {
        	std::cout << "Tie\n";
        }
        return ;
    }
    
    int p1 = 0, p2 = 0;
    rep(i, 1, n, 1) {
        if (a[i] != b[i]) {
            if (i % 2 == 1) 
            	p1 ++;
            else {
            	p2 ++;
            }
        }
    }
    
    if (f % 2 == 1) {
        if ((xora > xorb) or (xora == 0 and xorb == 1)) {
            std::cout << "Ajisai\n";
        } else if (xora == xorb) {
            std::cout << "Tie\n";
        } else {
            std::cout << "Mai\n";
        }
    } else {
        if ((xorb > xora) or (xorb == 0 and xora == 1)) {
            std::cout << "Mai\n";
        } else if (xora == xorb) {
            std::cout << "Tie\n";
        } else {
            std::cout << "Ajisai\n";
        }
    }
    /*太好了，这回只花998244353min就打完了！*/
/*
Test Sample

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
    for (std::cin >> _; _; _--)
        VioletEverGraden();

    return 0;
}