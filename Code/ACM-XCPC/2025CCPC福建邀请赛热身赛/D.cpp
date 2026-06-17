#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, l, r) for (int i = l; i <= r; i ++)
#define red(i, l, r) for (int i = l; i >= r; i --)
#define FOR(i, l, r, x) for (int i = l; i <= r; i += x)
#define ROF(i, l, r, x) for (int i = l; i >= r; i -= x)

int a[105];
int n;
void solve() {
    cin>>n;
    bool op1=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==1)
        {
            op1==1;
        }
    }
    if(op1)
    {
        cout<<n-1<<endl;
        return ;
    }
    sort(a+1,a+n+1);
    int cnt=gcd(a[1],a[2]);
    bool op2=0;
    for(int i=2;i<=n;i++)
    {
        if(a[i]== a[i-1]+1 )
        {
            op2=1;
        }
        cnt=gcd(cnt,a[i]);
    }
    if(cnt==a[1])
    {
        cout<<n-1<<endl;
        return ;
    }
    if(op2)
    {
        cout<<n<<endl;
        return ;
    }
    cout<<n+1<<endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int _ = 1;
    for (std::cin >> _; _; _ --)
        solve();

    return 0;
}
/*

2
4
2 3 5 7
4
2 4 6 8


4
3
*/