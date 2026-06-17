# XCPC Algorithm Template

## 零、标准头文件模板

### 0.0、缺省源

`````c++
/*1.深呼吸，不要紧张，慢慢读题，读明白题，题目往往比你想的简单。2.暴力枚举:枚举什么，是否可以使用一些技巧加快枚举速度（预处理、前缀和、数据结构、数论分块）
3.贪心:需要排序或使用数据结构（pq）吗，这么贪心一定最优吗。
4.二分：满足单调性吗，怎么二分，如何确定二分函数返回值是什么。5.位运算：按位贪心，还是与位运算本身的性质有关。
6.数学题：和最大公因数、质因子、取模是否有关。
7.dp：怎么设计状态，状态转移方程是什么，初态是什么，使用循环还是记搜转移。8.搜索：dfs 还是 bfs ，搜索的时候状态是什么，需要记忆化吗。
9.树上问题：是树形 dp、树上贪心、或者是在树上搜索。
10.图论：依靠什么样的关系建图，是求环统计结果还是最短路。
11.组合数学：有几种值，每种值如何被组成，容斥关系是什么。
12.交互题：log(n)次如何二分，2*n 次如何通过 n 次求出一些值，再根据剩余次数求答案。13.如果以上几种都不是，多半是有一个 point 你没有注意到，记住正难则反。*/
#pragma GCC optimize("O3,unroll-loops,Ofast,inline")
#include "bits/stdc++.h"

using i64 = int64_t;
using i128 =  __int128_t;

using u32 = uint32_t;
using u64 = uint64_t;
using u128 = __uint128_t;

using f32 = float;
using f64 = double;
using f80 = long double;

constexpr int INF = 0x3f3f3f3f;
constexpr i64 LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr i64 mod = 998'244'353LL;
constexpr i64 MOD = 1e9 + 7;

static inline void VioletEverGraden() {
    
/*
愿幸运女神与最纯粹的前行者同在。 
Test Sample

*/
}

signed main() {
#ifdef Algostruggler
    freopen("A.in", "r", stdin);
#endif // Algostruggler

    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

    // std::cout << std::fixed << std::setprecision(12), std::cerr << std::fixed << std::setprecision(12);

    // for (int _ = [&]() -> int { int T; std::cin >> T; return T; }(); _; _ --)
        VioletEverGraden();

    return 0;
}
`````

### 0.1、i128 库函数自定义

```````````c++
// 输入 i128
std::istream &operator >> (std::istream &is, i128 &n) {
    std::string s;
    is >> s;
    n = 0;
    bool neg = false;
    size_t i = 0;
    if (s[0] == '-') { 
        neg = true; i = 1; 
    }
    for (; i < s.size(); i ++) {
        n = n * 10 + (s[i] - '0');
    }
    if (neg) {
        n = -n;
    }
    return is;
}

// 输出 i128
std::ostream &operator<<(std::ostream &os, i128 n) {
    if (n == 0) {
        return os << 0;
    }
    std::string s;
    while (n > 0) {
        s += char('0' + n % 10);
        n /= 10;
    }
    std::reverse(s.begin(), s.end());
    return os << s;
}

// 字符串转 i128
i128 toi128(const std::string &s) {
    i128 n = 0;
    for (auto c : s) {
        n = n * 10 + (c - '0');
    }
    return n;
}

// 整数平方根（向下取整）
i128 sqrti128(i128 n) {
    i128 lo = 0, hi = 1E16;
    while (lo < hi) {
        i128 x = (lo + hi + 1) / 2;
        if (x * x <= n) {
            lo = x;
        } else {
            hi = x - 1;
        }
    }
    return lo;
}

// 最大公约数（非负）
i128 gcd(i128 a, i128 b) {
    while (b) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}
```````````

### 0.2、常用库函数重载

`````c++
// 上取整下取整
i64 ceilDiv(i64 n, i64 m) {
    if (n >= 0) {
        return (n + m - 1) / m;
    } else {
        return n / m;
    }
}
 
i64 floorDiv(i64 n, i64 m) {
    if (n >= 0) {
        return n / m;
    } else {
        return (n - m + 1) / m;
    }
}

// 最大值赋值
template<class T>
void chmax(T &a, T b) {
    if (a < b) {
        a = b;
    }
}

// 最大公约数
i128 gcd(i128 a, i128 b) {
    return b ? gcd(b, a % b) : a;
}

// 精确开平方
i64 sqrt(i64 n) {
    i64 s = std::sqrt(n);
    while (s * s > n) {
        s--;
    }
    while ((s + 1) * (s + 1) <= n) {
        s++;
    }
    return s;
}

// 精确开平方
i64 get(i64 n) {
    i64 u = std::sqrt(2.0L * n);
    while (u * (u + 1) / 2 < n) {
        u++;
    }
    while (u * (u - 1) / 2 + 1 > n) {
        u--;
    }
    return u;
}

// 求 Log
int logi(int a, int b) {
    int t = 0;
    i64 v = 1;
    while (v < b) {
        v *= a;
        t++;
    }
    return t;
}
 
int llog(int a, int b) {
    if (a <= b) {
        int l = logi(a, b);
        return (l == 0 ? 0 : std::__lg(2 * l - 1));
    }
    int l = logi(b, a + 1) - 1;
    assert(l > 0);
    return -std::__lg(l);
}
`````

## 一、基础算法

### 1.1、二分与三分

#### 整数二分

* 在递增序列 $A$ 中查找 $\ge x$ 数中最小的一个（即 $x$ 或 $x$ 的后继）。

`````c++
int L = 0, R = 1E8, ans = R;
while (L <= R) {
    int mid = L + R >> 1;
    if (check(mid)) {
        R = mid - 1;
        ans = mid;
    } else {
        L = mid + 1;
    }
}
return ans;
`````

* 在递增序列 $A$ 中查找 $\leq x$ 数中最大的一个（即 $x$ 或 $x$ 的前驱）。

`````c++
int L = 0, R = 1E8, ans = L;
while (L <= R) {
    int mid = L + R >> 2;
    if (check(mid)) {
        L = mid + 1;
        ans = mid;
    } else {
        R = mid - 1;
    }
}
return ans;
`````

#### 实数二分

目前主流的写法是限制二分次数。

```c++
using f80 = long double;
for (int t = 1; t <= 100; t ++) {
    f80 mid = (L + R) / 2;
    if (check(mid)) {
        r = mid;
    } else {
        L = mid;
    }
}
std::cout << L << '\n';
```

#### 整数三分

````c++
while (L < R) {
    int mid = (L + R) / 2;
    if (check(mid) <= check(mid + 1)) {
        R = mid;
    } else {
        L = mid + 1;
    }
}
std::cout << check(L) << '\n';
````

#### 实数三分

```c++
using f80 = long double;
f80 L = -1E9, R = 1E9;
for (int t = 1; t <= 100; t ++) {
    f80 mid1 = (L * 2 + R) / 3;
    f80 mid2 = (L + R * 2) / 3;
    if (check(mid1) < check(mid2)) {
        R = mid2;
    } else {
        L = mid1;
    }
}
std::cout << L << endl;
```

## 二、STL 与库函数

### 2.1 pb_ds 库

其中 gp_hash_table 使用的最多，其等价于 unordered_map，内部是无序的。

```cpp
#include <bits/exec.h>
#include <ext/pb_ds/assoc_container.hpp>
template<class S, class T> using omap = __gnu_pbds::gp_hash_table<S, T, myhash>;
```

###  2.2、查找后继 lower_bound、upper_bound

lower 表示 $\ge$，upper 表示 $>$。使用前记得先进行排序

```c++
//返回a数组[start,end)区间中第一个>=x的地址【地址！！！】
cout << lower_bound(a + start, a + end, x);

cout << lower_bound(a, a + n, x) - a; //在a数组中查找第一个>=x的元素下标
upper_bound(a, a + n, k) - lower_bound(a, a + n, k); //查找k在a中出现了几次
```

### 2.3、数组打乱 shuffle

`````c++
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
shuffle(ver.begin(), ver.end(), rnd);
`````

### 2.4、二分搜索 binary_search

用于查找某一元素是否在容器中，相当于 find 函数。在使用前需要先进行排序。

`````c++
//在a数组[start,end)区间中查找x是否存在，返回bool型
cout << binary_search(a + start, a + end, x);
`````

### 2..5、批量递增赋值函数 iota

`````c++
//将a数组[start,end)区间赋值成“x, x+1, x+2, ...”
iota(a + start, a + end, x);
`````

### 2..6、数组去重函数 unique

在使用前需要先进行排序。

其作用是，对于区间 [开始位置, 结束位置]，不停的把后面不重复的元素移到前面来，也可以说是用 **不重复的元素占领重复元素的位置**。并且返回去重后容器中不重复序列的最后一个元素的下一个元素。所以在进行操作后，数组、容器的大小并没有发生改变。

`````
//将a数组[start,end)区间去重，返回迭代器
unique(a + start, a + end);

//与erase函数结合，达到去重+删除的目的
a.erase(unique(ALL(a)), a.end());
`````

### 2.7、位运算函数 __builtin__

```c++
__builtin_popcount(x) // 返回x二进制下含1的数值，例如x=15=(1111)时答案为4
__builtin_ffs(x)     // 返回x右数第一个1的位置(1-idx)，1(1) 返回 1, 8(1000) 返回 4, 26(11010) 返回 2
__builtin_ctz(x)     // 返回x二进制下后导0的个数，1(1) 返回 0, 8(1000) 返回 3
bit_width(x)         // 返回x二进制下的位数，9(1001) 返回 4, 26(11010) 返回 5
```

注：以上函数的 `long long` 版本只需要在函数后面加上 `ll` 即可（例如 `__builtin_popcountll(x)`），`unsigned long long` 加上 `ull`。

### 2.8、数字转字符串函数

`itoa` 虽然能将整数转换成任意进制的字符串，但是其不是标准的C函数，且为Windows独有，且不支持 `long long`，建议手写。

`````c++
// to_string函数会直接将你的各种类型的数字转换为字符串。
// string to_string(T val);
double val = 12.12;
cout << to_string(val);
`````

`````c++
// 【不建议使用】itoa允许你将整数转换成任意进制的字符串，参数为待转换整数、目标字符数组、进制。
// char* itoa(int value, char* string, int radix);
char ans[10] = {};
itoa(12, ans, 2);
cout << ans << endl; /*1100*/

// 长整型函数名ltoa，最高支持到int型上限2^31。ultoa同理。
`````

### 2.9、字符串转数字

`````c++
// stoi直接使用
cout << stoi("12") << endl;

// 【不建议使用】stoi转换进制，参数为待转换字符串、起始位置、进制。
// int stoi(string value, int st, int radix);
cout << stoi("1010", 0, 2) << endl; /*10*/
cout << stoi("c", 0, 16) << endl;   /*12*/
cout << stoi("0x3f3f3f3f", 0, 0) << endl; /*1061109567*/

// 长整型函数名stoll，最高支持到long类型上限2^63。stoull、stod、stold同理。
`````

`````c++
// atoi直接使用，空字符返回0，允许正负符号，数字字符前有其他字符返回0，数字字符前有空字符自动去除
cout << atoi("12") << endl;
cout << atoi(" -12") << endl;   /*12*/
cout << atoi("-12abc") << endl; /*-12*/
cout << atoi("abc12") << endl;  /*0*/

// 长整型函数名atoll，最高支持到long类型上限2^63。
`````

### 2.10、全排列算法 next_permutation、prev_permutation

在提及这个函数时，我们先需要补充几点字典序相关的知识。

对于三个字符所组成的序列 {a,b,c}，其按照字典序的6种排列分别为：
{abc}, {acb}, {bac}, {cba}, {cab}, {cba}

其排序原理是：先固定 a（序列最小元素），再对之后的元素排列。而 b < c，所以 abc < acb。
同理，先固定 b（序列次小元素），再对之后的元素排列。即可得出以上序列。

next_permutation 算法，即是按照字典序顺序输出的全排列；相对应的，prev_permutation 则是按照逆字典序顺序输出的全排列。可以是数字，亦可以是其他类型元素。其直接在序列上进行更新，故直接输出序列即可。

```cpp
int n;
cin >> n;
vector<int> a(n);
// iota(a.begin(), a.end()), 1);
for (auto & it : a) cin >> it;
sort(a.begin(), a.end());

do {
    for (auto it : a) cout << it << " ";
    cout << endl;
} while (next_permutation(a.begin(), a.end()));
```

### 2.11、字符串转换为数值函数 sto

可以快捷的将一串字符串转换为指定进制的数字。

使用方法

- `stoi`(字符串, 0, x进制)：将一串 x 进制的字符串转换为 int 型数字。

