#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++) {
        std::cin >> a[i];
    }

    std::sort(a.begin() + 1, a.end(), [&](int a, int b) -> bool {
        return a < b;
    });

    auto find = [&](int x) -> int {
        int l = 1; int r = a[n];
        
        int ans = 0;
        while (l <= r) {
            int mid = l + r >> 1;
            
            if (mid < x) {
                l = mid + 1;
                ans = mid;
            } else {
                r = mid - 1;
            }
        }

        return ans;
    };

    int ans = 1;
    for (int i = 1; i <= n; i ++) {
        for (int j = i + 1; j <= n; j ++) {
            int p = a[i] + a[j];
            if (p & 1) {
                continue;
            }

            p >>= 1;
            int idl = std::lower_bound(a.begin() + 1, a.end(), p) - (a.begin() + 1);
            if (idl + 1 == n or a[idl + 1] != p) {
                continue;
            } 
            int idr = std::lower_bound(a.begin() + 1, a.end(), p + 1) - (a.begin() + 1) - 1;

            int l = idl + 1 - i; int r = j - idr - 1;
            int tmp = idr - idl + 1;

            if (l < r) {
                int dif = std::min(r - l, tmp);
                l += dif;
                tmp -= dif;
                r = l;
            }

            if (l > r) {
                int dif = std::min(l - r + 1, tmp);
                r += dif;
                tmp -= dif;
                l = r - 1;
            }
            
            ans = std::max(ans, l + r + tmp);
        }
    }

    std::cout << ans << '\n';
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
4
7
3 5 9 8 2 11 5
7
7 9 2 4 17 10 15
1
100
2
100 100
*/