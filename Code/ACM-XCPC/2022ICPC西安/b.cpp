#include <bits/stdc++.h>
using namespace std;
#define int  long long
#define endl '\n'
#define rep(i, l, r) for (int i = l; i <= r; i ++)
const int INF = 0x3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int N =3e3+10;
int dis[N], pre[N], preve[N];
struct edge {
    int to, cost, capa, rev;
    edge(int to_, int cost_, int c, int rev_) {
        to = to_; cost = cost_; capa = c; rev = rev_;
    }
};
std::vector<edge> e[N];
void addedge(int from, int to, int cost, int capa) {
    e[from].push_back(edge(to, cost, capa, e[to].size()));
    e[from].push_back(edge(from, -cost, 0, e[to].size() - 1));
}
bool spfa(int s, int t, int cnt) {
    bool inq[N];
    memset(pre, -1, sizeof pre);
    rep(i, 1, cnt) {
        dis[i] = INF; inq[i] = false;
    }
    dis[s] = 0;
    queue<int> Q;
    Q.push(s);
    inq[s] = true;
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        inq[u] = false;
        for (int i = 0; i < e[u].size(); i ++) {
            if (e[u][i].capa > 0) {
                int v = e[u][i].to, cost = e[u][i].cost;
                if (dis[u] + cost < dis[v]) {
                    dis[v] = dis[u] + cost;
                    pre[v] = u;
                    preve[v] = i;
                    if (!inq[v]) {
                        inq[v] = true;
                        Q.push(v);
                    }
                } 
            }
        }
    }
    return dis[t] != INF;
}
int mincost(int s, int t, int cnt) {
    int cost = 0;
    while (spfa(s, t, cnt)) {
        int v = t, flow = INF;
        while (pre[v] != -1) {
            int u = pre[v], i = preve[v];
            flow = min(flow, e[u][i].capa);
            v = u;
        }
        v = t;
        while (pre[v ] != -1){
            int u = pre[v], i = preve[v];
            e[u][i].capa -= flow;
            e[v][e[u][i].rev].capa += flow;
            v = u;
        }
        cost += dis[t] * flow;
    }
    return cost;
}
int n,m,s,t,c,d;
int cnt=0;
vector<int>row[N];
vector<int>col[N];
int check(int x){
    s=cnt+n+m+x+2;
    t=s+1;
    rep(i,0,t){
        e[i].clear();
    }
    rep(i,1,n){
        for(auto it:row[i]){
            addedge(it,i+cnt,0,1);
        }
        addedge(i+cnt,cnt+n+m+1,d,inf);
        rep(j,1,x){
            addedge(i+cnt,cnt+n+m+1+j,0,1);
        }
    }
    rep(i,1,m){
        for(auto it:col[i]){
            addedge(it,i+cnt+n,0,1);
        }
        addedge(i+cnt+n,cnt+n+m+1,d,inf);
        rep(j,1,x){
            addedge(i+cnt+n,cnt+n+m+1+j,0,1);
        }
    }
    
    rep(i,0,x){
        addedge(cnt+n+m+1+i,t,0,inf);
    }
    rep(i,1,cnt){
        addedge(s,i,0,1);
    }
    return mincost(s,t,t)+x*c;
}
void solve(){
    cin>>n>>m>>c>>d;
    rep(i,1,n){
        string s;cin>>s;
        for(int j=0;j<m;j++){
            if(s[j]=='.'){
                cnt++;
                row[i].push_back(cnt);
                col[j+1].push_back(cnt);
            }
        }
    }
    int l=0,r=max(n,m);
    int f1,f2;
    int num=0;
    // while(l<r){
    //     num++;
    //     int lp=l+(r-l)/3;
    //     int rp=r-(r-l)/3;
    //     f1=check(lp);
    //     f2=check(rp);
    //     cout<<f1<<' '<<f2<<endl;
    //     if(num>1e2)break;
    //     if(f1<=f2){
    //         r=rp-1;
    //     }
    //     else l=lp+1;
    // }
    cout<<check(l)<<endl;
}

signed main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t = 1;
    // cin >> t;

    while(t--)solve();
    return 0;
}