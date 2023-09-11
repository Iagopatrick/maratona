n = int(input())
s = input()


if s[0:int(n/2)] == s[int(n/2):]:
    print("Yes")
else:
    print("No")
