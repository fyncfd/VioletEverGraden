/*
* @Author: AlgoStruggler
* @Create Time: 2026-02-15 19:31:58
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

    std::vector<i64> a(n + 1);
    for (int i = 1; i <= n; i ++) {
    	std::cin >> a[i];
    }

	struct Segment {
	    int L, R;
	    std::vector<i64> odd;
	    std::vector<i64> even;
	};

    std::vector<int> sid(n + 1, 0), pos(n + 1, 0);
    std::vector<Segment> f;

    int id = 0;
    for (int i = 1; i <= n; i ++) {
        if (a[i] > 0) {
            int L = i, R = i;
            while (R + 1 <= n && a[R + 1] > 0) {
            	R ++;
            }
            int len = R - L + 1;
            Segment seg;
            seg.L = L; seg.R = R;
            seg.odd.resize(len + 1, 0);
            seg.even.resize(len + 1, 0);
            i64 sum1 = 0, sum2 = 0;
            for (int j = L; j <= R; j ++) {
                int k = j - L + 1;
                if (k & 1) {
                    sum1 += a[j];
                } else {
                    sum2 += a[j];
                }
                seg.odd[k] = sum1;
                seg.even[k] = sum2;
                sid[j] = id;
                pos[j] = k;
            }
            f.push_back(seg);
            id ++;
            i = R;
        }
    }

    std::vector<i64> pre(n + 2, 0), suf(n + 2, 0);
    for (auto &seg : f) {
        i64 c = std::min(seg.odd[seg.R - seg.L + 1], seg.even[seg.R - seg.L + 1]);
        pre[seg.R + 1] += c;
        suf[seg.L - 1] += c;
    }
    for (int i = 1; i <= n; i ++) {
    	pre[i] += pre[i - 1];
    }
    for (int i = n; i >= 1; i --) {
    	suf[i] += suf[i + 1];
    }

    i64 ans = 0;
    for (int i = 1; i <= n; i ++) {
        i64 cur = 0;
        if (a[i] == 0) {
            cur = pre[i] + suf[i];
        } else {
            int x1 = sid[i];
            int x2 = pos[i];
            Segment &seg = f[x1];
            int L = seg.L, R = seg.R;
            int len = R - L + 1;
            i64 Ls = 0, Rs = 0;

            if (x2 > 1) {
                Ls = std::min(seg.odd[x2 - 1], seg.even[x2 - 1]);
            }

            if (x2 < len) {
                i64 oddR = seg.odd[len] - seg.odd[x2];
                i64 evenR = seg.even[len] - seg.even[x2];
                int d = x2;
                if (d % 2 == 0) {
                    Rs = std::min(oddR, evenR);
                } else {
                    Rs = std::min(evenR, oddR);
                }
            }

            cur = a[i] + Ls + Rs + pre[i] + suf[i];
        }
        if (cur > ans) {
        	ans = cur;
        }
    }
    
    std::cout << ans << "\n";
/*
愿幸运女神与最纯粹的前行者同在。 
Test Sample

3
3
1 2 3
4
0 0 1 0
5
5 0 5 0 5

4
1
5


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