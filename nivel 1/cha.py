cha_certo = input()
entrada = input().split()
contador = 0
for cha in entrada:
    if cha == cha_certo:
        contador += 1
print(contador)