/*
* @Author: AlgoStruggler
* @Create Time: 2026-02-07 21:08:49
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

static inline void VioletEverGraden() {
    i64 N, D;
    std::cin >> N >> D;

    std::vector<i64> A(N + 1);
    for (int i = 1; i <= N; i ++) {
    	std::cin >> A[i];
    }

    std::multiset<int> st;
    i64 ans = 0;
    int R = 1;
    for (int L = 1; L <= N; L ++) {
        while (R <= N) {
            if (st.empty()) {
                st.insert(A[R]);
                R ++;
                continue;
            }
            auto it = st.lower_bound(A[R]);
            bool ok = true;

            if (it != st.end()) {
                if (*it - A[R] < D) {
                	ok = false;
                }
            }
            if (it != st.begin()) {
                auto p = prev(it);
                if (A[R] - *p < D) {
                	ok = false;
                }
            }
            if (!ok) break;
            st.insert(A[R]);
            R ++;
        }
        ans += (R - L);
        st.erase(st.find(A[L]));
    }

    std::cout << ans << '\n';
    
    /* 愿幸运女神与最纯粹的前行者同在。 */
/*
Test Sample

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