`````c++
void Solve() {
    cout << stoi("1010", 0, 2) << endl;
    cout << stoi("c", 0, 16) << endl;
    cout << stoi("0x3f3f3f3f", 0, 0) << endl;
    cout << stoi("10", 0, 8) << endl;
    cout << stoll("aaaaaaaaaa", 0, 16) << endl;
}
`````

输出示例：

`````output
10
12
1061109567
8
11728124029610
`````

### 2.12、数值转换为字符串函数 to_string

允许将各种数值类型转换为字符串类型。

```cpp
// 将数值num转换为字符串
string s = to_string(num);
```

### 2.13、 判断非递减 is_sorted

`````c++
// a数组[start,end)区间是否是非递减的，返回bool型
cout << is_sorted(a + start, a + end);
`````

### 2.14、累加 accumulate

`````c++
// 将a数组[start,end)区间的元素进行累加，并输出累加和+x的值
cout << accumulate(a + start, a + end, x);
`````

### 2.15、迭代器 iterator

`````c++
// 构建一个UuU容器的正向迭代器，名字叫it
UUU::iterator it;

vector<int>::iterator it; // 创建一个正向迭代器，++ 操作时指向下一个
vector<int>::reverse_iterator it; // 创建一个反向迭代器，++ 操作时指向上一个
`````

### 2.16、其他函数

`exp2(x)` : 返回 $2^x$

`log2(x)` : 返回 $\log_2(x)$

`gcd(x, y)` / `lcm(x, y)` : 以 log 的复杂度返回 gcd($|x|$, $|y|$) 与 lcm($|x|$, $|y|$)，且返回值符号也为正数。

### 2.17、容器与成员函数

#### 元组 tuple

```c++
// 获取obj对象中的第index个元素—get<index>(obj)
// 需要注意的是这里的index只能手动输入，使用for循环这样的自动输入是不可以的
tuple<string, int, int> Student = {"Wida", 23, 45000};
cout << get<0>(Student) << endl; // 获取Student对象中的第一个元素，这里的输出结果应为“Wida”
```

#### 数组 array

```c++
array<int, 3> x; // 建立一个包含三个元素的数组x

// 跟正常数组一样，可以使用随机访问
cout << x[0]; // 获取数组的第一个元素
```

#### 变长数组 vector

```cpp
resize(n)        // 重设容器大小，但是不改变已有元素的值
assign(n, θ)     // 重设容器大小为 n，且替换容器内的内容为 θ

// 尽量不要使用[]的形式声明多维变长数组，而是使用嵌套的方式替代
vector<int> ver[n + 1];           // 不好的声明方式
vector<vector<int>> ver(n + 1);

// 嵌套时只需要在最后一个注明变量类型
vector dis(n + 1, vector<int>(m + 1));
vector dis(m + 1, vector(n + 1, vector<int>(n + 1)));
```

#### 栈 stack

栈顶入，栈顶出。先进后出。

```c++
// 没有clear函数
size() / empty()
push(x)   // 向栈顶插入 x
top()     // 获取栈顶元素
pop()     // 弹出栈顶元素
```

#### 队列 queue

队尾进，队头出。先进先出。

```c++
// 没有clear函数
size() / empty()
push(x)   // 向队尾插入 x
front() / back()   // 获取队头、队尾元素
pop()     // 弹出队头元素

// 没有clear函数，但是可以用重新构造替代
queue<int> q;
q = queue<int>();
```

#### 双向队列 deque

```c++
size() / empty() / clear()
push_front(x) / push_back(x)
pop_front(x) / pop_back(x)
front() / back()
begin() / end()
[]
```

#### 优先队列 priority_queue

默认升序（大根堆），自定义排序需要重载 `<`。

```c++
// 没有clear函数
priority_queue<int, vector<int>, greater<int>> p;   // 重定义为降序（小根堆）
push(x);   // 向堆中插入 x
top();     // 获取堆顶元素
pop();     // 弹出堆顶元素
// 重载运算符【注意，符号相反！！！】
struct Node {
    int x; string s;
    friend bool operator < (const Node &a, const Node &b) {
        if (a.x != b.x) return a.x > b.x;
        return a.s > b.s;
    }
};
```

#### 字符串 string

```c++
size() / empty() / clear()

// 从字符串s的S[start]开始，取出长度为len的子串—S.substr(start, len)
// len省略时默认取到结尾，超过字符串长度时也默认取到结尾
cout << S.substr(1, 12);

find(x) / rfind(x);   // 顺序、逆序查找x，返回下标，没找到时返回一个极大值【！建议与 size() 比较，而不要和 -1 比较，后者可能出错】
// 注意，没有count函数
```

#### 有序、多重有序集合 set、multiset

默认升序（大根堆），set 去重，multiset 不去重，O(log N)。

```c++
set<int, greater<> > s;   // 重定义为降序（小根堆）
size() / empty() / clear()
begin() / end()
++ / --   // 返回前驱、后继

insert(x);                // 插入x
find(x) / rfind(x);       // 顺序、逆序查找x，返回迭代器【迭代器！！！】，没找到时返回end()
count(x);                 // 返回x的个数
lower_count(x);           // 返回第一个>=x的迭代器【迭代器！！！】
upper_count(x);           // 返回第一个>x的迭代器【迭代器！！！】
```

特殊函数 next 和 prev 详解：

```c++
auto it = s.find(x);      // 建立一个迭代器
prev(it) / next(it);      // 默认返回迭代器it的前/后一个迭代器
prev(it, 2) / next(it, 2);// 可选参数可以控制返回前/后任意个迭代器

/* 以下是一些应用 */
auto pre = prev(s.lower_bound(x));  // 返回第一个<x的迭代器
int ed = *prev(S.end(), 1);         // 返回最后一个元素
```



`erase(x);` 有两种删除方式：

- 当 `x` 为某一元素时，删除所有这个数，复杂度为 $O(num_x + \log N)$；
- 当 `x` 为迭代器时，删除这个迭代器。

```cpp
// 连续头部删除
set<int> S = {0, 9, 98, 1087, 894, 34, 756};
auto it = S.begin();
int len = S.size();
for (int i = 0; i < len; ++i) {
    if (*it >= 500) continue;
    it = S.erase(it); // 删除所有小于500的元素
}
// 错误用法如下【千万不能这样用！！！】
// for (auto it : S) {
//     if (it >= 500) continue;
//     S.erase(it); // 删除所有小于500的元素
// }
```

#### map、multimap

默认升序（大根堆），map 去重，multimap 不去重，$O(\log S)$，其中 $S$ 为元素数量。

```c++
map<int, int, greater<> > mp;   // 重定义为降序（小根堆）
size() / empty() / clear()
begin() / end()
++ / --   // 返回前驱、后继

insert({x, y});       // 插入二元组
[]                    // 随机访问，multimap不支持
count(x);             // 返回x为下标的个数
lower_bound(x);       // 返回第一个下标>=x的迭代器
upper_bound(x);       // 返回第一个下标>x的迭代器
```

`erase(x);` 有两种删除方式：

- 当 `x` 为某一元素时，删除所有以这个元素为下标的二元组，复杂度为 $O(num_x + \log N)$；
- 当 `x` 为迭代器时，删除这个迭代器。

**慎用随机访问！** ——当不确定某次查询是否存在于容器中时，不要直接使用下标查询，而是先使用 `count()` 或者 `find()` 方法检查key值，防止不必要的零值二元组被构造。

```c++
int q = 0;
if (mp.count(i)) q = mp[i];
```

慎用自带的 pair、tuple 作为key值类型！使用自定义结构体！

```c++
struct fff {
    LL x, y;
    friend bool operator < (const fff &a, const fff &b) {
        if (a.x != b.x) return a.x < b.x;
        return a.y < b.y;
    }
};
map<fff, int> mp;
```

#### bitset

将数据转换为二进制，从高位到低位排序，以 0 为最低位。当位数相同时支持全部的位运算。

```c++
// 如果输入的是01字符串，可以直接使用“>>”读入
bitset<10> s;
cin >> s;

// 使用只含01的字符串构造—bitset<容器长度>B（字符串）
string S; cin >> S;
bitset<32> B (S);

// 使用整数构造（两种方式）
int x; cin >> x;
bitset<32> B1 (x);
bitset<32> B2 = x;

// 构造时，头括号里的数字不能是变量
int x; cin >> x;
bitset<x> ans; // 错误构造

[] // 随机访问
set(x)        // 将第x位置1，x省略时默认全部位置1
reset(x)      // 将第x位置0，x省略时默认全部位置0
flip(x)       // 将第x位取反，x省略时默认全部位取反
to_ullong()   // 重转换为ULL类型
to_string()   // 重转换为ULL类型
count()       // 返回1的个数
any()         // 判断是否至少有一个1
none()        // 判断是否全为0

bitset<23> B1("11101001"), B2("11101000");
cout << (B1 ^ B2) << "\n"; // 按位异或
cout << (B1 | B2) << "\n"; // 按位或
cout << (B1 & B2) << "\n"; // 按位与
cout << (B1 == B2) << "\n"; // 比较是否相等
cout << B1 << " " << B2 << "\n"; // 你可以直接使用cout输出
```

### 2.18、程序标准化

#### 使用 Lambda 函数

- **function** 统一写法

需要注意的是，虽然 `function` 定义时已经声明了返回值类型了，但是有的时候会出错（例如，声明返回 `long long` 但是返回 `int`，原因没去了解），所以推荐在后面使用 -> 再行声明一遍。

```cpp
function<void(int, int)> clac = [&](int x, int y) -> void {
    ;
    clac(1, 2);
}
function<bool(int)> dfs = [&](int x) -> bool {
    return dfs(x + 1);
};
dfs(1);
```

- **auto** 非递归写法

不需要使用递归函数时，直接用 `auto` 替换 `function` 即可。

```c++
auto clac = [&](int x, int y) -> void {
    ;
}
```

- **auto** 递归写法

相较于 `function` 写法，需要额外引用一遍自身。

```c++
auto dfs = [&](auto self, int x) -> bool {
    return self(self, x + 1);
};
dfs(dfs, 1);
```

#### 使用构造函数

可以将一些必要的声明和预处理放在构造函数，在编译时，无论放置在程序的哪个位置，都会先于主函数进行。下方是我将输入流控制声明的过程。

```c++
int __FAST_IO__ = []() { // 函数名称可以随意修改
    ios::sync_with_stdio(0), cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12);
    freopen("out.txt", "r", stdin);
    freopen("in.txt", "w", stdout);
    return 0;
};
```

## 三、图论

### 3.1、树的直径 

树上任意两节点之间最长的简单路径即为树的「直径」。

显然，一棵树可以有多条直径，他们的长度相等。

#### 两次 $dfs$ 

定理：在一棵树上，从任意节点 $y$ 开始进行一次 DFS，到达的距离其最远的节点 $z$ 必为直径的一端。

`````c++
#include <bits/stdc++.h>

void VioletEverGraden() {
    int n;
    std::cin >> n;

    int tot = 1;
    struct Edge {
        int to; int nxt; int w;
    };
    std::vector<int> head(n + 1, -1);
    std::vector<Edge> G(2 * n + 10);
    auto AddEdge = [&](int u, int v, int w = 0) -> void {
        G[tot].to = v;
        G[tot].nxt = head[u];
        G[tot].w = w;
        head[u] = tot ++;
    };

    int __ = n - 1;
    while (__ --) {
        int u, v;
        std::cin >> u >> v;
        AddEdge(u, v); AddEdge(v, u);
    }

    std::vector<int> dis(n + 1, 0); int c;
    auto dfs = [&](auto&& dfs, int u, int fa) -> void {
    for (int i = head[u]; ~i; i = G[i].nxt) {
        int v = G[i].to;
        if (v == fa) {
            continue;
        }
        dis[v] = dis[u] + 1;
        if (dis[v] > dis[c]) {
            c = v;
        }
        dfs(dfs, v, u);
    }
};

    dfs(dfs, 1, 0);
    dis[c] = 0; 
    dfs(dfs, c, 0);

    std::cout << dis[c] << '\n';
}

signed main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

    // std::cout << std::fixed << std::setprecision(12), std::cerr << std::fixed << std::setprecision(12);

    // for (int _ = [&]() -> int { int T; std::cin >> T; return T; }(); _; _ --)
        VioletEverGraden();

    return 0;
}
`````

#### 树形 $DP$

树形 DP 可以在存在负权边的情况下求解出树的直径

