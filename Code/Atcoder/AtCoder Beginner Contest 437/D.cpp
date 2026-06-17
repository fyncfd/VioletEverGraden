/*
* @Author: AlgoStruggler
* @Create Time: 2026-01-20 16:24:32
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

    std::vector<i64> A(N + 1);
    for (int i = 1; i <= N; i ++) {
    	std::cin >> A[i];
    }

    std::vector<i64> B(M + 1);
    for (int i = 1; i <= M; i ++) {
    	std::cin >> B[i];
    }

    std::sort(A.begin() + 1, A.end(), [&](i64 a, i64 b) -> bool {
    	return a < b;
    });
    std::sort(B.begin() + 1, B.end(), [&](i64 a, i64 b) -> bool {
    	return a < b;
    });

    // std::vector<i64> preA(N + 1, 0);
    std::vector<i64> preB(M + 1, 0);
    for (int i = 1; i <= M; i ++) {
    	preB[i] = (preB[i - 1] + B[i]) % mod;
    }

    std::vector<i64> sufB(M + 2, 0);
    for (int i = M; i >= 1; i --) {
    	sufB[i] = (sufB[i + 1] + B[i]) % mod;
    }

    i64 ans = 0;
    for (int i = 1; i <= N; i ++) {
    	int j = std::lower_bound(B.begin() + 1, B.end(), A[i]) - B.begin();
    	if (j - 1 >= 1) {
    		ans += ((j - 1) * A[i] % mod - preB[j - 1] % mod) % mod;
    	}
    	if (j <= M) {
    		ans += (sufB[j] - (M - j + 1) * A[i] % mod) % mod;
    	}
    	ans %= mod;
    }

    ans = (ans + mod) % mod;

    std::cout << ans << '\n';
    
    /*太好了，这回只花998244353min就打完了!
    真好。记得多手造几组。ACM拍什么拍。 */
/*
Test Sample

4 2
1 6 9 2
3 1

26

8 8
185991676 311812083 311812083 84357963 185991676 185991676 724020528 369175631
455049197 387671868 4361724 724020528 724020528 455049197 455049197 724020528

529117255


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