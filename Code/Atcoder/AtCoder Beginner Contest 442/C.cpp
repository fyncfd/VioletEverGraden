/*
* @Author: AlgoStruggler
* @Create Time: 2026-01-24 20:11:22
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
    int N, M;
    std::cin >> N >> M;

/*    std::vector<int> fa(N + 1); std::vector<int> num(N + 1, 1);
    for (int i = 1; i <= N; i ++) {
    	fa[i] = i;
    }

    auto find = [&](auto &&find, int x) -> int {
    	if (fa[x] == x) {
    		return x;
    	} else {
    		return find(find, fa[x]);
    	}
    };

    auto merge = [&](int x, int y) -> void {
    	int rx = find(find, x); int ry = find(find, y);
    	if (rx != ry) {
    		fa[rx] = ry;
    		num[ry] += num[rx];
    	}
    };*/

    std::vector<int> num(N + 1, 0);

    int __ = M;
    while (__ --) {
    	int A, B;
    	std::cin >> A >> B;
    	// merge(A, B);
    	num[A] ++; num[B] ++;
    }

    auto C = [&](i64 x) -> i64 {
    	return (x * (x - 1) * (x - 2)) / 6;
    };

    for (int i = 1; i <= N; i ++) {
    	// int ri = find(find, i);
    	i64 p = N - num[i] - 1;
    	i64 ans = C(p);
    	std::cout << ans << " \n"[i == N];
    }
    
    /*太好了，这回只花998244353min就打完了!
    真好。记得多手造几组。ACM拍什么拍。 */
/*
Test Sample

6 5
1 2
1 4
2 3
5 3
3 1

0 1 0 4 4 10

7 3
1 2
3 4
5 6

10 10 10 10 10 10 20

6 9
3 6
2 5
2 3
4 3
1 5
6 2
3 1
5 3
2 4

1 0 0 1 0 1


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