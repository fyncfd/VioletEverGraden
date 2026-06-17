#define  _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize("O2")
#include "bits/stdc++.h"

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef __int128 i128;

using namespace std;
template <typename T> 
using pq = std::priority_queue<T>;
template<class T> 
using matrix = std::vector<std::vector<T>>;
template <typename T>
using vec = std::vector<T>;

template<class T> concept Signed = std::is_signed_v<T>;
template<class T> concept Unsigned = std::is_unsigned_v<T>;
template<class T> concept Arithmetic = std::is_arithmetic_v<T>;

#define rep(i, l, r) for (int i = l; i <= r; i++)
#define red(i, l, r) for (int i = l; i >= r; i--)
#define lop(i, x) for (auto i : x)
#define all(x) a.begin(), a.end()
/*------------------------------SORT_AND_UNIQUE-------------------------------*/
//#define int long long
const double eps = 1e-9;
constexpr int inf = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;
constexpr ll mod = 998244353;
constexpr ll MOD = 1e9 + 7;
int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };
constexpr int MAXN = 1e5 + 5;
int n;
ll a[MAXN];
/*-------------------------------MY_CODE_BEGIN--------------------------------*/
static inline void VioletEverGraden() {
    std::cin >> n;
    rep(i, 1, n) {
    	std::cin >> a[i];
    }

    ll ans = 0;
    bool ok = false;
    rep(i, 2, n - 1) {
    	ll temp = 0;
    	if (a[i- 1] < a[i] and a[i] > a[i + 1]) {
    		temp = a[i] - ((a[i - 1] + a[i + 1]) >> 1);
    		ok = true;
    	}
    	ans = std::max(ans, temp);
    }

    if (ok) {
    	std::cout << ans << '\n';
    	return ;
    }

    std::cout << -1 << '\n';
    //debug();
/*

5
14 15 1 10 1

9

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

    //for (std::cin >> _; _; _--)
        VioletEverGraden();

    return 0;
}