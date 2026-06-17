/*
* @Author: AlgoStruggler
* @Create Time: 2025-05-17 20:09:30
* "To the Splendor of ACM-ICPC, We Consecrate Our AC Triumphs."
*/
#define  _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize("O2")
#include "bits/stdc++.h"
//#include <ext/pb_ds/assoc_container.hpp>

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef __int128 i128;
typedef std::pair<int, int> pii;
typedef std::pair<ll, ll> pll;

//using namespace std;
//using namespace __gnu_pbds;
template <typename T> 
using pq = std::priority_queue<T>;
template<class T> 
using matrix = std::vector<std::vector<T>>;
template <typename T>
using vec = std::vector<T>;
template <class Key, class Value>
using ump = std::unordered_map<Key, Value>;
template <typename T>
using ust = std::unordered_set<T>;
//template <typename Key, typename Value>
//using hash = __gnu_pbds::gp_hash_table<Key, Value>;

template<class T> concept Signed = std::is_signed_v<T>;
template<class T> concept Unsigned = std::is_unsigned_v<T>;
template<class T> concept Arithmetic = std::is_arithmetic_v<T>;

#define all(x) x.begin() + 1, x.end()
#define LLA(x) (x).rbegin(), (x).rend()
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define red(i, l, r) for (int i = l; i >= r; i--)
#define lop(i, x) for (auto i : x)
/*------------------------------SORT_AND_UNIQUE-------------------------------*/
//#define int long long
const double eps = 1e-9;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF = 0x3f3f3f3f3f3f3f3f;
constexpr ll mod = 998244353;
constexpr ll MOD = 1e9 + 7;
int dx[] = {0, 0, 1, 0, -1 };
int dy[] = {0, -1, 0, 1, 0 };
constexpr int MAXN = 0;
int n, k;
std::vector<ll> a;
/*-------------------------------MY_CODE_BEGIN--------------------------------*/
using std::istream;
using std::ostream;
using std::string;
using std::vector;
class BigInt {
   public:
    BigInt(long long num = 0) {
        negtive = false;
        if (num < 0) {
            negtive = true;
            num = -num;
        }
        if (num == 0) {
            number.push_back(0);
        } else {
            while (num > 0) {
                number.push_back(num % 10);
                num /= 10;
            }
        }
    }
    
    explicit BigInt(string str) {
        negtive = false;
        if (str.empty()) {
            number.push_back(0);
            return;
        }
        if (str[0] == '-') {
            negtive = true;
            str = str.substr(1);
        }
        for (auto it = str.rbegin(); it != str.rend(); ++it) {
            if (*it >= '0' && *it <= '9') {
                number.push_back(*it - '0');
            } else {
                throw std::invalid_argument("Invalid character in BigInt string");
            }
        }
        trim();
    }
    
    ~BigInt() = default;
    
    int digit_at(size_t index) const {
        if (index >= number.size()) return 0;
        return number[index];
    }
    
    BigInt& operator=(const BigInt& number2) {
        if (this == &number2) return *this;
        number = number2.number;
        negtive = number2.negtive;
        return *this;
    }
    
    BigInt& operator+=(const BigInt& number2) {
        if (negtive == number2.negtive) {
            simple_calc(number, number2.number, true);
        } else {
            if (greater(number, number2.number)) {
                simple_calc(number, number2.number, false);
            } else {
                vector<char> temp = number2.number;
                simple_calc(temp, number, false);
                number = temp;
                negtive = number2.negtive;
            }
        }
        trim();
        return *this;
    }
    
    BigInt& operator*=(const BigInt& number2) {
        vector<char> result(number.size() + number2.number.size(), 0);
        for (size_t i = 0; i < number.size(); ++i) {
            for (size_t j = 0; j < number2.number.size(); ++j) {
                result[i + j] += number[i] * number2.number[j];
                if (result[i + j] >= 10) {
                    result[i + j + 1] += result[i + j] / 10;
                    result[i + j] %= 10;
                }
            }
        }
        number = result;
        negtive = (negtive != number2.negtive);
        trim();
        return *this;
    }
    
    BigInt& operator-=(const BigInt& number2) {
        if (negtive != number2.negtive) {
            simple_calc(number, number2.number, true);
        } else {
            if (greater(number, number2.number)) {
                simple_calc(number, number2.number, false);
            } else {
                vector<char> temp = number2.number;
                simple_calc(temp, number, false);
                number = temp;
                negtive = !negtive;
            }
        }
        trim();
        return *this;
    }
    
    BigInt& operator/=(const BigInt& number2) {
        if (number2.number.size() == 1 && number2.number[0] == 0) {
            throw std::runtime_error("Division by zero");
        }
        BigInt dividend(*this);
        BigInt divisor(number2);
        bool result_negative = (dividend.negtive != divisor.negtive);
        dividend.negtive = false;
        divisor.negtive = false;
        
        if (dividend < divisor) {
            number = {0};
            negtive = false;
            return *this;
        }
        
        BigInt quotient;
        BigInt current;
        quotient.number.resize(dividend.number.size(), 0);
        
        for (int i = dividend.number.size() - 1; i >= 0; --i) {
            current.number.insert(current.number.begin(), dividend.number[i]);
            current.trim();
            char digit = 0;
            while (current >= divisor) {
                current -= divisor;
                ++digit;
            }
            quotient.number[i] = digit;
        }
        quotient.trim();
        quotient.negtive = result_negative;
        *this = quotient;
        return *this;
    }
    
