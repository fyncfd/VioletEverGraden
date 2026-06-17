/*
* @Author: AlgoStruggler
* @Create Time: 2026-01-22 23:34:53
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
    i64 a, b;
    std::cin >> a >> b;

    std::vector<int> bita;
    for (int i = 0; i <= 32; i ++) {
    	if (1LL << i > a) {
    		break;
    	}
    	if (1LL << i & a) {
    		bita.push_back(1);
    	} else {
    		bita.push_back(0);
    	}
    }

    std::vector<int> bitb;
        for (int i = 0; i <= 32; i ++) {
    	if (1LL << i > b) {
    		break;
    	}
    	if (1LL << i & b) {
    		bitb.push_back(1);
    	} else {
    		bitb.push_back(0);
    	}
    }

    if (bitb.size() > bita.size()) {
    	std::cout << -1 << '\n';
    	return ;
    }

    std::vector<i64> ans;
    int len = std::max(bita.size(), bitb.size());
    for (int i = 0; i < len; i++) {
        int abit = (i < bita.size()) ? bita[i] : 0;
        int bbit = (i < bitb.size()) ? bitb[i] : 0;
        if (abit != bbit) {
            ans.push_back(1LL << i);
        }
    }

    std::cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i ++) {
        std::cout << ans[i] << " \n"[i == ans.size() - 1];
    }
    
    /*太好了，这回只花998244353min就打完了!
    真好。记得多手造几组。ACM拍什么拍。 */
/*
Test Sample

6
9 6
13 13
292 929
405 400
998 244
244 353

4
1 2 4 8
0
-1
2
1 4
4
2 16 256 512
-1


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