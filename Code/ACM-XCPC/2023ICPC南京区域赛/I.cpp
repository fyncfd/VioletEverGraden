#include <bits/stdc++.h>

using ll = long long;
using namespace std;

#define rep(i, l, r) for (int i = l; i <= r; i ++)
#define red(i, l, r) for (int i = l; i >= r; i --)
//#define int long long

const int MAXN = 0;
struct pii
{
    int x,y;
};
bool cmp(pii a,pii b){
    return a.x<b.x;
}

void solve() {
    int n,m;
    std::cin>>n>>m;
    std::vector<pii>a(m+1);
    a[0].x=0,a[0].y=0;
    for(int i=1;i<=m;i++){
        std::cin>>a[i].x>>a[i].y;
    }
    sort(a.begin(),a.end(),cmp);
    for(int i=1;i<=m;i++){

        if(a[i].x<a[i].y){
            cout<<"No\n";
            return ;
        }

        if(a[i].x== (a[i-1].x+1) ){
            if(a[i-1].y!=0&&a[i].y==1){
                cout<<"No\n";
                return ; 
            }
        }

        int cnt=a[i].x-(a[i-1].x+1);
        if( (a[i].y==(a[i-1].y+cnt+1))){
            continue;
        }
        if(a[i].y>cnt)
        {
            cout<<"No\n";
            return ;
        }
    }
    cout<<"Yes\n";
    
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


3
7 4
4 0
2 2
7 1
5 1
3 2
2 2
3 1
3 1
3 100





Yes3
7 4
4 0
2 2
7 1
5 1
3 2
2 2
3 1
3 1
3 100
No
No
*/