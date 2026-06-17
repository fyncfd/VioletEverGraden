#include<bits/stdc++.h> 

using i64 = long long;

#define int long long

signed main( )
{
    int n;
    std::cin >> n;

    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++) {
        std::cin >> a[i];
    }

    std::vector<int> ans;
    int jw = 0;
    for (int p = 4; p <= 7; p ++) {
        int cnt = jw;
        for (int i = 1; i <= n; i ++) {
            if ((a[i] >> p) & 1) {
                cnt += 1;
            } else {
                cnt += 0;
            }
        }
        jw = cnt / 2;
        cnt %= 2;
        // std::cout << "p:" << p << ' ' << "cnt:" << cnt << '\n';
        ans.push_back(cnt);
    }

    for (int p = 0; p <= 3; p ++) {
        int cnt = jw;
        for (int i = 1; i <= n; i ++) {
            if ((a[i] >> p) & 1) {
                cnt += 1;
            } else {
                cnt += 0;
            }
        }
        jw = cnt / 2;
        cnt %= 2;
        ans.push_back(cnt);
    }
    
    while (jw) {
        // std::cout << "???\n";
        ans.push_back(jw % 2);
        jw /= 2;
    }

    i64 res = 0;
    for (int i = 0; i < ans.size(); i ++) {
        res += ans[i] * std::pow(2, i);
    } 
    std::cout << res << '\n';

    // std::cout << "2555 * 5 = " << 255 * 5 << '\n';

    return 0;
}