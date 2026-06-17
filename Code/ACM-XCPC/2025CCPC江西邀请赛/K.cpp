#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, l, r, x) for (int i = l; i <= r; i += x)

int a[1000005];
void solve() {
    int n;
    cin>>n;
    vector<int> a1,a2,a3,a0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]%4==1)
        {
            a1.push_back(i);
        }
        else if(a[i]%4==2)
        {
            a2.push_back(i);
        }
        else if(a[i]%4==3)
        {
            a3.push_back(i);
        }
        else
        {
            a0.push_back(i);
        }
    }
   
    /*if(a1.size()> ( a2.size()*2+a3.size() ) )
    {
        cout<<"-1"<<endl;
        return ;
    }
    if( ((a3.size()-a1.size())/2) >a2.size())
    {
        cout<<"-1\n";
        return ;
    }*/
    int c1=0,c2=0,c3=0;
    std::vector<int> ans;
    int mo=0;
    for(auto x:a0)
    {
        ans.push_back(x);
    }

    for(int i=1;i<=(n-a0.size());i++)
    {
        if(mo==0)
        {
            
            if(c3<a3.size())
            {
                ans.push_back(a3[c3++]);
                mo=3;
            }
            else if(c2<a2.size())
            {
                ans.push_back(a2[c2++]);
                mo=2;
            }
            else{
                cout<<"-1\n";
                return ;
            }
        }
        else if(mo==2)
        {
            
            if(c1<a1.size())
            {
                ans.push_back(a1[c1++]);
                mo=3;
            }
            else if(c2<a2.size())
            {
                ans.push_back(a2[c2++]);
                mo=0;
            }
            else
            {
                cout<<"-1\n";
                return ;
            }
        }
        else if(mo==3)
        {
           
            if(c1<a1.size())
            {
                ans.push_back(a1[c1++]);
                mo=0;
            }
            else if(c3<a3.size())
            {
                ans.push_back(a3[c3++]);
                mo=2;
            }
            else
            {
                cout<<"-1\n";
                return;
            }
        }
    }
    for(auto x:ans)
    {
        cout<<x<<" ";
    }cout<<endl;
   
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
3
4
4 6 3 3
4
1 3 3 1
4
1 1 1 1


3 1 4 2
2 3 4 1
‐1

1
4
4 6 3 3
*/