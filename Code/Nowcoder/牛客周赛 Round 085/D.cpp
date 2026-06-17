#define  _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize("O2")
#include "bits/stdc++.h"

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;

using namespace std;
template <typename T> 
using pq = std::priority_queue<T>;
template<class T> 
using matrix = std::vector<std::vector<T>>;
template <typename T>
using vec = std::vector<T>;

template<class T> concept Signed = std::is_signed_v<T>;
template<class T> concept Unsigned = std::is_unsigned_v<T>;
template<class T> concept Arithmetic = std::is_arithmetic_v<T>;

#define rep(i, l, r) for (int i = l; i <= r; i++)
#define red(i, l, r) for (int i = l; i >= r; i--)
#define lop(i, x) for (auto i : x)
/*------------------------------SORT_AND_UNIQUE-------------------------------*/
//#define int long long
const double eps = 1e-9;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
const ll MOD = 1e9 + 7;
int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };

constexpr int MAXN = 1e6 + 6;
int n;
std::string s;
/*-------------------------------MY_CODE_BEGIN--------------------------------*/
static inline void VioletEverGraden() {
    std::cin >> n;
    std::cin >> s;
    s = ' ' + s;

    if (n == 1) {
        std::cout << 0 << '\n';
        return ;
    }

    if (n == 2) {
        std::cout << 0 << '\n';
        return ;
    }

    int num0 = 0;
    int num1 = 0;
    rep(i, 1, n) {
    	if (s[i] == '0') {
    		num0 ++;
    	}
    	else {
    		num1 ++;
    	}
    }

    int ps0[MAXN];
    int ps1[MAXN];
    ps0[0] = 0;
    ps1[0] = 0;
    rep(i, 1, s.size() - 1) {
    	ps0[i] = ps0[i - 1] + s[i] == '0';
    	ps1[i] = ps1[i - 1] + s[i] == '1';
    }

    ll ans = 0;
    rep(i, 1, n - 2) {
    	int temp0 = num0;
    	int temp1 = num1;
    	temp0 -= ps0[i];
    	temp1 -= ps1[i];
    	if (temp0 % 2 == 0 and temp1 % 2 == 0) {
    		ans ++;
    	}
    	else {
    		red(j, n, i + 3) {
    			if (s[j] == '1') {
    				temp1 --;
    			}
    			else {
    				temp0 --;
    			}
    			if (temp1 % 2 == 0 and temp0 % 2 ==0) {
    				ans ++;
    				break;
    			}
    		}
    	}
    }

    std::cout << 1.0 * ans / n << '\n';
    //debug();
}
/*-------------------------------Author_Fd------------------------------------*/
void TestArea();
void TimeTest();
static inline void VioletEverGraden();

signed main() {
#ifdef LOCAL
    freopen("A.in", "r", stdin);
#endif // LOCAL

    cout << fixed << setprecision(6);
    cerr << fixed << setprecision(6);

    std::cin.tie(nullptr) ->std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);

    int _ = 1;

    //for (std::cin >> _; _; _--)
        VioletEverGraden(); //TimeTest();
        
    /*fio::fio<int> intIO;
    _ = intIO.read();
    rep(i, 1, _) {
        VioletEverGraden();
        //TimeTest();
    }*/

    return 0;
}
/*------------------------------TIME_LIMITED----------------------------------*/
void TestArea() {
    VioletEverGraden();
}
void TimeTest() {
    auto start = std::chrono::steady_clock::now();//使用 steady_clock 代替 system_clock
    TestArea();
    auto end = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::duration<double>>(end - start).count();
    std::cout << "\ntime cost:" << duration << " /s";
}