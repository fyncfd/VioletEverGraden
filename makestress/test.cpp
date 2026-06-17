#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long LL;
typedef double db;
typedef pair<ll,ll> p;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define red(i, l, r) for (int i = l; i >= r; i--)

#define int long long
const double eps = 1e-9;
const ll inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
const ll MOD = 1e9 + 7;
int d[4][2] = { {0,1},{0,-1},{1,0},{-1,0}};
const int MAXN = 0;

void solve(){
    int  a,b;
    cin >> a >> b;
    int c=a^b;
    int ma=max(a,b),mi=min(a,b);
    if(a==0){
        cout << b << endl;
        return;
    }
    if(b==0){
        cout << a << endl;
        return;
    }
    while(c<ma){
        mi=mi >> 1;
        c=ma^mi;
    }
    cout << c << endl; 
}

signed main(){
  ios::sync_with_stdio(false); 
    cin.tie(NULL);       
   int t;
   cin >> t;
   while(t--){
     solve();
   } 
   return 0;  
}