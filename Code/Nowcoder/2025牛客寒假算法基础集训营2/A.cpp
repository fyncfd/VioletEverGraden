/*
* @Author: AlgoStruggler
* @Create Time: 2026-02-01 14:24:46
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
    std::vector<int> a(8);
    for (int i = 1; i <= 7; i ++) {
    	std::cin >> a[i];
    }

    for (int i = 1; i <= 7; i ++) {
    	if (a[i] > 6 or a[i] == 4) {
    		std::cout << "NO\n";
    		return ;
    	}
    }

    std::cout << "YES\n";
    
    /* 愿幸运女神与最纯粹的前行者同在。 */
/*
Test Sample

1 2 3 5 5 5 3

YES

4 5 3 6 2 5 1

NO


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