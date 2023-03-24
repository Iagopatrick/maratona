import queue

while True:
    pilha = queue.LifoQueue()
    try:
        entrada = input()

        for carac in entrada:
            if carac == '(':
                pilha.put(carac)
            if carac == ')' and not pilha.empty():
                pilha.get_nowait()
            elif carac == ')':
                pilha.put(carac)
                break

        if pilha.empty():
            print('correct')
        else:
            print('incorrect')
    except EOFError:
        break