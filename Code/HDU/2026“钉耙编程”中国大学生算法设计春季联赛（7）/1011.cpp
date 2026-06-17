/*
* @Author: AlgoStruggler
* @Create Time: 2026-05-08 20:17:45
* "To the Splendor of ACM-ICPC, We Consecrate Our AC Triumphs."
*/
#pragma GCC optimize("O3,unroll-loops,Ofast,inline")
#include "bits/stdc++.h"
using namespace std;
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
	int n, k;
	std::cin >> n >> k;

	std::string s;
	std::cin >> s;

	// std::cout << s << '\n';
	int sum1 = 0, sum2 = 0;
	for(int i=0;i<n;i++){
		if(s[i]=='1') sum1++;
		else sum2++;
	}
	// cout<<endl<<1<<endl;
	if(n%2==0){
		if(sum1&1){
			cout<<"NO"<<endl;
		}
		else{
			if(gcd(n,k)==1) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
	}
	else{
		if(gcd(n,k)==1) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
/*
愿幸运女神与最纯粹的前行者同在。 `
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