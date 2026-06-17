#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, l, r) for (int i = 1; i <= n; i ++)
#define red(i, l, r) for (int i = l; i >= n; i --)
#define int long long

int n, q;
std::vector<int> a;
int p, l, r;
void solve() {
    std::cin >> n >> q;
    a.resize(n + 1);
    rep(i, 1, n) {
        std::cin >> a[i];
    }

    struct pii { int fi; int se; };
    std::vector<pii> ip(n + 1, {-1, 1000000009});
    int __ = q;
    while (__ --) {
        std::cin >> p >> l >> r;
        if (ip[p].fi < l) {
            ip[p].fi = l;
        }
        if (ip[p].se > r) {
            ip[p].se = r;
        }
    }

    int ans = 0; bool ok = false;
    rep(i, 1, n) {
        if (ip[i].fi != -1 and ip[i].se != -1) {
            //std::cerr << ip[i].fi << ' ' << ip[i].se << '\n';
            pii node = ip[i];

            if (node.se < node.fi) {
                ok = true;
            } else {
                if (a[i] < node.fi) {
                    ans += abs(node.fi - a[i]);
                } else if (a[i] > node.se) {
                    ans += abs(node.se - a[i]);
                }
            }

        }
    }

    if (ok) {
        std::cout << -1 << '\n';
    } else {
        std::cout << ans << '\n';
    }
}

auto __init__ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
};

signed main() {
    __init__();

    int _ = 1;
    for (std::cin >> _; _; _ --) 
        solve();

    return 0;
}

/*
3
4 3
20 25 4 27
3 5 7
1 10 15
3 2 6
1 2
7
1 3 5
1 9 9
1 2
7
1 3 9
1 4 15

1
4 3
20 25 4 27
3 5 7
1 10 15
3 2 6

1
1 2
7
1 3 5
1 9 9


1
1 2
7
1 3 9
1 4 15


6
-1
0

*/