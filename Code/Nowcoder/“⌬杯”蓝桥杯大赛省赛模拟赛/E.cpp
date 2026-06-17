/*
* @Author: AlgoStruggler
* @Create Time: 2026-03-29 13:48:58
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
    i64 n, k;
    std::cin >> n >> k;

    std::vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i ++) {
    	std::cin >> a[i];
    }

    std::deque<int> q;
    std::vector<int> t1;
    for (int i = 1; i <= n; i ++) {
    	q.push_back(a[i]);
    	t1.push_back(a[i]);
    }
/*
	for (int i = 0; i < t1.size(); i ++) {
		std::cout << "t1:" << t1[i] << '\n';
	}
	std::cout << '\n';*/

/*    int x = 1000;
    while (x --) {
    	int f = q.front();
    	q.pop_front();
    	int d = q.front();
    	q.pop_front();
    	if (f > d) {
    		q.push_front(f);
    		q.push_back(d);
    	} else {
    		q.push_front(d);
    		q.push_back(f);
    	}

    	std::vector<int> t2(q.begin(), q.end());
    	for (int i = 0; i < t2.size(); i ++) {
    		std::cout << "t2:" << t2[i] << '\n';
    	}
    	if (t1 == t2) {
    		std::cout << "cnt:" <<  100 - x << '\n';
    		break;
    	}
    	std::cout << '\n';
    }*/

    int cnt = 0;
    for (int i = 1; i <= n; i ++) {
    	if (a[i] == n) {
    		cnt = i - 1;
    	}
    }

    if (k <= cnt) {
    	int __ = k;
	    while (__ --) {
	    	int f = q.front();
	    	q.pop_front();
	    	int d = q.front();
	    	q.pop_front();
	    	if (f > d) {
	    		q.push_front(f);
	    		q.push_back(d);
	    	} else {
	    		q.push_front(d);
	    		q.push_back(f);
	    	}
    	}
    	std::vector<int> t2(q.begin(), q.end());
    	for (int i = 0; i < t2.size(); i ++) {
    		std::cout << t2[i] << " \n"[i + 1 == t2.size()];
    	}
    } else {
    	// std::cout << "k:" << k << '\n';
    	// std::cout << "cnt:" << cnt << '\n';
    	k = k - cnt + 1;
    	k %= (n - 1);
    	k += cnt;
    	k --;
    	// std::cout << "k:" << k << '\n';
    	int __ = k;
	    while (__ --) {
	    	int f = q.front();
	    	q.pop_front();
	    	int d = q.front();
	    	q.pop_front();
	    	if (f > d) {
	    		q.push_front(f);
	    		q.push_back(d);
	    	} else {
	    		q.push_front(d);
	    		q.push_back(f);
	    	}
    	}
    	std::vector<int> t2(q.begin(), q.end());
    	for (int i = 0; i < t2.size(); i ++) {
    		std::cout << t2[i] << " \n"[i + 1 == t2.size()];
    	}
    }
/*
愿幸运女神与最纯粹的前行者同在。 
#16
t2:5
t2:3
t2:1
t2:4
t2:2

Test Sample
3
5 0
3 4 1 5 2
5 1
3 4 1 5 2
5 3
3 4 1 5 2

t1:3
t1:4
t1:1
t1:5
t1:2

t2:4
t2:1
t2:5
t2:2
t2:3

t2:4
t2:5
t2:2
t2:3
t2:1

t2:5
t2:2
t2:3
t2:1
t2:4

t2:5
t2:3
t2:1
t2:4
t2:2

t2:5
t2:1
t2:4
t2:2
t2:3

t2:5
t2:4
t2:2
t2:3
t2:1

t2:5
t2:2
t2:3
t2:1
t2:4

t2:5
t2:3
t2:1
t2:4
t2:2

t2:5
t2:1
t2:4
t2:2
t2:3

t2:5
t2:4
t2:2
t2:3
t2:1

t2:5
t2:2
t2:3
t2:1
t2:4

t2:5
t2:3
t2:1
t2:4
t2:2

t2:5
t2:1
t2:4
t2:2
t2:3

t2:5
t2:4
t2:2
t2:3
t2:1

t2:5
t2:2
t2:3
t2:1
t2:4

t2:5
t2:3
t2:1
t2:4
t2:2

t2:5
t2:1
t2:4
t2:2
t2:3

t2:5
t2:4
t2:2
t2:3
t2:1

t2:5
t2:2
t2:3
t2:1
t2:4

t2:5
t2:3
t2:1
t2:4
t2:2

t2:5
t2:1
t2:4
t2:2
t2:3

t2:5
t2:4
t2:2
t2:3
t2:1

t2:5
t2:2
t2:3
t2:1
t2:4

t2:5
t2:3
t2:1
t2:4
t2:2

t2:5
t2:1
t2:4
t2:2
t2:3

t2:5
t2:4
t2:2
t2:3
t2:1

t2:5
t2:2
t2:3
t2:1
t2:4

t2:5
t2:3
t2:1
t2:4
t2:2

t2:5
t2:1
t2:4
t2:2
t2:3

t2:5
t2:4
t2:2
t2:3
t2:1

t2:5
t2:2
t2:3
t2:1
t2:4

t2:5
t2:3
t2:1
t2:4
t2:2

t2:5
t2:1
t2:4
t2:2
t2:3

t2:5
t2:4
t2:2
t2:3
t2:1

t2:5
t2:2
t2:3
t2:1
t2:4

t2:5
t2:3
t2:1
t2:4
t2:2

t2:5
t2:1
t2:4
t2:2
t2:3

t2:5
t2:4
t2:2
t2:3
t2:1

t2:5
t2:2
t2:3
t2:1
t2:4

t2:5
t2:3
t2:1
t2:4
t2:2

t2:5
t2:1
t2:4
t2:2
t2:3

t2:5
t2:4
t2:2
t2:3
t2:1

t2:5
t2:2
t2:3
t2:1
t2:4

t2:5
t2:3
t2:1
t2:4
t2:2

t2:5
t2:1
t2:4
t2:2
t2:3

t2:5
t2:4
t2:2
t2:3
t2:1

t2:5
t2:2
t2:3
t2:1
t2:4

t2:5
t2:3
t2:1
t2:4
t2:2

t2:5
t2:1
t2:4
t2:2
t2:3

t2:5
t2:4
t2:2
t2:3
t2:1

t2:5
t2:2
t2:3
t2:1
t2:4

t2:5
t2:3
t2:1
t2:4
t2:2

t2:5
t2:1
t2:4
t2:2
t2:3

t2:5
t2:4
t2:2
t2:3
t2:1

t2:5
t2:2
t2:3
t2:1
t2:4

t2:5
t2:3
t2:1
t2:4
t2:2

t2:5
t2:1
t2:4
t2:2
t2:3

t2:5
t2:4
t2:2
t2:3
t2:1
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