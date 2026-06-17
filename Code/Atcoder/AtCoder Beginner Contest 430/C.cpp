#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, A, B;
    string S;
    cin >> N >> A >> B >> S;

    vector<int> prefix_a(N + 1, 0);
    vector<int> prefix_b(N + 1, 0);

    for (int i = 0; i < N; i++) {
        prefix_a[i + 1] = prefix_a[i] + (S[i] == 'a');
        prefix_b[i + 1] = prefix_b[i] + (S[i] == 'b');
    }

    long long ans = 0;

    for (int l = 1; l <= N; l++) {
        int low = l, high = N + 1;
        while (low < high) {
            int mid = (low + high) / 2;
            int cnt_b = prefix_b[mid] - prefix_b[l - 1];
            if (cnt_b >= B) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        int max_r = low - 1;

        if (max_r < l) continue; 

        low = l, high = max_r + 1;
        while (low < high) {
            int mid = (low + high) / 2;
            int cnt_a = prefix_a[mid] - prefix_a[l - 1];
            if (cnt_a >= A) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        if (low <= max_r) {
            ans += (max_r - low + 1);
        }
    }

    cout << ans << endl;

    return 0;
}