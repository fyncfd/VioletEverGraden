#include <bits/stdc++.h>

using i64 = long long;

constexpr i64 mod = 998244353;

i64 ksm(i64 a, i64 b, i64 m) {//迭代法求取模快速幂
    a %= m;//先取模，确保a < m;
    i64 res = 1;
    while (b > 0) {
        if (b & 1) {
            res = (res * a) % m;
        }
        a = (a * a) % m;//平方后取模
        b >>= 1;
    }
    return res;
}

void solve() {
    int n; i64 m;
    std::cin >> n >> m;

    std::unordered_map<i64, i64> mp;
    for (int i = 1; i <= n; i ++) {
        i64 a, b;
        std::cin >> a >> b;
        mp[b] += a;
    }

    std::vector<i64> p;
    for (auto [x, y] : mp) {
        p.push_back(x);
    }
    std::sort(p.begin(), p.end(), [&](i64 a, i64 b) -> bool {
        return a > b;
    });

    i64 tot = 0, pre = p[0], res = 0;
    for (auto x : p) {
        if (tot) {
            i64 cnt = 0, tmp = tot;
            while (tmp) {
                tmp >>= 1;
                cnt ++;
            }

            if (cnt + pre - x >= 50) {
                break;
            }

            tot *= ksm(2, pre - x, LLONG_MAX);
        }

        pre = x;

        if (tot >= mp[x]) {
            tot -= mp[x];
            continue;
        }

        mp[x] -= tot;
        i64 f = (mp[x] + m - 1) / m;
        res = (res + f % mod * ksm(2, x, mod) % mod) % mod;
        tot = f * m - mp[x];
    }

    std::cout << res << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int _ = 1;
    for (std::cin >> _; _; _ --) 
        solve();

    return 0;
}

/*
2
5 4
3 0
2 3
3 1
1 3
2 1
2 20250427
1000000000 1000000000
114514 1919810
*/