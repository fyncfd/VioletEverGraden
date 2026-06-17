/*
* @Author: AlgoStruggler
* @Create Time: 2026-02-11 19:21:07
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
    int N, K;
    std::cin >> N >> K;

    std::vector<std::array<i64, 2>> p(N + 1);
    for (int i = 1; i <= N; i ++) {
    	std::cin >> p[i][0] >> p[i][1];
    }

    std::sort(p.begin() + 1, p.end(), [&](std::array<i64, 2> a, std::array<i64, 2> b) -> bool {
    	return a[0] - a[1] > b[0] - b[1];
    });

    i64 ans = 0;
    for (int i = 1; i <= N; i ++) {
    	if (i <= K) {
    		ans += p[i][1];
    	} else {
    		ans += p[i][0];
    	}
    }

    std::cout << ans << '\n';
    
    /* 愿幸运女神与最纯粹的前行者同在。 */
/*
Test Sample

3 2
100 80
200 150
300 250

500

5 3
1000 500
800 800
600 400
900 700
1200 300

2900

7 4
500000000 100000000
300000000 250000000
800000000 200000000
150000000 150000000
600000000 350000000
400000000 100000000
700000000 650000000

1900000000


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