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

    std::vector<i64> a(2 * n + 20);
    for (int i = 1; i <= n; i ++) {
        std::cin >> a[i];
        a[i+n] = a[i];
    }

    i64 sum = 0; int cnt = 0;
    int ans = 0;
    for(int i=1;i<=2*n;i++){
        sum+=a[i];
        cnt++;
        if(sum<0){
            cnt=0;
            sum=0;
        }
        else{
            // cnt++;
            if(cnt==n){
                ans=i;
                break;
            }
        }
    }
    std::cout << ans-n+1  << '\n';
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

    for (int _ = [&]() -> int { int T; std::cin >> T; return T; }(); _; _ --)
        VioletEverGraden();

    return 0;
}