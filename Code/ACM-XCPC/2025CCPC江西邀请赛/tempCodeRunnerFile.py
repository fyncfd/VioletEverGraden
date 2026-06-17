import random
import os
import zipfile

def generate_test_case(max_n, max_m, max_coeff, case_id):
    """生成一个测试用例"""
    # 随机确定n和m的大小，但至少为1
    n = random.randint(1, max_n)
    m = random.randint(1, max_m)
    
    # 生成多项式系数
    a = [random.randint(-max_coeff, max_coeff) for _ in range(n)]
    b = [random.randint(-max_coeff, max_coeff) for _ in range(m)]
    
    # 构建输入内容
    input_content = f"{n} {m}\n"
    input_content += " ".join(map(str, a)) + "\n"
    input_content += " ".join(map(str, b))
    
    # 计算期望输出（使用直接卷积计算）
    output_content = compute_convolution(a, b)
    
    return input_content, output_content

def compute_convolution(a, b):
    """计算两个多项式的卷积（直接方法）"""
    n, m = len(a), len(b)
    c = [0] * (n + m - 1)
    
    for i in range(n):
        for j in range(m):
            c[i + j] += a[i] * b[j]
    
    return " ".join(map(str, c))

def generate_extreme_cases():
    """生成一些极端测试用例"""
    cases = []
    
    # 用例1: 最小规模
    a = [random.randint(-100, 100)]
    b = [random.randint(-100, 100)]
    cases.append((f"1 1\n{a[0]}\n{b[0]}", compute_convolution(a, b)))
    
    # 用例2: 最大规模
    n, m = 100000, 100000
    a = [random.randint(-100, 100) for _ in range(n)]
    b = [random.randint(-100, 100) for _ in range(m)]
    cases.append((f"{n} {m}\n" + " ".join(map(str, a)) + "\n" + " ".join(map(str, b)), 
                  compute_convolution(a, b)))
    
    # 用例3: 很多零系数
    n, m = 50000, 50000
    a = [0] * (n//2) + [random.randint(-100, 100) for _ in range(n//2)]
    b = [0] * (m//2) + [random.randint(-100, 100) for _ in range(m//2)]
    random.shuffle(a)
    random.shuffle(b)
    cases.append((f"{n} {m}\n" + " ".join(map(str, a)) + "\n" + " ".join(map(str, b)), 
                  compute_convolution(a, b)))
    
    # 用例4: 全正系数
    n, m = 50000, 50000
    a = [random.randint(1, 100) for _ in range(n)]
    b = [random.randint(1, 100) for _ in range(m)]
    cases.append((f"{n} {m}\n" + " ".join(map(str, a)) + "\n" + " ".join(map(str, b)), 
                  compute_convolution(a, b)))
    
    # 用例5: 全负系数
    n, m = 50000, 50000
    a = [random.randint(-100, -1) for _ in range(n)]
    b = [random.randint(-100, -1) for _ in range(m)]
    cases.append((f"{n} {m}\n" + " ".join(map(str, a)) + "\n" + " ".join(map(str, b)), 
                  compute_convolution(a, b)))
    
    return cases

def main():
    random.seed(42)  # 设置随机种子以便结果可重现
    
    # 创建测试数据目录
    if not os.path.exists("test_data"):
        os.makedirs("test_data")
    
    test_cases = []
    
    # 生成极端测试用例
    print("生成极端测试用例...")
    extreme_cases = generate_extreme_cases()
    test_cases.extend(extreme_cases)
    
    # 生成随机测试用例
    print("生成随机测试用例...")
    for i in range(10):  # 生成10个随机测试用例
        print(f"生成测试用例 {i+1}...")
        
        # 随机选择规模
        if i < 5:
            # 前5个用例：中等规模
            max_n = random.randint(50000, 100000)
            max_m = random.randint(50000, 100000)
        else:
            # 后5个用例：各种规模混合
            max_n = random.choice([100, 1000, 10000, 50000, 100000])
            max_m = random.choice([100, 1000, 10000, 50000, 100000])
        
        input_content, output_content = generate_test_case(
            max_n, max_m, 100, i
        )
        test_cases.append((input_content, output_content))
    
    # 保存测试用例
    print("保存测试用例...")
    for i, (input_content, output_content) in enumerate(test_cases):
        with open(f"test_data/input_{i+1}.txt", "w", encoding='utf-8') as f:
            f.write(input_content)
        with open(f"test_data/output_{i+1}.txt", "w", encoding='utf-8') as f:
            f.write(output_content)
    
    # 创建压缩包
    print("创建压缩包...")
    with zipfile.ZipFile("polynomial_multiplication_test_data.zip", "w") as zipf:
        for file in os.listdir("test_data"):
            zipf.write(os.path.join("test_data", file), file)
    
    # 生成测试用例说明
    with open("test_cases_description.txt", "w", encoding='utf-8') as f:
        f.write("多项式乘法测试用例说明\n")
        f.write("=" * 50 + "\n\n")
        f.write("共生成 15 个测试用例：\n")
        f.write("1. 用例 1-5: 极端情况测试\n")
        f.write("   - 用例1: 最小规模 (1x1)\n")
        f.write("   - 用例2: 最大规模 (100000x100000)\n")
        f.write("   - 用例3: 稀疏多项式 (很多零系数)\n")
        f.write("   - 用例4: 全正系数\n")
        f.write("   - 用例5: 全负系数\n")
        f.write("2. 用例 6-15: 随机测试用例\n")
        f.write("   - 包含各种规模组合\n")
        f.write("   - 系数范围: [-100, 100]\n\n")
        f.write("数据特征：\n")
        f.write("- 最大规模: 100000 x 100000\n")
        f.write("- 系数绝对值不超过 100\n")
        f.write("- 包含边界情况和随机情况\n")
    
    print("测试数据生成完成！")
    print(f"共生成 {len(test_cases)} 个测试用例")
    print("文件: polynomial_multiplication_test_data.zip")
    print("说明: test_cases_description.txt")

if __name__ == "__main__":
    main()