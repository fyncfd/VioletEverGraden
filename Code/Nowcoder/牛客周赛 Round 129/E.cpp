/*
* @Author: AlgoStruggler
* @Create Time: 2026-02-01 19:25:59
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
constexpr int MAXN = 2e5 + 10;
/*-----------------------------------MY_CODE_BEGIN------------------------------------*/
i64 fac[MAXN], inv[MAXN];

i64 ksm(i64 a, i64 b, i64 p) {
    i64 res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

void precompute(int n) {
    fac[0] = 1;
    for (int i = 1; i <= n; i ++) {
        fac[i] = fac[i - 1] * i % MOD;
    }

    inv[n] = ksm(fac[n], MOD - 2, MOD);

    for (int i = n - 1; i >= 0; i --) {
        inv[i] = inv[i + 1] * (i + 1) % MOD;
    }
}

static inline void VioletEverGraden() {
    int n;
    std::cin >> n;

    auto C = [&](int n, int k) -> i64 {
	    if (k < 0 or k > n) {
	    	return 0;
	    }
	    return fac[n] * inv[k] % MOD * inv[n - k] % MOD;
    };

    i64 f = ksm(2, n - 1, MOD);
    for (int k = 1; k <= n; k ++) {
        i64 ans = f * C(n, k) % MOD;
        std::cout << ans << " \n"[k == n];
    }
    
    /* 愿幸运女神与最纯粹的前行者同在。 */
/*
Test Sample

3

12 12 4


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

    precompute(MAXN);

    int _ = 1;
    //for (std::cin >> _; _; _--)
        VioletEverGraden();

    return 0;
}