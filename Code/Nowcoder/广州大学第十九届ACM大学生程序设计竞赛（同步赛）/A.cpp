#include <bits/stdc++.h>

#define rep(i, l, r) for(int i = l; i <= r; i ++)

int n, m;
std::vector<std::vector<char>> s;

void solve() {
    std::cin >> n >> m;
    s.resize(n + 1, std::vector<char>(m + 1));
    rep(i, 1, n) {
        rep(j, 1, m) {
            std::cin >> s[i][j];
        }
    }

    int i = 1; int j = 1;
    std::vector<char> ans;
    while (i <= n) {
        if (i & 1) {
            ans.push_back(s[i][j]);
            j ++;
            if (j > m) { 
                i ++;
                j = m;
            }
        }
        else {
            ans.push_back(s[i][j]);
            j --;
            if (j < 1) {
                i ++;
                j = 1;
            }
        }
    }

    int num = 0;
    rep(i, 0, (int)ans.size() - 4) {
        if (i + 3 < ans.size() && 
            ans[i] == 'G' && 
            ans[i + 1] == 'Z' && 
            ans[i + 2] == 'H' && 
            ans[i + 3] == 'U') {
            num ++;
        }
    }

    std::cout << num << '\n';
}

signed main() {
    std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);

    int _ = 1;
    //std::cin >> _;

    while (_ --) {
        solve();
    }

    return 0;
}