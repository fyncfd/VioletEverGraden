#include <iostream>
#include <vector>
using namespace std;

const int MOD = 998244353;
const int INV2 = 499122177;

vector<long long> precompute() {
    vector<long long> dp_f0 = {0, 500000004, 1, 1, 500000004};
    return dp_f0;
}

long long mod_pow(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

int main() {
    vector<long long> dp_f0 = precompute();
    int T;
    cin >> T;
    while (T--) {
        long long n;
        cin >> n;
        long long mod = n % 5;
        long long res;
        if (mod == 0 || mod == 1 || mod == 4) {
            res = INV2;
        } else {
            res = 1;
        }
        cout << res << endl;
    }
    return 0;
}