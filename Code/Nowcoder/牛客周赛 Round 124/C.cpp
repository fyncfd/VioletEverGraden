/*
* @Author: AlgoStruggler
* @Create Time: 2026-02-06 02:26:56
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
    int n; i64 m;
    std::cin >> n >> m;

    // std::cout << n << ' ' << m << '\n';


    std::vector<i64> a(n + 1, -1);
    std::map<i64, int> mp;
    for (int i = 1; i <= n; i ++) {
    	std::cin >> a[i];
    	mp[a[i]] ++;
    }

    if (m > n + 1) {
    	std::cout << "NO\n";
    	return ;
    }

    std::sort(a.begin() + 1, a.end(), [&](int a, int b) -> bool {
    	return a < b;
    });

   	for (int i = m - 1; i <= n; i ++) {
        if (a[i] - a[i - (m - 1) + 1] == m - 2 or a[i] - a[i - m + 2] == m - 1) {
        	std::cout << "YES\n";
        	return ;
        }
    }

    std::cout << "NO\n";
    
    /* 愿幸运女神与最纯粹的前行者同在。 */
/*
Test Sample

3
3 3
1 2 5
3 10
1 2 3
3 2
5 1 3

YES
NO
YES


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