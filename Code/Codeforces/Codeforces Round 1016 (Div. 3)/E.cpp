#include <bits/stdc++.h>
using namespace std;

bool check(int x_candidate, const vector<int>& a, int k) {
    if (x_candidate == 0) {
        return true;
    }
    int n = a.size();
    vector<int> current_counts(x_candidate, 0);
    int required = x_candidate;
    int splits = 0;
    int last_split_end = -1;
    
    for (int i = 0; i < n; ++i) {
        if (a[i] < x_candidate) {
            current_counts[a[i]]++;
        }
        bool all_present = true;
        for (int j = 0; j < x_candidate; ++j) {
            if (current_counts[j] == 0) {
                all_present = false;
                break;
            }
        }
        if (all_present) {
            splits++;
            fill(current_counts.begin(), current_counts.end(), 0);
            last_split_end = i;
            if (splits == k) {
                break;
            }
        }
    }
    return splits >= k && last_split_end == n - 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        unordered_map<int, int> freq;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            freq[a[i]]++;
        }
        
        int x_candidate = 0;
        while (freq.count(x_candidate) && freq[x_candidate] >= k) {
            x_candidate++;
        }
        
        bool found = false;
        int result = 0;
        while (x_candidate >= 0) {
            bool valid = true;
            for (int i = 0; i < x_candidate; ++i) {
                if (freq[i] < k) {
                    valid = false;
                    break;
                }
            }
            if (!valid) {
                x_candidate--;
                continue;
            }
            if (check(x_candidate, a, k)) {
                result = x_candidate;
                found = true;
                break;
            }
            x_candidate--;
        }
        cout << result << '\n';
    }
    return 0;
}