    BigInt& operator%=(const BigInt& number2) {
        BigInt temp = *this;
        temp /= number2;
        temp *= number2;
        *this -= temp;
        return *this;
    }
    
    BigInt& operator++() {
        *this += BigInt(1);
        return *this;
    }
    
    BigInt& operator--() {
        *this -= BigInt(1);
        return *this;
    }
    
    BigInt operator++(int) {
        BigInt temp(*this);
        ++(*this);
        return temp;
    }
    
    BigInt operator--(int) {
        BigInt temp(*this);
        --(*this);
        return temp;
    }
    
    friend bool operator==(const BigInt& number1, const BigInt& number2) {
        return number1.negtive == number2.negtive && number1.number == number2.number;
    }
    
    friend bool operator!=(const BigInt& number1, const BigInt& number2) {
        return !(number1 == number2);
    }
    
    friend bool operator<(const BigInt& number1, const BigInt& number2) {
        if (number1.negtive != number2.negtive) {
            return number1.negtive;
        }
        if (number1.number.size() != number2.number.size()) {
            return (number1.number.size() < number2.number.size()) ^ number1.negtive;
        }
        for (int i = number1.number.size() - 1; i >= 0; --i) {
            if (number1.number[i] != number2.number[i]) {
                return (number1.number[i] < number2.number[i]) ^ number1.negtive;
            }
        }
        return false;
    }
    
    friend bool operator>(const BigInt& number1, const BigInt& number2) {
        return number2 < number1;
    }
    
    friend bool operator<=(const BigInt& number1, const BigInt& number2) {
        return !(number1 > number2);
    }
    
    friend bool operator>=(const BigInt& number1, const BigInt& number2) {
        return !(number1 < number2);
    }
    
    friend BigInt operator+(const BigInt& number1, const BigInt& number2) {
        BigInt result(number1);
        result += number2;
        return result;
    }
    
    friend BigInt operator*(const BigInt& number1, const BigInt& number2) {
        BigInt result(number1);
        result *= number2;
        return result;
    }
    
    friend BigInt operator-(const BigInt& number1, const BigInt& number2) {
        BigInt result(number1);
        result -= number2;
        return result;
    }
    
    friend BigInt operator/(const BigInt& number1, const BigInt& number2) {
        BigInt result(number1);
        result /= number2;
        return result;
    }
    
    friend BigInt operator%(const BigInt& number1, const BigInt& number2) {
        BigInt result(number1);
        result %= number2;
        return result;
    }
    
    friend ostream& operator<<(ostream& output, const BigInt& num) {
        if (num.negtive) output << '-';
        for (auto it = num.number.rbegin(); it != num.number.rend(); ++it) {
            output << static_cast<int>(*it);
        }
        if (num.number.empty()) output << '0';
        return output;
    }
    
    friend istream& operator>>(istream& input, BigInt& num) {
        string str;
        input >> str;
        num = BigInt(str);
        return input;
    }
    
   private:
    vector<char> number;
    bool negtive;
    
    void trim() {
        while (number.size() > 1 && number.back() == 0) {
            number.pop_back();
        }
        if (number.empty()) {
            number.push_back(0);
            negtive = false;
        }
    }
    
    static void simple_calc(vector<char>& number1, const vector<char>& number2, bool plus) {
        size_t max_size = std::max(number1.size(), number2.size());
        number1.resize(max_size, 0);
        char carry = 0;
        for (size_t i = 0; i < max_size; ++i) {
            char digit2 = i < number2.size() ? number2[i] : 0;
            if (plus) {
                number1[i] += digit2 + carry;
            } else {
                number1[i] -= digit2 + carry;
            }
            if (number1[i] >= 10) {
                number1[i] -= 10;
                carry = 1;
            } else if (number1[i] < 0) {
                number1[i] += 10;
                carry = 1;
            } else {
                carry = 0;
            }
        }
        if (carry) {
            number1.push_back(carry);
        }
    }
    
    static void add_at(vector<char>& num, int i, unsigned char x) {
        if (i >= num.size()) {
            num.resize(i + 1, 0);
        }
        num[i] += x;
    }
    
    static bool greater(const vector<char>& number1, const vector<char>& number2) {
        if (number1.size() != number2.size()) {
            return number1.size() > number2.size();
        }
        for (int i = number1.size() - 1; i >= 0; --i) {
            if (number1[i] != number2[i]) {
                return number1[i] > number2[i];
            }
        }
        return false;
    }
};

static inline void VioletEverGraden() {
    std::cin >> n >> k;
    a.resize(n + 1);
    rep(i, 1, n) {
        std::cin >> a[i];
    }

    BigInt ans = a[1];
    rep(i, 2, n) {
        ans *= a[i];
        BigInt limit(1);
        for (int j = 0; j < k; ++j) {
            limit *= BigInt(10);
        }
        if (ans >= limit) {
            ans = BigInt(1);
        }
    }

    std::cout << ans << '\n';
}

/*-------------------------------Author_Fd------------------------------------*/
static inline void VioletEverGraden();

auto __INIT__ = []() {
    std::cin.tie(nullptr) ->
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    return 0;
}();

signed main() {
#ifdef LOCAL
    freopen("A.in", "r", stdin);
#endif // LOCAL

    //__INIT__();

    int _ = 1;
    VioletEverGraden();

    return 0;
}