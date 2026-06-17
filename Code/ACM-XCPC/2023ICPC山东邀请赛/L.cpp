#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define reo(i, l, r) for (int i = l; i <= r; i ++)
#define red(i, l, r) for (int i = l; i >= r; i --)
//define int long long;
const int MAXN = 0;


void solve() {
   int n,a,b;
   cin>>n>>a>>b;
   int u,d,l,r;
   u=a;
   d=a;
   l=b;
   r=b;
   cout<<"Yes\n"<<n-1<<endl;
   for(int i=1;i< n;i++)
   {
     if(u>1 and l>1)
     {
        u--;
        l--;
        cout<<u<<" "<<l<<" "<<i<<' '<<i<<endl;
     }
     else if(u>1 and r<n)
     {
        u--;
        r++;
        cout<<u<<" "<<r<<" "<<i<<" -"<<i<<endl;
     }
     else if(d<n and r<n)
     {
        r++;
        d++;
        cout<<d<<" "<<r<<" -"<<i<<" -"<<i<<endl;
     }
     else if(d<n and l>1)
     {
        d++;
        l--;
        cout<<d<<" "<<l<<" -"<<i<<" "<<i<<endl;
     }
   }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);

    int _ = 1;
    //for (std::cin >> _; _; _ --)
        solve();
    
    return 0;
}