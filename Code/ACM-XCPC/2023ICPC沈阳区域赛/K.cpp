#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define rep(i, l, r) for (int i = 1; i <= r; i ++)
#define red(i, l, r) for (int i = l; i >= r; i ++)
#define lop(x, y) for (auto x : y);

const int N = 1e6 + 10;
ll sum[N<<2],ma[N<<2],se[N<<2],num[N<<2];
ll ls(ll p){return p<<1;}
ll rs(ll p){return p<<1|1;}

void pushup(int p) {
    sum[p] = sum[ls(p)] + sum[rs(p)];
    ma[p] = max(ma[ls(p)], ma[rs(p)]);
    if (ma[ls(p)] == ma[rs(p)]) {
        se[p] = max(se[ls(p)], se[rs(p)]);
        num[p] = num[ls(p)] + num[rs(p)];
    } else {
        se[p] = max(se[ls(p)], se[rs(p)]);
        se[p] = max(se[p],min(ma[ls(p)], ma[rs(p)]));
        num[p] = ma[ls(p)] > ma[rs(p)] ? num[ls(p)] : num[rs(p)];
    }
}

void build(int p, int pl, int pr) {
    if (pl == pr) {
        scanf("%lld", &sum[p]);
        ma[p] = sum[p]; se[p] = -1; num[p] = 1;
        return ;
    }
    ll mid = (pl + pr) >> 1;
    build(ls(p), pl, mid);
    build(rs(p), mid + 1, pr);
    pushup(p);
}

void addtag(int p, int x) {
    if(x >= ma[p])  return ;
    sum[p] -= num[p] * (ma[p] - x);
    ma[p] = x;
}

void pushdown(int p) {
    addtag(ls(p), ma[p]);
    addtag(rs(p), ma[p]);
}

void update(int L, int R, int p, int pl, int pr, int x) {
    if (x >= ma[p])  return ;
    if (L <= pl && pr <= R && se[p] < x) {
        addtag(p, x); 
        return ;
    }
    pushdown(p);
    ll mid = (pl + pr) >> 1;
    if (L <= mid)   update(L, R, ls(p), pl, mid, x);
    if (R > mid)    update(L, R, rs(p), mid + 1, pr, x);
    pushup(p); 
}

int queryMAX(int L, int R, int p, int pl, int pr) {
    if (pl >= L && R >= pr) return ma[p];
    pushdown(p);
    int res = 0;
    ll mid = (pl + pr) >> 1;
    if (L <= mid)   res = queryMAX(L, R, ls(p), pl, mid);
    if (R > mid)    res = max(res, queryMAX(L, R, rs(p), mid + 1, pr));
    return res;
}

ll querySum(int L, int R, int p, int pl, int pr) {
    if (L <= pl && R >= pr)     return sum[p];
    pushdown(p);
    ll res = 0;
    ll mid = (pl + pr) >> 1;
    if (L <= mid)   res += querySum(L, R, ls(p), pl, mid);
    if (R > mid)    res += querySum(L, R, rs(p), mid + 1, pr);
    return res;
}

void solve() {

}

auto INIT = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
};

signed main() {
    //INIT();

    int _ = 1;

    for (std::cin >> _; _;_ --) 
        solve();

    return 0;
}

/*
0 1 

4

1 2 

4
*/