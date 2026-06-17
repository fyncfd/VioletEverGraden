/*
* @Author: AlgoStruggler
* @Create Time: 2026-02-07 20:04:16
* "To the Splendor of ACM-ICPC, We Consecrate Our AC Triumphs."
*/#define  _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize("O2")
#include "bits/stdc++.h"
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using ldb = long double;
typedef unsigned long long u64;
typedef __int128 i128;
typedef unsigned __int128 u128;

const double eps = 1e-9;
constexpr int INF = 0x3f3f3f3f;
constexpr i64 LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr i64 mod = 998244353;
constexpr i64 MOD = 1e9 + 7;
constexpr int MAXN = 0;

static inline void VioletEverGraden() {
    int N;
    std::cin >> N;

    std::vector<i64> A(N + 1);
    // std::set<int> st;
    for (int i = 1; i <= N; i ++) {
    	std::cin >> A[i];
    	// st.insert(A[i]);
    }

    i64 sum = std::accumulate(A.begin() + 1, A.end(), 0LL);
    i64 max = *std::max_element(A.begin() + 1, A.end());

    std::map<i64, int> cnt;
    for (int i = 1; i <= N; i ++) {
        cnt[A[i]] ++;
    }

    std::set<i64> st;
    // i64 sqrtS = std::sqrt(sum);
    for (i64 i = 1; i * i <= sum; i ++) {
        if (sum % i == 0) {
            if (i >= max) {
            	st.insert(i);
            }
            if (sum / i >= max) {
            	st.insert(sum / i);
            }
        }
    }

    std::vector<i64> ans;
    for (i64 L : st) {
        bool ok = true;
        for (const auto& p : cnt) {
            i64 a = p.first;
            int c = p.second;
            if (a > L) {
                ok = false;
                break;
            }
            if (a < L) {
                i64 b = L - a;
                auto it = cnt.find(b);
                int cntB = (it != cnt.end()) ? it->second : 0;
                if (cntB != c) {
                    ok = false;
                    break;
                }
            }
        }
        if (ok) {
            ans.push_back(L);
        }
    }

    for (int i = 0; i < ans.size(); i ++) {
        std::cout << ans[i] << " \n"[i == ans.size() - 1];
    }

    /* 愿幸运女神与最纯粹的前行者同在。 */
/*
Test Sample

4
10 5 5 10

10 15

3
4 4 4

4

6
10 187 344 100 434 257

444


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