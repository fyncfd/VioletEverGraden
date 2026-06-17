#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr ll LINF = 0x3f3f3f3f3f3f3f3fLL;
ll n,m;
void solve(){
    cin>>n>>m;
    vector<ll>pre(n+1,0);
    vector<ll>a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]+a[i];
    }
    ll minn=LINF;
    for(int i=1;i<=n-m+1;i++){
        ll temp=pre[i+m-1]-pre[i-1];
        if(temp<minn){
            minn=temp;
        }
    }
    cout<<minn<<'\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
//     int t;
//     cin>>t;
//     while(t--){
         solve();
//     }
    return 0;
}