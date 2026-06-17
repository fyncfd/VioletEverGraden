/*
* @Author: AlgoStruggler
* @Create Time: 2026-04-08 18:31:55
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

const int N = 10005;

int fa[N];
int num[N];
int sum[N];
int sz[N];

void init() {
    for (int i = 0; i <= N; i ++) {
        fa[i] = i;
        num[i] = 0;
        sum[i] = 0;
        sz[i] = 1;
    }
}

int find(int x) {
    if (fa[x] == x) {
        return fa[x];
    }
    return fa[x] = find(fa[x]);
}

void merge(int x, int y) {
    int rx = find(x); int ry = find(y);
    if (rx > ry) {
        std::swap(rx, ry);
    }
    if (rx != ry) {
        fa[ry] = rx;
        sz[rx] += sz[ry];
        num[rx] += num[ry];
        sum[rx] += sum[ry];
    }
}

static inline void VioletEverGraden() {
    int n;
    std::cin >> n;

    init();

    std::vector<bool> vis(10005, false);

    for (int i = 1; i <= n; i ++) {
        int id;
        std::cin >> id;
        vis[id] = true;

        int f, m;
        std::cin >> f >> m;
        if (f != -1) {
            merge(id, f);
            vis[f] = true;
        }
        if (m != -1) {
            merge(id, m);
            vis[m] = true;
        }

        int k;
        std::cin >> k;
        for (int j = 1; j <= k; j ++) {
            int son;
            std::cin >> son;
            vis[son] = true;
            merge(id, son);
        }

        int nu, su;
        std::cin >> nu >> su;
        int rt = find(id);
        num[rt] += nu; sum[rt] += su;
    }

    int cnt = 0;
    struct pii {
        int id;
        int rk; double rn, rs;
    };
    std::vector<pii> ans;
    for (int i = 0; i <= 9999; i ++) {
        if (fa[i] == i && vis[i]) {
            ans.push_back({i, sz[i], 1.0 * num[i] / sz[i], 1.0 * sum[i] / sz[i]});
            cnt ++;
        }
    }

    std::sort(ans.begin(), ans.end(), [&](pii a, pii b) -> bool {
        if (std::fabs(a.rs - b.rs) > 1e-9) {
            return a.rs > b.rs;
        }
        return a.id < b.id;
    });

    std::cout << cnt << '\n';
    for (int i = 0; i < ans.size(); i ++) {
        int x = ans[i].id;
        if (x >=0  && x <= 9) {
            std::cout << "000" << x << ' ';
        } else if (x >= 10 && x <= 99) {
            std::cout << "00" << x << ' ';
        } else if (x >= 100 && x <= 999) {
            std::cout << "0" << x << ' ';
        } else {
            std::cout << x << ' ';
        }
        std::cout << ans[i].rk << ' ';
        std::cout << std::fixed << std::setprecision(3) << ans[i].rn << ' ' << ans[i].rs << '\n';
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