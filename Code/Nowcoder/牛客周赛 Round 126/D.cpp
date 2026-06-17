/*
* @Author: AlgoStruggler
* @Create Time: 2026-02-09 09:29:59
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
    int x, y, n;
    std::cin >> x >> y >> n;

    std::vector<int> c(x + 1, -1);
    for (int i = 1; i <= x; i ++) {
    	std::cin >> c[i];
    }

    std::vector<int> d(y + 1, -1);
    for (int i = 1; i <= y; i ++) {
    	std::cin >> d[i];
    }

    std::vector<int> st = c;
    std::reverse(d.begin() + 1, d.end());

    for (int i = 1; i <= y; i ++) {
    	int m = st.back();
    	// std::cerr << m << "???\n";
    	if (m > d[i]) {
    		st.push_back(d[i]);
    	}
    }

    // for (int i = 1; i < st.size(); i ++) {
    // 	std::cout << st[i] << " \n"[i + 1 == st.size()];
    // }

    std::vector<int> pre(1);
    for (int i = 1; i < st.size(); i ++) {
    	if (st[i] > st[i - 1]) {
    		pre.push_back(st[i]);
    	}
    }

    std::vector<int> suf(1);
    st.push_back(-1);
    for (int i = st.size() - 2; i >= 1; i --) {
    	if (st[i] > st[i + 1]) {
    		suf.push_back(st[i]);
    	}
    }

/*    for (int i = 1; i < pre.size(); i ++) {
    	std::cerr << pre[i] << "!!!";
    }

    std::cout << '\n';

    for (int i = 1; i < suf.size(); i ++) {
    	std::cerr << suf[i] << "???";
    }

    std::cout << '\n';*/

    for (int i = 1; i <= x; i ++) {
    	// std::cerr << pre[i] << "===" << c[i] << '\n';
    	if (pre[i] != c[i]) {
    		std::cout << -1 << '\n';
    		return ;
    	}
    }

    std::reverse(d.begin() + 1, d.end());
    for (int i = 1; i <= y; i ++) {
    	// std::cerr << suf[i] << "===" << d[i] << '\n';
    	if (suf[i] != d[i]) {
    		std::cout << -1 << '\n';
    		return ;
    	}
    }

    int sz = st.size() - 2;
    // std::cerr << sz << '\n';
    if (sz > n) {
    	std::cout << -1 << '\n';
    	return ;
    }

    int dif = n - sz;
    for (int i = 1; i + 1 < st.size(); i ++) {
    	std::cout << st[i] << ' ';
    }
    for (int i = 1; i <= dif; i ++) {
    	std::cout << st[sz] << " \n"[i == dif];
    }
    
    /* 愿幸运女神与最纯粹的前行者同在。 */
/*
Test Sample

2 3 4
1 5
1 4 5

1 5 4 1

1 1 2
1
2

-1

4 2 6
2 3 4 5
1 5

2 3 4 5 1 1


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