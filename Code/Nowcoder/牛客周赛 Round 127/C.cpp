/*
* @Author: AlgoStruggler
* @Create Time: 2026-01-18 19:13:35
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
    std::string s;
    std::cin >> s;

    int n = s.size();

/*    auto f = [&](char c) -> int {
    	if (c - '0' >= 5) {
    		return ((c - '0') + 1) + '0' ;
    	} else {
    		return 0;
    	}
    };

    for (int i = 1; i < s.size(); i ++) {
    	if (f(s[i]) > s[i] - '0') {
    		if (s[i] != '9') {
    			for (int j = i + 1; j < s.size(); j ++) {
    				s[i] = 0;
    			}
    			s[i] = f(s[i]) + '0';
    		} else {
    			s[i] = '0';
    			for (int j = i + 1; j < s.size(); j ++) {
    				s[i] = '0';
    			}
    			int cnt = 1;
    			for (int j = i - 1; j >= 1; j --) {
    				int p = s[j] - '0';
    				p += cnt;
    				if (p == 10) {
    					p = 0;
    					cnt = 1;
    				} else {
    					cnt = 0;
    				}
    			}
    		}
    	}
    }

    if (s[1] == '0') {
    	std::cout << '1';
    	for (int i = 1; i < s.size(); i ++) {
    		std::cout << s[i];
    	}
    } else {
    	for (int i = 1; i < s.size(); i ++) {
    		std::cout << s[i];
    	}
    }
    std::cout << '\n';*/
    int pos = -1;
    for (int i = 0; i < n; i ++) {
        if (s[i] >= '5') {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        s[n - 1] = '0';
        std::cout << s << '\n';
        return ;
    }

    for (int i = pos; i < n; i ++) {
        s[i] = '0';
    }

    int cnt = pos - 1;
    while (cnt >= 0) {
        if (s[cnt] < '9') {
            s[cnt] ++;
            std::cout << s << '\n';
            return ;
        } else {
            s[cnt] = '0';
            cnt --;
        }
    }

    std::cout << '1' << s << '\n';
    
    /*太好了，这回只花998244353min就打完了!
    真好。记得多手造几组。ACM拍什么拍。 */
/*
Test Sample

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