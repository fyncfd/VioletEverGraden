/*
* @Author: AlgoStruggler
* @Create Time: 2026-02-07 14:22:02
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
constexpr int MAXN = 32000;

/**   欧拉筛
 *    2023-11-14: https://qoj.ac/submission/251234
**/

std::vector<int> minp, primes;

void sieve(int n) {
    minp.assign(n + 1, 0);
    primes.clear();
    
    for (int i = 2; i <= n; i ++) {
        if (minp[i] == 0) {
            minp[i] = i;
            primes.push_back(i);
        }
        
        for (auto p : primes) {
            if (i * p > n) {
                break;
            }
            minp[i * p] = p;
            if (p == minp[i]) {
                break;
            }
        }
    }
}

std::vector<int> init(int x) {
    std::vector<int> fac;
    for (int p : primes) {
        if (p * p > x) {
        	break;
        }
        if (x % p == 0) {
            fac.push_back(p);
            while (x % p == 0) x /= p;
        }
    }
    if (x > 1) {
    	fac.push_back(x);
    }
    return fac;
}

static inline void VioletEverGraden() {
    int n;
    std::cin >> n;

    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++) {
        std::cin >> a[i];
    }

    std::map<int, int> id;
    int ans1 = -1, ans2 = -1;
    for (int i = 1; i <= n; i ++) {
        int x = a[i];
        std::vector<int> f = init(x);
        for (int p : f) {
            if (id.count(p)) {
                ans1 = id[p];
                ans2 = i;
                break;
            } else {
                id[p] = i;
            }
        }
        if (ans1 != -1) {
        	break;
        }
    }

    if (ans1 == -1) {
        std::cout << "-1\n";
    } else {
        std::cout << a[ans1] << ' ' << a[ans2] << '\n';
    }
    
    /* 愿幸运女神与最纯粹的前行者同在。 */
/*
Test Sample

*/
}

signed main() {
#ifdef Algostruggler
    freopen("A.in", "r", stdin);
#endif // Algostruggler

    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

    /*std::cout << std::fixed << std::setprecision(9);
    std::cerr << std::fixed << std::setprecision(9);*/

    sieve(MAXN);

    int _ = 1;
    for (std::cin >> _; _; _--)
        VioletEverGraden();

    return 0;
}