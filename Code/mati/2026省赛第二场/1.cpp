#include<bits/stdc++.h> 

using namespace std;

#define int long long

signed main( )
{
    int n;
    std::cin >> n;

    int a1 = 0, a2 = 100000000, b1 = 0, b2 = 100000000;
    for (int i = 1; i <= n; i ++) {
    	int x, y;
    	std::cin >> x >> y;

    	a1 = std::max(a1, x);
    	a2 = std::min(a2, x);

    	b1 = std::max(b1, y);
    	b2 = std::min(b2, y);
    }

    long long ans = (a2 - a1) * (b2 - b1);
    std::cout << ans << '\n';

    return 0;
}