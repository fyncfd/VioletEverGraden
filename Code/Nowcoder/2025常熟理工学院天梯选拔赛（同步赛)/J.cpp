#define  _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize("O2")
#include "bits/stdc++.h"


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

int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };

constexpr int MAXN = 0;
int n, k;
std::string s;
/*-------------------------------MY_CODE_BEGIN--------------------------------*/
constexpr int P = 1e9 + 7;
using i64 = long long;
// assume -P <= x < 2P
int norm(int x) {
    if (x < 0) {
        x += P;
    }
    if (x >= P) {
        x -= P;
    }
    return x;
}
template<class T>
T power(T a, i64 b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}
struct Z {
    int x;
    Z(int x = 0) : x(norm(x)) {}
    Z(i64 x) : x(norm(x % P)) {}
    int val() const {
        return x;
    }
    Z operator-() const {
        return Z(norm(P - x));
    }
    Z inv() const {
        assert(x != 0);
        return power(*this, P - 2);
    }
    Z &operator*=(const Z &rhs) {
        x = i64(x) * rhs.x % P;
        return *this;
    }
    Z &operator+=(const Z &rhs) {
        x = norm(x + rhs.x);
        return *this;
    }
    Z &operator-=(const Z &rhs) {
        x = norm(x - rhs.x);
        return *this;
    }
    Z &operator/=(const Z &rhs) {
        return *this *= rhs.inv();
    }
    friend Z operator*(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res *= rhs;
        return res;
    }
    friend Z operator+(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res += rhs;
        return res;
    }
    friend Z operator-(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res -= rhs;
        return res;
    }
    friend Z operator/(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res /= rhs;
        return res;
    }
    friend std::istream &operator>>(std::istream &is, Z &a) {
        i64 v;
        is >> v;
        a = Z(v);
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const Z &a) {
        return os << a.val();
    }
};

Z func(int x) {
	Z ans = 1;
	rep(i, 1, x) {
		ans *= i;
	}
	return ans;
}

static inline void VioletEverGraden() {
    std::cin >> n >> k;
    std::cin >> s;

    int numa = 0; int numb = 0;
    lop(x, s) {
    	if (x == 'a') {
    		numa ++;
    	}
    	else {
    		numb ++;
    	}
    }

    if (numa >= k) {
    	Z ans = func(numa) / (func(k) * func(numa - k));
    	std::cout << ans << '\n';
    	return ;
    }

    Z ans = 0;
    ans = func(numb) / (func(k - numa) / func(numb - k + numa));
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