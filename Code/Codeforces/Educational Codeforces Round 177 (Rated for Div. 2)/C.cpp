#include <bits/stdc++.h>

using ll = long long;

int n;

void solve() {
    std::cin >> n;
    std::vector<int> p(n + 1), d(n);
    for (int i = 1; i <= n; i ++) {
        std::cin >> p[i];
    }
    for (int i = 0; i < n; i ++) {
        std::cin >> d[i];
    }
    
    std::vector<int> cnt(n + 2, 0);
    for (int i = 1; i <= n; i ++) {
        cnt[p[i]] ++;
    }
    
    ll sum = 0; ll max = 0; ll temp = 0;
    for (int v = 1; v <= n; v ++) {
        temp += std::max(0, cnt[v] - 1);
    }
    
    std::vector<bool> a(n + 2, false);
    std::vector<int> res;
    for (int i = 0; i <= n - 1; i ++) {
        int di = d[i];
        int v = p[di];
        cnt[v] --;
        
        if (a[v]) {
            sum --;
            ll odd = std::max(0, cnt[v] + 1 - 1);
            ll ndd = std::max(0, cnt[v] - 1);
            max = max - odd + ndd;
        } 
        else {
            ll odd = std::max(0, cnt[v] + 1 - 1);
            ll ndd = std::max(0, cnt[v] - 1);
            temp += (ndd - odd);
        }
        
        a[di] = true;
        sum += cnt[di];
        ll add = std::max(0, cnt[di] - 1);
        max += add;
        temp -= add;
        
        ll ans = (i + 1) + (sum + (temp - max));
        res.push_back(ans);
    }
    
    for (int i = 0; i <= res.size() - 1; i ++) {
        std::cout << res[i] << " \n"[i == res.size() - 1];
    }
}

signed main() {
    std::cin.tie(nullptr) ->
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int _ = 1;
    std::cin >> _;

    while (_ --) {
        solve();
    }

    return 0;
}
/*
3
3
1 2 3
3 2 1
5
4 5 3 1 2
4 5 1 3 2
7
4 3 1 2 7 5 6
1 2 3 4 5 6 7

1 2 3
2 4 4 5 5
2 4 4 4 6 7 7
*/