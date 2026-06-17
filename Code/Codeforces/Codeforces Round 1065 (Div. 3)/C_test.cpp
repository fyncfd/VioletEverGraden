/*
* @Author: AlgoStruggler
* @Create Time: 2025-11-20 23:46:59
* "To the Splendor of ACM-ICPC, We Consecrate Our AC Triumphs."
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        
        int xorA = 0, xorB = 0;
        for (int i = 0; i < n; i++) {
            xorA ^= a[i];
            xorB ^= b[i];
        }
        
        // 统计ai != bi的位置数量
        int diffCount = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) diffCount++;
        }
        
        // 如果没有不同的位置，直接比较初始异或值
        if (diffCount == 0) {
            if (xorA > xorB) cout << "Ajisai\n";
            else if (xorA < xorB) cout << "Mai\n";
            else cout << "Tie\n";
            continue;
        }
        
        // 计算不同位置的奇偶性控制
        int ajisaiControl = 0, maiControl = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) {
                if ((i + 1) % 2 == 1) ajisaiControl++;  // 奇数位置，Ajisai控制
                else maiControl++;                      // 偶数位置，Mai控制
            }
        }
        
        // 分析博弈情况
        if (diffCount % 2 == 1) {
            // 奇数个不同位置，最后一个操作的是Ajisai
            // Ajisai可以选择是否翻转最终结果
            if ((xorA > xorB) || (xorA == 0 && xorB == 1)) {
                cout << "Ajisai\n";
            } else if (xorA == xorB) {
                cout << "Tie\n";
            } else {
                cout << "Mai\n";
            }
        } else {
            // 偶数个不同位置，最后一个操作的是Mai
            // Mai可以选择是否翻转最终结果
            if ((xorB > xorA) || (xorB == 0 && xorA == 1)) {
                cout << "Mai\n";
            } else if (xorA == xorB) {
                cout << "Tie\n";
            } else {
                cout << "Ajisai\n";
            }
        }
    }
    
    return 0;
}