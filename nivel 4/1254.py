def kmp(word):
    pi = []
    j = 0
    for i in range(1, len(word)):
        if(word[j] == word[i]):
            pi.push(j)
            j+=1
        else:
            if j != 0:
                j = pi[j]
            pi.push(j)
    return pi
    


def main():
    while True:
        try:
            tag = input()
            newTag = input()
            text = input()
            resp = ""
            pi = []
            lowerText = text.lower()
            lowerTag = tag.lower()
            flag = False
            pi = kmp(tag)
            j = 0
            aux = ""
            while c in range(len(lowerText)):
                if(lowerText[c] == '<'):
                    flag = True
                elif(lowerText[c] == '>'):
                    flag = False
                if(flag):
                    if(lowerText[c] == lowerTag[j]):
                        j += 1
                        aux += lowerText[c]
                        if(j == len(tag) - 1):
                            j = 0
                            resp += tag
                            aux = ""
                        continue
                    else:
                        j = pi[j]
                        resp += text[c]
                        continue
                resp += text[c]

                    
            print(resp)
        except:
            break
main()     