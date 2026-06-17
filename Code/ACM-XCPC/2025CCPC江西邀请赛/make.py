import random
import sys

def generate_polynomial_test_cases():
    """生成多项式乘法的测试数据"""
    random.seed(42)  # 固定种子保证可重复性
    
    test_cases = []
    
    # 1. 示例案例
    test_cases.append((2, 3, [1, 2], [3, 4, 5]))
    
    # 2. 小规模随机案例
    for _ in range(4):
        n = random.randint(1, 10)
        m = random.randint(1, 10)
        a = [random.randint(-10, 10) for _ in range(n)]
        b = [random.randint(-10, 10) for _ in range(m)]
        test_cases.append((n, m, a, b))
    
    # 3. 中等规模
    sizes = [(100, 100), (500, 500), (1000, 1000), (5000, 5000)]
    for n, m in sizes:
        a = [random.randint(-100, 100) for _ in range(n)]
        b = [random.randint(-100, 100) for _ in range(m)]
        test_cases.append((n, m, a, b))
    
    # 4. 特殊案例
    # 全零
    test_cases.append((100, 100, [0]*100, [random.randint(-100, 100) for _ in range(100)]))
    # 全一
    test_cases.append((50, 50, [1]*50, [1]*50))
    # 大系数
    test_cases.append((100, 100, [random.randint(80, 100) for _ in range(100)], 
                                 [random.randint(80, 100) for _ in range(100)]))
    
    # 5. 大规模案例 (接近10^5)
    large_sizes = [(50000, 50000), (80000, 80000), (100000, 100000)]
    for n, m in large_sizes:
        a = [random.randint(-100, 100) for _ in range(n)]
        b = [random.randint(-100, 100) for _ in range(m)]
        test_cases.append((n, m, a, b))
    
    return test_cases

def main():
    print("正在生成多项式乘法测试数据...")
    
    test_cases = generate_polynomial_test_cases()
    
    for i, (n, m, a, b) in enumerate(test_cases, 1):
        filename = f"testcase_{i:02d}.in"
        with open(filename, 'w') as f:
            f.write(f"{n} {m}\n")
            f.write(" ".join(map(str, a)) + "\n")
            f.write(" ".join(map(str, b)) + "\n")
        
        print(f"生成 {filename}: {n}×{m} 规模")
    
    print(f"\n完成！共生成 {len(test_cases)} 个测试用例")
    print("包含从小规模到最大规模(10^5)的各种情况")

if __name__ == "__main__":
    main()