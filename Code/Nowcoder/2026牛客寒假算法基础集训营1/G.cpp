/*
* @Author: AlgoStruggler
* @Create Time: 2026-02-03 14:51:33
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
    i64 l, r;
    std::cin >> l >> r;

    auto rev = [&](i64 x) -> i64 {
        std::string s = std::to_string(x);
        reverse(s.begin(), s.end());
        return stoll(s);
    };

/*    i64 ans = 0LL;
    i64 st = std::max(l, r - 2000LL);
    for (i64 x = r; x >= st; x --) {
        ans = std::max(ans, rev(x));
    }

    for (auto num : p) {
        if (num >= l and num <= r) {
            ans = std::max(ans, num);
        }
    }*/

/*    i64 ans = 0;
    i64 p = 1;
    for (int i = 0; i <= 50; i ++) {
        if (p > r) {
            break;
        }
        i64 a = (l + p - 1) / p;
        i64 b = r / p;
        if (a > b) {
            p *= 10;
            continue;
        }
 
        i64 y = b;
        if (y % 10 == 0) {
            y = b - 1;
        }
        if (y < a) {
            p *= 10;
            continue;
        }
 
        i64 ry = rev(y);
        if (ry > ans) {
            ans = ry;
        }
        p *= 10;
    }*/

/*    if (r - l <= 100000) {
        i64 ans = 0;
        for (i64 i = l; i <= r; i ++) {
            ans = std::max(ans, rev(i));
        }
        std::cout << ans << "\n";
        return ;
    }

    i64 ans = 0;
    ans = std::max(ans, rev(r));
    for (i64 i = r; i >= std::max(l, r - 100); i --) {
        ans = std::max(ans, rev(i));
    }

    for (int len = 1; len <= 16; len ++) {
        i64 num = 0;
        for (int i = 0; i < len; i++) {
            num = num * 10 + 9;
        }

        i64 cnt = 0;
        i64 tmp = num;
        while (tmp > 0) {
            cnt = cnt * 10 + (tmp % 10);
            tmp /= 10;
        }
        
        for (int k = 0; k <= 15; k ++) {
            i64 x = cnt;
            for (int i = 0; i < k; i ++) {
                x *= 10;
            }
            if (x >= l and x <= r) {
                ans = std::max(ans, num);
                break;
            }
        }
    }

    for (int len = 2; len <= 16; len ++) {
        i64 num = 1;
        for (int i = 1; i < len; i ++) {
            num = num * 10 + 9;
        }

        i64 cnt = 0;
        i64 tmp = num;
        while (tmp > 0) {
            cnt = cnt * 10 + (tmp % 10);
            tmp /= 10;
        }
        
        for (int k = 0; k <= 15; k ++) {
            i64 x = cnt;
            for (int i = 0; i < k; i ++) {
                x *= 10;
            }
            if (x >= l and x <= r) {
                ans = std::max(ans, num);
                break;
            }
        }
    }
    
    std::cout << ans << '\n';*/

    i64 ans = rev(r);
    ans = std::max(ans, rev(l));
    std::string s = std::to_string(r);
    int n = s.size();
    for (int i = 0; i < n; i ++) {
        if (s[i] > '0') {
            std::string tmp = s;
            tmp[i] --; 
            for (int j = i + 1; j < n; j ++) {
                tmp[j] = '9';
            }
            i64 val = std::stoll(tmp);
            
            if (val >= l) {
                ans = std::max(ans, rev(val));
            }
        }
    }
    
    std::cout << ans << '\n';
    
    /* 愿幸运女神与最纯粹的前行者同在。 */
/*
Test Sample

3
1 20
1000 10000
1 999

91
9999
999

1
1 100001

100001

1
245 331

992

1
7580534 7745620

9999967


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

    // init();

    int _ = 1;
    for (std::cin >> _; _; _--)
        VioletEverGraden();

    return 0;
}