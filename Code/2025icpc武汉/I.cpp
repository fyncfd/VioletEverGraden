#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
int n,k;
void solve() {
    cin>>n>>k;
    // cout<<n<<k<<endl;
    // return;
    if(n==1){
        if(k==1){
            cout<<"Yes"<<endl;
            cout<<1<<endl;
            return;
        }
        else{
            cout<<"No"<<endl;
            return;
        }
    }
    int m[n+6][n+6];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            m[i][j]=-1;
        }
    }
    int cnt=1;
    int t=n*n-n+1;
    // cout<<t<<endl;
    for(int i=1;i<=n;i++){
        m[i][i]=t;
        t++;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(m[i][j]==-1){
                m[i][j]=cnt;
                cnt++;
            }
        }
    }
    // cout<<n<<k<<endl;
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout<<m[i][j]<<" \n"[j==n];
    //     }
    // }
    if(k<n||k>n * n - n+1){
        cout<<"No"<<endl;
        return;
    }
    int nx,ny;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(m[i][j]==k){
                nx=i;
                ny=j;
                break;
            }
        }
    }
    // cout<<nx<<" "<<ny<<endl;
    // return;
    swap(m[1][1],m[nx][ny]);
    // int k=m[1][1];
    cout<<"Yes"<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<m[i][j]<<" \n"[j==n];
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int _ = 1;
    for (std::cin >> _; _; _ --) 
        solve();

    return 0;
}

/*
4
3 5
4 10
5 2
1 1
*/