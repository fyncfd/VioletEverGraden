/*
* @Author: AlgoStruggler
* @Create Time: 2026-02-09 16:02:36
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

i128 exgcd(i128 a, i128 b, i128 &x, i128 &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    i128 g = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return g;
}

std::istream &operator >> (std::istream& is, i128& n) {
    std::string s;
    is >> s;
    n = 0;
    bool neg = false;
    int i = 0;
    if (s[0] == '-') {
        neg = true;
        i = 1;
    }
    for (; i < (int)s.size(); i++) {
        n = n * 10 + (s[i] - '0');
    }
    if (neg) n = -n;
    return is;
}

std::ostream &operator << (std::ostream &os, i128 n) {
    if (n == 0) {
        return os << 0;
    }
    std::string s;
    while (n > 0) {
        s += char('0' + n % 10);
        n /= 10;
    }
    std::reverse(s.begin(), s.end());
    return os << s;
}

static inline void VioletEverGraden() {
    i128 x, a, s;
    std::cin >> x >> a >> s;

    i128 c1 = 0; i128 c2 = 0;
    i128 g = exgcd(a, s, c1, c2);
    if (x % g != 0) {
    	std::cout << "No\n";
    	return ;
    }

    i128 mul = x / g;
    c1 *= mul; c2 *= mul;
    i128 pa = a / g; i128 ps = s / g;
    i128 min = (c1 % ps + ps) % ps;
    i128 k = (min - c1) / ps;
    c1 = min;
    c2 = c2 - k * pa;

    if (c2 < 0) {
    	std::cout << "No\n";
    	return ;
    }

    i128 M = c2 / pa;
    i128 dif = c2 - c1;
    i128 den = pa + ps;
    i128 cnt = (dif >= 0) ? (dif / den) : 0;

    std::array<i128, 2> f = {cnt, cnt + 1};
    i128 res = -1;
    i128 ans1 = -1; i128 ans2 = -1;
    for (int i = 0; i < 2; i ++) {
    	i128 tmp = f[i];
    	if (tmp < 0) {
    		tmp = 0;
    	}
    	if (tmp > M) {
    		tmp = M;
    	}

    	i128 cur1 = c1 + tmp * ps;
    	i128 cur2 = c2 - tmp * pa;
    	i128 max = std::max(cur1, cur2);

        if (res == -1 or max < res) {
            res = max;
            ans1 = cur1;
            ans2 = cur2;
        }
    }

    std::cout << "Yes\n";
    std::cout << ans1 << ' ' << ans2 << '\n';

    /* 愿幸运女神与最纯粹的前行者同在。 */
/*
Test Sample

2
2 1 1
1 2 2

Yes
1 1
No


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