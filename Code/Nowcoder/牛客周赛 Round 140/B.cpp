/*
* @Author: AlgoStruggler
* @Create Time: 2026-04-19 19:32:00
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

    std::string s;
    std::cin >> s;

    std::vector<char> st;
    for (char c : s) {
        st.push_back(c);
        if (st.size() >= 2 && st[st.size() - 2] == 'm' && st.back() == 'o') {
            st.pop_back();
            st.pop_back();
        }
        else if (st.size() >= 3 && st[st.size() - 3] == 'n' && st[st.size() - 2] == 'i' && st.back() == 'u') {
            st.pop_back();
            st.pop_back();
            st.pop_back();
        }
    }

    std::cout << (st.empty() ? "Yes" : "No") << '\n';
/*
愿幸运女神与最纯粹的前行者同在。 
Test Sample

5
niumo

Yes

5
omuin

No


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