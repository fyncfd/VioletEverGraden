/*
* @Author: AlgoStruggler
* @Create Time: 2026-02-11 19:34:44
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
    i64 N, K, M;
    std::cin >> N >> K >> M;

    std::vector<i64> A(N + 1);
    std::vector<i64> pre(N + 1, 0);
    for (int i = 1; i <= N; i ++) {
    	std::cin >> A[i];
    	pre[i] = pre[i - 1] + A[i];
    }

    i64 ans = 0;
    for (int L = 1; L <= N; L ++) {
    	int R = L + K - 1;
    	if (R > N) {
    		break;
    	}

    	i64 V = pre[L - 1] + M;
    	int pos = std::lower_bound(pre.begin() + R, pre.end(), V) - pre.begin();
    	if (pos <= N) {
    		ans += (N - pos + 1);
    	}
    }

    std::cout << ans <<'\n';
    
    /* 愿幸运女神与最纯粹的前行者同在。 */
/*
Test Sample

5 2 10
3 5 4 2 6

6

8 3 15
2 4 6 3 5 7 1 8

17

10 4 1000000000000
500000000 600000000 400000000 300000000 700000000 200000000 800000000 100000000 900000000 550000000

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
    //for (std::cin >> _; _; _--)
        VioletEverGraden();

    return 0;
}