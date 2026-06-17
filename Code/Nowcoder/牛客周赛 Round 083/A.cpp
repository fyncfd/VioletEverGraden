#define  _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize("O2")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using db = double;
#define endl '\n'
typedef pair<int, int> pii;
#define all(x) x.begin(), x.end()
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define red(i, l, r) for (int i = l; i >= r; i--)
#define lop(i, x) for (auto i : x)
/*-------------------------------DEBUG_TOLL-----------------------------------*/
#ifdef DEBUG
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
void debug_out() { 
    cerr << endl; 
}
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << H;
    debug_out(T...);
}
#else
#define debug(...)
#endif
/*---------------------------RANDON_NUMBER_GRNERATION-------------------------*/
#ifdef RANDOM_TEST
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rand_int(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng); 
}
#endif
/*------------------------------SORT_AND_UNIQUE-------------------------------*/
//#define int long long
const double eps = 1e-9;
const ll inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
const ll MOD = 1e9 + 7;
int dx[] = { 0,1,0,-1 };
int dy[] = { -1,0,1,0 };
const int MAXN = 0;
char ch;
/*-------------------------------MY_CODE_BEGIN--------------------------------*/
static inline void solve() {
    std::cin >> ch;
    if (ch == 'U' or ch == 'D') {
    	std::cout << 'L' << endl;
    }
    else if (ch == 'L' or ch == 'R') {
    	std::cout << 'U' << endl;
    }
    //debug();
}
/*-------------------------------Author_Fd------------------------------------*/
signed main() {
#ifdef LOCAL
    freopen("A.in", "r", stdin);
#endif // LOCAL
    /*cout << fixed << setprecision(15);
    cerr << fixed << setprecision(12);*/
    std::cin.tie(nullptr) ->
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);
    int _ = 1;
    
    void TestArea();
    void TimeTest();

    //for (std::cin >> _; _; _--)
        solve(); //TimeTest();
        
    /*fio::fio<int> intIO;
    _ = intIO.read();
    rep(i, 1, _) {
        solve();
        //TimeTest();
    }*/

    return 0;
}
/*------------------------------TIME_LIMITED----------------------------------*/
void TestArea() {
    solve();
}
void TimeTest() {
    auto start = chrono::steady_clock::now();//使用 steady_clock 代替 system_clock
    TestArea();
    auto end = chrono::steady_clock::now();
    auto duration = chrono::duration_cast<chrono::duration<double>>(end - start).count();//直接获取时间
    std::cout << "\ntime cost:" << duration << " /s";
}