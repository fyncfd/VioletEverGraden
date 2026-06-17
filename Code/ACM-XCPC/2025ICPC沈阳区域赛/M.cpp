#include <bits/stdc++.h>

using ll = long long;

#define rep(i, l, r, x) for (int i = l; i <= r; i += x)

void solve() {
    struct pii { int x; double y; };
    std::vector<int> a(8); std::vector<int> b(8);
    rep(i, 0, 7, 1) {
        std::cin >> a[i] >> b[i];
        //std::cerr << "+++\n";
    }

    int n = 7;
    std::vector<int> p;
    rep(i, 0, 7, 1) {
        p.push_back(i);
    }

    // auto f = [&](int pos) -> double {
        
    // };

    double ans = 0;
    do {
        // std::cerr << "???\n";
        std::vector<std::vector<pii>> v(8);
        rep(i, 0, n, 1) {
            v[i] = {{p[i], 1.0}};
        }

        rep(c, 1, 3, 1) {
            // std::cerr<<i<<std::endl;
            std::vector<std::vector<pii>> v2;
            for (int i = 0; i < v.size() - 1; i += 2) {
                v2.push_back({});
                for (auto [x, p] : v[i]) for (auto [y, q] : v[i + 1]) {
                        int pa = a[x]; int pb = b[y];
                        v2.back().push_back({x, p * q * pa / (pa + pb)});
                        v2.back().push_back({y, p * q * pb / (pa + pb)});
                }
            }
            v = v2;
        }
      
        double temp = 0;
        for (auto [x, p]: v[0]) {
            if (x == 0) {
                temp += p;
            }
        }
        ans = std::max(ans, temp);
        // for (auto &x : p) {
        //     std::cout << x << '\n';
        // }
    } while(std::next_permutation(p.begin(), p.end()));

    std::cout << ans << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cout << std::fixed << std::setprecision(12);
    int _ = 1;
    // for (std::cin >> _; _; _ --)
        solve();

    return 0;
}

/*
10 80
20 70
30 60
40 50
50 40
60 30
70 20
80 10

0.329505822460368



100 100
100 100
100 100
100 100
100 100
100 100
100 100
100 100

0.125000000000000




*/