#include<bits/stdc++.h> 

using i64 = long long;

#define int long long

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::string> s(n + 1);
    for (int i = 1; i <= n; i ++) {
        std::cin >> s[i];
    }

    int ans = 0;
    for (int j = 0; j < m; j ++) {
        std::unordered_map<char, int> cnt;
        int sum = 0;
        for (int i = 1; i <= n; i ++) {
            for (char c = 'a'; c <= 'z'; c ++) {
                if (c != s[i][j]) {
                    sum += cnt[c];
                }
            }
            cnt[s[i][j]] ++;
        }
        ans += sum;
    }

    std::cout << ans << '\n';

    return 0;
}