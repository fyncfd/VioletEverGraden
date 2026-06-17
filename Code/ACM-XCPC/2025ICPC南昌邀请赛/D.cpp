#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, l, r) for (int i = 1; i <= n; i ++)
#define red(i, l, r) for (int i = l; i >= n; i --)
int nm( vector<pair<int, int>> p)
{
    priority_queue<int,vector<int>,greater<> > q;
    int cnt=0;
    for(auto x:p)
    {
       int L=x.first,R=x.second;
       while(q.size()&&q.top()<L)
                q.pop();
        q.push(R);
        cnt=max((int)q.size(),cnt);
    }
    return cnt;
}
void solve() {
    int n, a, b, c;
    std::cin >> n >>a >> b >> c;
    std::vector<std::pair<int, int>> x, y, z;
    for (int i = 0; i < n; i++) {
        int x0, y0, z0, x1, y1, z1;
        std::cin >> x0 >> y0 >> z0 >> x1 >> y1 >> z1;
        x.push_back({std::min(x0, x1), std::max(x0, x1)});
        y.push_back({std::min(y0, y1), std::max(y0, y1)});
        z.push_back({std::min(z0, z1), std::max(z0, z1)});
    }
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    sort(z.begin(),z.end());
    int ans1=nm(x);
    int ans2=nm(y);
    int ans3=nm(z);
    int ans=max(ans1,ans2);
    ans=max(ans,ans3);
    cout<<ans<<endl;
   
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
