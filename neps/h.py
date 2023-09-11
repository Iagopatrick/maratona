n = int(input())
a = [int(i) for i in input().split()]
m = int(input())
b = [int(i) for i in input().split()]
pont = 0

for i in range(n):
    pont += a[i]
    if pont in b:
        pont = 0

print(pont)