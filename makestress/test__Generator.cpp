#include <bits/stdc++.h>
using namespace std;

// 随机数生成器
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// 生成一个在 [l, r] 范围内的随机整数
int rand_int(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}

// 随机选择一个小写字母
char rand_lower() {
    return 'a' + rand_int(0, 25);
}

// 随机选择一个数字
char rand_digit() {
    return '0' + rand_int(0, 9);
}

// 生成随机测试数据
void generate_test_case() {
    // 生成参数 p1, p2, p3
    int p1 = rand_int(1, 3);
    int p2 = rand_int(1, 8);
    int p3 = rand_int(1, 2);
    cout << p1 << " " << p2 << " " << p3 << endl;
    
    // 生成字符串长度 (1-100)
    int len = rand_int(1, 100);
    string s;
    
    for (int i = 0; i < len; i++) {
        // 决定生成什么类型的字符
        int type = rand_int(0, 9);  // 0-9 共10种可能
        
        if (type < 6) {  // 60% 概率生成字母或数字（正常字符）
            if (rand_int(0, 1)) {
                s += rand_lower();
            } else {
                s += rand_digit();
            }
        } else if (type < 8) {  // 20% 概率生成减号
            s += '-';
        } else {  // 20% 概率生成可能形成展开的字符对（带减号）
            // 生成可能形成展开的形式，比如 "a-d" 或 "3-7"
            if (i + 2 < len) {  // 有足够空间
                bool is_letter = rand_int(0, 1);
                char left, right;
                
                if (is_letter) {
                    left = rand_lower();
                    // 让 right 可能大于 left，可能等于，可能小于
                    int offset = rand_int(-3, 5);  // 范围稍大，包含各种情况
                    right = left + offset;
                    if (right < 'a') right = 'a';
                    if (right > 'z') right = 'z';
                } else {
                    left = rand_digit();
                    int offset = rand_int(-3, 5);
                    right = left + offset;
                    if (right < '0') right = '0';
                    if (right > '9') right = '9';
                }
                
                s += left;
                s += '-';
                s += right;
                i += 2;  // 跳过了两个字符和一个减号的位置
            } else {
                // 空间不足，就放普通字符
                if (rand_int(0, 1)) {
                    s += rand_lower();
                } else {
                    s += rand_digit();
                }
            }
        }
    }
    
    // 确保字符串长度不超过100
    if (s.length() > 100) {
        s = s.substr(0, 100);
    }
    
    cout << s << endl;
}

int main() {
    int T = 10;
    std::cout << T << '\n';
    for (int i = 1; i <= T; i ++) {
        std::cout << rand_int(100, 200) << ' ' << rand_int(100, 200) << '\n';
    } 
    return 0;
}