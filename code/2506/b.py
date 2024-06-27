import math as m
t = int(input())

for i in range(t):
    x, y, k = [int(x) for x in input().split()]
    aux = k
    _k = 0
    while _k < k:
        divisor = int(x/y) + 1
        ob = divisor * y
        _k += abs(ob-x)
        if(_k > k):
            x += aux
            continue
        x = ob
        if aux - _k >= 0:
            aux -= _k
        else:
            aux = 0
            print(f"Meu _k foi: {_k}")
        
        
        x = int(m.log10(x)/m.log10(y))
    print(x)
