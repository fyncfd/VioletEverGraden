/*
* @Author: AlgoStruggler
* @Create Time: 2026-02-03 23:46:23
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

const double eps = 1e-9;
constexpr int INF = 0x3f3f3f3f;
constexpr i64 LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr i64 mod = 998244353;
constexpr i64 MOD = 1e9 + 7;
constexpr int MAXN = 0;

static inline void VioletEverGraden() {
    int n;
    std::cin >> n;

    std::vector<std::vector<char>> g(n + 1, std::vector<char> (n + 1));
    for (int i = 1; i  <= n; i ++) {
    	for (int j = 1; j <= n; j ++) {
    		std::cin >> g[i][j];
    	}
    }

    const int dx[] = {0, 0, 1, -1}; const int dy[] = {1, -1, 0, 0};
    std::vector<std::vector<int>> cnt(n + 1, std::vector<int> (n + 1, 0));
    for (int i = 1; i <= n; i ++) {
    	for (int j = 1; j <= n; j ++) {
    		for (int k = 0; k < 4; k ++) {
    			int nx = i + dx[k]; int ny = j + dy[k];
    			if (nx >= 1 and nx <= n and ny >= 1 and ny <= n) {
    				if (g[nx][ny] == '*') {
    					cnt[i][j] ++;
    					if (cnt[i][j] == 3) {
    						std::cout << "T\n";
    						return ;
    					}
    				}
    			}
    		}
    	}
    }

    std::cout << "L\n";
    
    /* 愿幸运女神与最纯粹的前行者同在。 */
/*
Test Sample

3
5
.....
.....
.***.
..*..
.....
5
.....
..*..
..*..
.**..
.....
6
......
..*...
.**...
..*...
......
......
T
L
T


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