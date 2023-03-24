# 
# Matriz de Adj
#    a, b, c, d
# a  0  1  1  1
# b  0  0  1  0
# c  0  0  0  1
# d  0  0  1  0
# 
# Lista de Adj
# a - [ B, C, D ]
# b - [ A, C ]
# c - [ A, B, D ]
# d - [ A, C ]

# [A , B, C, D, E, F, G]
# [A, B, D, E, C, F, G]

def buscaProf (listaAdj, origem, vertices):
    alc = []
    exp = []

    alc.append(origem)

    while len(alc) != 0:
        origem = alc[0]
        for adj in listaAdj[origem]:
            if adj not in alc and adj not in exp:
                alc.append(adj)
            
        alc.remove(origem)
        exp.append(origem)
    
    if len(exp) != vertices:
        print("Desconexo")
    else:
        print("Conexo")

def main():
    entrada = input().split()
    v = int(entrada[0])
    e = int(entrada[1])
    listaAdj = {}

    for i in range(e):
        vertices = input().split()
        a = int(vertices[0])
        b = int(vertices[1])
        #{0 = [1]
        # 1 = []
        # 2 = []
        # 3 = [0]
        # }

        if a in listaAdj:
            listaAdj[a].append(b)
        else:
            listaAdj[a] = [b]
        
        if b in listaAdj:
            listaAdj[b].append(a)
        else:
            listaAdj[b] = [a]

    buscaProf(listaAdj, 0, v)


main()