#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, l, r) for (int i = l; i <= r; i ++)
#define red(i, l, r) for (int i = l; i >= r; i --)
#define FOR(i, l, r, x) for (int i = l; i <= r; i += x)
#define ROF(i, l, r, x) for (int i = l; i >= r; i -= x)

ll n;

void solve() {
    cin>>n;
    std::vector<int> a(n + 1);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int cnt1=4,cnt2=4;
    int ans1=0,ans2=0;
    for(int i=2;i<=n;i++)
    {
        if(a[i]==a[i-1])
        {
            ans1++;
        }
        else
        {
            if(cnt1<=0)
            {
                break;
            }
            else
            {
                ans1++;
                cnt1--;
            }
        }
    }
    for(int i=n-1;i>=1;i--)
    {
        if(a[i]==a[i+1])
        {
            ans2++;
        }
        else
        {
            if(cnt2<=0)
            {
                break;
            }
            else
            {
                ans2++;
                cnt2--;
            }
        }
    }
    cout<<min(ans1,ans2)<<endl;

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



*/