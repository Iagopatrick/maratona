import queue
def main():
    while True:
        try:
            pilha = queue.LifoQueue()
            entrada = input()
            saida = "incorrect"
            balanco = 0
            for caracter in entrada:
                if pilha.empty() and caracter == ')':
                    balanco -= 1
                    break
                elif caracter == '(' and balanco < 0:
                    break
                elif caracter == ')':
                    pilha.put(caracter)
                    balanco += -1
                elif caracter == '(':
                    pilha.put(caracter)
                    balanco += 1

            if balanco == 0:
                saida = "correct"

            print(saida)
        except:
            break

main()