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
constexpr int MAXN = 0;
ll n, m, k, q;
/*-------------------------------MY_CODE_BEGIN--------------------------------*/
static inline void VioletEverGraden() {
    std::cin >> n >> m >> k >> q;

    bool ok1 = ((n - q) % k == 0);
    bool ok2 = (q <= m * (k - 1));

    int x = 1;
    std::cout << (ok1 and ok2 ? "Yes" : "No") << " \n"[x == 1];
    //debug();
/*
Test Sample

2
100 1 2 1
100 1 3 1

No
Yes

3
21 4 5 16
16 4 5 16
21 4 5 21

Yes
Yes
No


2
100 1 2 1
100 1 3 1

No
Yes

3
21 4 5 16
16 4 5 16
21 4 5 21

Yes
Yes
No


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

    for (std::cin >> _; _; _--)
        VioletEverGraden();

    return 0;
}