/*
* @Author: AlgoStruggler
* @Create Time: 2025-05-17 22:48:05
* "To the Splendor of ACM-ICPC, We Consecrate Our AC Triumphs."
*/
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n, m, a, b;
        cin >> n >> m >> a >> b;
        
        int max_r = max(a - 1, n - a);
        int max_c = max(b - 1, m - b);
        
        int steps_r = 0, steps_c = 0;
        if (max_r) steps_r = 32 - __builtin_clz(max_r);
        if (max_c) steps_c = 32 - __builtin_clz(max_c);
        
        cout << max(steps_r, steps_c) << '\n';
    }
    
    return 0;
}