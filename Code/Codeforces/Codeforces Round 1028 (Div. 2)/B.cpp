/*
* @Author: AlgoStruggler
* @Create Time: 2025-05-31 23:35:15
* "To the Splendor of ACM-ICPC, We Consecrate Our AC Triumphs."
*/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <tuple>
using namespace std;

const int mod = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    vector<vector<long long>> outputs;
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n), q(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> q[i];
        }

        vector<long long> power(n+1);
        power[0] = 1;
        for (int i = 1; i <= n; i++) {
            power[i] = (power[i-1] * 2) % mod;
        }

        vector<long long> r(n, -1);
        vector<int> pos_p(n, -1), pos_q(n, -1);
        for (int i = 0; i < n; i++) {
            pos_p[p[i]] = i;
            pos_q[q[i]] = i;
        }

        set<pair<int, int>> available_p;
        set<pair<int, int>> available_q;
        for (int i = 0; i < n; i++) {
            available_p.insert({p[i], i});
            available_q.insert({q[i], i});
        }

        for (int a = n-1; a >= 0; a--) {
            tuple<int, int, int, int> event1 = make_tuple(-1, -1, -1, -1);
            tuple<int, int, int, int> event2 = make_tuple(-1, -1, -1, -1);

            auto it_p = available_p.find({a, pos_p[a]});
            if (it_p != available_p.end() && !available_q.empty()) {
                auto best_q = *available_q.rbegin();
                int b_val = best_q.first;
                int b_idx = best_q.second;
                int j = pos_p[a];
                int k = b_idx;
                if (j + k < n) {
                    event1 = make_tuple(max(a, b_val), min(a, b_val), j, k);
                }
            }

            auto it_q = available_q.find({a, pos_q[a]});
            if (it_q != available_q.end() && !available_p.empty()) {
                auto best_p = *available_p.rbegin();
                int c_val = best_p.first;
                int c_idx = best_p.second;
                int j = c_idx;
                int k = pos_q[a];
                if (j + k < n) {
                    event2 = make_tuple(max(a, c_val), min(a, c_val), j, k);
                }
            }

            int max1 = get<0>(event1);
            int min1 = get<1>(event1);
            int max2 = get<0>(event2);
            int min2 = get<1>(event2);

            if (max1 == -1 && max2 == -1) {
                continue;
            }

            if (max1 > max2) {
                int j = get<2>(event1);
                int k = get<3>(event1);
                int diag = j + k;
                r[diag] = (power[max1] + power[min1]) % mod;
                available_p.erase({a, j});
                available_q.erase({get<1>(*available_q.rbegin()), k});
            } else if (max1 < max2) {
                int j = get<2>(event2);
                int k = get<3>(event2);
                int diag = j + k;
                r[diag] = (power[max2] + power[min2]) % mod;
                available_p.erase({get<1>(*available_p.rbegin()), j});
                available_q.erase({a, k});
            } else {
                if (min1 >= min2) {
                    int j = get<2>(event1);
                    int k = get<3>(event1);
                    int diag = j + k;
                    r[diag] = (power[max1] + power[min1]) % mod;
                    available_p.erase({a, j});
                    available_q.erase({get<1>(*available_q.rbegin()), k});
                } else {
                    int j = get<2>(event2);
                    int k = get<3>(event2);
                    int diag = j + k;
                    r[diag] = (power[max2] + power[min2]) % mod;
                    available_p.erase({get<1>(*available_p.rbegin()), j});
                    available_q.erase({a, k});
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (r[i] == -1) {
                long long best_val = 0;
                for (int j = 0; j <= i; j++) {
                    int k = i - j;
                    if (k < 0 || k >= n) continue;
                    int a = p[j];
                    int b = q[k];
                    long long candidate = (power[a] + power[b]) % mod;
                    if (candidate > best_val) {
                        best_val = candidate;
                    }
                }
                r[i] = best_val;
            }
        }

        outputs.push_back(r);
    }

    for (auto &v : outputs) {
        for (int i = 0; i < v.size(); i++) {
            cout << v[i];
            if (i < v.size() - 1) {
                cout << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}