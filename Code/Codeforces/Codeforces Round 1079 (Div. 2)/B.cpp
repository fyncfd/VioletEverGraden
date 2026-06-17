/*
* @Author: AlgoStruggler
* @Create Time: 2026-02-11 22:51:53
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
    int n;
    std::cin >> n;

    std::vector<int> p(n + 1);
    std::vector<int> pos(n + 1);
    for (int i = 1; i <= n; i ++) {
        std::cin >> p[i];
        pos[p[i]] = i;
    }

    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++) {
        std::cin >> a[i];
    }

    int id = 0;
    for (int i = 1; i <= n; i ++) {
        if (i == 1 || a[i] != a[i - 1]) {
            int val = a[i];
            int cur = pos[val];
            if (cur < id) {
                std::cout << "NO" << '\n';
                return;
            }
            id = cur;
        }
    }

    std::cout << "YES" << '\n';
    
    /* 愿幸运女神与最纯粹的前行者同在。 */
/*
Test Sample

6
3
1 2 3
1 2 2
4
3 1 2 4
3 4 2 2
5
1 3 2 5 4
3 3 3 5 4
7
3 7 4 2 1 6 5
3 3 4 4 5 6 5
7
1 2 3 4 5 6 7
7 7 7 7 7 7 7
7
1 3 2 7 5 4 6
2 2 7 7 7 5 6

YES
NO
YES
NO
YES
YES


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