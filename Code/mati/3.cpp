#include<bits/stdc++.h> 
using ll = long long;

bool vis1[3][300015];bool vis0[3][300015];
int n;    char g[3][300015];
int dx[] = {99, 1, 0, -1, 0};
int dy[] = {99, 0, -1, 0, 1};
ll ans1 = 0; ll ans0 = 0;
void dfs1(int x, int y) {
    vis1[x][y] = true;
    for (int i = 1; i <= 4; i ++) {
        int nx = x + dx[i]; int ny = y + dy[i];
        if (nx < 1 or nx > 2 or ny < 1 or ny > n or g[nx][ny] == '0' or vis1[nx][ny]) {
            continue;
        }
        vis1[nx][ny] = true;
        dfs1(nx, ny);
    }
}
void dfs0(int x, int y) {
    vis0[x][y] = true;
    for (int i = 1; i <= 4; i ++) {
        int nx = x + dx[i]; int ny = y + dy[i];
        if (nx < 1 or nx > 2 or ny < 1 or ny > n or g[nx][ny] == '1' or vis0[nx][ny]) {
            continue;
        }
        vis0[nx][ny] = true;
        dfs0(nx, ny);
    }
}

void solve() {
    std::cin >> n;

    for (int i = 1; i <= 2; i ++) {
        for (int j = 1; j <= n; j ++) {
            std::cin >> g[i][j];
        }
    }

    for (int i = 1; i <= 2; i ++) {
        for (int j = 1; j <= n; j ++) {
            if (g[i][j] == '1' and !vis1[i][j]) {
                ans1 ++;
                dfs1(i, j);
            } else if (g[i][j] == '0' and !vis0[i][j]) {
                ans0 ++;
                dfs0(i, j);
            }
        }
    }

    //std::cout << ans1 << ans0 << '\n';

    std::cout << ans1 + ans0 << '\n';
}

int main( ) {
    int _ = 1;
    //std::cin >> _;
    while (_ --) {
        solve();
    }

    return 0;
}