/*
* @Author: AlgoStruggler
* @Create Time: 2025-11-22 20:55:20
* "To the Splendor of ACM-ICPC, We Consecrate Our AC Triumphs."
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    long long M;
    cin >> N >> M;
    
    vector<long long> A(N);
    vector<int> len(N);
    
    // 预计算10的幂次模M
    vector<long long> pow10(11);
    pow10[0] = 1 % M;
    for (int i = 1; i <= 10; i++) {
        pow10[i] = (pow10[i-1] * 10) % M;
    }
    
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        long long x = A[i];
        int length = 0;
        while (x > 0) {
            length++;
            x /= 10;
        }
        len[i] = length;
    }
    
    // 存储对于每个位数d，每个模数值的出现次数
    unordered_map<long long, int> count[11];
    for (int i = 0; i < N; i++) {
        count[len[i]][A[i] % M]++;
    }
    
    long long result = 0;
    
    // 对于每个A[j]
    for (int j = 0; j < N; j++) {
        long long aj_mod = A[j] % M;
        int length_j = len[j];
        long long target = (M - aj_mod) % M;
        long long power = pow10[length_j];
        
        // 对于每种可能的位数d
        for (int d = 1; d <= 10; d++) {
            // 我们需要找到所有x使得 (x * power) % M == target
            // 这等价于 x ≡ target * inv(power) (mod M)
            // 但由于逆元可能不存在，我们直接检查条件
            
            auto it = count[d].find(target);
            if (it != count[d].end() && (it->first * power) % M == target) {
                result += it->second;
            }
        }
    }
    
    cout << result << endl;
    
    return 0;
}