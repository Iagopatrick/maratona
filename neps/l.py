n = int(input())
m = [int(i) for i in input().split()]
saida = [1] * n
for i in range(n):
    for j in range(n):
        if m[i] > m[j]:
            saida[i] += 1
    print(saida[i])

