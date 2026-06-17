/*
* @Author: AlgoStruggler
* @Create Time: 2026-02-09 14:44:38
* "To the Splendor of ACM-ICPC, We Consecrate Our AC Triumphs."
*/
#define  _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize("O2")
#include "bits/stdc++.h"
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using ldb = long double;
typedef __int128 i128;
typedef unsigned __int128 u128;

const double eps = 1e-9;
constexpr int INF = 0x3f3f3f3f;
constexpr i64 LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr i64 mod = 998244353;
constexpr i64 MOD = 1e9 + 7;
constexpr int MAXN = 0;

static inline void VioletEverGraden() {
    int n, m, q;
    std::cin >> n >> m >> q;
    
    std::vector<std::vector<i64>> a(n + 1, std::vector<i64> (m + 1, 0));
    std::vector<std::vector<i64>> sum(n + 1, std::vector<i64> (m + 1, 0));
    
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            std::cin >> a[i][j];
        }
    }

    auto check = [&](int x, int y) -> bool {
    	return x >= 1 and x <= n and y >= 1 and y <= m;
    };

    auto f = [&](int x, int y, i64 val) {
        for (int dx = -2; dx <= 2; dx ++) {
            for (int dy = -2; dy <= 2; dy ++) {
                if (std::abs(dx) + std::abs(dy) > 2) {
                	continue;
                }
                int nx = x + dx; int ny = y + dy;
                if (check(nx, ny)) {
                    sum[nx][ny] += val;
                }
            }
        }
    };

    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            f(i, j, a[i][j]);
        }
    }

    i64 max = -1;
    int ans1 = 1; int ans2 = 1;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            if (sum[i][j] > max) {
                max = sum[i][j];
                ans1 = i;
                ans2 = j;
            }
        }
    }

    while (q--) {
        int x, y;
        i64 z;
        std::cin >> x >> y >> z;

        a[x][y] += z;
        for (int dx = -2; dx <= 2; dx ++) {
            for (int dy = -2; dy <= 2; dy ++) {
                if (std::abs(dx) + std::abs(dy) > 2) {
                	continue;
                }
                int nx = x + dx; int ny = y + dy;
                if (check(nx, ny)) {
                    sum[nx][ny] += z;
                    if (sum[nx][ny] > max) {
                        max = sum[nx][ny];
                        ans1 = nx;
                        ans2 = ny;
                    }
                }
            }
        }

        std::cout << ans1 << ' ' << ans2 << '\n';
    }
    
    /* 愿幸运女神与最纯粹的前行者同在。 */
/*
Test Sample

3 3 2
1 1 0
1 0 0
0 0 0
2 2 2
3 3 3

1 1
2 2

6 6 5
1 1 4 5 1 4
1 9 1 9 8 1
3 5 0 2 3 4
3 1 0 1 1 0
1 9 9 7 0 1
0 9 3 7 2 4
6 4 8
3 2 8
5 1 2
2 5 6
1 2 8

5 3
4 2
4 2
4 2
2 3


*/
}

signed main() {
#ifdef Algostruggler
    freopen("A.in", "r", stdin);
#endif // Algostruggler

    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

    /*std::cout << std::fixed << std::setprecision(9);
    std::cerr << std::fixed << std::setprecision(9);*/

    int _ = 1;
    //for (std::cin >> _; _; _--)
        VioletEverGraden();

    return 0;
}