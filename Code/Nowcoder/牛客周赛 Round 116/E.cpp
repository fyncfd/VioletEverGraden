/*
* @Author: AlgoStruggler
* @Create Time: 2025-11-02 20:04:02
* "To the Splendor of ACM-ICPC, We Consecrate Our AC Triumphs."
*/
#define  _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize("O2")
#include "bits/stdc++.h"

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef __int128 i128;

#define all(x) x.begin() + 1, x.end()
#define rep(i, l, r) for (int i = (l); i <= (r); i++)
#define per(i, r, l) for (int i = (r); i >= (l); i--)

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MOD = 1e9 + 7;

struct Node {
    int cnt = 0; 
    ll cl = 0; 
};

std::vector<Node> tree;

void recalc(int v, int a, int b) {
    if (tree[v].cnt > 0) {
        tree[v].cl = b - a + 1;
    } else if (a == b) { 
        tree[v].cl = 0;
    } else { 
        tree[v].cl = tree[2 * v].cl + tree[2 * v + 1].cl;
    }
}

void update(int v, int a, int b, int L, int R, int addv) {
    if (L > R || a > R || b < L) {
        return; 
    }
    if (L <= a && b <= R) { 
        tree[v].cnt += addv;
        recalc(v, a, b);
        return;
    }
    int mid = (a + b) / 2;
    update(2 * v, a, mid, L, R, addv);
    update(2 * v + 1, mid + 1, b, L, R, addv);
    recalc(v, a, b);
}

int n, m;
std::map<int, std::vector<std::tuple<int, int, int>>> a;

/*-------------------------------MY_CODE_BEGIN--------------------------------*/
static inline void VioletEverGraden() {
    std::cin >> n >> m;
    a.clear();
    
    rep(i, 1, n) {
        int l, r;
        std::cin >> l >> r;
        a[l].emplace_back(1, l, m);
        a[l + 1].emplace_back(-1, l, m);
        if (l + 1 <= r) {
            a[l + 1].emplace_back(1, r, m);
            a[r + 1].emplace_back(-1, r, m);
        }
        if (1 <= l - 1) {
            a[1].emplace_back(1, l, r);
            a[l].emplace_back(-1, l, r);
        }
    }
    a[m + 1];
    tree.resize(4 * m + 5);
    
    rep(i, 1, 4 * m + 4) {
        tree[i].cnt = 0;
        tree[i].cl = 0;
    }

    ll ans = 0;
    ll posl = 1;

    for (auto const& [L, list] : a) {
        ll k = L - posl;
        if (k > 0) {
            ll r = tree[1].cl; 
            ans += k * r;
        }

        if (L > m) {
            break; 
        }
        for (auto const& [type, R1, R2] : list) {
            update(1, 1, m, R1, R2, type);
        }

        posl = L;
    }

    ll sum = (ll)m * (m + 1) / 2;
    std::cout << sum - ans << "\n";
}
/*-------------------------------Author_Fd------------------------------------*/
static inline void VioletEverGraden();

auto __FAST_IO__ = []() -> int {
    std::ios_base::sync_with_stdio(false); 
    std::cin.tie(nullptr); 
    std::cout.tie(nullptr);
    return 0;
}();

signed main() {
#ifdef LOCAL
    freopen("A.in", "r", stdin);
#endif

    int _ = 1;
    for (std::cin >> _; _; _--)
        VioletEverGraden();

    return 0;
}