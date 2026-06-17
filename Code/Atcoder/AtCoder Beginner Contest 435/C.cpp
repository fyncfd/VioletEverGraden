/*
* @Author: AlgoStruggler
* @Create Time: 2026-02-06 22:45:27
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
typedef unsigned long long u64;
typedef __int128 i128;
typedef unsigned __int128 u128;

const double eps = 1e-9;
constexpr int INF = 0x3f3f3f3f;
constexpr i64 LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr i64 mod = 998244353;
constexpr i64 MOD = 1e9 + 7;
constexpr int MAXN = 0;

static inline void VioletEverGraden() {
    int N;
    std::cin >> N;

    std::vector<int> A(N + 1);
    for (int i = 1; i <= N; i ++) {
    	std::cin >> A[i];
    }

    int ans = 0;
    int cnt = 1;
    for (int i = 1; i <= cnt and i <= N; i ++) {
        int cur = i + A[i] - 1;
        if (cur > cnt) {
            cnt = cur;
        }
        ans = cnt;
    }

    ans = std::min(ans, N);

    std::cout << ans << '\n';
    
    /* 愿幸运女神与最纯粹的前行者同在。 */
/*
Test Sample

4
3 1 4 1

4

9
1 4 1 4 2 1 3 5 6

1

10
5 4 3 2 1 1 2 3 4 5

5


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