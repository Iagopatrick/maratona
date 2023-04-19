while True:
    try:
        entrada = [int(i) for i in input().split()]
        entrada1 = entrada[0]
        entrada2 = entrada[1]
        if entrada1 > entrada2:
            maior = entrada1
            menor = entrada2
        else:
            maior = entrada2
            menor = entrada1
        print(maior - menor)
    except EOFError:
        break