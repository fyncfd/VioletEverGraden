/*
* @Author: AlgoStruggler
* @Create Time: 2026-01-18 19:03:34
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
	int n = 4;
    std::vector<std::vector<int>> a(n + 1, std::vector<int> (n + 1, 0));
    for (int i = 1; i <= n; i ++) {
    	for (int j = 1; j <= n; j ++) {
    		std::cin >> a[i][j];
    	}
    }
    
    bool ok = true;
    for (int i = 1; i <= n; i ++) {
        std::vector<bool> vis(5, false);
        for (int j = 1; j <= 4; j ++) {
            int num = a[i][j];
            if (vis[num]) {
                ok = false;
                break;
            }
            vis[num] = true;
        }
        if (!ok) {
        	break;
        }
    }

    if (ok) {
        for (int j = 1; j <= 4; j ++) {
            std::vector<bool> vis(5, false);
            for (int i = 1; i <= 4; i ++) {
                int num = a[i][j];
                if (vis[num]) {
                    ok = false;
                    break;
                }
                vis[num] = true;
            }
            if (!ok) break;
        }
    }

    if (ok) {
        std::vector<pii> p = {{1,1}, {1,3}, {3,1}, {3,3}};
        
        for (auto &f : p) {
            int x = f.fi; int y = f.se;
            std::vector<bool> vis(5, false);
            for (int i = 0; i < 2; i ++) {
                for (int j = 0; j < 2; j ++) {
                    int num = a[x + i][y + j];
                    if (vis[num]) {
                        ok = false;
                        break;
                    }
                    vis[num] = true;
                }
                if (!ok) break;
            }
            if (!ok) break;
        }
    }

    if (ok) {
        std::cout << "YES" << '\n';
    } else {
        std::cout << "NO" << '\n';
    }
    /*太好了，这回只花998244353min就打完了!
    真好。记得多手造几组。ACM拍什么拍。 */
/*
Test Sample

2
1 2 3 4
3 4 1 2
2 1 4 3
4 3 2 1
1 2 3 4
2 3 4 1
3 4 1 2
4 1 2 3

YES
NO


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
    for (std::cin >> _; _; _--)
        VioletEverGraden();

    return 0;
}