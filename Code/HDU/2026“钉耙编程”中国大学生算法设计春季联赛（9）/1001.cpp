/*
* @Author: AlgoStruggler
* @Create Time: 2026-05-22 20:08:28
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

constexpr int N = 1e5;
constexpr int B = 320;

int n, m;

struct cloud {
	i64 x, y;
	int id, type, cnt;
	bool alive;
};
std::vector<cloud> a;
std::vector<int> blk[N / B + 5];
i64 L[N / B + 5], R[N / B + 5];
i64 addx[N / B + 5], addy[N / B + 5];
int addcnt[N / B + 5];
int bn;

void rebuild(int b) {
	L[b] = 1e18, R[b] = 1e18;
	std::vector<int> tmp;
	for (int i : blk[b]) {
		if (!a[i].alive) {
			continue;
		}
		tmp.push_back(i);
		i64 rx = a[i].x + addx[i];
		L[b] = std::min(L[b], rx);
		R[b] = std::max(R[b], rx);
	} 
	blk[b] = tmp;
}

void push_down(int b) {
	if (addcnt[b] == 0 && addx[b] == 0 && addy[b] == 0) {
		return ;
	}
	for (int i : blk[b]) {
		a[i].cnt += addcnt[b];
		if (a[i].type == 0 && a[i].cnt > 0) {
			a[i].type = 1;
		}
		a[i].x += addx[b];
		a[i].y += addy[b];
	}
	addcnt[b] = addx[b] = addy[b] = 0;
}

void update(int l, int r, i64 u, i64 v) {
	for (int b = 0; b < bn; b ++) {
		if (blk[b].empty()) {
			continue;
		}
		i64 bl = L[b], br = R[b];
		if (br < l || bl > r) {
			continue;
		}

		if (bl >= l && br <= r) {
			addcnt[b] ++;
			addx[b] += u;
			addy[b] += v;
            L[b] += u;
            R[b] += u;
		} else {
            push_down(b);
            std::vector<int> tmp;
            for (int i : blk[b]) {
                i64 rx = a[i].x;
                if (rx >= l && rx <= r) {
                    a[i].cnt ++;
                    if (a[i].type == 0) a[i].type = 1;
                    a[i].x += u;
                    a[i].y += v;
                }
                if (a[i].cnt < 6) {
                    tmp.push_back(i);
                } else {
                    a[i].alive = false;
                }
            }
            blk[b] = tmp;
            L[b] = 1e18, R[b] = -1e18;
            for (int i : blk[b]) {
                L[b] = std::min(L[b], a[i].x);
                R[b] = std::max(R[b], a[i].x);
            }
		}
	}
}

static inline void VioletEverGraden() {
    std::cin >> n >> m;

    a.resize(n);
    for (int i = 0; i < n; i ++) {
        std::cin >> a[i].x >> a[i].y;
        a[i].cnt = 0;
        a[i].type = 0;
        a[i].id = i;
        a[i].alive = true;
    }

    std::sort(a.begin(), a.end(), 
    	[&](cloud &a, cloud &b) -> bool {
    		return a.x < b.x;
    	});

    bn = (n + B - 1) / B;
    for (int i = 0; i < n; i ++) {
        int b = i / B;
        blk[b].push_back(i);
    }
    for (int b = 0; b < bn; b ++) {
        L[b] = 1e18, R[b] = -1e18;
        for (int i : blk[b]) {
            L[b] = std::min(L[b], a[i].x);
            R[b] = std::max(R[b], a[i].x);
        }
    }

    while (m --) {
        i64 l, r, u, v;
        std::cin >> l >> r >> u >> v;
        update(l, r, u, v);
    }

    std::vector<std::pair<int, std::tuple<int, i64, i64>>> ans(n);
    for (int b = 0; b < bn; b ++) {
        push_down(b);
        for (int i : blk[b]) {
            if (a[i].cnt >= 6) {
            	continue;
            }
            ans[a[i].id] = {a[i].id, {a[i].type, a[i].x, a[i].y}};
        }
    }
    
    for (int i = 0; i < n; i ++) {
        if (ans[i].second == std::tuple<int, i64, i64>{0, 0, 0}) {
            std::cout << "Disappeared\n";
        } else {
            auto [typ, x, y] = ans[i].second;
            std::cout << (typ == 0 ? "Cumulus " : "Cirrus ") << x << " " << y << '\n';
        }
    }/*
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