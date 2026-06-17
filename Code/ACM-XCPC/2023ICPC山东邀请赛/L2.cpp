#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define reo(i, l, r) for (int i = l; i <= r; i ++)
#define red(i, l, r) for (int i = l; i >= r; i --)
//define int long long;
const int MAXN = 0;

int n, a, b;
void solve() {
    std::cin >> n >> a >> b;
    int u = a; int d = a;
    int l = b; int r = b;
    std::cout << "Yes\n";
    std::cout << n - 1 << '\n';

    int num = 1;
    while (num < n) {
        if (u > 1 and l > 1) {
            std::cout << -- u << ' ' << -- l << ' ' << num << ' ' << num << '\n';
        } else if (u > 1 and r < n) {
            std::cout << -- u << ' ' << ++ r << ' ' << num << ' ' << -num << '\n';
        } else if (l > 1 and d < n) {
            std::cout << ++ d << ' ' << -- l << ' ' << -num << ' ' << num << '\n';
        } else {
            std::cout << ++ d << ' ' << ++ r << ' ' << -num << ' ' << -num << '\n';
        }

        num ++;
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);

    int _ = 1;
    //for (std::cin >> _; _; _ --)
        solve();
    
    return 0;
}