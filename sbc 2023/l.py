s,k  = input().split()
k = int(k)
s1 = [i for i in s]
for i in range(0,len(s),k):
    aux = s1[i]
    s1[i] = s1[k-i]
    s1[k-i] = aux
    print(s1)

print(s1)