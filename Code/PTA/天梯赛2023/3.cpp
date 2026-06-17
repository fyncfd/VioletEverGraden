#include "bits/stdc++.h"

using ll = long long;
using ull = unsigned long long;

#define rep(i, l, r) for (int i = l; i <= r; i ++)
#define red(i, l, r) for (int i = l; i >= r; i --)

//#deifne int long long;
int a, b, c, d;

void solve() {
    std::cin >> a >> b >> c >> d;
    if(d < a and c >= b) {
    	printf("%d-Y %d-Y\nqing 1 zhao gu hao 2",c, d);
    }
    if(c < a and d >= b) {
    	printf("%d-Y %d-Y\nqing 2 zhao gu hao 1",c,d);
    }
    if(c>=a and d>=a) {
    	printf("%d-Y %d-Y\nhuan ying ru guan",c,d);
    }
    if(c<a and d<a) {
    	printf("%d-N %d-N\nzhang da zai lai ba",c,d);
    }
    if(c>=a and c<b and d<a)
    	printf("%d-Y %d-N\n1: huan ying ru guan",c,d);
    if(d>=a and d<b and c<a) {
    	printf("%d-N %d-Y\n2: huan ying ru guan",c,d);
    }
}

signed main() {
	std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);
	std::cout.tie(nullptr);

	int _ = 1;
	//std::cin >> _;

	while (_ --) {
		solve();
	}

	return 0;
}