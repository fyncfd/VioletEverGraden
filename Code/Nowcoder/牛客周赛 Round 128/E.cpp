/*
* @Author: AlgoStruggler
* @Create Time: 2026-01-25 19:48:00
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

    int cnt1 = 0;
    for (char c : s) {
    	if (c == '1') {
    		cnt1 ++;
    	}
    }

    int f1 = cnt1 / 2; int f2 = cnt1 % 2;
    std::vector<int> p(n, 0);
    int pos = 0;
    for (int i = 0; i < n; i ++) {
    	if (s[i] != '1') {
    		p[i] = 0;
    		continue;
    	}

    	if (f2 > 0) {
    		int f = std::max(i + 1, pos);
    		char nxt = 0;

    		while (f < n) {
    			if (s[f] != '1') {
    				nxt = s[f];
    				break;
    			}
    			f ++;
    		}
    		pos = f;

	    	if (nxt == '0' and f1 > 0) {
	    		p[i] = 1;
	    		f1 --;
	    	} else {
	    		p[i] = 2;
	    		f2 --;
    		} 
    	} else {
    		if (f1 > 0) {
    			p[i] = 1;
    			f1 --;
    		} else {
    			p[i] = 3;
    		}
    	}
    }

    for (int i = 0; i < n; i ++) {
    	if (s[i] != '1') {
    		std::cout << s[i];
    	} else {
    		if (p[i] == 2) {
    			std::cout << '1';
    		} else if (p[i] == 3) {
    			std::cout << '2';
    		}
    	}
    }
    std::cout << '\n';
    
    /*太好了，这回只花998244353min就打完了!
    真好。记得多手造几组。ACM拍什么拍。 */
/*
Test Sample

12101

1202

12112

1222


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