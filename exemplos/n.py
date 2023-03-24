while True:
    entrada = input().split()
    if(entrada == "0 0"): break

    cartasAlice = set()
    cartasBeatriz = set()

    for i in input().split():
        cartasAlice.add(int(i))
    # print(cartasAlice)
    for i in input().split():
        cartasBeatriz.add(int(i))
    # print(cartasBeatriz)
    

    if len(cartasAlice) < len(cartasBeatriz):
        # print(cartasAlice.difference(cartasBeatriz))
        print(len(cartasAlice.difference(cartasBeatriz)))
    else:
        # print(cartasBeatriz.difference(cartasAlice))
        print(len(cartasBeatriz.difference(cartasAlice)))
