/*
* @Author: AlgoStruggler
* @Create Time: 2026-01-28 18:22:50
* "To the Splendor of ACM-ICPC, We Consecrate Our AC Triumphs."
*/
#define  _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize("O2")
#include "bits/stdc++.h"
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;

using i64 = long long;
using ldb = long double;
typedef unsigned long long u64;
typedef __int128 i128;
struct pii { int fi; int se; };
struct pll { i64 fi; i64 se; };
#define debug(x) std::cerr << #x << " = " << x << '\n'
#define debug2(x, y) std::cerr << #x << " = " << x << ", " << #y << " = " << y << '\n'
/*------------------------------SORT_AND_UNIQUE-------------------------------*/
const double eps = 1e-9;
constexpr int INF = 0x3f3f3f3f;
constexpr i64 LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr i64 mod = 998244353;
constexpr i64 MOD = 1e9 + 7;
constexpr int MAXN = 0;
/*-------------------------------MY_CODE_BEGIN--------------------------------*/
static inline void VioletEverGraden() {
    int n, m;
    std::cin >> n >> m;

    // std::cout << (m & (m - 1)) << '\n';

    if (m % 2 == 0 or n < (1 << std::__lg(m))) {
        std::cout << -1 << '\n';
        return ;
    }

    int cnt1 = 0;
    std::vector<int> bit;
    for (int i = 1; i <= 32; i ++) {
        if (1LL << i > n) {
            break;
        }
        if ((1LL << i) & m) {
            cnt1 ++;
            bit.push_back(i);
        }
    }


/*    for (auto x : bit) {
        std::cout << x << '\n';
    }*/

    // debug(cnt1);
    std::vector<int> p;
    std::map<int, bool> vis;
    for (auto x : bit) {
        vis[2 << (x - 1)] = true;
        // p.push_back(2 << x);
        std::cout << (2 << (x - 1)) << ' ';
    }

/*    for (auto x : p) {
        std::cout << x << ' ';
    }*/
    for (int i = 1; i <= n; i ++) {
        if (!vis[i]) {
            std::cout << i << ' ';
        }
    }
    std::cout << '\n';

    std::cout << bit.size() + 1 << '\n';

    for (int i = 0; i < bit.size(); i ++) {
        std::cout << i + 1 << ' ' << i + 1 << '\n';
    }

    std::cout << bit.size() + 1 << ' ' << n << '\n';
    
    /*太好了，这回只花998244353min就打完了!
    真好。记得多手造几组。ACM拍什么拍。 */
/*
Test Sample

6 7

2 4 1 3 5 6 
1 1
2 2
3 6

3 2

-1


*/
}
/*-----------------------------Algostruggler----------------------------------*/
signed main() {
#ifdef LOCAL
    freopen("A.in", "r", stdin);
#endif // LOCAL

    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

    /*std::cout << std::fixed << std::setprecision(9);
    std::cerr << std::fixed << std::setprecision(9);*/

    int _ = 1;
    //for (std::cin >> _; _; _--)
        VioletEverGraden();

    return 0;
}