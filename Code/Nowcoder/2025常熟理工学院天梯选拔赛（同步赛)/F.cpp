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

constexpr int MAXN = 105;
int n;
int op;
char c;
/*-------------------------------MY_CODE_BEGIN--------------------------------*/
static inline void VioletEverGraden() {
    std::cin >> n;
    int numr = 0; int numl = 0;
    char s[MAXN][MAXN];
    memset(s, ' ', sizeof s);
    while (n --) {
    	std::cin >> op;
    	if (op == 1) {
    		std::cin >> c;
    		if (c == 'L') {
    			numl ++;
    		}
    		else {
    			numr ++;
    		}
    	}
    	else {
    		if (numl % 4 == 0) {
    			s[1][3] = 'y';
    			s[2][3] = 'y';
    			s[3][3] = 'b';
    			s[4][3] = 'b';
    			s[5][3] = 'w';
    			s[6][3] = 'w';
    			s[7][3] = 'g';
    			s[8][3] = 'g';
    		}
    		else if (numl % 4 == 1) {
    			s[1][3] = 'g';
    			s[2][3] = 'g';
    			s[3][3] = 'y';
    			s[4][3] = 'y';
    			s[5][3] = 'b';
    			s[6][3] = 'b';
    			s[7][3] = 'w';
    			s[8][3] = 'w';
    		}
    		else if(numl % 4 == 2) {
    			s[1][3] = 'w';
    			s[2][3] = 'w';
    			s[3][3] = 'g';
    			s[4][3] = 'g';
    			s[5][3] = 'y';
    			s[6][3] = 'y';
    			s[7][3] = 'b';
    			s[8][3] = 'b';
    		}
    		else if (numl % 4== 3) {
    			s[1][3] = 'b';
    			s[2][3] = 'b';
    			s[3][3] = 'w';
    			s[4][3] = 'w';
    			s[5][3] = 'g';
    			s[6][3] = 'g';
    			s[7][3] = 'y';
    			s[8][3] = 'y';
    		}
    		if (numr % 4 == 0) {
    			s[1][4] = 'y';
    			s[2][4] = 'y';
    			s[3][4] = 'b';
    			s[4][4] = 'b';
    			s[5][4] = 'w';
    			s[6][4] = 'w';
    			s[7][4] = 'g';
    			s[8][4] = 'g';
    		}
    		else if (numr % 4 == 1) {
    			s[1][4] = 'b';
    			s[2][4] = 'b';
    			s[3][4] = 'w';
    			s[4][4] = 'w';
    			s[5][4] = 'g';
    			s[6][4] = 'g';
    			s[7][4] = 'y';
    			s[8][4] = 'y';
    		}
    		else if(numr % 4 == 2) {
    			s[1][4] = 'w';
    			s[2][4] = 'w';
    			s[3][4] = 'g';
    			s[4][4] = 'g';
    			s[5][4] = 'y';
    			s[6][4] = 'y';
    			s[7][4] = 'b';
    			s[8][4] = 'b';
    		}
    		else if (numr % 4== 3) {
    			s[1][4] = 'g';
    			s[2][4] = 'g';
    			s[3][4] = 'y';
    			s[4][4] = 'y';
    			s[5][4] = 'b';
    			s[6][4] = 'b';
    			s[7][4] = 'w';
    			s[8][4] = 'w';
    		}
    		std::cout << "  " << s[1][3] << s[1][4] << "  " << '\n';
    		std::cout << "  " << s[2][3] << s[2][4] << "  " << '\n';
    		std::cout << "oo" << s[3][3] << s[3][4] << "rr" << '\n';
    		std::cout << "oo" << s[4][3] << s[4][4] << "rr" << '\n';
    		std::cout << "  " << s[5][3] << s[5][4] << "  " << '\n';
    		std::cout << "  " << s[6][3] << s[6][4] << "  " << '\n';
    		std::cout << "  " << s[7][3] << s[7][4] << "  " << '\n';
    		std::cout << "  " << s[8][3] << s[8][4] << "  " << '\n';
    	}
    }
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