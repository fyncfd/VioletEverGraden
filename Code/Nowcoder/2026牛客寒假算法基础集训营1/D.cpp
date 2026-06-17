/*
* @Author: AlgoStruggler
* @Create Time: 2026-02-03 17:26:31
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
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n + 1);
    std::vector<int> ck(n + 1);
    for (int i = 1; i <= n; i ++) {
    	std::cin >> a[i];
    	ck[i] = (a[i] > 0);
    }

    std::vector<int> p(n + 1);
    int cur = 0;
    for (int i = 1; i <= n; i ++) {
    	if (ck[i]) {
    		cur = std::max(cur, std::min(n, i + a[i]));
    	}
    	p[i] = cur;
    }

    std::vector<std::vector<int>> up(20, std::vector<int> (n + 1));
    for (int i = 1; i <= n; i ++) {
    	up[0][i] = p[i];
    }

/*    std::cout << "up[0]: ";
    for (int i = 1; i <= n; i ++) {
    	std::cerr << up[0][i] << "?\n"[i == n];
    }*/

    for (int j = 1; j < 20; j ++) {
    	for (int i = 1; i <= n; i ++) {
    		int mid = up[j - 1][i];
    		if (mid == 0) {
    			up[j][i] = 0;
    		} else {
    			up[j][i] =  up[j - 1][mid];
    		}
    	}
    }

    // std::cerr << "up[1][1]: " << up[1][1] << "????\n";

    auto check = [&](int mid) -> bool {
        int cnt = 0; int cur = 1;
        while (cur <= n) {
            while (cur <= n and !ck[cur]) {
            	cur ++;
            }
            if (cur > n) {
            	break;
            }
            cnt ++;
            if (cnt > k) {
            	return false;
            }

            int pos = cur;
            for (int j = 0; j < 20; j ++) {
                if ((mid >> j) & 1) {
                    pos = up[j][pos];
                    if (pos == n) {
                    	break; 
                    }
                }
            }

            cur = pos + 1;
        }
        return cnt <= k;
    };

    i64 lo = 0, hi = n;
    i64 ans = -1;
    while (lo <= hi) {
    	// i64 mid = lo + hi + 1 >> 1;
        i64 mid = lo + (hi - lo) / 2;
        // std::cerr << "mid " << mid << '\n';
        if (check(mid)) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    std::cout << ans << '\n';
    
    /* 愿幸运女神与最纯粹的前行者同在。 */
/*
Test Sample

3
6 2
2 0 1 1 0 1
5 1
1 1 1 1 1
5 1
1 0 1 0 1

2
4
-1


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
    for (std::cin >> _; _; _--)
        VioletEverGraden();

    return 0;
}