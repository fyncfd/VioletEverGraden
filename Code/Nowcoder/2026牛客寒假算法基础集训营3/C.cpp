/*
* @Author: AlgoStruggler
* @Create Time: 2026-02-07 15:17:03
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
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

//     bool ok =true;
//     for (int i = 1; i < n; i ++) {
//     	if (s[i] == s[i - 1]) {
//     		ok = false;
//     		break;
//     	}
//     }
//     if (ok) {
//     	std::cout << "0\n";	
//     	return ;
//     }

//     auto f = [&](int st) -> int {
// /*	    char cur = st;
// 	    int pre = -1;
// 	    bool ok = true;
// 	    for (int i = 0; i < n; i ++) {
// 	        if (s[i] != cur) {
// 	            if (pre == i - 1 and s[i] == s[i-1]) {
// 	                return false;
// 	            }
// 	            if (!ok && pre != -1 && pre == s[i]) { 
// 	              	return false; 
// 	            }
// 	            pre = s[i];
// 	            ok = false;
// 	        }
// 	        if (cur == '0') {
// 	        	cur = '1';
// 	        } else {
// 	        	cur = '0';
// 	        }
// 	    }
// 	    return true;*/

// 		std::string t = "";
// 	    for (int i = 0; i < n; ++i) {
// 	        int p = (st + i) % 2;
// 	        int cur = s[i] - '0';
// 	        if (cur != p) {
// 	            t += s[i];
// 	        }
// 	    }
	    
// 	    if (t.empty()) {
// 	    	return 0;
// 	    }

// 	    int max = 0;
// 	    int len = 0;
// 	    for (int i = 0; i < t.size(); i ++) {
// 	        if (i == 0) {
// 	            len = 1;
// 	        } else {
// 	            if (t[i] == t[i-1]) {
// 	                len ++;
// 	            } else {
// 	                len = 1;
// 	            }
// 	        }
// 	        max = std::max(max, len);
// 	    }
// 	    return max;
//     };

//     // if (f('0') or f('1')) {
//     //     std::cout << "1\n";
//     // } else {
//     //     std::cout << "2\n";
//     // }

//     int ans1 = f(0); int ans2 = f(1);
//     int ans = std::min(ans1, ans2);

//     std::cerr << ans1 << ' ' << ans2 << '\n';

//     std::cout << ans << '\n';

	int max = 0;
    int len = 0;
    char pre = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == pre) {
            len ++;
        } else {
            max = std::max(max, len);
            len = 1;
            pre = s[i];
        }
    }

    max = std::max(max, len);
    if (max <= 1) {
        std::cout << 0 << '\n';
    } else {
        std::cout << (int)log2(max) << '\n';
    }
/*

    int ans = std::max(cnt0, cnt1);

    std::cout << (ans + 1) / 2 << "\n";*/
    
    /* 愿幸运女神与最纯粹的前行者同在。 */
/*
Test Sample

2
5
11101
5
11100

1
1

1
5
01101

1


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