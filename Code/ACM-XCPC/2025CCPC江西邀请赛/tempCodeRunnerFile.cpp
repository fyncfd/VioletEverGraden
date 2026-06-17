#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, l, r, x) for (int i = l; i <= r; i += x)

const int MAXN = 2e5 + 5;


int n,m;
std::vector<ll> a;
int op;
ll x, y, k;

struct info{
    ll max;
};
std::vector<info> seg((MAXN << 2) + 10);
std::vector<ll> tag((MAXN << 2) + 10);

void update(ll id) {
    seg[id].max = std::max(seg[id * 2].max, seg[id * 2 + 1].max);
}

void build(ll id, ll l, ll r) {
    tag[id] = 0;
    if (l == r) {
        seg[id].max = a[l];
    } else {
        ll mid = l + r >> 1;
        build(id * 2, l, mid);
        build(id * 2 + 1, mid + 1, r);
        update(id);
    }
}

void addtag(ll id, ll l, ll r, ll val) {
    tag[id] += val;
    seg[id].max += val;
}

void pushdown(ll id, ll l, ll r) {
    if (tag[id]) {
        ll mid = l + r >> 1;
        addtag(id * 2, l, mid, tag[id]);
        addtag(id * 2 + 1, mid + 1, r ,tag[id]);
        tag[id] = 0;
    }
}

void modify(ll id, ll l, ll r, ll ql, ll qr, ll val) {
    if (l >= ql and r <= qr) {
        addtag(id, l, r, val);
        return ;
    }
    pushdown(id, l, r);
    ll mid = l + r >> 1;
    if (ql <= mid) {
        modify(id * 2, l , mid, ql, qr, val);
    }
    if (qr > mid) {
        modify(id * 2 + 1, mid + 1, r, ql, qr, val);
    }
    update(id);
}

ll query(ll id, ll l, ll r, ll ql, ll qr) {
    if (ql <= l and r <= qr) {
        return seg[id].max;
    }
    pushdown(id, l, r);
    ll mid = l + r >> 1;
    ll res = 0;
    if (ql <= mid) {
        res = std::max(res, query(id * 2, l, mid, ql, qr));
    }
    if (qr > mid) {
        res = std::max(res, query(id * 2 + 1, mid + 1, r, ql, qr));
    }
    return res;
}

void solve() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> L(n + 1, 0); std::vector<int> R(n + 1, 0);
    rep(i, 1, n, 1) {
        std::cin >> L[i] >> R[i];
    }
    
    a.resize(n + 1, 0);
    build(1, 1, n);


    ll l = 1; ll r = 0;
    ll ans = 0;
    while (r < n) {
        r ++;
        modify(1, 1, n, L[r], R[r], 1);
        while (l < r and query(1, 1, n, L[r], R[r]) > k) {
            modify(1, 1, n, L[l], R[l], -1);
            l ++;
        }
        ans = std::max(ans, r - l + 1);
    }

    std::cout << ans << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int _ = 1;
    for (std::cin >> _; _; _ --)
        solve();

    return 0;
}

/*
5 5
1 5 4 2 3
2 2 4
1 2 3 2
2 3 4
1 1 5 1
2 1 4


2
3 1
1 2
2 3
3 3
5 2
1 5
1 3
2 4
4 5
1 1
*/