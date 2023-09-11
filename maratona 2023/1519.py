import queue



frase = ""

while frase != ".":
    frase = input().split()
    filaP = queue.PriorityQueue() 
    for i in range(len(frase)):
        temp = [frase[i], i, frase[i]]
        filaP.put(temp)
    
    f = 0
    contador = 0
    uL = ""
    vetor = [0] * 26
    for i in range(len(frase)):
        
        final = filaP.get()
        if len(final[2]) > 2:
            if uL == frase[2][0]:
                f += 1
            else:
                f = 0

            
            if f > 0:
                for j in range(1, len(frase[2])):
                    if vetor[ord(final[2][i]) - 97] == 0:
                        temp = j 
                        break
                final[2] = (final[2][temp] + ".") if len(final[2][temp]) < len(final[2]) else final[2]
                print(final[2][temp])
                vetor[ord(final[2][temp]) - 97] += 1
            else:
                final[2] = final[2][0] + "."
                vetor = [0] * 26
            uL = final[2][0]

        print(final)    


    