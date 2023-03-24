import queue

def removeString(diagrama, pilha):
    removidaI = ""
    removidaII = ""
    print(diagrama + "é aq")
    last = pilha.get()
    while not pilha.empty():
        temp = pilha.get()
        removidaI += temp
    removidaII += removidaI[-1] + removidaI[:-1] + last
    diagrama = diagrama.replace(removidaII, "") 

    print(removidaII)
    print(diagrama)
    return diagrama

def clear(pilha):
    while not pilha.empty():
        try:
            pilha.get()
        except:
            break
    return pilha

def main():
    entrada = int(input())
    for i in range(entrada):
        diagrama = input()
        diamantes = 0
        contador = 0
        inicio = 0
        fim = 0
        while True:
            pilha = queue.LifoQueue()
            try:
                while '<' in diagrama and '>' in diagrama:
                    if diagrama[contador] == '<' and pilha.empty():
                        pilha.put(diagrama[contador])
                        inicio = 1
                    elif diagrama[contador] == '<' and not pilha.empty():
                        pilha = clear(pilha)
                        pilha.put(diagrama[contador])
                        inicio = i
                    elif diagrama[contador] == '>' and not pilha.empty():
                        pilha.put(diagrama[contador])
                        fim = i
                        # print("aqui estou")
                        pilha = clear(pilha)
                        diamantes += 1
                        contador = 0
                    elif diagrama[contador] == '.' and not pilha.empty():
                        pilha.put(diagrama[contador])
                    contador += 1
                    
            except:
                break
        print(diamantes)    
main()
    