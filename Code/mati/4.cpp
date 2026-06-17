#include<bits/stdc++.h> 
using ll = long long;
#define int long long
const ll mod = 998244353;
ll n, m;
std::vector<int> a;
std::vector<int> b;
void solve() {
    std::cin >> n >> m;
    a.resize(n + 1);
    b.resize(m + 1);
    for (int i = 1; i <= n; i ++) {
        std::cin >> a[i];
    }
    for (int i = 1; i <= m; i ++) {
        std::cin >> b[i];
    }

    std::map<ll, std::vector<int>> pos;
    for (int i = 1; i <= n; i ++) {
        pos[a[i]].push_back(i);
    }

    int pos1 = 0; int pos2 = 0;

    if (pos[b[1]].size() < 2) {
        std::cout << "No\n";
        return ;
    } 
    pos1 = pos[b[1]][0]; pos2 = pos[b[1]][1];

    for (int i = 2; i <= m; i ++) {
        if (pos[b[i]].size() < 2) {
            std::cout << "No\n";
            return ;
        }

        if (pos1 > pos[b[i]][0] or pos2 > pos[b[i]][1]) {
            std::cout << "No\n";
            return ;
        }
        pos1 = pos[b[i]][0]; pos2 = pos[b[i]][1];
    }

    std::cout << "Yes\n";
    
}

signed main( ) {
    int _ = 1;
    //std::cin >> _;
    while (_ --) {
        solve();
    }

    return 0;
}