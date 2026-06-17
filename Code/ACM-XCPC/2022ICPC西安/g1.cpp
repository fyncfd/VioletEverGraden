#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define rep(i, l, r) for (int i = l; i <= r; i ++)
const int N=1e5+10;
const int NN=650;
int f[N][2];
string s[N];
map<string,int>mp;
vector<int>e[NN];
bool cmp(string a,string b){
    int len1=a.size();
    int len2=b.size();
    if(len1==len2){
        return a<b;
    }
    return len1<len2;
}
void solve(){
    int n;cin>>n;
    int cnt=0;
    int ans=0;
    rep(i,1,n){
        cin>>s[i];
    }
    sort(s+1,s+1+n,cmp);
    rep(i,1,n){
        int len=s[i].size();
        if(len>=NN)continue;
        cnt=max(cnt,len);
        if(len==1){
            e[len].push_back(i);
            f[i][0]=1;
            f[i][1]=1;
            mp[s[i]]=1;
            ans=1;
        }
        else{
            e[len].push_back(i);
        }
    }
    rep(i,2,cnt){
        bool flag=0;
        for(auto it:e[i]){
            string d=s[it];
            if(f[it][0]==0){
                string d1=d;d1.erase(0,1);
                
                if(mp[d1]==1){
                    f[it][0]=1;
                }
            }
            if(f[it][1]==0){
                string d1=d;d1.pop_back();
                if(mp[d1]==1){
                    f[it][1]=1;
                }
            }
            if(f[it][0]==1&&f[it][1]==1){
                flag=1;
                mp[d]=1;
            }
        }
        if(flag)ans=i;
        else break;
    }
    cout<<ans<<endl;
}
signed main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)solve();
    return 0;
}