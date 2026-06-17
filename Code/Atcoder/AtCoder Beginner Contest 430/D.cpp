#include <iostream>
#include <set>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    set<long long> positions;          
    map<long long, long long> d;       
    long long total = 0;               

    positions.insert(0);


    for (int i = 0; i < N; i++) {
        long long x;
        cin >> x;

        auto ret = positions.insert(x);
        auto it = ret.first; 

        long long prev = -1; 
        long long next = -1;   

        if (it != positions.begin()) {
            auto pit = it;
            --pit;
            prev = *pit;
        }

        auto nit = it;
        ++nit;
        if (nit != positions.end()) {
            next = *nit;
        }

        long long d_new;
        if (prev == -1) {
            d_new = next - x;
        } else if (next == -1) {
            d_new = x - prev;
        } else {
            d_new = min(x - prev, next - x);
        }
        d[x] = d_new;
        total += d_new;

        if (prev != -1) {
            long long dist_to_new = x - prev;
            if (dist_to_new < d[prev]) {
                total -= d[prev];
                d[prev] = dist_to_new;
                total += d[prev];
            }
        }

        if (next != -1) {
            long long dist_to_new = next - x;
            if (dist_to_new < d[next]) {
                total -= d[next];
                d[next] = dist_to_new;
                total += d[next];
            }
        }

        cout << total << '\n';
    }

    return 0;
}