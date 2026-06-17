#include <bits/stdc++.h>

using ll = long long;
using namespace std;

#define rep(i, l, r) for (int i = l; i <= r; i ++)
#define red(i, l, r) for (int i = l; i >= r; i --)
//#define int long long

const int MAXN = 0;
int n, m, k;
struct pii {
    int w; int v;
};

void solve() {
    std::cin >> n >> m >> k;
    
    std::vector<pii> p(n + 1);
    rep(i, 1, n) {
        std::cin >> p[i].w >> p[i].v;
    }

    std::sort(p.begin() + 1, p.end(), [&](pii a, pii b) {
        return a.v / a.w < b.v / b.w;
    });

    int ans = 0;
    rep(i, 1, n) {
        if (m <= 0) {
            ans += p[i].v;
            break;
        }

        ans += p[i].v;
        m -= p[i].w;
    }

    std::cout << ans << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int _ = 1;
    //std::cin >> _;

    //for (std::cin >> _; _; _ --) 
        solve();
    
        return 0;
}


/*
4 10 1
9 10
10 1
3 5
5 20

35





5 13 2
5 16
5 28
7 44
8 15
8 41


129



*/