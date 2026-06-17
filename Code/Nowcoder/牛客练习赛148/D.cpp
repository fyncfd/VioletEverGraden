/*
* @Author: AlgoStruggler
* @Create Time: 2026-01-23 19:30:34
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
constexpr int MAXN = 1001;
/*-------------------------------MY_CODE_BEGIN--------------------------------*/
static inline void VioletEverGraden() {
    int n;
    std::cin >> n;

    std::vector<i64> a(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    std::vector<i64> b(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> b[i];
    }

    std::vector<int> p1, p2;
    for (int i = 1; i <= n; i++) {
        if (b[i] != 0 && a[i] % b[i] == 0) {
            p1.push_back(b[i]);
            p2.push_back(a[i] / b[i]);
        }
    }
    int m = p1.size();

    std::vector<bool> vis(MAXN, false);
    for (int i = 0; i < m; i++) {
        if (p1[i] < MAXN) {
            vis[p1[i]] = true;
        }
    }
    
    std::vector<int> B;
    for (int i = 1; i < MAXN; i++) {
        if (vis[i]) {
            B.push_back(i);
        }
    }
    
    std::vector cnt(MAXN, std::vector<int>(MAXN, 0));
    for (int d : B) {
        for (int i = 0; i < m; i++) {
            if (p2[i] % d == 0) {
                if (p1[i] < MAXN) {
                    cnt[d][p1[i]]++;
                }
            }
        }
    }

    i64 ans = 0;
    for (int x : B) {
        i64 f = cnt[x][x];
        ans += f * (f - 1) / 2;
    }
    for (int x : B) {
        for (int y : B) {
            if (x < y) {
                ans += (i64)cnt[y][x] * cnt[x][y];
            }
        }
    }

    std::cout << ans << '\n';
    
    /*太好了，这回只花998244353min就打完了!
    真好。记得多手造几组。ACM拍什么拍。 */
/*
Test Sample

3
2 3 4
1 2 2

1

4
4 6 4 1
2 2 2 2

1


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