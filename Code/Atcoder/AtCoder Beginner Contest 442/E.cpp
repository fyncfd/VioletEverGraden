/*
* @Author: AlgoStruggler
* @Create Time: 2026-01-24 20:40:39
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
bool operator<(const pll& a, const pll& b) {
    return a.fi == b.fi ? a.se < b.se : a.fi < b.fi;
}
static inline void VioletEverGraden() {
    int N, Q;
    std::cin >> N >> Q;

    std::vector<int> X(N + 1), Y(N + 1);
    for (int i = 1; i <= N; i ++) {
    	std::cin >> X[i] >> Y[i];
    }

    auto gcd = [](i64 a, i64 b) -> i64 {
        a = std::abs(a); b = std::abs(b);
        if (a == 0) return b;
        if (b == 0) return a;
        while (b != 0) {
            a %= b;
            std::swap(a, b);
        }
        return a;
    };

    auto f = [&](i64 x, i64 y) -> pll {
        if (x == 0 && y == 0) {
        	return {0, 0};
        }
        i64 g = gcd(x, y);
        x /= g; y /= g;
        return {x, y};
    };

    std::map<pll, std::vector<int>> g;
    std::vector<pll> dir(N + 1);
    for (int i = 1; i <= N; i ++) {
        pll d = f(X[i], Y[i]);
        dir[i] = d;
        g[d].push_back(i);
    }

    struct info {
        ldb ang; i64 cnt; pll vec;
    };
    std::vector<info> list;
    const ldb PI = acosl(-1.0L);
    for (auto &kv : g) {
        pll vec = kv.first;
        i64 cnt = (i64)kv.second.size();
        ldb ang = atan2l((ldb)vec.se, (ldb)vec.fi);
        if (ang < 0) ang += 2 * PI;
        list.push_back({ang, cnt, vec});
    }

    std::sort(list.begin(), list.end(), [&](info &a, info &b) -> bool {
        return a.ang < b.ang;
    });

    int M = (int)list.size();
    std::map<pll, int> id;
    for (int i = 0; i < M; i ++) {
        id[list[i].vec] = i;
    }

    std::vector<i64> pre(M);
    if (M > 0) {
        pre[0] = list[0].cnt;
        for (int i = 1; i < M; i ++) {
            pre[i] = pre[i - 1] + list[i].cnt;
        }
    }
    i64 sum = (M > 0 ? pre.back() : 0);

    auto getsum = [&](int idx) -> i64 {
        if (idx < 0) {
        	return 0;
        }
        return pre[idx];
    };

    while (Q--) {
        int A, B;
        std::cin >> A >> B;

        pll dA = dir[A]; pll dB = dir[B];

        int idA = id[dA]; int idB = id[dB];

        if (idA == idB) {
            std::cout << list[idA].cnt << '\n';
        } else if (idA <= idB) {
            i64 part1 = getsum(idA);
            i64 part2 = sum - getsum(idB - 1);
            std::cout << part1 + part2 << '\n';
        } else {
            i64 ans = getsum(idA) - getsum(idB - 1);
            std::cout << ans << '\n';
        }
    }
    
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
    //for (std::cin >> _; _; _--)
        VioletEverGraden();

    return 0;
}