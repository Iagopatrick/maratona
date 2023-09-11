
def troca(p):
    
    if(p == 'j'):
        p = 'J'
    elif p == 'i':
        p = 'I'
    else:
        p = 'O'
    return p

def main():
    n = int(input())
    s = input()

    _s = s + " "
   
    nova = ""
    
    flag = False
    for i in range(n):
        if flag:
            flag = False
            continue
        if _s[i] == _s[i+1]:
            nova += troca(s[i])
            nova += troca(s[i+1])
            flag = True
           
           
        else:
            
            nova += _s[i]
        

    print(nova)

main()
