print("欢迎来到购物车系统！")

print()

print("########## 购物车系统 ##########")
print("#        1. 添加购物车          ")
print("#        2. 修改购物车          ")
print("#        3. 删除购物车          ")
print("#        4. 查询购物车          ")
print("#        5. 退出购物车          ")



shopping_cart = {}

n = 0
while n != 5:
    n = int(input("请选择要执行的操作(1-5):"))
    if n == 1:
        product_name = input("请输入要添加的商品名称:")
        product_price = float(input("请输入要添加的商品价格:"))
        shopping_cart[product_name] = product_price
        print("商品已添加到购物车！")
    elif n == 2:
        product_name = input("请输入要修改的商品名称:")
        if product_name in shopping_cart:
            new_price = float(input("请输入新的商品价格:"))
            shopping_cart[product_name] = new_price
            print("商品价格已修改！")
        else:
            print("购物车中没有该商品！")
    elif n == 3:
        product_name = input("请输入要删除的商品名称:")
        if product_name in shopping_cart:
            del shopping_cart[product_name]
            print("商品已从购物车中删除！")
        else:
            print("购物车中没有该商品！")
    elif n == 4:
        if shopping_cart:
            print("购物车中的商品:")
            for product_name, product_price in shopping_cart.items():
                print(f"{product_name}: {product_price}元")
        else:
            print("购物车为空！")
    elif n == 5:
        print("退出购物车系统！")
    else:
        print("无效的操作，请选择1-5之间的数字！")