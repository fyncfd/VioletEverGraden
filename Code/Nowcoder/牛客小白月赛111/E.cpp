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

constexpr int MAXN = 1e3 + 3;
int n, m, k;
ll a[MAXN];
int t;
int x, y, v;
/*-------------------------------MY_CODE_BEGIN--------------------------------*/
static inline void VioletEverGraden() {
    std::cin >> n >> m >> k;
    rep(i, 0, n - 1) {
        std::cin >> a[i];
    }

    ll sum[MAXN + 1] = {0};
    ll pre[MAXN + 1] = {0};
    rep(i, 0, n - 1) {
        sum[i + 1] = sum[i] + a[i];
        pre[i + 1] = pre[i] + a[i] * a[i];
    }

    ll ans = 0;
    ll c = m + k + 1;

    rep(j, 0, n - 1) {
        ll aj = a[j];
        ll dmi = k + 1;
        ll dma = k + m;

        ll ami = aj - dma;
        ll ama = aj - dmi;

        int left = 0, right = j - 1;
        int d= j, u = -1;

        if (j == 0) {
        	continue;
        }
        int l = 0, r = j - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (a[mid] >= ami) {
                d = mid;
                r = mid - 1;
            } 
            else {
                l = mid + 1;
            }
        }

        l = 0, r = j - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (a[mid] <= ama) {
                u = mid;
                l = mid + 1;
            } 
            else {
                r = mid - 1;
            }
        }

        if (d > u or u < 0) {
        	continue;
        }

        int cnt = u - d + 1;
        ll cnt1 = sum[u + 1] - sum[d];
        ll cnt2 = pre[u + 1] - pre[d];

        ll temp1 = c * c * cnt;
        ll temp2 = -2 * c * (aj * cnt - cnt1);
        ll temp3 = aj * aj * cnt - 2 * aj * cnt1 + cnt2;

        ans += temp1 + temp2 + temp3;
    }

    std::cout << ans << '\n';
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