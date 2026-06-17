const int mod = 1e9 + 7;
ll T, n, t[5][5], a[5][5], b[5][5];
void matrixQp(ll y){
    while (y) {
        if (y & 1) {
            memset(t, 0, sizeof t);
            rep(i, 1, 3, 1) {
                rep(j, 1, 1, 1) {
                    rep(k, 1, 3, 1) {
                        t[i][j] = ( t[i][j] + (a[i][k] * b[k][j]) % mod ) % mod;
                    }
                }
            }
            memcpy(b, t, sizeof t);
        }
        y >>= 1;
        memset(t, 0, sizeof t);
        rep(i, 1, 3, 1) {
            rep(j, 1, 3, 1) {
                rep(k, 1, 3, 1) {
                    t[i][j] = ( t[i][j] + (a[i][k] * a[k][j]) % mod ) % mod;
                }
            }
        }
        memcpy(a, t, sizeof t);
    }
}
void init(){
    b[1][1] = b[2][1] = b[3][1] = 1;
    memset(a, 0, sizeof a);
    a[1][1] = a[2][1] = a[1][3] = a[3][2] = 1;
}
void solve(){
    std::cin >> n;
    if (n <= 3) {
        std::cout << "1\n";
    } else {
        init();
        matrixQp(n - 3);
        std::cout << b[1][1] << "\n";
    }
}
int main(){
    std::cin >> T;
    while (T --) {
        solve();
    }
    return 0;
}
