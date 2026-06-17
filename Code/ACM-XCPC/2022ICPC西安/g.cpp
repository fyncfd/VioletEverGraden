#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define rep(i, l, r) for (int i = l; i <= r; i ++)
const int N=1e5+10;
const int NN=650;
int f[N][2];
string s[N];
vector<int>a[NN][30];
vector<int>b[NN][30];
vector<int>aa[NN][30][30];
vector<int>bb[NN][30][30];
vector<int>aa[NN][30][30];
vector<int>bb[NN][30][30];
vector<int>e[NN];
void solve(){
    int n;cin>>n;
    int cnt=0;
    rep(i,1,n){
        cin>>s[i];
        int len=s[i].size();
        if(len>=NN)continue;
        cnt=max(cnt,len);
        if(len==1){
            e[len].push_back(i);
            f[i][0]=1;
            f[i][1]=1;
        }
        else if(len==2){
            e[len].push_back(i);
            a[len][s[i][0]-'a'].push_back(i);
            b[len][s[i][1]-'a'].push_back(i);
        }
        else{
            e[len].push_back(i);
            aa[len][s[i][0]-'a'][s[i][1]-'a'].push_back(i);
            bb[len][s[i][1]-'a'][s[i][2]-'a'].push_back(i);
        }
    }
    int ans=0;
    rep(i,1,cnt){
        bool flag=0;
        for(auto it:e[i]){
            // cout<<it<<'_'<<endl;
            if(f[it][0]==1&&f[it][1]==1){
                flag=1;
                string d=s[it];
                if(i>=2){
                    for(auto it1:aa[i+1][d[0]-'a'][d[1]-'a']){
                    string dd=s[it1];dd.pop_back();
                        if(dd==d){
                            f[it1][0]=1;
                        }
                    }
                    for(auto it2:bb[i+1][d[0]-'a'][d[1]-'a']){
                        string dd=s[it2];
                        dd[0]='a';
                        string ddd='a'+d;
                        // cout<<it2<<' '<<dd<<' '<<d<<endl;
                        if(dd==ddd){
                            f[it2][1]=1;
                        }
                    }
                    continue;
                }
                for(auto it1:a[i+1][d[0]-'a']){
                    string dd=s[it1];dd.pop_back();
                    // cout<<it1<<' '<<dd<<' '<<d<<endl;
                    if(dd==d){
                        f[it1][0]=1;
                    }
                }
                for(auto it2:b[i+1][d[0]-'a']){
                    string dd=s[it2];
                    dd[0]='a';
                    string ddd='a'+d;
                    // cout<<it2<<' '<<dd<<' '<<d<<endl;
                    if(dd==ddd){
                        f[it2][1]=1;
                    }
                }
            }
        }
        // cout<<flag<<endl;
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