```c++
#include <bits/stdc++.h>

void VioletEverGraden() {
    int n;
    std::cin >> n;

    int tot = 1;
    struct Edge {
        int to; int nxt; int w;
    };
    std::vector<int> head(n + 1, -1);
    std::vector<Edge> G(2 * n + 10);
    auto AddEdge = [&](int u, int v, int w = 0) -> void {
        G[tot].to = v;
        G[tot].nxt = head[u];
        G[tot].w = w;
        head[u] = tot ++;
    };

    int __ = n - 1;
    while (__ --) {
        int u, v;
        std::cin >> u >> v;
        AddEdge(u, v); AddEdge(v, u);
    }

    std::vector<int> dp(n + 1, 0);
    int d = 0;
    auto dfs = [&](auto &&dfs, int u, int fa) -> void {
        for (int i = head[u]; ~i; i = G[i].nxt) {
            int v = G[i].to;
            if (v == fa) {
                continue;
            }
            dfs(dfs, v, u);
            d = std::max(d, dp[u] + dp[v] + 1);
            dp[u] = std::max(dp[u], dp[v] + 1);
        }
    };

    dfs(dfs, 1, 0);

    std::cout << d << '\n';
}

signed main() {
    std::cin.tie(nullptr) ->
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);

signed main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

    // std::cout << std::fixed << std::setprecision(12), std::cerr << std::fixed << std::setprecision(12);

    // for (int _ = [&]() -> int { int T; std::cin >> T; return T; }(); _; _ --)
        VioletEverGraden();

    return 0;
}
```

### 3.2、树的中心

在树中，如果节点 $x$ 作为根节点时，从 $x$ 出发的最长链最短，那么称 $x$ 为这棵树的中心。

