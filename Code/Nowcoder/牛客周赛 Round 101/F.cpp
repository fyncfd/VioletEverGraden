/*
* @Author: AlgoStruggler
* @Create Time: 2026-01-28 23:16:48
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
i64 ksm(i64 x,i64 y,int z) {
    i64 ans = 1 % z;
    x %= z;
    x = (x + z) % z;
    for ( ; y > 0; y >>= 1) {
        if (y & 1) {
            ans = (ans *x ) % z;
        }
        x = (x * x) % z;
    }
    return ans;
}
static inline void VioletEverGraden() {
    i64 base; std::vector<i64> c(10000000); i64 p;
    std::cin >> base >> c[0] >> p; //c[0] %= p;

    std::map<i64, i64> mp; //mp[c[0]] = 0;
    std::vector<i64> pre(10000000, 0); //pre[0] = c[0] % p;
    i64 len = 0; i64 pos = 0; i64 id = 1;
    while (true) {
    	c[id] = ksm(base, c[id - 1], p);
    	pre[id] = (pre[id - 1] + c[id]) % p;
    	if (mp.count(c[id])) {
    		pos = mp[c[id]];
    		len = id - mp[c[id]];
    		break;
    	} 
    	mp[c[id]] = id;
        id ++;
    }

    i64 q;
    std::cin >> q;

    i64 __ = q;
    while (__ --) {
    	i64 k;
    	std::cin >> k;

    	if (k < pos) {
    		i64 ans = pre[k];
    		std::cout << ans << '\n';
    	} else {
    		i64 ans = ((pre[(k - pos) % len + pos] + ((k - pos) / len) % p * (pre[id] - pre[pos] + p) % p) % p) % p;
    		std::cout << ans % p << '\n';
    	}
    }
    
    /*太好了，这回只花998244353min就打完了!
    真好。记得多手造几组。ACM拍什么拍。 */
/*
Test Sample

13 3 79231
3
1
2
3

2197
9593
66390

1919 810 114514
5
76
114514
1919810
1000000000
1000000000000000000

3624
80720
63830
32422
97088


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
    //for (std::cin >> _; _; _--)
        VioletEverGraden();

    return 0;
}