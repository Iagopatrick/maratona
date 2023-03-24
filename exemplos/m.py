conj = set()
while True:
    try:
        entrada = input()
        conj.add(entrada)
    except EOFError:
        print(len(conj))
        break