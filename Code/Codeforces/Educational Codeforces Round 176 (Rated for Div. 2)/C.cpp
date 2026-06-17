#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(m);
        for (auto &x : a) cin >> x;
        sort(a.begin(), a.end());
        
        long long total = 0;
        for (int k = 1; k < n; ++k) {
            int s = n - k;
            int ma = max(k, s);
            
            auto kk = lower_bound(a.begin(), a.end(), k);
            int l = a.end() - kk;
            
            auto it_s = lower_bound(a.begin(), a.end(), s);
            int r = a.end() - it_s;
            
            auto it_mx = lower_bound(a.begin(), a.end(), ma);
            int same = a.end() - it_mx;
            
            total += 1LL * l * r - same;
        }
        cout << total << '\n';
    }
    
    return 0;
}