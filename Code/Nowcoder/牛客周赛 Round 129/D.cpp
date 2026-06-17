/*
* @Author: AlgoStruggler
* @Create Time: 2026-02-01 19:16:21
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
/*----------------------------------SORT_AND_UNIQUE-----------------------------------*/
const double eps = 1e-9;
constexpr int INF = 0x3f3f3f3f;
constexpr i64 LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr i64 mod = 998244353;
constexpr i64 MOD = 1e9 + 7;
constexpr int MAXN = 0;
/*-----------------------------------MY_CODE_BEGIN------------------------------------*/
static inline void VioletEverGraden() {
    std::string s;
    std::cin >> s;

    int n = s.size();
    if (n == 0) {
        std::cout << 0 << '\n';
        return ;
    }

    i64 ans = 1;
    if (n <= 2) {
        std::cout << ans << '\n';
        return ;
    }

    std::vector<int> vis(n - 1);
    for (int i = 0; i < n - 1; i ++) {
        vis[i] = (s[i] == s[i + 1]) ? 1 : 0;
    }

    std::vector<i64> suf0(n, 0), suf1(n, 0);
    for (int i = n - 2; i >= 0; i --) {
        suf0[i] = suf0[i + 1] + (vis[i] == 0);
        suf1[i] = suf1[i + 1] + (vis[i] == 1);
    }

    for (int i = 1; i <= n - 2; i ++) {
        if (vis[i - 1] == 0) {
            ans += suf1[i];
        } else {
            ans += suf0[i];
        }
    }

    std::cout << ans << '\n';
    
    /* 愿幸运女神与最纯粹的前行者同在。 */
/*
Test Sample

011

2

0011000

9


*/
}
/*---------------------------------Algostruggler--------------------------------------*/
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