- 树的中心不一定唯一，但最多有 2![2](data:image/gif;base64,R0lGODlhAQABAIAAAAAAAP///yH5BAEAAAAALAAAAAABAAEAAAIBRAA7) 个，且这两个中心是相邻的。
- 树的中心一定位于树的直径上。
- 树上所有点到其最远点的路径一定交会于树的中心。
- 当树的中心为根节点时，其到达直径端点的两条链分别为最长链和次长链。
- 当通过在两棵树间连一条边以合并为一棵树时，连接两棵树的中心可以使新树的直径最小。
- 树的中心到其他任意节点的距离不超过树直径的一半。

`````c++
#include <bits/stdc++.h>

void VioletEverGraden() {
    int n, m;
    std::cin >> n >> m;

    int tot = 1;
    struct Edge {
        int to; int nxt; int w;
    };
    std::vector<int> head(n + 1, -1);
    std::vector<Edge> G(2 * m + 10);
    auto AddEdge = [&](int u, int v, int w = 0) -> void {
        G[tot].to = v;
        G[tot].nxt = head[u];
        G[tot].w = w;
        head[u] = tot ++;
    };

    int __ = m;
    while (__ --) {
        int u, v, w;
        std::cin >> u >> v >> w;
        AddEdge(u, v, w); AddEdge(v, u, w);
    }

    std::vector<int> d1(n + 1, 0), d2(n + 1, 0), up(n + 1, 0);
    int c1 = 0, c2 = 0, min = 1e9;

    auto dfs1 = [&](auto &&dfs1, int u, int fa) -> void {
        for (int i = head[u]; ~i; i = G[i].nxt) {
            int v = G[i].to; int w = G[i].w;
            if (v == fa) {
                continue;
            }
            dfs1(dfs1, v, u);
            if (d1[v] + w > d1[u]) {
                d2[u] = d1[u];
                d1[u] = d1[v] + w;
            } else if (d1[v] + w > d2[u]) {
                d2[u] = d1[v] + w;
            }
        }
    };

    auto dfs2 = [&](auto &&dfs2, int u, int fa) -> void {
        for (int i = head[u]; ~i; i = G[i].nxt) {
            int v = G[i].to; int w = G[i].w;
            if (v == fa) {
                continue;
            }
            up[v] = up[u] + w;
            if (d1[v] + w != d1[u]) {
                up[v] = std::max(up[v], d1[u] + w);
            } else {
                up[v] = std::max(up[v], d2[u] + w);
            }
            dfs2(dfs2, v, u);
        }
    };

    auto center = [&]() -> void {
        dfs1(dfs1, 1, 0); dfs2(dfs2, 1, 0);
        for (int i = 1; i <= n; i ++) {
            if (std::max(d1[i], up[i]) < min) {
                min = std::max(d1[i], up[i]);
                c1 = i; c2 = 0;
            } else if (std::max(d1[i], up[i]) == min) {
                c2 = i;
            }
        }
    };

    center();

    std::cout << c1 << ' ' << c2 << '\n';

/*
Test Sample

6 5
1 2 1
1 3 1
2 4 1
2 5 1
3 6 1

1 0


*/
}

signed main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

    // std::cout << std::fixed << std::setprecision(12), std::cerr << std::fixed << std::setprecision(12);

    // for (int _ = [&]() -> int { int T; std::cin >> T; return T; }(); _; _ --)
        VioletEverGraden();

    return 0;
}
`````

### 3.3、树的重心

### 3.4、最近公共祖先

1. 单个节点的 LCA 为其自身：  $\text{LCA}(\{u\}) = u$

2. 祖先判定：  $u$ 是 $v$ 的祖先 **当且仅当**  $\text{LCA}(u, v) = u$

3. 若 $u$ 不是 $v$ 的祖先，且 $v$ 也不是 $u$ 的祖先，则 $u, v$ 分别位于 $\text{LCA}(u, v)$ 的两棵不同子树中。

4. 遍历顺序特性：  
   - 在前序遍历中，$\text{LCA}(S)$ 出现在集合 $S$ 中所有元素**之前**。  
   - 在后序遍历中，$\text{LCA}(S)$ 出现在集合 $S$ 中所有元素**之后**。

5. 集合合并的 LCA 满足结合律：  $\text{LCA}(A \cup B) = \text{LCA}\big(\text{LCA}(A),\; \text{LCA}(B)\big)$

6. 路径性质：  两点的 LCA 必定位于这两点之间的最短路径上。

7. 距离公式：  设 $h(x)$ 表示节点 $x$ 到树根的距离（深度），则树上两点 $u, v$ 之间的距离为：$d(u, v) = h(u) + h(v) - 2 \cdot h\big(\text{LCA}(u, v)\big)$

#### 倍增法

`````c++
#include <bits/stdc++.h>

using i64 = long long;

void VioletEverGraden() {
    int n, m, r;
    std::cin >> n >> m >> r;

    int tot = 1;
    std::vector<int> head(n + 1, -1);
    struct Edge {
        int to; int nxt; int w;
    };
    std::vector<Edge> G(2 * m + 10);
    auto AddEdge = [&](int u, int v, int w = 0) -> void {
        G[tot].to = v;
        G[tot].nxt = head[u];
        G[tot].w = w;
        head[u] = tot ++;
    };

    int __ = n - 1;
    while (__ --) {
        int u, v;
        std::cin >> u >> v;
        AddEdge(u, v); AddEdge(v, u);
    }

    std::vector<std::vector<int>> fa(31, std::vector<int> (n + 1, 0));
    std::vector<int> dep(n + 1, 0);
    auto dfs = [&](auto &&dfs, int u, int p) -> void {
        fa[0][u] = p;
        dep[u] = dep[p] + 1;

        for (int i = 1; i <= 30; i ++) {
            fa[i][u] = fa[i - 1][fa[i - 1][u]];
        }

        for (int i = head[u]; ~i; i = G[i].nxt) {
            int v = G[i].to;
            if (v == p) {
                continue;
            }
            dfs(dfs, v, u);
        }
    };

    dfs(dfs, r, 0);

    auto LCA = [&](int u, int v) -> int {
        if (dep[u] > dep[v]) {
            std::swap(u, v);
        }
        int dif = dep[v] - dep[u];
        for (int i = 0; dif; dif >>= 1, i ++) {
            if (dif & 1) {
                v = fa[i][v];
            }
        }

        if (u == v) {
            return u;
        }

        for (int i = 30; i >= 0; i --) {
            if (fa[i][u] != fa[i][v]) {
                u = fa[i][u];
                v = fa[i][v];
            }
        }

        return fa[0][u];
    };

    __ = m;
    while (__ --) {
        int u, v;
        std::cin >> u >> v;

        std::cout << LCA(u, v) << '\n';
    }

/*
Test Sample

5 5 4
3 1
2 4
5 1
1 4
2 4
3 2
3 5
1 2
4 5

4
4
1
4
4


*/
}

signed main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

    // std::cout << std::fixed << std::setprecision(12), std::cerr << std::fixed << std::setprecision(12);

    // for (int _ = [&]() -> int { int T; std::cin >> T; return T; }(); _; _ --)
        VioletEverGraden();

    return 0;
}
`````

### 3.5、图的定义

- oriented graph：有向图
- bidirectional edges：双向边
- 二分图：一个图能被分为左右两部分，任何一条边的两个端点都不在同一部分中。
- 平面图：若能将无向图 $G = (V,E)$ 画在平面上使得任意两条无重合顶点的边不相交，则称 $G$ 是平面图。
- 匹配：一个边的集合，这些边没有公共顶点。
- 割点（割顶）：将与某点 $i$ 连接的所有边删去后，原图分成两个以上不相连的子图，称 $i$ 为图的割点。
- 点双连通：在一张连通的无向图中，对于两个点 $u$ 和 $v$，删去任何一个点（只能删去一个，且不能删 $u$ 和 $v$ 自己）它们依旧连通，则称 $u$ 和 $v$ 点双连通。如果一个图不存在割点，那么它是一个点双连通图。
- 割边（桥）：将某边 $e$ 删去后，原图分成两个以上不相连的子图，称 $e$ 为图的割边。
- 边双连通：在一张连通的无向图中，对于两个点 $u$ 和 $v$，删去任何一条边（只能删去一条）它们依旧连通，则称 $u$ 和 $v$ 边双连通。一个图如果不存在割边，则它是一个边双连通图。
- 无向正权图上某一点的偏心距：记为 $ecc(u) = \max {dist(u,v)}$。
- 图的直径：定义为 $d = \max {ecc(u)}$。
- 图的中心：定义为 $arg = \min {ecc(u)}$。
- 图的绝对中心：可以定义在边上的图的中心。
- 图的半径：定义为 $r = \min {ecc(u)}$。

### 3.6、拓扑排序

假设这个图 $ G = (V, E) $ 在初始化入度为 $ 0 $ 的集合 $ S $ 的时候就需要遍历整个图，并检查每一条边，因而有 $ O(E + V) $ 的复杂度。然后对该集合进行操作，显然也是需要 $ O(E + V) $ 的时间复杂度。

因而总的时间复杂度为 $ O(E + V) $。
```cpp
#include <bits/stdc++.h>

using ll = long long;
#define rep(i, l, r, x) for (int i = l; i <= r; i += x)
const int MAXN = 0;

int n, m;
int u, v;

void violet() {
    std::cin >> n >> m;

    int tot = 1;
    std::vector<int> head(n + 1, -1);
    struct Edge { 
        int to; int nxt; 
    };
    std::vector<Edge> G(m + 10);
    auto AddEdge = [&](int u, int v) -> void {
        G[tot].to = v; 
        G[tot].nxt = head[u]; 
        head[u] = tot ++;
    };

    int __ = m;
    std::vector<int> indeg(n + 1, 0);
    while (__ --) {
        std::cin >> u >> v;
        AddEdge(u, v);
        indeg[v] ++;
    }

    std::vector<int> topo; topo.push_back(-1);
    auto toposort = [&]() -> void {
        std::queue<int> q;
        rep(i, 1, n, 1) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            auto u = q.front();
            q.pop();
            topo.push_back(u);

            for (int i = head[u]; ~i; i = G[i].nxt) {
                int v = G[i].to;
                indeg[v] --;
                if (indeg[v] == 0) {
                    q.push(v);
                }
            }
        }
    };

    toposort();

    if (topo.size() == n + 1) {
        for (int i = 1; i <= n; i ++) {
            std::cout << topo[i] << " \n"[i == n];
        }
    } else {
        std::cout << -1 << '\n';
    }

/*
Test Sample
5 4
1 2
2 3
3 4
4 5

1 2 3 4 5
*/
}

signed main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout.tie(nullptr);

    int _ = 1;
    // for (std::cin >> _; _; _ --)
        violet();

    return 0;
}
```
**合理性证明**

考虑一个图，删掉某个入度为 $0$ 的节点之后，如果新图可以拓扑排序，那么原图一定也可以。反过来，如果原图可以拓扑排序，那么删掉后也可以。

**应用**

拓扑排序可以判断图中是否有环，还可以用来判断图是否是一条链。拓扑排序可以用来求 $AOE$ 网中的关键路径，估算工程完成的最短时间。

**求字典序最大/最小的拓扑排序**

将 $Kahn$ 算法中的队列替换成最大堆/最小堆实现的优先队列即可，此时总的时间复杂度为 $ O(E + V \log V) $。

### 3.7 、最短路

#### 性质

对于边权为正的图，任意两个结点之间的最短路，不会经过重复的结点。

对于边权为正的图，任意两个结点之间的最短路，不会经过重复的边。

对于边权为正的图，任意两个结点之间的最短路，任意一条的结点数不会超过 \( n \)，边数不会超过 \( n-1 \)。

#### $Floyd$

是全源最短路。

适用于任何图，不管有向无向，边权正负，但是最短路必须存在。（不能有个负环）

```c++
#include <bits/stdc++.h>

using ll = long long;
const int INF = 0x3f3f3f3f;
const int MAXN = 0;

void violet() {
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> G(n + 1, std::vector<int> (n + 1, INF));
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            std::cin >> G[i][j];
            if (G[i][j] == -1) {
                G[i][j] = INF;
            }
        }
    }

    for (int k = 1; k <= n; k ++) {
        for (int u = 1; u <= n; u ++) {
            for (int v = 1; v <= n; v ++) {
                G[u][v] = std::min(G[u][v], G[u][k] + G[k][v]);
            }
        }
    }

    for (int u = 1; u <= n; u ++) {
        for (int v = 1; v <= n; v ++) {
            if (G[u][v] == INF) {
                std::cout << -1 << " \n"[v == n];
            } else {
                std::cout << G[u][v] << " \n"[v == n];
            }
        }
    }

/*
Test Sample

4
0 1 -1 -1
-1 0 1 -1
-1 -1 0 1
1 -1 -1 0

0 1 2 3
3 0 1 2
2 3 0 1
1 2 3 0
*/
}

signed main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout.tie(nullptr);

    int _ = 1;
    // for (std::cin >> _; _; _ --)
        violet();

    return 0;
}
```
#### $Bellman–Ford$

$Bellman–Ford$ 算法是一种基于松弛（$relax$）操作的最短路算法，可以求出有负权的图的最短路，并可以对最短路不存在的情况进行判断。

对于边 \( (u, v) \)，松弛操作对应下面的式子：
$$
\operatorname{dis}(v) = \min(\operatorname{dis}(v), \operatorname{dis}(u) + w(u, v)).
$$
Bellman–Ford 算法所做的，就是不断尝试对图上每一条边进行松弛。我们每进行一轮循环，就对图上所有的边都尝试进行一次松弛操作，当一次循环中没有成功的松弛操作时，算法停止。

每次循环是 \( O(m) \) 的，在最短路存在的情况下，由于一次松弛操作会使最短路的边数至少 \( +1 \)，而最短路的边数最多为 \( n - 1 \)，因此整个算法最多执行 \( n - 1 \) 轮松弛操作。故总时间复杂度为 \( O(nm) \)。

但还有一种情况，如果从 \( S \) 点出发，抵达一个负环时，松弛操作会无休止地进行下去。注意到前面的论证中已经说明了，对于最短路存在的图，松弛操作最多只会执行 \( n - 1 \) 轮，因此如果第 \( n \) 轮循环时仍然存在能松弛的边，说明从 \( S \) 点出发，能够抵达一个负环。
```c++
#include <bits/stdc++.h>

using ll = long long;
#define rep(i, l, r, x) for (int i = l; i <= r; i += x)
constexpr int INF = 0x3f3f3f3f;
constexpr int MAXN = 0;

int n, m;
int u, v, w;

void violet() {
    std::cin >> n >> m;

    int tot = 1;
    std::vector<int> head(n + 1, -1);
    struct Edge {
        int to; int nxt; int w;
    };
    std::vector<Edge> G(2 * m + 10);
    auto AddEdge = [&](int u, int v, int w) -> void {
        G[tot].to = v;
        G[tot].w = w;
        G[tot].nxt = head[u];
        head[u] = tot ++;
    };

    int __ = m; 
    while (__ --) {
        std::cin >> u >> v >> w;
        if (w >= 0) {
            AddEdge(u, v, w); AddEdge(v, u, w);
        } else {
            AddEdge(u, v, w);
        }
    }

    std::vector<int> dis(n + 1, INF);
    auto Bellman_Ford = [&](int s) -> bool {
        dis[s] = 0;
        bool ok = false;
        for (int k = 1; k <= n; k ++) {
            ok = false;
            for (int u = 1; u <= n; u ++) {
                if (dis[u] == INF) continue;
                for (int i = head[u]; ~i; i = G[i].nxt) {
                    int v = G[i].to; int w = G[i].w;
                    if (dis[v] > dis[u] + w) {
                        dis[v] = dis[u] + w;
                        ok = true;
                    }
                }
            }
            if (!ok) {
                break;
            }
        }
        return ok;
    };

    if (Bellman_Ford(1)) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }

/*
Test Sample

2
3 4
1 2 2
1 3 4
2 3 1
3 1 -3
3 3
1 2 3
2 3 4
3 1 -8

NO
YES
*/
}

signed main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout.tie(nullptr);

    int _ = 1;
    for (std::cin >> _; _; _ --)
        violet();

    return 0;
}
```
#### $SPFA$

即 $Shortest$ $Path$ $Faster$ $Algorithm$ 。

基于 $Bellman–Ford$ 的基础，使用队列优化。

很多时候我们并不需要那么多无用的松弛操作。

很显然，只有上一次被松弛的结点，所连接的边，才有可能引起下一次的松弛操作。

那么我们用队列来维护「哪些结点可能会引起松弛操作」，就能只访问必要的边了。

SPFA 也可以用于判断 \( s \) 点是否能抵达一个负环，只需记录最短路经过了多少条边，当经过了至少 \( n \) 条边时，说明 \( s \) 点可以抵达一个负环。
```c++
#include <bits/stdc++.h>

using ll = long long;
#define rep(i, l, r, x) for (int i = l; i <= r; i += x)
constexpr int INF = 0x3f3f3f3f;
constexpr int MAXN = 2e3 + 6;

int n, m;
int u, v, w;

void violet() {
    std::cin >> n >> m;

    int tot = 1;
    std::vector<int> head(n + 1, -1);
    struct Edge {
        int to; int nxt; int w;
    };
    std::vector<Edge> G(2 * m + 10);
    auto AddEdge = [&](int u, int v, int w) -> void {
        G[tot].to = v;
        G[tot].w = w;
        G[tot].nxt = head[u];
        head[u] = tot ++;
    };

    int __ = m; 
    while (__ --) {
        std::cin >> u >> v >> w;
        if (w >= 0) {
            AddEdge(u, v, w); AddEdge(v, u, w);
        } else {
            AddEdge(u, v, w);
        }
    }

    std::vector<int> dis(n + 1, INF);
    std::vector<int> cnt(n + 1, 0);
    bool vis[MAXN] = { false };
    auto SPFA = [&](int s) -> bool {
        std::queue<int> q;

        dis[s] = 0; vis[s] = 1; q.push(s);
        while (!q.empty()) {
            int u = q.front();
            q.pop(); vis[u] = false;
            for (int i = head[u]; ~i; i = G[i].nxt) {
                int v = G[i].to; int w = G[i].w;
                if (dis[v] > dis[u] + w) {
                    dis[v] = dis[u] + w; cnt[v] = cnt[u] + 1;
                    if (cnt[v] >= n) return false;
                    if (!vis[v]) {
                        q.push(v); vis[v] = true;
                    }
                }
            }
        }
        return true;
    };

    bool ok = SPFA(1);
    if (ok) {
        std::cout << "NO\n";
    } else{
        std::cout << "YES\n";
    }

/*
Test Sample

2
3 4
1 2 2
1 3 4
2 3 1
3 1 -3
3 3
1 2 3
2 3 4
3 1 -8

NO
YES
*/
}

signed main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout.tie(nullptr);

    int _ = 1;
    for (std::cin >> _; _; _ --)
        violet();

    return 0;
}
```
虽然在大多数情况下 $SPFA$ 跑得很快，但其最坏情况下的时间复杂度为 $O(nm)$ ，将其卡到这个复杂度也是不难的，所以考试时要谨慎使用（在没有负权边时最好使用 $Dijkstra$ 算法，在有负权边且题目中的图没有特殊性质时，若 $SPFA$ 是 $std$ 的一部分，题目不应当给出 $Bellman–Ford$ 无法通过的数据范围）。

#### $SPFA$ 的其他优化

* 堆优化：将队列换成堆，与 $Dijkstra$ 的区别是允许一个点多次入队。在有负权边的图可能被卡成指数级复杂度。
* 栈优化：将队列换成栈（即将原来的 $BFS$ 过程变成 $DFS$），在寻找负环时可能具有更高效率，但最坏时间复杂度仍然为指数级。
* $LLL$ 优化：将普通队列换成双端队列，每次将入队结点距离和队内距离平均值比较，如果更大则插入至队尾，否则插入队首。
* $SLF$ 优化：将普通队列换成双端队列，每次将入队结点距离和队首比较，如果更大则插入至队尾，否则插入队首。
* $D$ $\'Esopo–Pape$ 算法：将普通队列换成双端队列，如果一个节点之前没有入队，则将其插入队尾，否则插入队首。

#### $Djikstra$

$Djikstra$ 一般是按照下面的步骤来的：

将结点分成两个集合：已确定最短路长度的点集（记为 \( S \) 集合）和未确定最短路长度的点集（记为 \( T \) 集合）。一开始所有的点都属于 \( T \) 集合。

初始化 \( \operatorname{dis}(s) = 0 \)，其他点的 \( \operatorname{dis} \) 均为 \( +\infty \)。

然后重复这些操作：

1. 从 \( T \) 集合中，选取一个最短路长度最小的结点，移到 \( S \) 集合中。
2. 对那些刚刚被加入 \( S \) 集合的结点的所有出边执行松弛操作。

直到 \( T \) 集合为空，算法结束。

朴素的实现方法为每次 \( 2 \) 操作执行完毕后，直接在 \( T \) 集合中暴力寻找最短路长度最小的结点。\( 2 \) 操作总时间复杂度为 \( O(m) \)，\( 1 \) 操作总时间复杂度为 \( O(n^2) \)，全过程的时间复杂度为 \( O(n^2 + m) = O(n^2) \)。

可以用堆来优化这一过程：每成功松弛一条边 \( (u, v) \)，就将 \( v \) 插入堆中（如果 \( v \) 已经在堆中，直接执行 $Decrease-key$），\( 1 \) 操作直接取堆顶结点即可。共计 \( O(m) \) 次 $Decrease-key$ ，\( O(n) \) 次 $pop$ ，选择不同堆可以取到不同的复杂度。堆优化能做到的最优复杂度为 \( O(n\log n + m) \)，能做到这一复杂度的有斐波那契堆等。

特别地，可以使用优先队列维护，此时无法执行 $Decrease-key$ 操作，但可以通过每次松弛时重新插入该结点，且弹出时检查该结点是否已被松弛过，若是则跳过，复杂度 \( O(m\log n) \)，优点是实现较简单。

这里的堆也可以用线段树来实现，复杂度为 \( O(m\log n) \)，在一些特殊的非递归线段树实现下，该做法常数比堆更小。并且线段树支持的操作更多，在一些特殊图问题上只能用线段树来维护。

在稀疏图中，\( m = O(n) \)，堆优化的 $Dijkstra$ 算法具有较大的效率优势；而在稠密图中，\( m = O(n^2) \)，这时候使用朴素实现更优。
```c++
#include <bits/stdc++.h>

using ll = long long;
#define rep(i, l, r, x) for (int i = l; i <= r; i += x)
constexpr int INF = 0x3f3f3f3f;
const int MAXN = 0;

int n, m, s;
int u, v, w;

void violet() {
    std::cin >> n >> m >> s;

    int tot = 1;
    std::vector<int> head(n + 1, -1);
    struct Edge {
        int to; int nxt; int w;
    };
    std::vector<Edge> G(2 * m + 10);
    auto AddEdge = [&](int u, int v, int w) -> void {
        G[tot].to = v;
        G[tot].w = w;
        G[tot].nxt = head[u];
        head[u] = tot ++;
    };

    int __ = m;
    while (__ --) {
        std::cin >> u >> v >> w;
        AddEdge(u, v, w);
    }

    std::vector<int> dis(n + 1, INF);
    auto Dijkstra = [&](int s) -> void {
        dis[s] = 0;
        struct node {
            int id; int d;
            bool operator < (const node &a) const {
                return d > a.d;
            }
        };
        std::priority_queue<node> heap;
        heap.push({s, dis[s]});

        while (!heap.empty()) {
            auto [u, d] = heap.top();
            heap.pop();

            if (d > dis[u]) continue;
            for (int i = head[u]; ~i; i = G[i].nxt) {
                int v = G[i].to; int w = G[i].w;
                if (dis[v] > dis[u] + w) {
                    dis[v] = dis[u] + w;
                    heap.push({v, dis[v]});
                }
            }
        }
    };

    Dijkstra(1);

    for (int i = 1; i <= n; i ++) {
        std::cout << dis[i] << " \n"[i == n];
    }

/*
Test Sample

4 6 1
1 2 2
2 3 2
2 4 1
1 3 5
3 4 3
1 4 4

0 2 4 3
*/
}

signed main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout.tie(nullptr);

    int _ = 1;
    // for (std::cin >> _; _; _ --)
        violet();
        
    return 0;
}
```
#### $Johnson$

$Johnson$ 和 $Floyd$ 一样，是一种能求出无负环图上任意两点间最短路径的算法。

任意两点间的最短路可以通过枚举起点，跑 \( n \) 次 $Bellman–Ford$ 算法解决，时间复杂度是 \( O(n^2m) \) 的，也可以直接用 Floyd 算法解决，时间复杂度为 \( O(n^3) \)。

注意到堆优化的 $Dijkstra$ 算法求单源最短路径的时间复杂度比 $Bellman–Ford$ 更优，如果枚举起点，跑 \( n \) 次 $Dijkstra$ 算法，就可以在 \( O(nm\log m) \)（取决于 $Dijkstra$ 算法的实现）的时间复杂度内解决本问题，比上述跑 \( n \) 次 $Bellman–Ford$ 算法的时间复杂度更优秀，在稀疏图上也比 Floyd 算法的时间复杂度更加优秀。

但 $Dijkstra$ 算法不能正确求解带负权边的最短路，因此我们需要对原图上的边进行预处理，确保所有边的边权均非负。

$Johnson$ 算法则通过另外一种方法来给每条边重新标注边权。

我们新建一个虚拟节点（在这里我们就设它的编号为 \( 0 \)）。从这个点向其他所有点连一条边权为 \( 0 \) 的边。

接下来用 $Bellman–Ford$ 算法求出从 \( 0 \) 号点到其他所有点的最短路，记为 \( h_i \)。

假如存在一条从 \( u \) 点到 \( v \) 点，边权为 \( w \) 的边，则我们将该边的边权重新设置为 \( w + h_u - h_v \)。

接下来以每个点为起点，跑 \( n \) 轮 Dijkstra 算法即可求出任意两点间的最短路了。

一开始的 $Bellman\_Ford$ 算法并不是时间上的瓶颈，若使用$priority\_queue$ 实现 $Dijkstra$ 算法，该算法的时间复杂度是 \( O(nm\log m) \)。
```c++
#include <bits/stdc++.h>

using ll = long long;
#define rep(i, l, r, x) for (int i = l; i <= r; i += x)
constexpr int INF = 1e9;
const int MAXN = 1e5 + 5;

int n, m;
int u, v, w;

void violet() {
    std::cin >> n >> m;

    int tot = 1;
    std::vector<int> head(n + 10, -1);
    struct Edge {
        int to; int nxt; int w;
    };
    std::vector<Edge> G(n + m + 10);
    auto AddEdge = [&](int u, int v, int w) -> void {
        G[tot].to = v;
        G[tot].nxt = head[u];
        G[tot].w = w;
        head[u] = tot ++;
    };

    int __ = m;
    while (__ --) {
        std::cin >> u >> v >> w;
        AddEdge(u, v, w);
    }

    std::vector<ll> dis1(n + 10, INF);
    std::vector<ll> cnt(n + 10, 0);
    bool vis[MAXN] = { false };
    auto SPFA = [&](int s) -> bool {
        std::queue<int> q;

        dis1[s] = 0; vis[s] = 1; q.push(s);
        while (!q.empty()) {
            int u = q.front();
            q.pop(); vis[u] = false;
            for (int i = head[u]; ~i; i = G[i].nxt) {
                int v = G[i].to; int w = G[i].w;
                if (dis1[v] > dis1[u] + w) {
                    dis1[v] = dis1[u] + w; cnt[v] = cnt[u] + 1;
                    if (cnt[v] >= n + 1) return false;
                    if (!vis[v]) {
                        q.push(v); vis[v] = true;
                    }
                }
            }
        }
        return true;
    };

    for (int i = 1; i <= n; i ++) AddEdge(0, i, 0);
    if (!SPFA(0)) {
        std::cout << -1 << '\n';
        return ;
    }

    for (int u = 1; u <= n; u ++) {
        for (int i = head[u]; ~i; i = G[i].nxt) {
            int v = G[i].to;
            G[i].w += dis1[u] - dis1[v];
            if (G[i].w < 0) G[i].w = 0;
        }
    }

    std::vector<ll> dis2(n + 10, INF);
    auto Dijkstra = [&](int s) -> void {
        dis2.assign(n + 10, INF);
        dis2[s] = 0;
        struct node {
            int id; int d;
            bool operator < (const node &a) const {
                return d > a.d;
            }
        };
        std::priority_queue<node> heap;
        heap.push({s, dis2[s]});

        while (!heap.empty()) {
            auto [u, d] = heap.top();
            heap.pop();

            if (d > dis2[u]) continue;
            for (int i = head[u]; ~i; i = G[i].nxt) {
                int v = G[i].to; int w = G[i].w;
                if (dis2[v] > dis2[u] + w) {
                    dis2[v] = dis2[u] + w;
                    heap.push({v, dis2[v]});
                }
            }
        }
    };

    for (int i = 1; i <= n; i ++) {
        Dijkstra(i);
        ll ans = 0;
        for (int j = 1; j <= n; j ++) {
            if (dis2[j] == INF) {
                ans += 1LL * j * INF;
            } else {
                ans += 1LL * j * (dis2[j] + dis1[j] - dis1[i]);
            }
        }
        std::cout << ans << '\n';
    }

/* 
Test Sample
5 7
1 2 4
1 4 10
2 3 7
4 5 3
4 2 -2
3 4 -3
5 3 4

128
1000000072
999999978
1000000026
1000000014


5 5
1 2 4
3 4 9
3 4 -3
4 5 3
5 3 -2

-1
*/
}

signed main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout.tie(nullptr);

    int _ = 1;
    // for (std::cin >> _; _; _ --)
        violet();
        
    return 0;
}
```
#### 比较

| 最短路算法   | Floyd         | Bellman-Ford   | Dijkstra      | Johnson       |
|--------------|---------------|----------------|---------------|---------------|
| 最短路类型   | 每对结点之间的最短路 | 单源最短路      | 单源最短路     | 每对结点之间的最短路 |
| 作用于       | 任意图        | 任意图          | 非负权图      | 任意图         |
| 能否检测负环？| 能            | 能             | 不能          | 能            |
| 时间复杂度   | \( O(N^3) \)  | \( O(NM) \)    | \( O(M \log M) \) | \( O(NM \log M) \) |
#### 输出方案

开一个 $pre$ 数组，在更新距离的时候记录下来后面的点是如何转移过去的，算法结束前再递归地输出路径即可。

比如 $Floyd$ 就要记录 $pre[i][j] = k;$ ，$Bellman–Ford$ 和 $Dijkstra$ 一般记录 $pre[v] = u$。

### 3.8、生成树

#### 最小生成树

* $Kruskal$

````c++
* @Author: AlgoStruggler
* @Create Time: 2026-02-04 16:26:55
* "To the Splendor of ACM-ICPC, We Consecrate Our AC Triumphs."
*/
#define  _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize("O2")
#include "bits/stdc++.h"
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;

using i64 = long long;
using ldb = long double;
typedef unsigned long long u64;
typedef __int128 i128;

const double eps = 1e-9;
constexpr int INF = 0x3f3f3f3f;
constexpr i64 LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr i64 mod = 998244353;
constexpr i64 MOD = 1e9 + 7;
constexpr int MAXN = 0;

template <typename T>
class DisjointSetUnion {
private:
	int N;
	std::vector<int> Parent;
	std::vector<int> Siz;
public:
    DisjointSetUnion(int n) : N(n), Parent(N + 1), Siz(N + 1) {
        std::iota(Parent.begin() + 1, Parent.end(), 1);
        Siz.assign(N + 1, 1);
    }

    int find(int x) {
    	while (x != Parent[x]) {
    		x = Parent[x] = Parent[Parent[x]];
    	}
    	return x;
    }

    bool same(int x, int y) {
    	return find(x) == find(y);
    }

    bool Merge(int x, int y) {
        int RootX = find(x);
        int RootY = find(y);
        
        if (RootX == RootY) {
            return false;
        }

        if (Siz[RootX] < Siz[RootY]) {
            std::swap(RootX, RootY);
        }
        
        Parent[RootY] = RootX;
        Siz[RootX] += Siz[RootY];
        
        return true;
    }

    int size(int x) {
        return Siz[find(x)];
    }
};

static inline void VioletEverGraden() {
    int n, m;
    std::cin >> n >> m;

	struct Edge { i64 u; i64 v; i64 w; };
	std::vector<Edge> G;

	int __ = m;
	while (__ --) {
		i64 u, v, w;
		std::cin >> u >> v >> w;
		G.push_back({u, v, w});
	}

	int cnt = 0; i64 ans = 0;
	auto Kruskal = [&]() -> void {
		std::sort(G.begin(), G.end(), [&](Edge a, Edge b) -> bool {
			return a.w < b.w;
		});

		DisjointSetUnion<int> DSU(n);
		for (auto [u, v, w] : G) {
			if (DSU.Merge(u, v)) {
				ans += w;
				cnt ++;
				if (cnt == n - 1) {
					break;
				}
			}
		}
	};

	Kruskal();

	if (cnt != n - 1) {
		std::cout << "NO\n";
	} else {
		std::cout << ans << '\n';
	}
    
    /* 愿幸运女神与最纯粹的前行者同在。 */
/*
Test Sample

5 7
4 5 2
1 3 0
1 4 1
2 1 1
4 1 0
2 4 0
4 3 0

2

4 2
1 2 -12
3 4 2

NO


*/
}

signed main() {
#ifdef Algostruggler
    freopen("A.in", "r", stdin);
#endif // Algostruggler

    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

    /*std::cout << std::fixed << std::setprecision(9);
    std::cerr << std::fixed << std::setprecision(9);*/

    int _ = 1;
    //for (std::cin >> _; _; _--)
        VioletEverGraden();

    return 0;
}`
````

## 四、数据结构

### 4.1、并查集

`````c++
template <typename T>
class DisjointSetUnion {
private:
	int N;
	std::vector<int> Parent;
	std::vector<int> Size;
public:
    DisjointSetUnion(int n) : N(n), Parent(N + 1), Size(N + 1) {
        std::iota(Parent.begin() + 1, Parent.end(), 1);
        Size.assign(N + 1, 1);
    }

    int find(int x) {
    	while (x != Parent[x]) {
    		x = Parent[x] = Parent[Parent[x]];
    	}
    	return x;
    }

    bool same(int x, int y) {
    	return find(x) == find(y);
    }

    bool Merge(int x, int y) {
        int RootX = find(x);
        int RootY = find(y);
        
        if (RootX == RootY) {
            return false;
        }

        if (Size[RootX] < Size[RootY]) {
            std::swap(RootX, RootY);
        }
        
        Parent[RootY] = RootX;
        Size[RootX] += Size[RootY];
        
        return true;
    }

    int size(int x) {
        return Size[find(x)];
    }
};
`````

### 4.2、树状数组

`````c++
template <typename T>
class Fenwick {
private:
	int N;
	std::vector<i64> BIT;
	inline i64 lowbit(i64 x) {
		return x & -x;
	}

    T getSum(int pos) {
        T res = 0;
        while (pos > 0) {
            res += BIT[pos];
            pos -= lowbit(pos);
        }
        return res;
    }
public:
    Fenwick(int n = 0) : N(n), BIT(n + 1, 0) {}
    
    Fenwick(const std::vector<T> &arr) {
        N = arr.size() - 1;
        BIT.assign(N + 1, 0);
        
        std::vector<T> prefix(N + 1, 0);
        for (int i = 1; i <= N; i++) {
            prefix[i] = prefix[i - 1] + arr[i];
            BIT[i] = prefix[i] - prefix[i - lowbit(i)];
        }
    }

    void Update(int pos, T Val) {
        while (pos <= N) {
            BIT[pos] += Val;
            pos += lowbit(pos);
        }
    }

    T rangeSum(int L, int R) {
        return getSum(R) - getSum(L - 1);
    }

    T getVal(int pos) {
        return rangeSum(pos, pos);
    }

    void setVal(int pos, i64 Val) {
        i64 Cur = getVal(pos);
        i64 Dif = Val - Cur;
        Update(pos, Dif);
    }

    int size() const {
        return N;
    }

    void clear() {
        std::fill(BIT.begin(), BIT.end(), 0);
    }
};
`````

### 4.3、块状数组

`````c++
num = sqrt(n);
for (int i = 1; i <= num; i++)
  st[i] = n / num * (i - 1) + 1, ed[i] = n / num * i;
ed[num] = n;
for (int i = 1; i <= num; i++) {
  for (int j = st[i]; j <= ed[i]; j++) {
    belong[j] = i;
  }
  size[i] = ed[i] - st[i] + 1;
}
void Sort(int k) {
  for (int i = st[k]; i <= ed[k]; i++) t[i] = a[i];
  sort(t + st[k], t + ed[k] + 1);
}

void PushDown(int x) {
  if (delta[x] != 0x3f3f3f3f3f3f3f3fll)  // 用该值标记块内没有被整体赋值
    for (int i = st[x]; i <= ed[x]; i++) a[i] = t[i] = delta[x];
  delta[x] = 0x3f3f3f3f3f3f3f3fll;
}

void Modify(int l, int r, int c) {
  int x = belong[l], y = belong[r];
  PushDown(x);
  if (x == y) {
    for (int i = l; i <= r; i++) a[i] = c;
    Sort(x);
    return;
  }
  PushDown(y);
  for (int i = l; i <= ed[x]; i++) a[i] = c;
  for (int i = st[y]; i <= r; i++) a[i] = c;
  Sort(x);
  Sort(y);
  for (int i = x + 1; i < y; i++) delta[i] = c;
}

int Binary_Search(int l, int r, int c) {
  int ans = l - 1, mid;
  while (l <= r) {
    mid = (l + r) / 2;
    if (t[mid] <= c)
      ans = mid, l = mid + 1;
    else
      r = mid - 1;
  }
  return ans;
}

int Answer(int l, int r, int c) {
  int ans = 0, x = belong[l], y = belong[r];
  PushDown(x);
  if (x == y) {
    for (int i = l; i <= r; i++)
      if (a[i] <= c) ans++;
    return ans;
  }
  PushDown(y);
  for (int i = l; i <= ed[x]; i++)
    if (a[i] <= c) ans++;
  for (int i = st[y]; i <= r; i++)
    if (a[i] <= c) ans++;
  for (int i = x + 1; i <= y - 1; i++) {
    if (0x3f3f3f3f3f3f3f3fll == delta[i])
      ans += Binary_Search(st[i], ed[i], c) - st[i] + 1;
    else if (delta[i] <= c)
      ans += size[i];
  }
  return ans;
}
`````



### 4.4、ST表

`````c++
template <typename Info, typename T>
class SparseTable {
private:
    int N;
    std::vector<std::vector<Info>> ST;
    std::vector<int> log2;
public:
    SparseTable() : N(0) {}

    SparseTable(const std::vector<T> &arr) {
        N = (int)arr.size() - 1;

        log2.resize(N + 1);
        log2[1] = 0;
        for (int i = 2; i <= N; i++) {
            log2[i] = log2[i / 2] + 1;
        }
        
        int K = log2[N] + 1;
        ST.resize(K, std::vector<Info>(N + 1));

        for (int i = 1; i <= N; i ++) {
            ST[0][i] = Info(arr[i]);
        }
        for (int j = 1; j < K; j ++) {
            for (int i = 1; i + (1 << j) - 1 <= N; i ++) {
                ST[j][i] = ST[j - 1][i] + ST[j - 1][i + (1 << (j - 1))];
            }
        }
    }

    Info Query(int l, int r) {
        int j = log2[r - l + 1];
        Info res = ST[j][l] + ST[j][r - (1 << j) + 1];
        return res;
    }
};
struct Info {
    i64 max;
    i64 min;
    i64 gcd;
    Info() : 
    max(std::numeric_limits<i64>::min()), 
    min(std::numeric_limits<i64>::max()), 
    gcd(0) {}
    Info(i64 val) : 
    max(val), 
    min(val), 
    gcd(val) {}
};

Info operator + (const Info &a, const Info &b) {
    Info res;
    res.max = std::max(a.max, b.max);
    res.min = std::min(a.min, b.min);
    res.gcd = std::gcd(a.gcd, b.gcd);
    return res;
}
`````

### 4.5、线段树

#### 快速线段树（单点修改+区间最值）

`````c++
struct Segt {
    vector<int> w;
    int n;
    Segt(int n) : w(2*n, (int)-2E9), n(n) {}
    void modify(int pos, int val) {
        for (w[pos += n] = val; pos > 1; pos /= 2)
            w[pos/2] = max(w[pos], w[pos^1]);
    }
    int ask(int l, int r) {
        int res = -2E9;
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l & 1) res = max(res, w[l++]);
            if (r & 1) res = max(res, w[--r]);
        }
        return res;
    }
};
`````

#### 函数线段树

`````c++
#include <bits/stdc++.h>

