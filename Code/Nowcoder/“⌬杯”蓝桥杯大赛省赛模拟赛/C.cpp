/*
* @Author: AlgoStruggler
* @Create Time: 2026-03-29 13:18:27
* "To the Splendor of ACM-ICPC, We Consecrate Our AC Triumphs."
*/
#pragma GCC optimize("O3,unroll-loops,Ofast,inline")
#include "bits/stdc++.h"

using i64 = int64_t;
using i128 =  __int128_t;

using u32 = uint32_t;
using u64 = uint64_t;
using u128 = __uint128_t;

using f32 = float;
using f64 = double;
using f80 = long double;

constexpr int INF = 0x3f3f3f3f;
constexpr i64 LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr i64 mod = 998'244'353LL;
constexpr i64 MOD = 1e9 + 7;

static inline void VioletEverGraden() {
    int n, m;
    std::cin >> n >> m;

    std::string a;
    std::cin >> a;

    std::string s;
    std::cin >> s;

    std::map<int, int> mp;
    for (int i = 0; i <= 9; i ++) {
        mp[i] = i;
    }
    mp[10] = 0;
    mp[-1] = 9;

    int p = 0;
    for (int i = 0; i < m; i ++) {
    	char c = s[i];
    	if (c == 'L') {
    		if (p == 0) {
    			continue;
    		} else {
    			p --;
    		}
    	} else if (c == 'R') {
    		if (p == n - 1) {
    			continue;
    		} else {
    			p ++;
    		}
    	} else if (c == 'U') {
    		int x = a[p] - '0';
            x ++;
    		x = mp[x];
    		a[p] = x + '0';
    	} else if (c == 'D') {
    		int x = a[p] - '0';
    		x --;
            x = mp[x];
    		a[p] = x + '0';
    	}
    }

    std::cout << a << '\n';
/*
愿幸运女神与最纯粹的前行者同在。 
Test Sample

3
5 6
01234
RRUULD
1 5
9
UUUUU
4 8
1090
LLDURRRU

*/
}

signed main() {
#ifdef Algostruggler
    freopen("A.in", "r", stdin);
#endif // Algostruggler

    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

    // std::cout << std::fixed << std::setprecision(12), std::cerr << std::fixed << std::setprecision(12);

    for (int _ = [&]() -> int { int T; std::cin >> T; return T; }(); _; _ --)
        VioletEverGraden();

    return 0;
}