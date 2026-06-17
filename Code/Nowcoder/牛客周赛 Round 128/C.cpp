/*
* @Author: AlgoStruggler
* @Create Time: 2026-01-25 19:28:19
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

    std::vector<int> a(n + 1);
    std::vector<int> pos(n + 1);
    for (int i = 1; i <= n; i ++) {
    	std::cin >> a[i];
    	pos[a[i]] = i;
    }

    int k = (n + 1) / 2;
    if (n == 1) {
    	std::cout << a[1] << '\n';
    	return ;
    }

    std::vector<i64> pre(n + 1);
    for (int i = 1; i <= n; i ++) {
    	pre[i] = pre[i - 1] + i;
    }
    
    i64 res = LINF;
    int f = -1;
    int L = -1; int R = -1;

    for (int i = 0; i <= n - k; i ++) {
        int r = i + k - 1;
        int mid = (i + r) / 2;
        int m = mid + 1;

        int p1 = mid - i + 1; int p2 = r - mid;
        i64 sumL = pre[mid + 1] - pre[i];
        i64 sumR = pre[r + 1] - pre[mid + 1];
        i64 cost = 1LL * m * p1 - sumL + sumR - 1LL * m * p2;
        if (cost < res) {
            res = cost;
            f = m;
            L = i;
            R = r;
        }
    }

    std::vector<int> ans = a;
    for (int i = L + 1; i <= R + 1; i++) {
        int id = pos[i];        
        ans[id] = f;
    }

    for (int i = 1; i <= n; i ++) {
    	std::cout << ans[i] << " \n"[i == n];
    }

    /*太好了，这回只花998244353min就打完了!
    真好。记得多手造几组。ACM拍什么拍。 */
/*
Test Sample

4
1 3 2 4

1 3 1 4

5
1 3 2 5 4

2 2 2 5 4


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