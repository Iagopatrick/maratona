import queue
def main():
    while True:
        try:
            pilha = queue.LifoQueue()
            entrada = input()
            saida = "incorret"
            balanco = 0
            for caracter in entrada:
                if pilha.empty() and caracter == '(':
                    pilha.put(caracter)
                    balanco += 1
                elif pilha.empty() and caracter == ')':
                    break
                elif not pilha.empty() and caracter == ')':
                    pilha.put(caracter)
                    balanco += 1
                elif not pilha.empty() and caracter == '(':
                    pilha.put(caracter)
                    balanco += 1


            if not pilha.empty() and balanco % 2 == 0:
                saida = "correct"

            print(saida)
        except EOFError:
            break

main()