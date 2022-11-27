
numVagoes=1
saidas = []
flag = True
vagoes = []
while numVagoes != 0:
    numVagoes = int(input())
    if(numVagoes != 0):
        vagoes = [int(i) for i in input().split()]
        while vagoes[0] != 0:
            
            for i in range(len(vagoes)):
                if  vagoes[i + 1] != vagoes[i] + 1 or  vagoes[i] != vagoes[i + 1] - 1:
                    flag = False
                    
            if(flag == False):
                saidas.append("No")
            else:
                saidas.append("Yes")
            vagoes = [int(i) for i in input().split()]
    print(" ")

for i in range(len(saidas)):
    print(saidas[i]);

