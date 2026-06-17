/*
* @Author: AlgoStruggler
* @Create Time: 2026-04-13 22:42:52
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

const int N = 35000;

int in[N], pre[N];

struct Node {
	int l = -1; int r = -1;
};

Node tree[N];

int dfs(int la, int ra, int lb, int rb) {
	if (lb > rb) {
		return -1;
	}
	int rt = pre[la];
	int p1 = lb;
	while (in[p1] != rt) {
		p1 ++;
	}
	int len = p1 - lb;
	tree[rt].l = dfs(la + 1, la + len, lb, p1 - 1);
	tree[rt].r = dfs(la + len + 1, ra, p1 + 1, rb);
	return rt;
}

std::vector<int> ans;
void bfs(int x) {
	std::queue<int> q;
	q.push(x);

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		ans.push_back(x);
		if (tree[x].r != -1){
			q.push(tree[x].r);
		}
		if (tree[x].l != -1){
			q.push(tree[x].l);
		}
	}
}

static inline void VioletEverGraden() {
    int n;
    std::cin >> n;

    for (int i = 1; i <= n; i ++) {
    	std::cin >> in[i];
    }
    for (int i = 1; i <= n; i ++) {
    	std::cin >> pre[i];
    }

    int root = dfs(1, n, 1, n);
    bfs(root);

    for (int i = 0; i < n; i ++) {
    	std::cout << ans[i] << " \n"[i + 1 == n];
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