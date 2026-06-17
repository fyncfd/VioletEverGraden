#define  _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize("O2")
#include "bits/stdc++.h"

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;

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
/*------------------------------SORT_AND_UNIQUE-------------------------------*/
#define int long long
const double eps = 1e-9;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
const ll MOD = 1e9 + 7;
int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };

constexpr int MAXN = 0;
int a, b, c;
/*-------------------------------MY_CODE_BEGIN--------------------------------*/
static inline void VioletEverGraden() {
    std::cin >> a >> b >> c;

    ll ans = 0;
    if (b % 3 != 0) {
    	int cnt = (b / 3 + 1) * 3;

    	if (cnt - b > c) {
    		std::cout << -1 << '\n';
    		return ;
    	}

    	ans += a;
    	ans += cnt / 3;
    	int k = c - (cnt - b);
    	ans += k / 3 + (k % 3 != 0);
    	std::cout << ans << '\n';
    	
    	return ;
    }

    if (b % 3 == 0) {
    	ans += a;
    	ans += b / 3;

    	ans += c / 3 + (c % 3 != 0);
    	std::cout << ans << '\n';
    	return ;
    }
    //debug();
/*
10
1 2 3
1 4 1
1 4 2
1 1 1
1 3 2
19 7 18
0 0 0
7 0 0
0 24 0
1000000000 1000000000 1000000000

3
-1
3
-1
3
28
0
7
8
1666666667
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

    std::cin.tie(nullptr) ->std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);

    int _ = 1;

    for (std::cin >> _; _; _--)
        VioletEverGraden(); //TimeTest();
        
    /*fio::fio<int> intIO;
    _ = intIO.read();
    rep(i, 1, _) {
        VioletEverGraden();
        //TimeTest();
    }*/

    return 0;
}