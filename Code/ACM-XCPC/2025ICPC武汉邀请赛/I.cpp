#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, l, r) for (int i = 1; i <= n; i ++)
#define red(i, l, r) for (int i = l; i >= n; i --)

void solve() {
    int n, k;
    std::cin >> n >> k;
    if (k < n or k > n * (n - 1) + 1) {
        std::cout << "No\n";
        return ;
    }
    int cnt=1;
    cout<<"Yes\n";
    bool vis[200005]={0};
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j)
            {
                cout<<k<<" ";
                vis[k]=1;
                k++;
                
            }
            else
            {
                if(!vis[cnt])
                {
                    cout<<cnt<<" ";
                    cnt++;
                }
                else
                {
                    cnt+=n;
                    cout<<cnt<<" ";
                    cnt++;
                }
            }
        }cout<<endl;
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
    for (std::cin >> _; _; _ --) 
        solve();

    return 0;
}

/*
4
3 5
4 10
5 2
1 1


Yes
4 2 5
7 1 9
8 6 3Yes
4 2 5
7 1 9
8 6 3
Yes
14 9 2 13
1 11 16 8
10 3 7 5
6 15 4 12
No
Yes
1

Yes
14 9 2 13
1 11 16 8
10 3 7 5
6 15 4 12
No
Yes
1


*/