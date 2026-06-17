#define  _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize("O2")
#include "bits/stdc++.h"

typedef long long ll;
typedef unsigned long long ull;

template <typename T> 
using pq = std::priority_queue<T>;
template<class T> 
using matrix = std::vector<std::vector<T>>;

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

constexpr int MAXN = 0;
int n;
std::string s;
/*-------------------------------MY_CODE_BEGIN--------------------------------*/
static inline void VioletEverGraden() {
    int n;
    std::string s;
    std::cin >> n >> s;

    int num = 0;
    lop(c, s) {
        if (c == '3') {
            num++;
        }
    }

    if (num < 2) {
        std::cout << 0 << '\n';
        return;
    }

    int pos3 = -1; // 第一个3
    int pos31 = -1; // 最后一个3
    int pos32 = -1; // 第二个3
    int pos8 = -1; // 最后一个8

    rep(i, 0, n - 1) {
        if (s[i] == '3') {
            if (pos3 == -1) {
            	pos3 = i;
            }
            else if (pos32 == -1) {
            	pos32 = i;
            }
            pos31 = i;
        }
        if (s[i] == '8') {
            pos8 = i;
        }
    }

    int ma = pos31 - pos3;

    if (pos8 == -1 or pos8 < pos3) {
        std::cout << ma << '\n';
        return;
    }

    int temp = 0;
    int minm = pos3;
    int maxm = pos8;
    if (pos32 > pos8) {
        maxm = pos31;
    } 
    else {
        maxm = pos8;
    }

    temp = maxm - minm;
    int ans = std::max(ma, temp);
    std::cout << ans << '\n';
}
/*-------------------------------Author_Fd------------------------------------*/
void TestArea();
void TimeTest();
static inline void VioletEverGraden();

signed main() {
#ifdef LOCAL
    freopen("A.in", "r", stdin);
#endif // LOCAL

    /*cout << fixed << setprecision();
    cerr << fixed << setprecision();*/

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