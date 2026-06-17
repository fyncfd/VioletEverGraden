#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, l, r) for (int i = 1; i <= n; i ++)
#define red(i, l, r) for (int i = l; i >= n; i --)
contst int n=1e5+10;
struct node
{
    int fi;
    int se;
    int id;
};
int newa2[N],dlda3[N],newa3[N];
bool cmp(node X,node Y)
{
    if(X.fi!=Y.fi)
    {
        return X.fi<Y.fi;
    }
    else
    {
        return X.se<Y.se;
    }
}
void solve() {
    int n, a, b, c;
    std::cin >> n >>a >> b >> c;
    std::vector<node> x, y, z;
    for (int i = 0; i < n; i++) {
        int x0, y0, z0, x1, y1, z1;
        std::cin >> x0 >> y0 >> z0 >> x1 >> y1 >> z1;
        x.push_back({std::min(x0, x1), std::max(x0, x1)});
        y.push_back({std::min(y0, y1), std::max(y0, y1)});
        z.push_back({std::min(z0, z1), std::max(z0, z1)});
        x[i].id=i;
        y[i].id=i;
        z[i].id=i;
    }
    sort(x.begin(),x.end(),cmp);
    sort(y.begin(),y.end(),cmp);
    sort(z.begin(),z.end(),cmp);
    for(int i=0;i<n;i++)
    {
        newa1[x[i].id]=i;
        newa2[y[i].id]=i;
        newa3[z[i].id]=i;
    }
    int ans = 0;
    int a1 = 0;
    for (int i = 0; i < n; i++) {
        newa1[x[i].fi] ++;
        mp[x[i].second + 1] -= 1;
    }
    for (auto o:mp) {
        a1 += o.second;
        ans = std::max(a1, ans);
    }
}

auto __init__ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
};

signed main() {
    __init__();

    int _ = 1;
    // for (std::cin >> _; _; _ --) 
        solve();

    return 0;
}


/*
3 2 2 2
1 1 0 1 1 2
1 0 1 1 2 1
0 1 1 2 1 1

3


4 10 4 10
0 4 6 6 4 4
10 2 10 8 4 4
0 4 0 2 4 0
0 0 10 0 2 10


3
*/
