/*
* @Author: AlgoStruggler
* @Create Time: 2026-05-22 18:50:11
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
    string s;
    cin>>s;
    if(s.size()<7){
    	cout<<s<<endl;
    	return;
    }
    std::vector<int> f;
    for(int i=0;i<s.size()-6;i++){
    	if(s[i]=='e'&&s[i+1]=='x'&&s[i+2]=='e'&&s[i+3]=='c'&&s[i+4]=='u'&&s[i+5]=='t'&&s[i+6]=='e'){
    		f.push_back(i);
    		// cout<<i<<endl;
    	}
    }
    if(f.size()==1){
    	s[f[0]]='1';
    	cout<<s<<endl;
    	return;
    }
    int c=f.size();
    // for(int i=0;i<c;i++){
    // 	cout<<f[i]<<" \n"[i==c-1];
    // }
    // cout<<c<<endl;
    int cnt=1;
    for(int i=1;i<c;i++){
    	// cout<<i<<endl;
    	if(f[i]-f[i-1]==6){
    		cnt++;
    	}
    	else{
    		if(cnt&1){
    			s[f[i-cnt]]='1';
    			for(int k=i-cnt+2;k<=i;k+=2){
    				s[f[k]]='1';
    			}
    		}
    		else{
    			for(int k=i-cnt+1;k<=i;k+=2){
    				s[f[k]]='1';
    			}
    		}
    		cnt=1;
    	}
    	if(i==c-1&&cnt!=1){
    		// cout<<cnt<<endl;
    		if(cnt&1){
    			s[f[i-cnt+1]]='1';
    			for(int k=i-cnt+3;k<=i;k+=2){
    				s[f[k]]='1';
    			}
    		}
    		else{
    			for(int k=i-cnt+2;k<=i;k+=2){
    				s[f[k]]='1';
    			}
    		}
    		cnt=1;
    	}
    }
    // cout<<cnt<<endl;
    // for(int i=0;i<s.size()-6;i++){
    // 	if(s[i]=='e'&&s[i+1]=='x'&&s[i+2]=='e'&&s[i+3]=='c'&&s[i+4]=='u'&&s[i+5]=='t'&&s[i+6]=='e'){
    // 		s[i]='1';
    // 		// cout<<i<<endl;
    // 	}
    // }
    cout<<s<<endl;
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