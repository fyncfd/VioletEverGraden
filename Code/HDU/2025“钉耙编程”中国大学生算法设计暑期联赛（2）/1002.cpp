/*
* @Author: AlgoStruggler
* @Create Time: 2025-07-21 12:03:32
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



#define all(x) x.begin() + 1, x.end()
#define LLA(x) (x).rbegin(), (x).rend()
#define rep(i, l, r, x) for (decltype(l) i = (l); i <= (r); i += (x))
#define dep(i, l, r, x) for (decltype(l) i = (l); i >= (r); i -= (x))
#define lop(i, x) for (auto &i : x)
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
ll n, x, y;
/*-------------------------------MY_CODE_BEGIN--------------------------------*/
int count(ll num) {
    int count = 0;
    while (num > 0) {
        count += num & 1;
        num >>= 1;
    }
    return count;
}

ll lowbit(ll num) {
    return num & (-num);
}

static inline void VioletEverGraden() {
	std::cin >> n >> x >> y;

    if (x == y) {
    	std::cout << 0 << '\n';
    	return ;
    }

    int cntx = count(x); int xnty = count(y);
    ll nx = lowbit(x); ll ny = lowbit(y);
    if (cntx == xnty or nx == ny) {
    	std::cout << 1 << '\n';
    	return ;
    }

    int tempy = count(ny);
    if (tempy <= cntx) {
        ll z = ny;
        int res = cntx - tempy;
        if (res == 0) {
            if (z <= n) {
            	std::cout << 2 << '\n';
            	return ;
            }
        } else {
            ll m = ~(ny - 1); 
            ll up = n & m;
            if (up > ny) {
                std::cout << 2 <<'\n';
                return ;
            }
        }
    }

    int tempx = count(nx);
    if (tempx <= xnty) {
        ll z = nx; int res = xnty - tempx;
        if (res == 0) {
            if (z <= n) 
            	std::cout << 2 << '\n';
            return ;
        } else {
            ll m = ~(nx - 1); ll up = n & m;
            if (up > nx) {
                std::cout << 2 << '\n';
                return ;
            }
        }
    }
    
    std::cout << 3 << '\n';
    /*return AC*/
/*
Test Sample

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

    /*cout << std::fixed << std::setprecision(9);
    cerr << std::fixed << std::setprecision(9);*/


    __INIT__();

    int _ = 1;

    for (std::cin >> _; _; _--)
        VioletEverGraden();

    return 0;
}