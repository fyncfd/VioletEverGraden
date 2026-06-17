/*
* @Author: AlgoStruggler
* @Create Time: 2026-04-17 10:18:42
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

const std::string rep = "<censored>";
const std::string ss = "-_-";

static inline void VioletEverGraden() {
    int N;
    std::cin >> N;

    std::vector<std::string> a(N);
    for (int i = 0; i < N; i ++) {
    	std::cin >> a[i];
    }

    int k;
    std::cin >> k;

    std::cin.ignore();
    std::string s;
    getline(std::cin, s);

    int cnt = 0;
    for (int i = 0; i < N; i ++) {
    	std::string t = a[i];
    	while (s.find(t) != std::string::npos) {
    		int pos = s.find(t);
    		s.replace(pos, t.length(), ss);
    		cnt ++;
    	}
    }

    if (cnt >= k) {
    	std::cout << cnt << '\n';
    	std::cout << "He Xie Ni Quan Jia!\n";
    	return ;
    }

    while (s.find(ss) != std::string::npos) {
    	int pos = s.find(ss);
    	s.replace(pos, ss.length(), rep);
    }

    std::cout << s << '\n';
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