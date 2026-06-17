/*
* @Author: AlgoStruggler
* @Create Time: 2026-02-05 15:15:43
* "To the Splendor of ACM-ICPC, We Consecrate Our AC Triumphs."
*/
#define  _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize("O2")
#include "bits/stdc++.h"
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
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

    std::vector<i64> a(n + 1);
    for (int i = 1; i <= n; i ++) {
    	std::cin >> a[i];
    }

    i64 ans = 0;
    std::map<int, int> pos;
    for (int i = 1; i <= n; i ++) {
    	int pre = pos[a[i]];
    	pos[a[i]] = i;

    	i64 L = i - pre;
    	i64 len = n - i + 1;
    	i64 R = len * (len + 1) / 2;
    	ans += L * R;
    }

    std::cout << ans << '\n';

    /* 愿幸运女神与最纯粹的前行者同在。 */
/*
Test Sample

2
3
1 3 1
6
1 1 4 5 1 4

14
102


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