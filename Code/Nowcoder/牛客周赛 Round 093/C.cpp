/*
* @Author: AlgoStruggler
* @Create Time: 2025-05-18 19:06:36
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
int xa, ya;
int xb, yb;
/*-------------------------------MY_CODE_BEGIN--------------------------------*/
static inline void VioletEverGraden() {
    std::cin >> n;
    std::cin >> xa >> ya;
    std::cin >> xb >> yb;

    int a = abs(xa - xb), b = abs(ya - yb);
    if (a + b == 0) {
        std::cout << "YES";
    } else if (a == 1 and b == 1) {
        if (xa == 2 and ya == n) {
            std::cout << "NO";
            return ;
        }
        if (xb == 2 and yb == n) {
            std::cout << "NO";
            return ;
        }
        if (xa == 2 and ya == n - 1 and yb < ya) {
            std::cout << "NO";
            return ;
        }
        if (xb == 2 and yb == n - 1 and ya < yb) {
            std::cout << "NO";
            return ;
        }
        std::cout << "YES";
    } else {
        std::cout << "NO";
    }
    /*return AC*/
/*
Test Sample

6
1 1
1 1

YES

6
1 1
1 2

NO


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

    //for (std::cin >> _; _; _--)
        VioletEverGraden();

    return 0;
}