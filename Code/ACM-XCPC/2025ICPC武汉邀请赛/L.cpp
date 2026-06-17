#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, l, r) for (int i = 1; i <= n; i ++)
#define red(i, l, r) for (int i = l; i >= n; i --)

int n;
std::vector<int> a;
void solve() {
    std::cin >> n;
    a.resize(n + 1);
    rep(i, 1, n) {
        std:;cin >> a[i];
    }

    std::sort(a.begin() + 1, a.end(), [&](int a, int b) {
        return a < b;
    });

    // auto check = [&](int mid, int p) {
    //     if (mid > p) {
    //         return 
    //     }
    // };

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
    rep(i, 1, n) {
        rep(j, i + 1, n) {
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
            int temp = idr - idl + 1;
            
            if (l < r) {
                int dif = std::min(r - l, temp);
                l += dif;
                temp -= dif;
                r = l;
            }
            
            if (l > r) {
                int dif = std::min(l - r + 1, temp);
                r += dif;
                temp -= dif;
                l = r - 1;
            }
            
            ans = std::max(ans, l + r + temp);
        }
    }

    std::cout << ans << '\n';
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
4
7
3 5 9 8 2 11 5
7
7 9 2 4 17 10 15
1
100
2
100 100


5
4
1
2

*/