using ll = long long;
#define rep(i, l, r, x) for (int i = l; i <= r; i ++)

const int MAXN = 1e5 + 5;

int n, m;
std::vector<ll> a;
int op; ll x, y, k;

struct info {
    ll sum;
};
std::vector<info> seg((MAXN << 2) + 10);
std::vector<ll> tag((MAXN << 2) + 10);

void update(ll id) {
    seg[id].sum = seg[id * 2].sum + seg[id * 2 + 1].sum;
}

void build(ll id, ll l, ll r) {
    tag[id] = 0;
    if (l == r) {
        seg[id].sum = a[l];
    } else {
        ll mid = l + r >> 1;
        build(id * 2, l, mid);
        build(id * 2 + 1, mid + 1, r);
        update(id);
    }
}

void addtag(ll id, ll l, ll r, ll val) {
    tag[id] += val;
    seg[id].sum += val * (r - l + 1);
}

void pushdown(ll id, ll l, ll r) {
    if (tag[id]) {
        ll mid = l + r >> 1;
        addtag(id * 2, l, mid, tag[id]);
        addtag(id * 2 + 1, mid + 1, r, tag[id]);
        tag[id] = 0;
    }
}

void modify(ll id, ll l, ll r, ll ql, ll qr, ll val) {
    if (l >= ql && r <= qr) {
        addtag(id, l, r, val);
        return;
    }
    pushdown(id, l, r);
    ll mid = l + r >> 1;
    if (ql <= mid) {
        modify(id * 2, l, mid, ql, qr, val);
    }
    if (qr > mid) {
        modify(id * 2 + 1, mid + 1, r, ql, qr, val);
    }
    update(id);
}

