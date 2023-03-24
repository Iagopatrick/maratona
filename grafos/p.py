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

#[V, V, V, V, V, V, V, V]

def componentesConexos(listaAdj, vertices):
    explorados = [False]*vertices
    componentes = 0
    for i in range(vertices):
        if explorados[i] == False:
            componentes+=1
            buscaProf(listaAdj, i, explorados)

    return componentes


def buscaProf (listaAdj, origem, explorados):
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
        explorados[origem] = True
    

def main():
    casosTeste = int(input())
    for caso in range(casosTeste):
        a = input()

        #VERIFICAÇÃO POIS A ENTRADA DO BEECROWD TAVA ERRADA.
        if " " in a:    #Se tiver espaço, os dois numeros foram inseridos na mesma linha, 
                        #então a gente faz o split
            a = a.split()
            v = int(a[0])
            e = int(a[1])
        else:           #Se não, a leitura ta normal, e a gente só segue o fluxo
            v = int(a)
            e = int(input())
        
        listaAdj = {}
        for i in range(v):
            listaAdj[i] = []
            
        for i in range(e):
            vertices = input().split()
            a = int(vertices[0])-1
            b = int(vertices[1])-1
            #{0 = [1]
            # 1 = []
            # 2 = []
            # 3 = [0]
            # }

            listaAdj[a].append(b)
            listaAdj[b].append(a)

        componentes = componentesConexos(listaAdj, v)
        if componentes == 1:
            print(f"Caso #{caso+1}: a promessa foi cumprida")
        else:
            print(f"Caso #{caso+1}: ainda falta(m) {componentes-1} estrada(s)")


main()