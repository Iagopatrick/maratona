
n = int(input())
v = []
for i in range(n):
    j = input()
    v.append(j)
v.sort(key= lambda x: ord(x), reverse=True)

a = ""
for i in range(n):
    a += v[i]
print(a)
