def contaConexos(listaAdj, numVertices):
    explorados = [False] * numVertices
    componentes = 0
    for i in range(numVertices):
        if explorados[i] == False:
            componentes += 1
            componentesConexos(listaAdj, i, explorados)
    return componentes
        


def componentesConexos(listaAdj, origem, exploradosFV):
    explorados = []
    alcancados = []
    alcancados.append(origem)
    while len(alcancados) != 0:
        origem = alcancados[0]
        for adjacentes in listaAdj[origem]:
            if adjacentes not in explorados and adjacentes not in alcancados:
                alcancados.append(adjacentes)
        alcancados.remove(origem)
        explorados.append(origem)
        exploradosFV[origem] = True

def main():
    numTestes = int(input())
    for caso in range(numTestes):
        a = input()
        if " " in a:
            a = a.split()
            pontosDaCidade = int(a[0])
            estradasConstruidas = int(a[1])
        else:
            pontosDaCidade = int(a)
            estradasConstruidas = int(input())

        listaAdj = {}
        for j in range(pontosDaCidade):
            listaAdj[j] = []

        for i in range(estradasConstruidas):
            vertices = input().split()
            a = int(vertices[0]) - 1
            b = int(vertices[1]) - 1 #para começar em zero
            listaAdj[a].append(b)
            listaAdj[b].append(a)
        componentes = contaConexos(listaAdj, pontosDaCidade)
        if componentes == 1:
            print(f"Caso #{caso+1}: a promessa foi cumprida")
        else:
            print(f"Caso #{caso+1}: ainda falta(m) {componentes-1} estrada(s)")
main()

