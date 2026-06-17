#define  _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize("O2")
#include "bits/stdc++.h"
//#include <ext/pb_ds/assoc_container.hpp>

typedef long long LL;
typedef unsigned long long ULL;
typedef double DB;
typedef long double LDB;
typedef __int128 i128;
typedef std::pair<int, int> PII;
typedef std::pair<LL, LL> PLL;

//using namespace std;
//using namespace __gnu_pbds;
template <typename T> 
using PQ = std::priority_queue<T>;
template<class T> 
using MATRIX = std::vector<std::vector<T>>;
template <typename T>
using VEC = std::vector<T>;
template <class Key, class Value>
using UMP = std::unordered_map<Key, Value>;
template <typename T>
using UST = std::unordered_set<T>;
//template <typename Key, typename Value>
//using HASH = __gnu_pbds::gp_hash_table<Key, Value>;

template<class T> concept Signed = std::is_signed_v<T>;
template<class T> concept Unsigned = std::is_unsigned_v<T>;
template<class T> concept Arithmetic = std::is_arithmetic_v<T>;

#define ALL(x) x.begin(), x.end()
#define LLA(x) (x).rbegin(), (x).rend()
#define PB push_back
#define REP(i, l, r) for (int i = l; i <= r; i++)
#define RED(i, l, r) for (int i = l; i >= r; i--)
#define LOP(i, x) for (auto i : x)
/*------------------------------SORT_AND_UNIQUE-------------------------------*/
//#define int long long
const double EPS = 1e-9;
constexpr int INF = 0x3f3f3f3f;
constexpr LL LINF = 0x3f3f3f3f3f3f3f3f;
constexpr LL mod = 998244353;
constexpr LL MOD = 1e9 + 7;
int dx[] = {0, 0, 1, 0, -1 };
int dy[] = {0, -1, 0, 1, 0 };
constexpr int MAXN = 0;
std::string n;
/*-------------------------------MY_CODE_BEGIN--------------------------------*/
static inline void VioletEverGraden() {
    std::cin >> n;
    int max = 0;
    int temp = 0;
    LOP(c, n) {
        if (c == '0') {
            temp++;
        } 
        else {
            int p = temp + 1;
            if (p > max) {
                max = p;
            }
        }
    }
    if (max == 0) {
        std::cout << n.size() - 1 << '\n';
    } 
    else {
        std::cout << n.size() - max << '\n';
    }
    /*return AC*/
/*
Test Sample

4
666
13700
102030
7

2
4
3
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