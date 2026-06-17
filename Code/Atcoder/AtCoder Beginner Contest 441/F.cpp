/*
* @Author: AlgoStruggler
* @Create Time: 2026-01-19 15:57:16
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
    int N, M;
    std::cin >> N >> M;

    std::vector<int> P(N + 1); std::vector<i64> V(N + 1);
    for (int i = 1; i <= N; i ++) {
    	std::cin >> P[i] >> V[i];
    }

    std::vector<std::vector<i64>> dp1(N + 10, std::vector<i64> (M + 10, 0));
    for (int i = 1; i <= N; i ++) {
    	for (int j = 0; j <= M; j ++) {
    		if (P[i] <= j) {
    			dp1[i][j] = std::max(dp1[i - 1][j], dp1[i - 1][j - P[i]] + V[i]);
    		} else {
    			dp1[i][j] = dp1[i - 1][j];
    		}
    	}
    }

    std::vector<std::vector<i64>> dp2(N + 20, std::vector<i64> (M + 20, 0));
    for (int i = N; i >= 1; i --) {
    	for (int j = 0; j <= M; j ++) {
    		if (j >= P[i]) {
    			dp2[i][j] = std::max(dp2[i + 1][j], dp2[i + 1][j - P[i]] + V[i]);
    		} else {
    			dp2[i][j] = dp2[i + 1][j];
    		}
    	}
    }

    i64 max = dp1[N][M];
    std::string ans;
    for (int i = 1; i <= N; i ++) {
    	i64 max1 = 0; i64 max2 = 0;
    	i64 tmp = M - P[i];

    	for (int j = 0; j <= tmp; j ++) {
    		i64 val = dp1[i - 1][j] + dp2[i + 1][tmp - j];
    		max1 = std::max(max1, val + V[i]);
    	}

    	for (int j = 0; j <= M; j ++) {
    		i64 val = dp1[i - 1][j] + dp2[i + 1][M - j];
    		max2 = std::max(max2, val);
    	}

    	if (max1 < max) {
    		ans += 'C';
    	} else if (max2 == max) {
    		ans += 'B';
    	} else {
    		ans += 'A';
    	}
    }

    std::cout << ans << '\n';
    
    /*太好了，这回只花998244353min就打完了!
    真好。记得多手造几组。ACM拍什么拍。 */
/*
Test Sample

5 7
2 5
2 5
3 5
3 10
3 20

BBCBA

7 3
1 1
1 1
1 2
1 2
1 2
1 3
1 3

CCBBBAA


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