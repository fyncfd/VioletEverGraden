/*
* @Author: AlgoStruggler
* @Create Time: 2026-01-30 20:14:38
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
    int n, m, k;
    std::cin >> n >> m >> k;

    if (n == 1 and m == 1) {
        if (k == 0) {
            std::cout << "0\n";
        } else {
            std::cout << "-1\n";
        }
        return ;
    }

    if (n == 1) {
        int f1 = m - k;
        int f2 = (m + 2) / 3;
        if (f1 < f2 or f1 > m) {
            std::cout << "-1\n";
            return ;
        }
        std::vector<int> g(m + 1, 0);
        int p = 0;
        for (int j = 2; j <= m; j += 3) {
            if (p < f1) {
                g[j] = 1;
                p ++;
            }
        }
        for (int j = m; j >= 1 and p < f1; j --) {
            if (g[j] == 0) {
                g[j] = 1;
                p ++;
            }
        }
        for (int j = 1; j <= m; j ++) {
            std::cout << g[j];
        }
        std::cout << '\n';
        return ;
    }

    if (m == 1) {
        int f1 = n - k;
        int f2 = (n + 2) / 3;
        if (f1 < f2 or f1 > n) {
            std::cout << "-1\n";
            return ;
        }
        std::vector<int> g(n + 1, 0);
        int p = 0;
        for (int i = 2; i <= n; i += 3) {
            if (p < f1) {
                g[i] = 1;
                p ++;
            }
        }
        for (int i = n; i >= 1 and p < f1; i --) {
            if (g[i] == 0) {
                g[i] = 1;
                p ++;
            }
        }
        for (int i = 1; i <= n; i ++) {
            std::cout << g[i] << '\n';
        }
        return ;
    }

    int cnt = (n / 2) * (m / 2);
    int max = n * m - cnt;
    if (k > max) {
        std::cout << "-1\n";
        return ;
    }

    if (k <= m) {
        std::string r(m, '0');
        for (int j = 0; j < k; j ++) {
            r[j] = '1';
        }
        std::cout << r << '\n';
        std::cout << std::string(m, '0') << '\n';
        for (int i = 3; i <= n; i ++) {
            std::cout << std::string(m, '0') << '\n';
        }
        return ;
    }

    int x = k / m;
    int res = k % m;
    std::vector<std::string> ans;

    for (int i = 1; i <= x; i ++) {
        ans.push_back(std::string(m, '1'));
        ans.push_back(std::string(m, '0'));
    }

    if (res > 0) {
        std::string r(m, '0');
        for (int j = 0; j < res; j ++) {
            r[j] = '1';
        }
        ans.push_back(r);
        ans.push_back(std::string(m, '0'));
    }

    while ((int)ans.size() < n) {
        ans.push_back(std::string(m, '0'));
    }

    for (int i = 0; i < n; i ++) {
        std::cout << ans[i] << '\n';
    }
    
    /*太好了，这回只花998244353min就打完了!
    真好。记得多手造几组。ACM拍什么拍。 */
/*
Test Sample

4
1 1 0
2 3 3
2 3 6
4 4 10

0
111
000
-1
1111
0000
1111
0000


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