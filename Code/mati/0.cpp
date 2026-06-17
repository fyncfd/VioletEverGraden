#include<bits/stdc++.h> 
using ll = long long;
#define int long long

signed main( ) {
    int n;
    std::cin >> n;
    
    struct pii { ll l; ll r; };
    std::vector<pii> a(n + 1);
    for (int i = 1; i <= n; i ++) {
        std::cin >> a[i].l >> a[i].r;
    }
    
    std::sort(a.begin() + 1,  a.end(), [&](pii a, pii b) -> bool {
        if (a.l == b.l) {
            return a.r < b.r;
        } else {
            return a.l < b.l;
        }
    });

/*    for (int i = 1; i <= n; i ++) {
        std::cout << a[i].l << ' ' <<  a[i].r << '\n';
    }*/

    ll ans = 0; ans += a[1].r - a[1].l + 1;
    ll lo = a[1].l; ll hi = a[1].r;
    for (int i = 2; i <= n; i ++) {
        if (a[i].l > hi) {
            ans += a[i].r - a[i].l + 1;
            lo = a[i].l; hi = a[i].r;
        } else if (a[i].l == hi) {
            ans += a[i].r - a[i].l;
            hi = a[i].r;
        } else if (a[i].l < hi) {
            ans += std::max(a[i].r - hi, 0LL);
            hi = std::max(a[i].r, hi);
        }

        //std::cout << lo << ' ' << hi << "???\n";
    }

    std::cout << ans << '\n';


    return 0;
}