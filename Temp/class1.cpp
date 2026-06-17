#include <bits/stdc++.h>

using ll = long long;
#define rep(i, l, r, x) for (int i = l; i <= r; i ++)

const int MAXN = 1e5 + 5;

int n, m;
std::vector<ll> a;
int op; ll x, y, k;

struct info {
    ll sum;
};
std::vector<info> seg((MAXN << 2) + 10);
std::vector<ll> tag((MAXN << 2) + 10);

void push_up(ll id) {
    seg[id].sum = seg[id << 1].sum + seg[id << 1 | 1].sum;
}

void build(ll id, ll l, ll r) {
    tag[id] = 0;
    if (l == r) {
        seg[id].sum = a[l];
    } else {
        ll mid = l + r >> 1;
        build(id * 2, l, mid);
        build(id * 2 + 1, mid + 1, r);
        push_up(id);
    }
}

void addtag(ll id, ll l, ll r, ll val) {
    tag[id] += val;
    seg[id].sum += val * (r - l + 1);
}

void pushdown(ll id, ll l, ll r) {
    if (tag[id]) {
        ll mid = l + r >> 1;
        addtag(id * 2, l, mid, tag[id]);
        addtag(id * 2 + 1, mid + 1, r, tag[id]);
        tag[id] = 0;
    }
}

void modify(ll id, ll l, ll r, ll ql, ll qr, ll val) {
    if (l >= ql && r <= qr) {
        addtag(id, l, r, val);
        return;
    }
    pushdown(id, l, r);
    ll mid = l + r >> 1;
    if (ql <= mid) {
        modify(id * 2, l, mid, ql, qr, val);
    }
    if (qr > mid) {
        modify(id * 2 + 1, mid + 1, r, ql, qr, val);
    }
    push_up(id);
}

ll query(ll id, ll l, ll r, ll ql, ll qr) {
    if (ql <= l && r <= qr) {
        return seg[id].sum;
    }
    pushdown(id, l, r);
    ll mid = l + r >> 1;
    ll res = 0;
    if (ql <= mid) {
        res += query(id * 2, l, mid, ql, qr);
    }
    if (qr > mid) {
        res += query(id * 2 + 1, mid + 1, r, ql, qr);
    }
    return res;
}

void violet() {
    std::cin >> n >> m;
    a.resize(n + 10);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    build(1, 1, n);

    int __ = m;
    while (__--) {
        std::cin >> op;
        if (op == 1) {
            std::cin >> x >> y >> k;
            modify(1, 1, n, x, y, k);
        } else {
            std::cin >> x >> y;
            ll ans = query(1, 1, n, x, y);
            std::cout << ans << '\n';
        }
    }
}

signed main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout.tie(nullptr);

    int _ = 1;
    // for (std::cin >> _; _; _ --)
    	violet();

    return 0;
}