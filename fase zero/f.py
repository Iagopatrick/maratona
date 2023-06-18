

def main():
    n,m = [int(l) for l in input().split()]
    dna = input()
    dnaN = input()
    entradas = int(input())
    for i in range(entradas):
            j,k = [int(l) for l in input().split()]
            j -= 1
            k -= 1
            cont = 0
            tamanho = len(dnaN[j:k+1])
            if dnaN[j:k+1] not in dna:
                print(cont)
            else:
                inicio = dna.find(dnaN[j:k+1])
                fim = dna.rfind(dnaN[j:k+1])
                if fim - inicio != 0:
                    for t in range(inicio, fim, fim - inicio):
                        if dna[t:tamanho+1] == dnaN[j:k+1]:
                            cont += 1
                else:
                    cont += 1
                print(cont)
                    
main()