#define  _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize("O2")
#include "bits/stdc++.h"

typedef long long ll;
typedef unsigned long long ull;

using namespace std;
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

/*-------------------------------MY_CODE_BEGIN--------------------------------*/
static inline void VioletEverGraden() {
    string s;
    getline(cin, s);
    string op;
    getline(cin, op);
    vector<string> in;
    istringstream iss(op);
    string t;
    while (iss >> t) {
        if (t == "CTRL") {
            string arg;
            if (iss >> arg) {
                in.push_back("CTRL " + arg);
            }
        } 
        else {
            in.push_back(t);
        }
    }
    string str = s;
    int pos = str.size();
    vector<string> out;
    lop(cmd, in) {
        if (cmd == "LEFT") {
            pos = max(0, pos - 1);
        } 
        else if (cmd == "RIGHT") {
            pos = min((int)str.size(), pos + 1);
        } 
        else if (cmd.size() >= 5 && cmd.substr(0, 5) == "CTRL ") {
            string arg = cmd.substr(5);
            if (arg == "S") {
                out.push_back(str);
            } 
            else if (!arg.empty() && arg[0] == 'D') {
                int x = stoi(arg.substr(1));
                char c = str[pos - 1];
                str.insert(pos, x, c);
                pos += x;
            }
        }
    }
    lop(o, out) {
        cout << o << endl;
    }
    cout << str << endl;
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