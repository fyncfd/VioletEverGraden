/*
* @Author: AlgoStruggler
* @Create Time: 2026-01-31 20:18:24
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
    int N;
    std::cin >> N;

    std::vector<int> R(N + 1);
    for (int i = 1; i <= N; i ++) {
    	std::cin >> R[i];
    }

    std::vector<int> U(N + 1);
    U[1] = R[1];
    for (int i = 2; i <= N; i ++) {
    	U[i] = std::min(R[i], U[i - 1] + 1);
    }

    std::vector<int> V(N + 1);
    V[N] = R[N];
    for (int i = N - 1; i >= 1; i --) {
        V[i] = std::min(R[i], V[i + 1] + 1);
    }

    i64 ans = 0;
    for (int i = 1; i <= N; i ++) {
    	int res = std::min(U[i], V[i]);
    	ans += R[i] - res;
    }

    std::cout << ans << '\n';
    
    /*太好了，这回只花998244353min就打完了!
    真好。记得多手造几组。ACM拍什么拍。 */
/*
Test Sample

5
5
5 2 1 3 4
2
1 1
3
1 3 1
9
9 9 8 2 4 4 3 5 3
20
7 4 6 2 15 5 17 15 1 8 18 1 5 1 12 11 2 7 8 14

4
0
1
16
105


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