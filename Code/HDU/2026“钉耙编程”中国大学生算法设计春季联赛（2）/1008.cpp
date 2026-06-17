/*
* @Author: AlgoStruggler
* @Create Time: 2026-03-27 18:45:24
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

    std::vector<int> a(2 * n + 10);
    for (int i = 1; i <= n; i ++) {
        std::cin >> a[i];
        a[i + n] = a[i];
    }

    std::vector<i64> pre(2 * n + 10);
    for (int i = 1; i <= 2 * n; i ++) {
        pre[i] = pre[i - 1] + a[i];
    }

    
/*
愿幸运女神与最纯粹的前行者同在。 
Test Sample
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        
        // 构造双倍数组
        vector<ll> arr(2 * n);
        for (int i = 0; i < n; ++i) {
            arr[i] = a[i];
            arr[i + n] = a[i];
        }
        
        // 双倍前缀和
        vector<ll> S(2 * n + 1, 0);
        for (int i = 1; i <= 2 * n; ++i) {
            S[i] = S[i - 1] + arr[i - 1];
        }
        
        // 单调队列求区间 [k, k+n-1] 的最小 S'[j]
        // 注意 j 是前缀和的下标，从 1 开始
        // 我们要求的是 min_{j=k}^{k+n-1} S'[j]
        
        deque<int> dq;
        vector<ll> minS(2 * n + 1);
        
        for (int i = 1; i <= 2 * n; ++i) {
            // 维护队列单调递增
            while (!dq.empty() && S[dq.back()] >= S[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
            
            // 窗口长度是 n
            if (i >= n) {
                minS[i - n + 1] = S[dq.front()];
                
                // 移除离开窗口的元素
                if (dq.front() == i - n + 1) {
                    dq.pop_front();
                }
            }
        }
        
        int ans = -1;
        for (int k = 1; k <= n; ++k) {
            // 判断 S'[k-1] <= min_{j=k}^{k+n-1} S'[j]
            if (S[k - 1] <= minS[k]) {
                ans = k;
                break;
            }
        }
        
        cout << ans << "\n";
    }
    
    return 0;
}
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