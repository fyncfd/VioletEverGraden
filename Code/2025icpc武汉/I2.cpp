#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;

    if (k > n * n - n + 1 || k < n) {
        std::cout << "No\n";
        return ;
    }

    std::vector<std::vector<int>> g(n + 1, std::vector<int> (n + 1));
    std::vector<bool> vis(n * n + 1, false);
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