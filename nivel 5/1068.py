import queue
def main():
    while True:
        try:
            entrada = ""
            pilha = queue.LifoQueue()
            entrada = input()
            if entrada == "":
                break
            saida = "incorrect"
            balanco = 0
            for caracter in entrada:
                if pilha.empty() and caracter == ')':
                    print("incorrect")
                    break
                elif caracter == ')':
                    balanco -= 1
                    pilha.put(caracter)
                elif caracter == '(':
                    balanco += 1
                    pilha.put(caracter)
            if balanco == 0 and not pilha.empty():
                saida = "correct"
                

            print(saida)
        except EOFError:
            break

main()