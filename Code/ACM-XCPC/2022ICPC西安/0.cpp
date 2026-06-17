#include <bits/stdc++.h>
using namespace std;
#define int  long long
#define endl '\n'
#define rep(i, l, r) for (int i = l; i <= r; i ++)

void solve(){
    int n;
    cin >> n;
    int fa[n + 10], in[n + 10];
    memset(in, 0, sizeof in);
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        fa[i + 1] = x;
        in[x]++;
    }
    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(in[i] == 0){
            q.push(i);
        }
    }
    int res = n, cnt = 0;
    while(!q.empty()){
        res = min(res, cnt + (int)q.size());
        int now = q.front();
        q.pop();
        in[fa[now]]--;
        if(in[fa[now]] == 0){
            q.push(fa[now]);
        }
        cnt++;
    }
    cout << res << "\n";
}

signed main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t = 1;
    cin >> t;

    while(t--)solve();
    return 0;
}