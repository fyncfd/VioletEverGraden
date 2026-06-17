#include<bits/stdc++.h>
#define int long long
#define double long double
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define dep(i,r,l) for(int i=r;i>=l;i--)
#define lowbit(x) ((x)&-(x))
#define pb push_back
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin()+1,x.end()
using namespace std;
using VI=vector<int>;
using VVI=vector<vector<int>>;
using PII=pair<int,int>;
using PQI=priority_queue<int>;
using MI=map<int,int>;
// Author:@RainStormZZ
const int MAX=0x3f3f3f3f3f3f3f3f;
const int INF=-0x3f3f3f3f3f3f3f3f;
const int mod=1e9+7;
const int MOD=998244353;
const int N=2e5+9;
// const int fx[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
// const int fx[8][2]={{-1,-1},{0,-1},{1,-1},{-1,0},{1,0},{-1,1},{0,1},{1,1}};
// const int fx[8][2]={{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{2,-1},{1,2},{2,1}};
/*----------------------------global variable & function----------------------------*/
int n,m,q;
int x,y,g;
int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b,a%b);
}
/*---------------------------------------code---------------------------------------*/
void Rainstorm()
{
    cin>>n>>m>>q;
    VI ans(N,0);
    rep(i,1,n){
        cin>>x>>y>>g;
        if(ans[x]==0) ans[x]=g;
        if(ans[y]==0) ans[y]=g;
        ans[x]=lcm(ans[x],g);
        ans[y]=lcm(ans[y],g);
    }
    rep(i,1,q){
        cin>>x>>y;
        if(ans[x]==0||ans[y]==0){
            cout<<1<<endl;
        }
        else cout<<gcd(ans[x],ans[y])<<endl;
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int _=1;
    cin>>_;
    while(_--){
        Rainstorm();
    }
    return 0;
}