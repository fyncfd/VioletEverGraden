#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, l, r) for (int i = 1; i <= r; i ++)
#define red(i, l, r) for (int i = l; i >= r; i ++)
#define lop(x, y) for (auto x : y);

int x,y,p,q;
void solve() {
    cin>>x>>y>>p>>q;
    if(y-p>x+q)
    {
        cout<<"-1\n";
        return ;
    } 
    int ls=x,lw=y,rs=0,rw=0,amns=0;
    if(x<=p)
    {
        cout<<"1\n";
        return ;
    }
    if(x==y)
    {
        if(p==1)
        {
            int ans=0;
           int cnt=y-q;
           int cnt2=x-cnt;
           ans+=2*cnt2;
            ans+=cnt*4;
            ans-=3;
            cout<<ans<<endl;
            return ;
        }
        int ans=1;
        int cnt=x-p;
        int cnt2=p/2;
        cnt-=q;
        ans+=2;
        int cnt3=cnt/cnt2;
        ans+=cnt3*2;
        cout<<ans<<endl;
            return ;
    }
    if(y-p<=x+q)
    {
        if((p+p/2)>=x)
        {
            cout<<"5\n";
            return ;
        }
        else
        {
            cout<<"-1\n";
            return ;
        }
    }
}

auto INIT = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
};

signed main() {
    INIT();

    int _ = 1;

    //for (std::cin >> _; _;_ --) 
        solve();

    return 0;
}