ll query(ll id, ll l, ll r, ll ql, ll qr) {
    if (ql <= l && r <= qr) {
        return seg[id].sum;
    }
    pushdown(id, l, r);
    ll mid = l + r >> 1;
    ll res = 0;
    if (ql <= mid) {
        res += query(id * 2, l, mid, ql, qr);
    }
    if (qr > mid) {
        res += query(id * 2 + 1, mid + 1, r, ql, qr);
    }
    return res;
}

void violet() {
    std::cin >> n >> m;
    a.resize(n + 10);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    build(1, 1, n);

    int __ = m;
    while (__--) {
        std::cin >> op;
        if (op == 1) {
            std::cin >> x >> y >> k;
            modify(1, 1, n, x, y, k);
        } else {
            std::cin >> x >> y;
            ll ans = query(1, 1, n, x, y);
            std::cout << ans << '\n';
        }
    }
}

signed main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout.tie(nullptr);

    int _ = 1;
    // for (std::cin >> _; _; _ --)
    	violet();

    return 0;
}

/*
Test Sample
5 5
1 5 4 2 3
2 2 4
1 2 3 2
2 3 4
1 1 5 1
2 1 4

11
8
20
*/
`````

#### 线段树封装类

```````c++
template <typename Info, typename Tag, typename T = i64>
class LazySegmentTree {
private:
	int N;
	std::vector<i64> a;
	std::vector<Info> Seg;
	std::vector<Tag> Lazy;

	void push_up(i64 id) {
		Seg[id] = Seg[id << 1] + Seg[id << 1 | 1];
	}

	void Build(i64 id, i64 l, i64 r) {
		Lazy[id] = Tag();
		if (l == r) {
			Seg[id] = Info(a[l], 1);
		} else {
			i64 mid = l + r >> 1;
			Build(id << 1, l, mid);
			Build(id << 1 | 1, mid + 1, r);
			push_up(id);
		}
	}

    void ApplyTag(i64 id, const Tag &t) {
        Seg[id].ApplyTag(t);
        Lazy[id].ApplyTag(t);
    }

	void push_down(i64 id) {
        ApplyTag(id << 1, Lazy[id]);
        ApplyTag(id << 1 | 1, Lazy[id]);
        Lazy[id] = Tag();
	}

    void Update(i64 id, i64 l, i64 r, i64 pos, const Tag &v) {
        if (l == r) {
            ApplyTag(id, v);
            return;
        }
        push_down(id);

        i64 mid = l + r >> 1;
        if (pos <= mid) {
            Update(id << 1, l, mid, pos, v);
        } else {
            Update(id << 1 | 1, mid + 1, r, pos, v);
        }
        push_up(id);
    }

	void Modify(i64 id, i64 l, i64 r, i64 ql, i64 qr, const Tag &v) {
    	if (l >= ql and r <= qr) {
    		ApplyTag(id, v);
    		return ;
    	}
        push_down(id);

        i64 mid = l + r >> 1;
        if (ql <= mid) {
            Modify(id << 1, l, mid, ql, qr, v);
        }
        if (qr > mid) {
            Modify(id << 1 | 1, mid + 1, r, ql, qr, v);
        }
        push_up(id);
	}

	Info Query(i64 id, i64 l, i64 r, i64 ql, i64 qr) {
    	if (ql <= l and qr >= r) {
    		return Seg[id];
    	}
    	push_down(id);

    	i64 mid = l + r >> 1;
    	if (qr <= mid) {
    		return Query(id << 1, l, mid, ql, qr);
    	} 
    	if (ql > mid) {
    		return Query(id << 1 | 1, mid + 1, r, ql, qr);
    	}
    	return Query(id << 1, l, mid, ql, qr) + Query(id << 1 | 1, mid + 1, r, ql, qr);
	}
public:
    LazySegmentTree(const std::vector<T> &arr) {
        a = arr;
        N = (int)arr.size() - 1;
        Seg.resize(N << 2);
        Lazy.resize(N << 2);
        Build(1, 1, N);
    }

    void Update(i64 pos, const Tag &v) {
    	return Update(1, 1, N, pos, v);
    }

    void Modify(i64 l, i64 r, const Tag &v) {
    	return Modify(1, 1, N, l, r, v);
    }

    Info Query(i64 l, i64 r) {
    	return Query(1, 1, N, l, r);
    }
};

struct Tag {
	i64 add;
	Tag(i64 a = 0) : add(a) {}

	void ApplyTag(const Tag &t) {
		add += t.add;
	}
};

struct Info {
	i64 sum;
	i64 len;
	Info(i64 s = 0, i64 l = 1) : sum(s), len(l) {}

	Info operator + (const Info &a) const {
		Info res;
		res.sum = sum + a.sum;
		// res.max = std::max(max, a.max)
		res.len = len + a.len;
		return res;
	}

	void ApplyTag(const Tag &t) {
		sum += t.add * len;
	}
};
```````

#### 动态开点的线段树

`````c++
#include <bits/stdc++.h>

using ll = long long;
const int MAXN = 1e5 + 5;

int n, m;
std::vector<ll> a;
int op; ll x, y, k;

struct Node {
    ll sum, tag;
    int ls, rs;
    Node() : sum(0), tag(0), ls(0), rs(0) {}
};

int root, cnt;
std::vector<Node> seg((MAXN << 2) + 10);

int newNode() {
    cnt ++;
    if (cnt >= seg.size()) {
        seg.resize(seg.size() * 2);
    }
    seg[cnt] = Node();
    return cnt;
}

void update(int id) {
    seg[id].sum = seg[seg[id].ls].sum + seg[seg[id].rs].sum;
}

void build(int &id, ll l, ll r) {
    if (!id) id = newNode();
    if (l == r) {
        seg[id].sum = a[l];
    } else {
        ll mid = l + r >> 1;
        build(seg[id].ls, l, mid);
        build(seg[id].rs, mid + 1, r);
        update(id);
    }
}

void addtag(int id, ll l, ll r, ll val) {
    if (!id) return;
    seg[id].tag += val;
    seg[id].sum += val * (r - l + 1);
}

void pushdown(int id, ll l, ll r) {
    if (seg[id].tag and l < r) {
        ll mid = l + r >> 1;
        
        if (!seg[id].ls) {
            seg[id].ls = newNode();
        }
        if (!seg[id].rs) {
            seg[id].rs = newNode();
        }
        
        addtag(seg[id].ls, l, mid, seg[id].tag);
        addtag(seg[id].rs, mid + 1, r, seg[id].tag);
        seg[id].tag = 0;
    }
}

void modify(int id, ll l, ll r, ll ql, ll qr, ll val) {
    if (ql <= l and r <= qr) {
        addtag(id, l, r, val);
        return ;
    }
    pushdown(id, l, r);
    ll mid = l + r >> 1;
    
    if (ql <= mid) {
        if (!seg[id].ls) seg[id].ls = newNode();
        modify(seg[id].ls, l, mid, ql, qr, val);
    }
    if (qr > mid) {
        if (!seg[id].rs) seg[id].rs = newNode();
        modify(seg[id].rs, mid + 1, r, ql, qr, val);
    }
    update(id);
}

