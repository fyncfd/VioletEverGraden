/*
* @Author: AlgoStruggler
* @Create Time: 2026-01-17 21:12:07
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
    int N;
    std::cin >> N;

    std::string S;
    std::cin >> S; S = " " + S;

    std::vector<int> a(N + 1);
    for (int i = 1; i <= N; i ++) {
        if (S[i] == 'A') {
            a[i] = 1;
        } else if (S[i] == 'B') {
            a[i] = -1;
        } else {
            a[i] = 0;
        }
    }

    std::vector<int> pre(N + 1, 0);
    for (int i = 1; i <= N; i ++) {
        pre[i] = pre[i - 1] + a[i];
    }

    i64 ans = 0;
    Fenwick<int> tree(2 * N + 100);
    tree.Update(N + 10, 1);
    for (int i = 1; i <= N; i ++) {
        int tmp = pre[i] + N + 10;
        ans += tree.getSum(tmp - 1);
        tree.Update(tmp, 1);
    }

    std::cout << ans << '\n';
    
    /*太好了，这回只花998244353min就打完了!
    真好。记得多手造几组。ACM拍什么拍。 */
/*
Test Sample

10
ACBBCABCAB

8

4
CCBC

0

36
CABACBBBBBAABABACCBCABCCABAABABBCBAC

136


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