/*
* @Author: AlgoStruggler
* @Create Time: 2025-04-24 22:54:17
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
#define pb push_back
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
int n, k;
/*-------------------------------MY_CODE_BEGIN--------------------------------*/
static inline void VioletEverGraden() {
    std::cin >> n >> k;
    std::vector<int> a(n + 1), b(n + 1);
    rep(i, 1, n) {
        std::cin >> a[i];
    }
    rep(i, 1, n) {
        std::cin >> b[i];
    }

    int x = -1;
    bool ok = true;
    rep(i, 1, n) {
        if (b[i] != -1) {
            int temp = a[i] + b[i];
            if (x == -1) {
                x = temp;
            } 
            else if (x != temp) {
                ok = false;
                break;
            }
        }
    }

    if (!ok) {
        std::cout << "0\n";
        return ;
    }

    if (x == -1) {
        int minx = 0, maxx = INF;
        rep(i, 1, n) {
            minx = std::max(minx, a[i]);
            maxx = std::min(maxx, a[i] + k);
        }
        if (minx <= maxx) {
            std::cout << maxx - minx + 1 << "\n";
        } 
        else {
            std::cout << "0\n";
        }
    } 
    else {
        rep(i, 1, n) {
            if (b[i] != -1) {
                if (b[i] != x - a[i]) {
                    ok = false;
                    break;
                }
            } 
            else {
                int bi = x - a[i];
                if (bi < 0 or bi > k) {
                    ok = false;
                    break;
                }
            }
        }
        if (ok) {
            std::cout << "1\n";
        } 
        else {
            std::cout << "0\n";
        }
    }
    /*return AC*/
/*
Test Sample

7
3 10
1 3 2
-1 -1 1
5 1
0 1 0 0 1
-1 0 1 0 -1
5 1
0 1 0 0 1
-1 1 -1 1 -1
5 10
1 3 2 5 4
-1 -1 -1 -1 -1
5 4
1 3 2 1 3
1 -1 -1 1 -1
5 4
1 3 2 1 3
2 -1 -1 2 0
5 5
5 0 5 4 3
5 -1 -1 -1 -1

1
0
0
7
0
1
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