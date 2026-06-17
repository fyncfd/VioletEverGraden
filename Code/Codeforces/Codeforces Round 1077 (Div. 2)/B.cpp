/*
* @Author: AlgoStruggler
* @Create Time: 2026-01-29 23:01:45
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

    std::string s;
    std::cin >> s;

    int cnt1 = 0;
    for (auto c : s) {
    	if (c == '1') {
    		cnt1 ++;
    	}
    }

    if (cnt1 == 0) {
    	std::cout << (n + 2) / 3 << '\n';
    	return ;
    }

    int fi = -1; int se = -1;
    for (int i = 0; i < s.size(); i ++) {
    	if (s[i] == '1') {
    		if (fi == -1) {
    			fi = i;
    		}
    		se = i;
    	}
    }

    i64 ans = 0;
    if (fi > 0) {
    	int L = fi;
    	int res = std::max(0, L - 1);
    	ans += (res + 2) / 3;
    }

    if (se < n - 1) {
    	int R = n - 1 - se;
    	int res = std::max(0, R - 1);
    	ans += (res + 2) / 3;
    }

    int i = fi + 1;
    while (i < se) {
        if (s[i] == '0') {
            int j = i;
            while (j <= se and s[j] == '0') {
            	j ++;
            }
            int L = j - i;
            int res = std::max(0, L - 2);
            ans += (res + 2) / 3;
            i = j;
        } else {
            i ++;
        }
    }

    ans += cnt1;

    std::cout << ans << '\n';
    
    /*太好了，这回只花998244353min就打完了!
    真好。记得多手造几组。ACM拍什么拍。 */
/*
Test Sample

5
1
0
3
000
5
00000
6
100101
13
0000100001000

1
1
2
3
5


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