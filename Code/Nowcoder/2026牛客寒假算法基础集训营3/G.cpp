/*
* @Author: AlgoStruggler
* @Create Time: 2026-02-07 14:09:37
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
    int n, m;
    std::cin >> n >> m;

    std::vector<i64> a(n + 1);
    for (int i = 1; i <= n; i ++) {
    	std::cin >> a[i];
    }

    std::vector<i64> b(m + 1);
    for (int i = 1; i <= m; i ++) {
    	std::cin >> b[i];
    }

    i64 sum1 = std::accumulate(a.begin() + 1, a.end(), 0LL);
    i64 sum2 = std::accumulate(b.begin() + 1, b.end(), 0LL);

    // std::cerr << sum1 << ' ' << sum2 << '\n';

    std::sort(a.begin() + 1, a.end(), [&](i64 a, i64 b) -> bool {
    	return a < b;
    });
    std::sort(b.begin() + 1, b.end(), [&](i64 a, i64 b) -> bool {
    	return a < b;
    });

    if (sum1 == sum2) {
    	std::cout << 1 << '\n';
    	return ;
    }

    i64 cnt1 = 0; i64 cnt2 = 0;
    if (sum1 > sum2) {
    	i64 dif = sum1 - sum2;
    	i64 sum = 0;
    	for(int i = n; i >= 1; i --) {
    		sum += a[i];
    		cnt1 ++;
    		if (sum >= dif) {
    			break;
    		}
    	}
    	std::cout << cnt1 << '\n';
    } else if (sum2 > sum1) {
    	i64 dif = sum2 - sum1;
    	i64 sum = 0;
    	for(int i = m; i >= 1; i --) {
    		sum += b[i];
    		cnt2 ++;
    		if (sum >= dif) {
    			break;
    		}
    	}
    	std::cout << cnt2 << '\n';
    }
    
    /* 愿幸运女神与最纯粹的前行者同在。 */
/*
Test Sample

2
1 1
10
10
1 4
1
1 1 1 1

1
3


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