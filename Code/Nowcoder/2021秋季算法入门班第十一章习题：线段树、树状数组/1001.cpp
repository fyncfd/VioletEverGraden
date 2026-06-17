/*
* @Author: AlgoStruggler
* @Create Time: 2026-02-12 13:08:40
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
typedef __int128 i128;
typedef unsigned __int128 u128;

const double eps = 1e-9;
constexpr int INF = 0x3f3f3f3f;
constexpr i64 LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr i64 mod = 998244353;
constexpr i64 MOD = 1e9 + 7;
constexpr int MAXN = 0;

/*
* @Author: AlgoStruggler
* SparseTable 不带修解决重复贡献问题。
* 最大值、最小值、最大公因数、最小公倍数、按位或、按位与。
* @Create Time: 2026-02-01 22:24:41
* "To the Splendor of ACM-ICPC, We Consecrate Our AC Triumphs."
* 愿幸运女神与最纯粹的前行者同在。
*/
template <typename Info, typename T>
class SparseTable {
private:
    int N;
    std::vector<std::vector<Info>> ST;
    std::vector<int> log2;
public:
    SparseTable() : N(0) {}

    SparseTable(const std::vector<T> &arr) {
        N = (int)arr.size() - 1;

        log2.resize(N + 1);
        log2[1] = 0;
        for (int i = 2; i <= N; i++) {
            log2[i] = log2[i / 2] + 1;
        }
        
        int K = log2[N] + 1;
        ST.resize(K, std::vector<Info>(N + 1));

        for (int i = 1; i <= N; i ++) {
            ST[0][i] = Info(arr[i]);
        }
        for (int j = 1; j < K; j ++) {
            for (int i = 1; i + (1 << j) - 1 <= N; i ++) {
                ST[j][i] = ST[j - 1][i] + ST[j - 1][i + (1 << (j - 1))];
            }
        }
    }

    Info Query(int l, int r) {
        int j = log2[r - l + 1];
        Info res = ST[j][l] + ST[j][r - (1 << j) + 1];
        return res;
    }
};
struct Info {
    i64 max;
    i64 min;
    i64 gcd;
    Info() : max(std::numeric_limits<i64>::min()), min(std::numeric_limits<i64>::max()),  gcd(0) {}
    Info(i64 val) : max(val), min(val),  gcd(val) {}
};

Info operator + (const Info &a, const Info &b) {
    Info res;
    res.max = std::max(a.max, b.max);
    res.min = std::min(a.min, b.min);
    res.gcd = std::gcd(a.gcd, b.gcd);
    return res;
}

static inline void VioletEverGraden() {
    int N, Q;
    std::cin >> N >> Q;

    std::vector<i64> a(N + 1);
    for (int i = 1; i <= N; i ++) {
    	std::cin >> a[i];
    }

    SparseTable<Info, i64> ST(a);
    while (Q --) {
    	int L, R;
    	std::cin >> L >> R;

    	i64 ans = ST.Query(L, R).max - ST.Query(L, R).min;
    	std::cout << ans << '\n';
    }
    
    /* 愿幸运女神与最纯粹的前行者同在。 */
/*
Test Sample

6 3
1
7
3
4
2
5
1 5
4 6
2 2

6
3
0


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
    //for (std::cin >> _; _; _--)
        VioletEverGraden();

    return 0;
}