#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        
        bool possible = true;
        for (int i = 0; i < n; ++i) {
            if (a[i] == '1') {
                bool found = false;
                if (i > 0 && b[i-1] == '0') {
                    found = true;
                }
                if (i < n && b[i] == '0') {
                    found = true;
                }
                if (!found) {
                    possible = false;
                    break;
                }
            }
        }
        cout << (possible ? "YES" : "NO") << '\n';
    }
    return 0;
}