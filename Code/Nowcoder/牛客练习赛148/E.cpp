/*
* @Author: AlgoStruggler
* @Create Time: 2026-01-23 20:04:05
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
    int n, m;
    std::cin >> n >> m;

    std::vector<i64> a(n + 1);
    std::vector<i64> b;
    for (int i = 1; i <= n; i ++) {
    	std::cin >> a[i];
    	b.push_back(a[i]);
    }

    std::sort(b.begin(), b.end(), [&](i64 a, i64 b) -> bool {
    	return a < b;
    });
    b.erase(unique(b.begin(), b.end()), b.end());

    for (int i = 1; i <= n; i ++) {
    	a[i] = std::lower_bound(b.begin(), b.end(), a[i]) - b.begin();
    }

/*    for (int i = 1; i <= n; i ++) {
    	debug(a[i]);
    }*/

    int cnt = b.size();
    std::vector<i64> suf(n + 1, 0);
    std::vector<std::vector<i64>> ans(n + 1, std::vector<i64> (n + 1, 0));
    for (int L = 1; L <= n; L ++) {
    	std::vector<int> f(n + 1, 0);
    	i64 sum = 0; i64 mid = 0; i64 num = 0;

    	for (int R = L; R <= n; R ++) {
    		int cur = a[R];
    		suf[R] = cur;

    		for (int i = L; i <= R; i ++) {
    			if (suf[i] > cur) {
    				suf[i] = cur;
    			}

    			int val = suf[i];
    			f[val] ++;
    			sum ++;
    			// std::cerr << f[i] << '\n';

    			if (val <= mid) {
    				num ++;
    			}
    		}

    		i64 res = (sum + 1) / 2;
    		// debug(res);
    		// std::cerr << sum << '\n';
    		while (num < res) {
    			mid ++;
    			num += f[mid];
    		}

    		while (mid > 0 and (num - f[mid] >= res)) {
    			num -= f[mid];
    			mid --;
    		}

    		ans[L][R] = b[mid];

/*    		for (auto x : f) {
    			debug(x);
    		}*/
    	}
    }

    int __ = m;
    while (__ --) {
    	int L, R;
    	std::cin >> L >> R;
    	std::cout << ans[L][R] << '\n';
    }
    
    /*太好了，这回只花998244353min就打完了!
    真好。记得多手造几组。ACM拍什么拍。 */
/*
Test Sample

3 2
1 2 3
1 3
2 3

1
2


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