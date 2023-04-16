# 16/04 tomei timelimit - max 3

while True:
    try:
        entrada = [int(i) for i in input().split()]
        n = entrada[0] #numero de linhas a serem lidas
        m = entrada[1] #comandos a serem feitos
        u = entrada[2] #numero máximo das entradas
        lista = []
        for i in range(n):
            lista.append(int(input()))
        for k in range(m):
            comandos = [int(i) for i in input().split()]
            l = comandos[0] - 1 #indice inicial para começar a comparação, vou colocar -1 para começar em 0, começo da lista
            r = comandos[1] - 1 #indice final da comparação, vou colocar -1 para seguir o raciocinio, onde o começo é 0 e não 1
            v = comandos[2] #numero a ser comparado
            p = comandos[3] - 1 #indice a ser mudado, é preciso ser -1 para continuar com o raciocinio
            k = 0 #contador dos numeros inferiores a v
            for j in lista[l:r+1]:
                if j < v:
                    k += 1
            novoNumero = int((u * k)/(r - l + 1))
            lista[p] = novoNumero

    except EOFError:
        break

for saida in lista:
    print(saida)