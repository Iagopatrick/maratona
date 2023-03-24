import queue
pilha = queue.LifoQueue()

entradas = input()
contador = 0
for i in range(int(entradas)):
    num = int(input())
    if num == 1 and pilha.empty():
        pilha.put(num)
    elif num == 1 and pilha[-1] == 2:
        contador += 3
        pilha = []
    elif num == 2 and pilha[-1] == 1:
        pilha.put(num)
    elif num == 2 and pilha.empty():
        pilha.put(num)
    elif num == 2 and pilha[-1] == 2:
        contador += 1
        pilha = []
    elif num == 2 and pilha[-1] == 1:
        pilha = []
        pilha.get(num)

print(contador)
