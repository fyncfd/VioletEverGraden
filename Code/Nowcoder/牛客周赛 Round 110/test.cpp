#include <bits/stdc++.h>
#define int long long
using ll = long long;

const int MAXN = 3e5 + 15;

struct node {
    int sum;
} seg[(MAXN << 2) + 10];

void update(int id) {
    seg[id].sum = seg[id * 2].sum + seg[id * 2 + 1].sum;
}
std::vector<ll> pre;
void build(int id, int l, int r) {
    if (l == r) {
        seg[id].minv = pre[l];
    } else {
        int mid = (l + r) >> 1;
        build(id * 2, l, mid);
        build(id * 2 + 1, mid + 1, r);
        update(id);
    }
}

int query(int id, int l, int r, int ql, int qr) {
    if (l == ql and r == qr) {
        return seg[id].minv;
    }
    int mid = (l + r) >> 1;
    if (qr <= mid) {
        return query(id * 2, l, mid, ql, qr);
    } else if (ql > mid) {
        return query(id * 2 + 1, mid + 1, r, ql, qr);
    } else {
        return std::max(query(id * 2, l, mid, ql, qr), query(id * 2 + 1, mid + 1, r, ql, qr));
    }
}

signed main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++) {
        std::cin >> a[i];
    }

    pre.resize(n + 1, 0);
    for (int i = 1; i <= n; i ++) {
        pre[i] = pre[i - 1] + a[i];
    }



    build(1, 1, n);

    ll ans = -1e18;
    for (int i = 1; i <= n; i ++) {
        ll max = query(1, 1, n, i, std::min(n, i + m - 1));
        ans = std::max(ans, max - pre[i - 1]);
    }

    std::cout << ans << '\n';

    return 0;
}