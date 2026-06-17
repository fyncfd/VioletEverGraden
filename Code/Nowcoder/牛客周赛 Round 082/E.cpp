/*
* @Author: AlgoStruggler
* @Create Time: 2026-01-30 14:49:39
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
    for (int i = 1; i <= n; i ++) {
    	std::cin >> a[i];
    }

    std::vector<i64> b(n + 1);
    for (int i = 1; i <= n; i ++) {
    	std::cin >> b[i];
    }

    std::vector<i64> pre(n + 1, 0);
    std::priority_queue<i64> heap1;
    for (int i = 1; i <= n; i ++) {
    	if (i <= m) {
    		pre[i] = pre[i - 1] + a[i];
    		heap1.push(a[i]);
    	} else {
    		if (a[i] > heap1.top()) {
    			pre[i] = pre[i - 1];
    		} else {
    			pre[i] = pre[i - 1] - heap1.top() + a[i];
    			heap1.pop();
    			heap1.push(a[i]);
    		}
    	}
    }

    std::vector<i64> suf(n + 2, 0);
    std::priority_queue<i64> heap2;
    for (int i = n; i >= 1; i --) {
    	if (i >= n - m + 1) {
    		suf[i] = suf[i + 1] + b[i];
    		heap2.push(b[i]);
    	} else {
    		if (b[i] > heap2.top()) {
    			suf[i] = suf[i + 1];
    		} else {
    			suf[i] = suf[i + 1] - heap2.top() + b[i];
    			heap2.pop();
    			heap2.push(b[i]);
    		}
    	}
    }

    i64 ans = LINF;
    for (int i = m; i <= n - m; i ++) {
    	ans = std::min(ans, pre[i] + suf[i + 1]);
    }

    std::cout << ans << '\n';
    
    /*太好了，这回只花998244353min就打完了!
    真好。记得多手造几组。ACM拍什么拍。 */
/*
Test Sample

3 1
3 1 2
5 6 4

5

4 2
-2 2 1 -1
-1 1 -2 2

0

6 2
1 2 1 3 3 9
3 3 9 1 2 1

4


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