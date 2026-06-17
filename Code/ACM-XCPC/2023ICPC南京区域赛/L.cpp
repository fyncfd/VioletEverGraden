#include <bits/stdc++.h>

using ll = long long;
using namespace std;

#define rep(i, l, r) for (int i = l; i <= r; i ++)
#define red(i, l, r) for (int i = l; i >= r; i --)
//#define int long long

const int MAXN = 0;
const int N=1e5+10;
struct node
{
    int num,wi,flo;
}a[N];
void solve() {
    int n,k,ans=0;
    cin>>n>>k;
    for(int i=1;i <= n; i++){
        cin>>a[i].num>>a[i].wi>>a[i].flo;
    }

    sort(a+1,a+n+1,[&](node x,node y){
       if(x.flo!=y.flo)
             return x.flo>y.flo;
        else
            return x.wi>y.wi;
    });
    int cnk=k;
    for(int i=1;i<=n;){
        if(cnk>a[i].wi*a[i].num){
            ans+=a[i].flo;
            i++;
        }
        if(cnk==0||cnk<a[i].wi){
            
            continue;
        }
    }
    /*for(int i=1; i<=n; i++){
      cout<<a[i].num<<" "<<a[i].wi<<" "<<a[i].flo<<endl;
    }*/
}

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



/*
2
4 6
1 1 8
7 2 5
1 1 7
3 2 6
8 1200000
100000 1 100000
100000 1 12345
100000 2 100000
100000 2 12345
100000 1 100000
100000 1 12345
100000 2 100000
100000 2 12345

*/