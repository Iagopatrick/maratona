
def decodificador(palavra):
    tamanho = int(len(palavra)/2)
    decodificada = ""
    final = ""
    
    for i in range(tamanho):
        decodificada += palavra[tamanho - i-1] #vai da metade até o inicio
        final += palavra[-i - 1] #vai do final até a metade
    
    decodificada += final
    return decodificada
    


def main():
    num = int(input())
    for i in range(num):
        entrada = input()
        
        palavra = decodificador(entrada)
        print(palavra)



main()
