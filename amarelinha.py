entrada = [int(j) for j in input().split()]
n = entrada[0]
q = entrada[1]
posicao = [int(j) for j in input().split()]
derrota = [-1]*n
for i in range(q):
    rodada = [int(j) for j in input().split()]
    c = rodada[0]
    d = rodada[1]
    for k in range(1,n):
        if c % (k+1) == 0 or (k+1) % c == 0:
            if posicao[k] != 0:
                posicao[k] = 0 if posicao[k] - d <= 0 else posicao[k] - d
                if posicao[k] == 0:
                    derrota[k] = i + 1
for i in range(n):
    print(derrota[i])

