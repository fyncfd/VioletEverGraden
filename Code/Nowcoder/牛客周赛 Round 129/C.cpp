/*
* @Author: AlgoStruggler
* @Create Time: 2026-02-01 19:05:43
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
constexpr int MAXN = 0;
/*-----------------------------------MY_CODE_BEGIN------------------------------------*/
static inline void VioletEverGraden() {
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<std::vector<i64>> a(n + 1, std::vector<i64> (m + 1));
    std::map<i64, i64> mp;
    for (int i = 1; i <= n; i ++) {
    	for (int j = 1; j <= m; j ++) {
    		std::cin >> a[i][j];
    		if (a[i][j] != 0) {
    			mp[a[i][j]] ++;
    		}
    	}
    } 

    i64 ans = 0; i64 cnt = 0;
    for (auto &[x, y] : mp) {
    	if (y >= 2) {
    		mp[x + 1] += y / 2;
    		cnt += y / 2;
    		if (x + 1 >= k) {
    			ans += y / 2;
    		}
    		mp[x] = y % 2;
    	}
    }

    std::cout << cnt << ' ' << ans << '\n';
    
    /* 愿幸运女神与最纯粹的前行者同在。 */
/*
Test Sample

2 3 3
1 0 0
1 1 1

3 1

3 3 1
3 0 0
0 0 4
0 2 2

3 3


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

    int _ = 1;
    //for (std::cin >> _; _; _--)
        VioletEverGraden();

    return 0;
}