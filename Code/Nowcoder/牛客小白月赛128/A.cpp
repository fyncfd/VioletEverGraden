/*
* @Author: AlgoStruggler
* @Create Time: 2026-01-30 18:59:59
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

    std::string s1;
    std::cin >> s1;

    std::string s2;
    std::cin >> s2;

    for (int i = 0; i < s1.size(); i ++) {
    	if (s1[i] == '1' or s1[i] == 'I' or s1[i] == 'l') {
    		s1[i] = '?';
    	} 
    	if (s1[i] == 'O' or s1[i] == '0') {
    		s1[i] = '!';
    	}
    }

    for (int i = 0; i < s2.size(); i ++) {
    	if (s2[i] == '1' or s2[i] == 'I' or s2[i] == 'l') {
    		s2[i] = '?';
    	} 
    	if (s2[i] == '0' or s2[i] == 'O') {
    		s2[i] = '!';
    	}
    }

    // std::cout << s1 << ' ' << s2 << '\n';

    if (s1 == s2) {
    	std::cout << "YES\n";
    } else {
    	std::cout << "NO\n";
    }
    
    /*太好了，这回只花998244353min就打完了!
    真好。记得多手造几组。ACM拍什么拍。 */
/*
Test Sample

4
9
Apple0123
Apple0123
5
AKIOI
AK101
10
ilovezaoly
1loveza0Iy
6
banana
BANANA

YES
YES
NO
NO


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