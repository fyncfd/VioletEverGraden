#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 300005;

vector<int> children[MAXN][2];
int parent[MAXN];
long long dp_down[MAXN];  // time to process subtree from node and return to node
long long dp_up[MAXN];    // time from node to parent when starting at node
long long ans[MAXN];
int n;

void dfs_down(int u) {
    if (children[u][0].empty()) {  // leaf
        dp_down[u] = 0;
        return;
    }
    
    int left = children[u][0][0];
    int right = children[u][1][0];
    
    dfs_down(left);
    dfs_down(right);
    
    // Time to process from u to parent:
    // 1. Go to left child
    // 2. Process left subtree and return to u
    // 3. Go to right child
    // 4. Process right subtree and return to u
    // 5. Go to parent
    dp_up[u] = (3 + dp_down[left] + dp_down[right]) % MOD;
    
    // dp_down[u] is the time to process subtree and return to u
    // Actually, for dp_down[u], we need total moves starting from u,
    // going through both subtrees, and returning to u
    // That's exactly: 2 (to left and back to u) + dp_down[left] + 2 (to right and back to u) + dp_down[right]
    // But careful - the pattern is different when not going to parent
    // Let's think differently:
    
    // Starting at u, with nothing written:
    // Go to left child: 1
    // Process left subtree and return to u: dp_down[left]
    // Now 'L' is written on u
    // Go to right child: 1
    // Process right subtree and return to u: dp_down[right]
    // Now 'R' is written on u
    // Erase and return to u? No, we stop at u
    // So total = 2 + dp_down[left] + dp_down[right]
    dp_down[u] = (2 + dp_down[left] + dp_down[right]) % MOD;
}

void dfs_up(int u, long long sum) {
    ans[u] = sum;
    
    if (children[u][0].empty()) {
        return;
    }
    
    int left = children[u][0][0];
    int right = children[u][1][0];
    
    dfs_up(left, (sum + dp_up[left]) % MOD);
    dfs_up(right, (sum + dp_up[right]) % MOD);
}

void solve() {
    cin >> n;
    
    for (int i = 0; i <= n; i++) {
        children[i][0].clear();
        children[i][1].clear();
    }
    
    // Root is 0
    for (int i = 1; i <= n; i++) {
        int l, r;
        cin >> l >> r;
        if (l > 0) {
            children[i][0].push_back(l);
            parent[l] = i;
        }
        if (r > 0) {
            children[i][1].push_back(r);
            parent[r] = i;
        }
    }
    
    // Set parent for vertex 1
    parent[1] = 0;
    
    // Process from leaves upward
    dfs_down(0);
    
    // Calculate answers
    dfs_up(0, 0);
    
    for (int i = 1; i <= n; i++) {
        cout << ans[i];
        if (i < n) cout << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}