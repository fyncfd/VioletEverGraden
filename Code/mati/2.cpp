#include<bits/stdc++.h> 
using ll = long long;

int n;


void solve() {
    std::cin >> n;
    std::vector<ll> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i ++) {
        std::cin >> a[i];
    }
    for (int i = 1; i <= n; i ++) {
        std::cin >> b[i];
    }

    std::vector<ll> prea(n + 1, 1), preb(n + 1, 1);
    for (int i = 1; i <= n; i ++) {
        prea[i] = prea[i - 1] ^ a[i];
        preb[i] = preb[i - 1] ^ b[i];
    }

    
}

int main( ) {
    int _ = 1;
    //std::cin >> _;
    while (_ --) {
        solve();
    }

    return 0;
}