ll query(int id, ll l, ll r, ll ql, ll qr) {
    if (!id) {
        return 0;
    }
    if (ql <= l and r <= qr) {
        return seg[id].sum;
    }
    pushdown(id, l, r);
    ll mid = l + r >> 1;
    ll res = 0;
    if (ql <= mid) {
        res += query(seg[id].ls, l, mid, ql, qr);
    }
    if (qr > mid) {
        res += query(seg[id].rs, mid + 1, r, ql, qr);
    }
    return res;
}

void violet() {
    std::cin >> n >> m;
    a.resize(n + 10);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    root = 0; cnt = 0;
    build(root, 1, n);

    int __ = m;
    while (__--) {
        std::cin >> op;
        if (op == 1) {
            std::cin >> x >> y >> k;
            modify(root, 1, n, x, y, k);
        } else {
            std::cin >> x >> y;
            ll ans = query(root, 1, n, x, y);
            std::cout << ans << '\n';
        }
    }
}

signed main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout.tie(nullptr);

    int _ = 1;
    // for (std::cin >> _; _; _ --)
        violet();
    return 0;
}

/*
Test Sample
5 5
1 5 4 2 3
2 2 4
1 2 3 2
2 3 4
1 1 5 1
2 1 4

11
8
20
*/
`````

### 4.6、平衡树



### 4.7、珂朵莉树

区间赋值的数据结构都可以写分，在数据随机的情况下，复杂度可以保证，时间复杂度：$ O(N \log \log N) $。



```c++
struct DOT {
    struct node {
        int l, r;
        mutable LL v;
        node(int l, int r = -1, LL v = 0) : l(l), r(r), v(v) {}
        bool operator<(const node &o) const {
            return l < o.l;
        }
    };
    set<Node> s;
    OOT() {
        s.clear();
    }

    auto split(int pos) {
        auto it = s.lower_bound(node(pos));
        if (it != s.end() && it->l == pos) return it;
        it--;
        int l = it->l, r = it->r;
        LL v = it->v;
        s.erase(it);
        s.insert(node(l, pos - 1, v));
        return s.insert(node(pos, r, v)).first;
    }

    void assign(int l, int r, LL x) {
        auto itr = split(r + 1), itl = split(l);
        s.erase(itl, itr);
        s.insert(node(l, r, x));
    }

    void add(int l, int r, LL x) {
        auto itr = split(r + 1), itl = split(l);
        for (auto it = itl; it != itr; it++) {
            it->v += x;
        }
    }

    LL kth(int l, int r, int k) {
        vector<pair<LL, int>> a;
        auto itr = split(r + 1), itl = split(l);
        for (auto it = itl; it != itr; it++) {
            a.push_back(pair<LL, int>(it->v, it->r - it->l + 1));
        }
        sort(a.begin(), a.end());
        for (auto [val, len] : a) {
            k -= len;
            if (k <= 0) return val;
        }
    }

    LL power(LL a, int b, int mod) {
        a %= mod;
        LL res = 1;
        for (; b; b /= 2, a = a * a % mod) {
            if (b % 2) {
                res = res * a % mod;
            }
        }
        return res;
    }

    LL powsum(int l, int r, int x, int mod) {
        auto itr = split(r + 1), itl = split(l);
        LL ans = 0;
        for (auto it = itl; it != itr; it++) {
            ans = (ans + power(it->v, x, mod) * (it->r - it->l + 1) % mod) % mod;
        }
        return ans;
    }
};
```
### 4.8、线性基

`````c++
template <typename T>
class LinearBasis {
private:
	static constexpr int BASE = sizeof(T) * 8;
	std::vector<T> Basis;
	std::vector<T> Reduced_Basis;
	std::vector<u64> Basis_Mask;
	std::vector<int> Index;

	int Reduce_Size;
	bool Has_Zoro;
public:
    LinearBasis() {
        Basis.assign(BASE, T{0});
        Reduced_Basis.assign(BASE, T{0});
        Basis_Mask.assign(BASE, 0);
        Reduce_Size = 0;
        Has_Zoro = false;
    }

    bool Insert(T Val, int Id) {
    	u64 Cur = 0;
    	for (int i = BASE - 1; i >= 0; i --) {
    		if ((Val >> i) & 1) {
    			if (!Basis[i]) {
    				Basis[i] = Val;
    				Basis_Mask[i] = Cur | (1ULL << Index.size());
    				Index.push_back(Id);
    				return true;
    			}

    			Val ^= Basis[i];
    			Cur ^= Basis_Mask[i];
    		}
    	}
    	Has_Zoro = true;
    	return false;
    }

    void ReBuild() {
    	for (int i = BASE - 1; i >= 0; i --) {
    		if (Basis[i]) {
    			for (int j = i - 1; j >= 0; j --) {
    				if ((Basis[i] >> j) & 1) {
    					Basis[i] ^= Basis[j];
    					Basis_Mask[i] ^= Basis_Mask[j];
    				}
    			}
    		}
    	}

    	Reduce_Size = 0;
    	for (int i = 0; i < BASE; i ++) {
    		if (Basis[i]) {
    			Reduced_Basis[Reduce_Size ++] = Basis[i];
    		}
    	}
    }

    T Kth_Value(i64 K) {
    	if (Has_Zoro) {
    		K --;
    	}
    	if (K == 0) {
    		return T{0};
    	}
    	if (K >= (1ULL << Reduce_Size)) {
    		return T{-1};
    	}

    	T res = 0;
    	for (int i = 0; i < Reduce_Size; i ++) {
    		if ((K >> i) & 1) {
    			res ^= Reduced_Basis[i];
    		}
    	}

    	return res;
    }

    T Max_Value() const {
    	T res = 0;
    	for (int i = BASE - 1; i >= 0; i --) {
    		if ((res ^ Basis[i]) > res) {
    			res ^= Basis[i];
    		}
    	}

    	return res;
    }

    T Min_Value() const {
    	if (Has_Zoro) {
    		return T{0};
    	}

    	for (int i = 0; i < BASE; i ++) {
    		if (Basis[i]) {
    			return Basis[i];
    		}
    	}

    	return T{0};
    }

    std::pair<bool, u64> Represent(T Val) const {
    	u64 res = 0;
    	for (int i = BASE - 1; i >= 0; i --) {
    		if ((Val >> i) & 1) {
    			if (!Basis[i]) {
    				return {false, 0ULL};
    			}
    			Val ^= Basis[i];
    			res ^= Basis_Mask[i];
    		}
    	}

    	return {true, res};
    }

    std::vector<int> getId(u64 S) const {
    	std::vector<int> res;
    	for (int i = 0; i < (int)Index.size(); i ++) {
    		if (S & (1ULL << i)) {
    			res.push_back(Index[i]);
    		}
    	}

    	return res;
    }

    int Rank() const {
    	int RK = 0;
    	for (int i = 0; i < BASE; i ++) {
    		if (Basis[i]) {
    			RK ++;
    		}
    	}

    	return RK;
    }

    bool Zero() const {
    	return Has_Zoro;
    }
};
`````

### 4.9、自动取模类

`````c++
template <typename T>
constexpr T ksm(T a, u64 b) {
    T res = 1;
    while (b) {
        if (b & 1) {
            res *= a;
        }
        a *= a;
        b >>= 1;
    }
    return res;
}

constexpr i64 ksc(i64 a, i64 b, i64 p) {
#ifdef __SIZEOF_INT128__
    return (i64)((__int128)a * b % p);
#else
    i64 res = a * b - i64(1.L * a * b / p - 0.5L) * p;
    res %= p;
    if (res < 0) {
        res += p;
    }
    return res;
#endif
}

template <i64 P>
class MLong {
private:
    i64 x;
    static i64 Mod;

    constexpr static i64 getMod() {
        if constexpr (P > 0) {
            return P;
        } else {
            return Mod;
        }
    }

    constexpr i64 Normalize(i64 Val) const {
        i64 m = getMod();
        Val %= m;
        if (Val < 0) {
            Val += m;
        }
        return Val;
    }
public:
    constexpr MLong() : x(0) {}
    constexpr MLong(i64 x) : x{Normalize(x % getMod())} {}
    
    constexpr static void setMod(i64 _Mod) {
        Mod = _Mod;
    }

    constexpr i64 val() const { 
        return x; 
    }
    
    explicit constexpr operator i64() const { 
        return x; 
    }

    constexpr MLong inv() const {
        assert(x != 0);
        return ksm(*this, getMod() - 2);
    }

    constexpr MLong pow(u64 b) const {
        return ksm(*this, b);
    }

    constexpr MLong operator - () const {
        return MLong(-x);
    }

    constexpr MLong &operator *= (MLong rhs) & {
        x = ksc(x, rhs.x, getMod());
        return *this;
    }
    constexpr MLong &operator += (MLong rhs) & {
        x = Normalize(x + rhs.x);
        return *this;
    }
    constexpr MLong &operator -= (MLong rhs) & {
        x = Normalize(x - rhs.x);
        return *this;
    }
    constexpr MLong &operator /= (MLong rhs) & {
        return *this *= rhs.inv();
    }

    constexpr MLong& operator ++ () {
        x = Normalize(x + 1);
        return *this;
    }
    constexpr MLong operator ++ (int) {
        MLong tmp = *this;
        ++ (*this);
        return tmp;
    }
    
    constexpr MLong& operator -- () {
        x = Normalize(x - 1);
        return *this;
    }
    constexpr MLong operator -- (int) {
        MLong tmp = *this;
        -- (*this);
        return tmp;
    }

    friend constexpr MLong operator * (MLong lhs, MLong rhs) {
        MLong res = lhs;
        res *= rhs;
        return res;
    }
    friend constexpr MLong operator + (MLong lhs, MLong rhs) {
        MLong res = lhs;
        res += rhs;
        return res;
    }
    friend constexpr MLong operator - (MLong lhs, MLong rhs) {
        MLong res = lhs;
        res -= rhs;
        return res;
    }
    friend constexpr MLong operator / (MLong lhs, MLong rhs) {
        MLong res = lhs;
        res /= rhs;
        return res;
    }

    friend constexpr bool operator == (MLong lhs, MLong rhs) {
        return lhs.val() == rhs.val();
    }
    friend constexpr bool operator != (MLong lhs, MLong rhs) {
        return lhs.val() != rhs.val();
    }

    friend constexpr bool operator < (MLong lhs, MLong rhs) {
        return lhs.val() < rhs.val();
    }
    friend constexpr bool operator <= (MLong lhs, MLong rhs) {
        return lhs.val() <= rhs.val();
    }

    friend constexpr bool operator > (MLong lhs, MLong rhs) {
        return lhs.val() > rhs.val();
    }
    friend constexpr bool operator >= (MLong lhs, MLong rhs) {
        return lhs.val() >= rhs.val();
    }

    friend constexpr std::istream &operator >> (std::istream &is, MLong &a) {
        i64 v;
        is >> v;
        a = MLong(v);
        return is;
    }
    friend constexpr std::ostream &operator << (std::ostream &os, const MLong &a) {
        return os << a.val();
    }
};

template<int P>
class MInt {
private:
    int x;
    static int Mod;

    constexpr static int getMod() {
        if constexpr (P > 0) {
            return P;
        } else {
            return Mod;
        }
    }

    constexpr int Normalize(i64 Val) const {
        int m = getMod();
        Val %= m;
        if (Val < 0) {
            Val += m;
        }
        return Val;
    }
public:
    constexpr MInt() : x(0) {}
    constexpr MInt(i64 x) : x{Normalize(x % getMod())} {}
    
    constexpr static void setMod(i64 _Mod) {
        Mod = _Mod;
    }

    constexpr int val() const { 
        return x; 
    }
    
    explicit constexpr operator int() const { 
        return x; 
    }

    constexpr MInt inv() const {
        assert(x != 0);
        return ksm(*this, getMod() - 2);
    }

    constexpr MInt pow(u64 b) const {
        return ksm(*this, b);
    }

    constexpr MInt operator - () const {
        return MInt(-x);
    }

    constexpr MInt &operator *= (MInt rhs) & {
        x = ksc(x, rhs.x, getMod());
        return *this;
    }
    constexpr MInt &operator += (MInt rhs) & {
        x = Normalize(x + rhs.x);
        return *this;
    }
    constexpr MInt &operator -= (MInt rhs) & {
        x = Normalize(x - rhs.x);
        return *this;
    }
    constexpr MInt &operator /= (MInt rhs) & {
        return *this *= rhs.inv();
    }

