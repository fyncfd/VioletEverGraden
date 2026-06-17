#include <bits/stdc++.h>

using ll = long long;
using namespace std;

#define rep(i, l, r) for (int i = l; i <= r; i ++)
#define red(i, l, r) for (int i = l; i >= r; i --)
#define int long long

const int MAXN = 0;
ll n, m;
//std::vector<int> p;

/*void solve() {
    std::cin >> n >> m;
    std::vector<std::vector<int>> op(n + 1);
    rep(i, 1, n) {
        int x; cin >> x;
        while(x -- ) {
            int pos; cin >> pos;
            op[i].push_back(pos);
        }
    }

    std::vector<bool> st(m + 1);
    std::vector<int> cnt(m + 1);
    for(auto t : op[n]) {
        cnt[t] ++ ;
    }

    bool ok = false;
    red(i, n - 1, 1) {
        bool ok = true;
        for (auto t : op[i]) {
            if(st[t]) {
                continue;
            }
            cnt[t] ++ ;
            if(cnt[t] > 1) {
                ok = false;
            }
        }

        for (auto t : op[i + 1]) {
            if (st[t]) {
                continue;
            }
            cnt[t] -- ; st[t] = true;
        }

        if (ok) {
            std::cout << "Yes\n";
            rep(j, 1, i - 1) {
                cout << j << ' ';
            }
            std::cout << i + 1 << ' ' << i;
            rep(j, i + 2, n) {
                std::cout << ' ' << j;
            }
            std::cout << '\n';
            return ;
        }
    }
    std::cout << "No\n";
}*/
void solve();

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int _ = 1;
    //std::cin >> _;

    for (std::cin >> _; _; _ --) 
        solve();
    
        return 0;
}



void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> op(n + 1);
    for(int i = 1; i <= n; i ++ ) {
        int x; cin >> x;
        while(x -- ) {
            int pos; cin >> pos;
            op[i].push_back(pos);
        }
    }
    vector<bool> st(m + 1);
    vector<int> cnt(m + 1);

    for(auto t : op[n]) cnt[t] ++ ;

    bool flag = false;
    for(int i = n - 1; i >= 1; i -- ) {
        bool flag = true;
        for(auto t : op[i]) {
            if(st[t]) continue;
            cnt[t] ++ ;
            if(cnt[t] > 1) flag = false;
        }
        for(auto t : op[i + 1]) {
            if(st[t]) continue;
            cnt[t] -- ; st[t] = true;
        }
        if(flag) {
            cout << "Yes\n";
            for (int j = 1; j <= i - 1; j ++ ) cout << j << ' ';
            cout << i + 1 << ' ' << i;
            for (int j = i + 2; j <= n; j ++ ) cout << ' ' << j;
            cout << '\n';
            return;
        }
    }
    cout << "No\n";
}

/*
3
3 6
3 3 1 5
2 5 3
2 2 6
2 3
3 1 3 2
2 3 1
1 3
2 2 1





Yes
3 1 2
No
No

*/