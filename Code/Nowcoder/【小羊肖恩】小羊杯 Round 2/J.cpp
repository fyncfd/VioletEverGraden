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
int x, y;
/*-------------------------------MY_CODE_BEGIN--------------------------------*/
namespace acm {
	template<typename T>
	class gal {
		public:
			T gcd(T a, T b) {//欧几里得辗转相除法求最大公约数
				if (!b) {
					return a;
				}
				return gcd(b, a % b);
			}
			T lcm(T a, T b) {//最小公倍数，其中先除后乘是尽可能避免溢出，尽量保持这个习惯
				return x / gcd(x, y) * y;
			}
	};
}
static inline void solve() {
    std::cin >> x >> y;
    int ma = max(x, y);
    ll ans = -1;
    acm::gal<int> i63;
    if (x == 1 and y == 1) {
    	std::cout << -1 << endl;
    	return ;
    }
    rep(i, 2, ma) {
    	if (i63.gcd(i, x) == 1 and i63.gcd(i, y) == 1) {
    		ans = i;
    		break;
    	}
    }
    std::cout << ans << endl;
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

    for (std::cin >> _; _; _--)
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