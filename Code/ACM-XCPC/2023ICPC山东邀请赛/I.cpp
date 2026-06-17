#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define reo(i, l, r) for (int i = l; i <= r; i ++)
#define red(i, l, r) for (int i = l; i >= r; i --)
//define int long long;
const int MAXN = 0;


void solve() {
    int a,b;
    cin>>a>>b;
    if(a==0)
    {
        if(b>=6 and b<=18)
        {
            cout<<"Yes"<<endl;
            return ;
        }
        else
        {
            cout<<"No"<<endl;
             return ;
        }
    }
    else if(a==1 or a==4)
    {
        if(b>=4 and b<=12)
        {
            cout<<"Yes"<<endl;
             return ;
        }
        else 
        {
            cout<<"No"<<endl;
             return ;
        }
    }
    else if (a==3 or a==12 or a==9 or a==6)
    {
        if(b==0)
        {
            cout<<"Yes"<<endl;
             return ;
        }
        else
        {
            cout<<"No"<<endl;
             return ;
        }
    }
    else if(a==2 or a==8 or a==5)
    {
        if(b==2 or b==3 or b==5 or b==6)
        {
            cout<<"Yes"<<endl;
             return ;
        }
        else
        {
            cout<<"No"<<endl;
             return ;
        }
    }
    cout<<"No"<<endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);

    int _ = 1;
    //for (std::cin >> _; _; _ --)
        solve();
    
    return 0;
}