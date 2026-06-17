#include <bits/stdc++.h>
using namespace std;
#define int  long long
#define endl '\n'
#define rep(i, l, r) for (int i = l; i <= r; i ++)
int ff[1000];
vector<int> get(int x){
    vector<int> v;
    while(x > 0){
        v.push_back(x % 3);
        x /= 3;
    }
    //reverse(v.begin(), v.end());
    return v;
}
int f(int x){
    if(x == 0) return 1ll;
    if(x > 0 && x % 3 == 0) return f(x / 3) + 1ll;
    if(x > 0 && x % 3 != 0) return f(x - 1) + 1ll;
}
void solve(){
    int l, r;
    cin >> l >> r;
    //for(l = 1; l <= 1000; l++) for(r = l + 3; r <= 1000; r++){
    auto L = get(l), R = get(r);
    if(L.size() < R.size()){
        int ans = 3*(R.size() - 1) + (R.back() - 1) + (R.back() != 1);
        ans = max(ans, f(r));
        int sum = R.back() + 1;
        for(int i = R.size() - 2; i >= max(1ll, (int)L.size() - 1); i--){
            if(R[i] >= 1){
                ans = max(ans, sum + 3ll * i + R[i]);
            }
        }
        // int MAX = 0, pos = 0;
        // for(int i = 1; i <= r; i++){
        //     if(ff[i] > MAX) pos = i;
        //     MAX = max(MAX, ff[i]);
        // }
        // if(MAX != ans) {
        //     cout << MAX << " " << ans << " ";
        //     cout << l << " " << r << " ";
        //     cout << pos << "?\n";
        // }
        //cout << MAX << "|";
        cout << ans << "\n";
    }else{
        int ans = 0;
        for(int i = R.size() - 1; i >= 0; i--){
            if(R[i] == L[i]){
                ans += R[i] + 1ll;
            }else{
                ans += 3ll * i + R[i];
                break;
            }
        }
        cout << max(f(r), ans) << "\n";
    }
    //}
}

signed main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t = 1;
    cin >> t;
    ff[0] = 1;
    for(int i = 1; i <= 1000; i++){
        if(i % 3 == 0) ff[i] = ff[i / 3] + 1;
        else ff[i] = ff[i - 1] + 1;
    }
    while(t--)solve();
    return 0;
}