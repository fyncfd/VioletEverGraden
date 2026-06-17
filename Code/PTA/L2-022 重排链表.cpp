/*
* @Author: AlgoStruggler
* @Create Time: 2026-04-15 15:33:35
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
    std::string had;
    std::cin >> had >> n;

    struct Node {
    	std::string add, nxt; int val;
    };
    std::map<int, Node> L;

    // std::cin >> had >> hid;

    struct node {
    	int vv; std::string nex;
    };
    std::map<std::string, node> mp;
    for (int i = 1; i <= n; i ++) {
    	std::string ad, nt; int v;
    	std::cin >> ad >> v >> nt;
    	mp[ad].vv = v;
    	mp[ad].nex = nt;
    }

    for (int i = 1; i <= n; i ++) {
		L[i].add = had;
		L[i].nxt = mp[had].nex;
		L[i].val = mp[had].vv;
		had = mp[had].nex;  	
    }

    int l = 1; int r = n;
    int pre = -1;
    while (l <= r) {
    	if (l == r) {
	    	if (pre != -1) {
	    		L[pre].nxt = L[r].add;
	    		pre = l;
	    	} else {
	    		;
	    	}
	    	L[l].nxt = "-1";
    	} else {
    		if (l == r - 1) {
    			L[r].nxt = L[l].add;
    			L[l].nxt = "-1";
	    		if (pre != -1) {
		    		L[pre].nxt = L[r].add;
		    		pre = l;
		    	} else {
		    		;
		    	}
    		} else {
		    	L[r].nxt = L[l].add;
		    	if (pre != -1) {
		    		L[pre].nxt = L[r].add;
		    		pre = l;
		    	} else {
		    		;
		    	}
		    }
	    	l ++; r --;
    	}
    }

    l = 1; r = n;
    // int pre = -1;
    while (l <= r) {
    	if (l == r) {
	    	std::cout << L[l].add << ' ' << L[l].val << ' ' << -1 << '\n';
    	} else {
    		std::cout << L[r].add << ' ' << L[r].val << ' ' << L[r].nxt << '\n';
	    	std::cout << L[l].add << ' ' << L[l].val << ' ' << L[l].nxt << '\n';
	    	l ++; r --;
    	}
    }
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