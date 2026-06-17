#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, l, r) for (int i = 1; i <= n; i ++)
#define red(i, l, r) for (int i = l; i >= n; i --)

void solve() {
    int n, k; std::cin >> n >> k;
    vector<double> c(n+2,0);
    double  p,L,R,cnt,cntc;
    cin>>cnt>>cntc>>p>>L>>R;
    std::vector<double> r(n + 2, L);
    r[0]=cnt;
    c[0]=cntc;
    
    std::vector<double> a;
    
    int __ = k;
    
    while (__ --) {
        int x; double y; std::cin >> x >> y;
        r[x] = y;
    }
    for(int i=1;i<=n+1;i++)
    {
        c[i]=p*(c[i-1])+(1-p)*r[i-1];
    }

    // rep(i, 1, n) {
    //     if (r[i] == -114514) {
    //         r[i] = l;
    //     }
    // }

    // rep(i, 1, n) {
    //     c[i] = p * c[i - 1] + (1- p) * r[i - 1];
    // }

    // double ans = 0;
    // rep(i, 1, n) {
    //     ans += 1.0 * (c[i] - r[i]);
    // }

    std::cout << 1.0 * (c[1] - c[n+1]) / (1 - p) << '\n';
}

auto __init__ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
};

signed main() {
    __init__();

    std::cout << std::fixed << std::setprecision(10);

    int _ = 1;
    for (std::cin >> _; _; _ --) 
        solve();

    return 0;
}


/*
2
3 2
5 6 0.5 1 10
1 4
2 5
5 2
10 5 0.5 3 12
1 4
3 6


5.1250000000
7.9062500000

5.1250000000
7.9062500000

*/