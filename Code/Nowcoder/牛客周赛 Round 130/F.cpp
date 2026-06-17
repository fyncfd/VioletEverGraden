/*
* @Author: AlgoStruggler
* @Create Time: 2026-02-04 01:18:20
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

const double eps = 1e-9;
constexpr int INF = 0x3f3f3f3f;
constexpr i64 LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr i64 mod = 998244353;
constexpr i64 MOD = 1e9 + 7;
constexpr int MAXN = 0;

static inline void VioletEverGraden() {
    int n;
    std::cin >> n;

    std::vector<int> a(n + 1);
    std::vector<int> pos(n + 1);
    for (int i = 1; i <= n; i ++) {
        std::cin >> a[i];
        pos[a[i]] = i;
    }

    std::vector<int> R(n + 1, 0);
    std::vector<bool> vis(n + 1, false);
    int c0 = 0;
    for (int i = 1; i <= n; i ++) {
        if (!vis[i]) {
            c0 ++;
            int j = i;
            while (!vis[j]) {
                vis[j] = true;
                R[j] = c0;
                j = a[j];
            }
        }
    }

    bool ok = false;
    for (int k = 1; k < n; k ++) {
        if (R[pos[k]] == R[pos[k + 1]]) {
            ok = true;
            break;
        }
    }

    int ans = 0;
    if (ok) {
        ans = n - (c0 + 1);
    } else {
        ans = n - (c0 - 1);
    }

    std::cout << ans << '\n';
    
    /* 愿幸运女神与最纯粹的前行者同在。 */
/*
Test Sample

5
1 2 4 3 5

0

5
1 2 4 3 5
5 2 3 4 1

0


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
    for (std::cin >> _; _; _--)
        VioletEverGraden();

    return 0;
}