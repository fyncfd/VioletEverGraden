/*
* @Author: AlgoStruggler
* @Create Time: 2025-05-24 22:58:12
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
std::vector<int> a;
/*-------------------------------MY_CODE_BEGIN--------------------------------*/
static inline void VioletEverGraden() {
    std::cin >> n;
    a.resize(n + 1);
    rep(i, 1, n) {
    	std::cin >> a[i];
    }
    
    std::sort(a.begin() + 1, a.end(), [&](int a, int b) {
        return a < b;
    });

/*    rep(i, 1, n) {
        std::cerr << a[i] << " \n"[i == n];
    }*/

    if ((a[n] + a[1]) % 2 == 0) {
        std::cout << 0 << '\n';
    } else {
        if (a[n] & 1) {
            int ans1 = 0; int ans2 = 0;
            int ans = 0;
            rep(i, 1, n) {
                if (a[i] & 1) {
                    ans1 = i - 1;
                    break;
                }
            }
            red(i, n, 1) {
                if (a[i] % 2 == 0) {
                    ans2 = n - i;// 2 2 3 4 5 ...5 - 3 + 1 = 3
                    break;
                }
            }

            ans = std::min(ans1, ans2);
            //std::cerr << "???1    " << ans1 << "<>" << ans2 << "==" << ans << '\n';

            std::cout << ans << '\n';
        } else {
            int ans1 = 0; int ans2 = 0;
            int ans = 0;
            rep(i, 1, n){
                if (a[i] % 2 == 0) {
                    ans1 = i - 1;
                    break;
                }
            }
            red(i, n, 1) {
                if (a[i] & 1) {
                    ans2 = n - i;
                    //std::cerr << "Flag" << i << '\n';
                    break;
                }
            }


            ans = std::min(ans1, ans2);
            //std::cerr << "???2    " << ans1 << "<>" << ans2 << "==" << ans << '\n';

            std::cout << ans << '\n';
        }
    }
    /*return AC*/
/*
Test Sample

6
2
5 2
7
3 1 4 1 5 9 2
7
2 7 4 6 9 11 5
3
1 2 1
2
2 1
8
8 6 3 6 4 1 1 6

1
0
2
1
1
3


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