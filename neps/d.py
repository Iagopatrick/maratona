n = int(input())
a = [int(i) - 1 for i in input().split()]
d1 = [0] * n



for i in range(n*2 - 1):
    d1[a[i]] += 1

print(d1.index(1) + 1)