    constexpr MInt& operator ++ () {
        x = Normalize(x + 1);
        return *this;
    }
    constexpr MInt operator ++ (int) {
        MInt tmp = *this;
        ++ (*this);
        return tmp;
    }
    
    constexpr MInt& operator -- () {
        x = Normalize(x - 1);
        return *this;
    }
    constexpr MInt operator -- (int) {
        MInt tmp = *this;
        -- (*this);
        return tmp;
    }

    friend constexpr MInt operator * (MInt lhs, MInt rhs) {
        MInt res = lhs;
        res *= rhs;
        return res;
    }
    friend constexpr MInt operator + (MInt lhs, MInt rhs) {
        MInt res = lhs;
        res += rhs;
        return res;
    }
    friend constexpr MInt operator - (MInt lhs, MInt rhs) {
        MInt res = lhs;
        res -= rhs;
        return res;
    }
    friend constexpr MInt operator / (MInt lhs, MInt rhs) {
        MInt res = lhs;
        res /= rhs;
        return res;
    }

    friend constexpr bool operator == (MInt lhs, MInt rhs) {
        return lhs.val() == rhs.val();
    }
    friend constexpr bool operator != (MInt lhs, MInt rhs) {
        return lhs.val() != rhs.val();
    }

    friend constexpr bool operator < (MInt lhs, MInt rhs) {
        return lhs.val() < rhs.val();
    }
    friend constexpr bool operator <= (MInt lhs, MInt rhs) {
        return lhs.val() <= rhs.val();
    }

    friend constexpr bool operator > (MInt lhs, MInt rhs) {
        return lhs.val() > rhs.val();
    }
    friend constexpr bool operator >= (MInt lhs, MInt rhs) {
        return lhs.val() >= rhs.val();
    }

    friend constexpr std::istream &operator >> (std::istream &is, MInt &a) {
        i64 v;
        is >> v;
        a = MInt(v);
        return is;
    }
    friend constexpr std::ostream &operator << (std::ostream &os, const MInt &a) {
        return os << a.val();
    }
};

template <>
i64 MLong<0>::Mod = i64(1E18) + 9;
template <>
int MInt<0>::Mod = 998244353;

using Z998244353 = MInt<998244353>;
using Z1e9_7 = MInt<1000000007>;
using Z1e9_9 = MInt<1000000009>;

constexpr auto inv2_998244353 = Z998244353(2).inv();
constexpr auto inv2_1e9_7 = Z1e9_7(2).inv();
constexpr auto inv2_1e9_9 = Z1e9_9(2).inv();

using DynZ = MInt<0>;
using Z = Z1e9_7;
`````

### 4.10、大整数类

`````c++
constexpr int N = 1000;

struct BigInt {
    int a[N];
    BigInt(int x = 0) : a{} {
        for (int i = 0; x; i++) {
            a[i] = x % 10;
            x /= 10;
        }
    }
    BigInt &operator*=(int x) {
        for (int i = 0; i < N; i++) {
            a[i] *= x;
        }
        for (int i = 0; i < N - 1; i++) {
            a[i + 1] += a[i] / 10;
            a[i] %= 10;
        }
        return *this;
    }
    BigInt &operator/=(int x) {
        for (int i = N - 1; i >= 0; i--) {
            if (i) {
                a[i - 1] += a[i] % x * 10;
            }
            a[i] /= x;
        }
        return *this;
    }
    BigInt &operator+=(const BigInt &x) {
        for (int i = 0; i < N; i++) {
            a[i] += x.a[i];
            if (a[i] >= 10) {
                a[i + 1] += 1;
                a[i] -= 10;
            }
        }
        return *this;
    }
};

std::ostream &operator<<(std::ostream &o, const BigInt &a) {
    int t = N - 1;
    while (a.a[t] == 0) {
        t--;
    }
    for (int i = t; i >= 0; i--) {
        o << a.a[i];
    }
    return o;
}
`````

## 五、数论

### 5.1、常见数列

#### 调和级数

满足调和级数 $ O\left(\frac{N}{1} + \frac{N}{2} + \frac{N}{3} + \cdots + \frac{N}{N}\right) $，可以用 $ N \ln N $ 来拟合，但是会略小，误差量级在 $10\% $ 左右。本地可以在500ms内完成 $10^8$  量级的预处理计算。

| N的量级 | 累加和         |
| ------- | -------------- |
| 1       | 27             |
| 2       | 482            |
| 3       | 7'069          |
| 4       | 93'668         |
| 5       | 1'166'750      |
| 6       | 13'970'034     |
| 7       | 162'725'364    |
| 8       | 1'857'511'568  |
| 9       | 20'877'697'634 |

#### 素数密度与分布

| N的量级  | 1    | 2    | 3    | 4     | 5     | 6      | 7       | 8         | 9          |
| :------- | :--- | :--- | :--- | :---- | :---- | :----- | :------ | :-------- | :--------- |
| 素数数量 | 4    | 25   | 168  | 1'229 | 9'592 | 78'498 | 664'579 | 5'761'455 | 50'847'534 |

对于任意两个相邻的素数 $p_1,p_2 \le 10^9$，有 $|p_1-p_2| < 300$。

#### 因数最多数字与其因数数量

| N的量级                | 1    | 2    | 3    | 4          | 5            | 6                                      | 7    |
| :--------------------- | :--- | :--- | :--- | :--------- | :----------- | :------------------------------------- | :--- |
| 因数最多数字的因数数量 | 1    | 2    | 4    | 6          | 12           | 24                                     | 48   |
| 因数最多的数字         | -    | -    | -    | 7560, 9240 | 83160, 98280 | 720720, 831600, 942480, 982800, 997920 | -    |

### 5.2、素数筛

#### 埃氏筛

#### 欧拉筛

`````c++
auto eulerSieve = [&](int n) -> void {
    prime.clear();
    isPrime.assign(n + 1, true);   // 初始都认为是素数
    isPrime[0] = isPrime[1] = false;
    
    for (int i = 2; i <= n; ++i) {
        if (isPrime[i]) {
            prime.push_back(i);
        }
        for (int j = 0; j < (int)prime.size() && i * prime[j] <= n; ++j) {
            isPrime[i * prime[j]] = false;   // 标记为合数
            if (i % prime[j] == 0) break;    // 核心优化：保证每个合数只被最小质因子筛一次
        }
    }
};
`````

### 5.3、龟速乘

#### 借助浮点数实现

`````c++
int mul(int a, int b, int m) {
    int r = a * b - m * (int)(1.0L / m * a * b);
    return r - m * (r >= m) + m * (r < 0);
}
`````

#### 借助int128实现

`````c++
int mul(int a, int b, int m) {
    return (int128)a * b % m;
}
`````

### 5.4、裴蜀定理

$ax + by = c$ 有整数解的充要条件是 $\gcd(a,b) \mid c$。

`````c++
LL n, a, ans;
LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (a < 0) a = -a;
        ans = gcd(ans, a);
    }
    cout << ans << "\n";
}
`````

### 5.5、逆元

#### 费马小定理

单次计算的复杂度即为快速幂的复杂度 $O(\log X)$。限制：$MOD$ 必须是质数，且需要满足 $x$ 与 $MOD$ 互质。

`````c++
i64 ksm(i64 a, i64 b, i64 p) {
    i64 res = 1;
    while (b) {
        if (b & 1) {
        	res = res * a % p;
        }
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

i64 inv(i64 x, i64 p) {
    return ksm(x, p - 2, p);
}
`````

#### 拓展欧几里得

此方法的 $MOD$ 没有限制，复杂度为 $O(\log X)$，但是比快速幂法常数大一些。

`````c++
int exgcd(int a, int b, int &x, int &y) {
    if (b == 0) { x = 1, y = 0; return a; }
    int r = exgcd(b, a % b, x, y);
    int temp = y;
    y = x - (a / b) * y;
    x = temp;
    return r;
}
LL getInv(int a, int mod) {
    LL x, y, d = exgcd(a, mod, x, y);
    return d == 1 ? (x % mod + mod) % mod : -1;
}
`````

#### 线性递推

以 $O(N)$ 的复杂度完成 $1 - N$ 中全部逆元的计算。

`````c++
inv[1] = 1;
for (int i = 2; i <= n; i++)
    inv[i] = (p - p / i) * inv[p % i] % p;
`````

#### 阶乘逆元（用于组合数）

`````c++
vector<long long> fact, invfact;
void precomputeFactorials(int n, long long mod) {
    fact.resize(n + 1);
    invfact.resize(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; ++i)
        fact[i] = fact[i - 1] * i % mod;
    invfact[n] = qpow(fact[n], mod - 2, mod);  // 费马
    for (int i = n; i >= 1; --i)
        invfact[i - 1] = invfact[i] * i % mod;
}

long long C(int n, int k, long long mod) {
    if (k < 0 || k > n) return 0;
    return fact[n] * invfact[k] % mod * invfact[n - k] % mod;
}
`````

### 5.6、组合数

提供一组测试数据：$\left( \frac{132}{66} \right) = 377'389'666'165'540'953'244'592'352'291'892'721'700$，模数为 $998244353$ 时为 $241'200'029$；$10^9 + 7$ 时为 $598375978$。

#### 组合数封装

`````c++
struct Comb {
    int n;
    vector<Z> _fac, _inv;

    Comb() : _fac{1}, _inv{0} {}
    Comb(int n) : Comb() {
        init(n);
    }

    void init(int m) {
        if (m <= n) return;
        _fac.resize(m + 1);
        _inv.resize(m + 1);
        for (int i = n + 1; i <= m; i++) {
            _fac[i] = _fac[i - 1] * i;
        }
        _inv[m] = _fac[m].inv();
        for (int i = m; i > n; i--) {
            _inv[i - 1] = _inv[i] * i;
        }
        n = m;
    }

    Z fac(int x) {
        if (x > n) init(x);
        return _fac[x];
    }

    Z inv(int x) {
        if (x > n) init(x);
        return _inv[x];
    }

    Z c(int x, int y) {
        if (x < 0 || y < 0 || x < y) return 0;
        return fac(x) * inv(y) * inv(x - y);
    }

    Z P(int x, int y) {
        if (x < 0 || y < 0 || x < y) return 0;
        return fac(x) * inv(x - y);
    }
};

comb(1 << 21);
`````

#### 取模组合数封装

基于自动取模类 $Z$ 。

`````c++
template <typename T = Z>
class Comb {
private:
	int N;
	std::vector<T> _Factor;
	std::vector<T> _InvFactor;
	std::vector<T> _Inv;
public:
    Comb() : N{0}, _Factor{1}, _InvFactor{1}, _Inv{0} {}
    
    explicit Comb(int n) : Comb() {
        Init(n);
    }

    void Init(int M) {
        if (M <= N) {
        	return ;
        }
        
        _Factor.resize(M + 1);
        _InvFactor.resize(M + 1);
        _Inv.resize(M + 1);

        for (int i = N + 1; i <= M; i ++) {
            _Factor[i] = _Factor[i - 1] * i;
        }

        _InvFactor[M] = _Factor[M].inv();
        for (int i = M; i > N; i --) {
            _InvFactor[i - 1] = _InvFactor[i] * i;
            _Inv[i] = _InvFactor[i] * _Factor[i - 1]; 
        }
        
        N = M;
    }

    Z Fac(int M) {
        if (M < 0) {
        	return 0; 
        }
        if (M > N) {
        	Init(std::max(M, N * 2));
        }
        return _Factor[M];
    }

    Z InvFac(int M) {
        if (M < 0) {
        	return 0;
        }
        if (M > N) {
        	Init(std::max(M, N * 2));
        }
        return _InvFactor[M];
    }
    
    Z Inv(int M) {
        if (M == 0) {
        	return 0;
        }
        if (M > N) {
        	Init(std::max(M, N * 2));
        }
        return _Inv[M];
    }

    Z C(int N, int M) {
        if (N < M or M < 0) {
        	return 0;
        }
        return Fac(N) * InvFac(M) * InvFac(N - M);
    }

    Z A(int n, int m) {
        if (n < m or m < 0) {
        	return 0;
        }
        return Fac(n) * InvFac(n - m);
    }

    Z Stirling2(int n, int k) {
        if (n < k or k < 0) {
        	return 0;
        }
        if (n == k or k == 1) {
        	return 1;
        }
        if (k == 0) {
        	return (n == 0) ? 1 : 0;
        }
        
        Z res = 0;
        for (int i = 0; i <= k; i ++) {
            Z term = C(k, i) * Z(i).pow(n);
            if ((k - i) & 1) {
            	res -= term;
            } else {
            	res += term;
            }
        }
        return res * InvFac(k);
    }

    Z Catalan(int n) {
        if (n < 0) return 0;
        return C(2 * n, n) * Inv(n + 1);
    }
};

constexpr int MAXN = 5e5 + 25;
Comb<> comb(MAXN);
`````
