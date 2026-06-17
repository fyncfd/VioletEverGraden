#define  _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize("O2")
#include "bits/stdc++.h"
//#include <ext/pb_ds/assoc_container.hpp>

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef __int128 i128;

using namespace std;
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

#define all(x) a.begin(), a.end()
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define red(i, l, r) for (int i = l; i >= r; i--)
#define lop(i, x) for (auto i : x)
/*------------------------------SORT_AND_UNIQUE-------------------------------*/
//#define int long long
const double eps = 1e-9;
constexpr int inf = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;
constexpr ll mod = 998244353;
constexpr ll MOD = 1e9 + 7;
int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };
constexpr int MAXN = 0;
int n;
/*-------------------------------MY_CODE_BEGIN--------------------------------*/
namespace gal {
	template<typename T>
	class gal {
		public:
			T gcd(T a, T b) {//欧几里得辗转相除法求最大公约数
				if (!b) {
					return a;
				}
				return gcd(b, a % b);
			}
			T lcm(T a, T b) {//最小公倍数，其中先除后乘是尽可能避免溢出，尽量保持这个习惯
				return a / gcd(a, b) * b;
			}
	};
}

static inline void VioletEverGraden() {
	gal::gal<int> i63;

    std::cin >> n;
    vec<int> a(n);
    rep(i, 0, n - 1) {
        cin >> a[i];
    }
    
    if (n < 2) {
        cout << -1 << endl;
        return ;
    }
    
    vec<int> dp(n + 1, -1);
    dp[0] = 0;
    
    rep(i, 1, n) {
        rep(j, 1, i - 1) {
            if (dp[j-1] != -1) {
                bool ok = true;
                if (i - j + 1 < 2) {
                    ok = false;
                } 
                else {
                    rep(x, j, i) {
                        bool can = false;
                        rep(y, j, i) {
                            if (x == y) {
                            	continue;
                            }
                            if (i63.gcd(a[x-1], a[y-1]) != 1) {
                                can = true;
                                break;
                            }
                        }
                        if (!can) {
                            ok = false;
                            break;
                        }
                    }
                }
                if (ok and dp[i] < dp[j-1] + 1) {
                    dp[i] = dp[j-1] + 1;
                }
            }
        }
    }
    
    std::cout << dp[n] << '\n';
    /*return AC*/
/*
Test Sample

7
2 2 3 3 4 8 4

3

7
5 5 3 3 5 8 4

2

1
4

-1

5
1 2 3 4 5

-1


*/
}
/*-------------------------------Author_Fd------------------------------------*/
void TestArea();
void TimeTest();
static inline void VioletEverGraden();

signed main() {
#ifdef LOCAL
    freopen("A.in", "r", stdin);
#endif // LOCAL

    /*cout << fixed << setprecision();
    cerr << fixed << setprecision();*/

    std::cin.tie(nullptr) -> 
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);

    int _ = 1;

    //'for (std::cin >> _; _; _--)
        VioletEverGraden();

    return 0;
}