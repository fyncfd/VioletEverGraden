/*
* @Author: AlgoStruggler
* @Create Time: 2026-04-15 23:01:30
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
    int n;
    std::cin >> n;

    std::vector<int> s1;
    for (int i = 1; i <= n; i ++) {
    	int x;
    	std::cin >> x;
    	s1.push_back(x);
    }

    std::vector<char> s2;
    for (int i = 1; i < n; i ++) {
    	char c;
    	std::cin >> c;
    	s2.push_back(c);
    }

    while (!s2.empty()) {
    	int n2 = s1.back();
    	s1.pop_back();
    	int n1 = s1.back();
    	s1.pop_back();
    	char op = s2.back();
    	s2.pop_back();

    	if (op == '+') {
    		s1.push_back(n1 + n2);
    	} else if (op == '-') {
    		s1.push_back(n1 - n2);
    	} else if (op == '*') {
    		s1.push_back(n1 * n2);
    	} else {
    		if (n2 == 0) {
    			std::cout << "ERROR: " << n1 << '/' << 0 << '\n';
    			return ;
    		} else {
    			s1.push_back(n1 / n2);
    		}
    	}
    }

    std::cout << s1.back() << '\n';
/*
愿幸运女神与最纯粹的前行者同在。 
Test Sample

*/
}

signed main() {
#ifdef Algostruggler
    freopen("A.in", "r", stdin);
#endif // Algostruggler

    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

    // std::cout << std::fixed << std::setprecision(12), std::cerr << std::fixed << std::setprecision(12);

    // for (int _ = [&]() -> int { int T; std::cin >> T; return T; }(); _; _ --)
        VioletEverGraden();

    return 0;
}