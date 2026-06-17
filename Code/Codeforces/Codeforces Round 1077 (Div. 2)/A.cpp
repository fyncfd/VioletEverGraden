/*
* @Author: AlgoStruggler
* @Create Time: 2026-01-29 22:46:14
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
    int n;
    std::cin >> n;

    std::vector<int> p(n + 1, 0);
    if (n & 1) {
    	p[1] = (n + 1) / 2;
    	int cnt = 1;
    	for (int i = 2; i <= n - 1; i += 2) {
    		p[i] = p[1] + cnt;
    		p[i + 1] = p[1] - cnt;
    		cnt ++;
    	}
    } else {
    	p[1] = n / 2;
    	int cnt = 1;
    	for (int i = 2; i <= n - 1; i += 2) {
    		p[i] = p[1] + cnt;
    		p[i + 1] = p[1] - cnt;
    		cnt ++;
    	}
    	p[n] = p[1] + cnt;
 	}

 	for (int i = 1; i <= n; i ++) {
 		std::cout << p[i] << " \n"[i == n];
 	}
    
    /*太好了，这回只花998244353min就打完了!
    真好。记得多手造几组。ACM拍什么拍。 */
/*
Test Sample

2
2
3

1 2
2 3 1

1
5

3 4 2 5 1

1
4

2 3 1 4


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