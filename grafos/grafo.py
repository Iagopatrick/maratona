def componentesConexos(listaAdj, origem, numVertices):
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
    if len(explorados) != numVertices:
        print("Nao conexo")
    else:
        print("Conexo")

def main():
    entrada = input().split()
    numVertices = int(entrada[0])
    numEntradas = int(entrada[1])
    listaAdj = {} #fazendo um dicionario que irá ter as listas
    for i in range(numEntradas):
        vertices = input().split()
        a = int(vertices[0])
        b = int(vertices[1])
        if a in listaAdj:
            listaAdj[a].append(b)
        else:
            listaAdj[a] = [b]
        
        if b in listaAdj:
            listaAdj[b].append(a)
        else:
            listaAdj[b] = [a]
    componentesConexos(listaAdj, 0, numVertices)
main()

