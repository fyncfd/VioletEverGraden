#include <bits/stdc++.h>

using namespace std;
#define int long long

int n, m, k;
int f[200005];
int x, y;

void solve() {
    cin >> n >> m >> k;
    map<int, bool> vis;
    memset(f, 0, sizeof f);
    for(int i = 1; i <= n; i ++) {
        cin >> f[i];
        vis[f[i]] = true;
    }

    vector<int> num(k + 1);
    long long ans = 0;
    map<pair<int, int>, int> mp;
    while (m --) {
        cin >> x >> y;

        if(vis[x] and vis[y]) {
            ans ++;
        }
        else if (vis[x]) {
            num[y] ++;
        }
        else if (vis[y]) {
            num[x] ++;
        }
        else {
            if (x < y) {
                swap(x, y);
            }
            if (x != y) {
                mp[{x, y}] ++;
            }
            else {
                num[x] ++;
            }
        }
    }

    vector<int> sum(k + 1);
    for(auto &x: mp) {
        auto [a, b] = x.first;
        sum[a] = max(sum[a], num[a] + num[b] + x.second);
        sum[b] = max(sum[b], num[a] + num[b] + x.second);
    }

    long long res = 0;
    vector<int> temp(k + 1);
    for(int i = 1; i <= k; i ++) {
        if (!vis[i]) {
            res = max(res, sum[i]);
            temp.push_back(num[i]);
        }
    }
    sort(temp.begin(), temp.end(), greater<int>());

    if (temp.size() >= 2) {
        res = max(res, temp[0] + temp[1]);
    }
    else if (temp.size()) {
        res = max(res, temp[0]);
    }

    cout << ans + res << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _ = 1;
    cin >> _;

    while (_ --) {
        solve();
    }
    return 0;
}