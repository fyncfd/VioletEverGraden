/*
* @Author: AlgoStruggler
* @Create Time: 2026-01-30 19:52:09
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
constexpr int MAXN = 2e5 + 10;
/*-------------------------------MY_CODE_BEGIN--------------------------------*/
int fac[MAXN]; int inv[MAXN];

int ksm(int a, int e) {
    int res = 1;
    while (e) {
        if (e & 1) res = 1LL * res * a % MOD;
        a = 1LL * a * a % MOD;
        e >>= 1;
    }
    return res;
}

void precompute() {
    fac[0] = 1;
    for (int i = 1; i < MAXN; i ++) {
        fac[i] = 1LL * fac[i - 1] * i % MOD;
    }
    inv[MAXN - 1] = ksm(fac[MAXN-1], MOD-2);
    for (int i = MAXN - 2; i >= 0; i --) {
        inv[i] = 1LL * inv[i + 1] * (i + 1) % MOD;
    }
}
static inline void VioletEverGraden() {
    int n; i64 m;
    std::cin >> n >> m;

    std::vector<int> a(n + 1);
    std::map<int, int> cnt;
    for (int i = 1; i <= n; i ++) {
    	std::cin >> a[i];
    	cnt[a[i]] ++;
    }

    int num = 0; i64 f = 1;
    for (int i = 1; i <= n; i ++) {
        if (cnt[i] == 0) {
        	continue;
        }
        if (cnt[i] % i != 0) {
        	std::cout << 0 << '\n';
        	return ;
        }
        int g = cnt[i] / i;
        num += g;
        i64 res = fac[cnt[i]];
        res = res * ksm(ksm(fac[i], g), MOD - 2) % MOD;
        res = res * inv[g] % MOD;
        f = f * res % MOD;
    }
    
    if (num > m) {
    	std::cout << 0 << '\n';
    	return ;
    }
    
    i64 tmp = 1;
    for (int i = 0; i < num; i ++) {
        tmp = tmp * ((m - i) % MOD) % MOD;
    }
    
    i64 ans = f * tmp % MOD;
    std::cout << ans << '\n';
    
    /*太好了，这回只花998244353min就打完了!
    真好。记得多手造几组。ACM拍什么拍。 */
/*
Test Sample

3
5 10
2 2 3 3 3
2 3
2 1
9 20014
1 1 7 7 7 7 7 7 7

90
0
610066079


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

    precompute();

    int _ = 1;
    for (std::cin >> _; _; _--)
        VioletEverGraden();

    return 0;
}