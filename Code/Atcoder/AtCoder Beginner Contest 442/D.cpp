/*
* @Author: AlgoStruggler
* @Create Time: 2026-01-24 20:21:31
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
template<typename T>
class Fenwick {
private:
    int n;
    std::vector<T> bit;
    inline int lowbit(int x) {
        return x & -x;
    }
public:
    Fenwick(int size = 0) : n(size), bit(size, 0) {}

    void Update(int pos, T val) {
        while (pos <= n) {
            bit[pos] += val;
            pos += lowbit(pos);
        }
    }

    T getSum(int pos) {
        T res = 0;
        while (pos > 0) {
            res += bit[pos];
            pos -= lowbit(pos);
        }
        return res;
    }

    T rangeSum(int l, int r) {
        return getSum(r) - getSum(l - 1);
    }

    T getval(int pos) {
        return rangeSum(pos, pos);
    }
};
static inline void VioletEverGraden() {
    int N, Q;
    std::cin >> N >> Q;

    Fenwick<i64> tree(N + 1);
    std::vector<int> A(N + 1);
    for (int i = 1; i <= N; i ++) {
    	std::cin >> A[i];
    	tree.Update(i, A[i]);
    }

    int __ = Q;
    while (__ --) {
    	int op;
    	std::cin >> op;

    	if (op == 1) {
    		int x;
    		std::cin >> x;
    		int num1 = tree.getval(x); int num2 = tree.getval(x + 1);
    		tree.Update(x, num2 - num1); tree.Update(x + 1, num1 - num2);
    	} else {
    		int l, r;
    		std::cin >> l >> r;
    		i64 ans = tree.rangeSum(l, r);
    		std::cout << ans << '\n';
    	}
    }
    
    /*太好了，这回只花998244353min就打完了!
    真好。记得多手造几组。ACM拍什么拍。 */
/*
Test Sample

4 4
2 7 1 8
1 2
2 1 2
1 1
2 2 4

3
17

8 10
22 75 26 45 72 81 47 29
2 2 7
2 6 8
2 4 4
1 2
2 1 3
1 1
2 2 4
1 2
1 4
2 1 1

346
157
45
123
142
26


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