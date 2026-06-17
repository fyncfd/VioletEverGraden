import csv
import os

from collections import defaultdict
from statistics import mean

# print(os.listdir("."))

sales = []
with open("Project\To_Do_List\商品信息读入读出\sales.csv", mode = "r", encoding = "utf-8") as f:
    reader = csv.DictReader(f)
    for  row in reader:
        row["price"] = int(row["price"])
        row["quantity"] = int(row["quantity"])
        sales.append(row)

# print(sales[:2])

total = sum(item["price"] * item["quantity"] for item in sales)
print(f"总销售额：{total} 元")

print()

sorted_by_quantity = sorted(sales, key=lambda x: x["quantity"], reverse=True)

for item in sorted_by_quantity:
    print(f"{item['item']} 销量 {item['quantity']} 件")

print()

sorted_by_price = sorted(sales, key=lambda x: x["price"])

for item in sorted_by_price:
    print(f"{item['item']} 单价 {item['price']} 元")

print()

filtered_sales = list(filter(lambda x: x["quantity"] > 6, sales))
for item in filtered_sales:
    print(f"{item['item']}：销量 {item['quantity']}")

print()

total_qty = defaultdict(int)
total_price = defaultdict(list)

for entry in sales:
    item = entry["item"]
    total_qty[item] += entry["quantity"]
    total_price[item].append(entry["price"])

print("各商品总销量：")
for item, qty in total_qty.items():
    print(f"{item}: {qty} 件")

print("\n各商品平均单价：")
for item, prices in total_price.items():
    avg = mean(prices)
    print(f"{item}: {avg:.2f} 元")

print()

revenue_by_item = defaultdict(int)

for entry in sales:
    revenue_by_item[entry["item"]] += entry["price"] * entry["quantity"]

sorted_revenue = sorted(revenue_by_item.items(), key=lambda x: x[1], reverse=True)

print("商品销售额排名：")
for item, revenue in sorted_revenue:
    print(f"{item}: {revenue} 元")