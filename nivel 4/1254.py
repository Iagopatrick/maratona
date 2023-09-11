def changeTag(text, lowerText, tag, newTag):
    index = len(tag)

    for i in range(0, len(lowerText[1:-1]), index):
        if lowerText[i:index+1] == tag:
            text[i:index+1] = newTag
            print(text[i:index+1])
    return text


def main():
    while True:
        
        tag = input().lower()
        newTag = input()
        text = input()
        newText = text
        lowerText = text.lower()
        index =  text.find('<')  
        rIndex = text.find('>') 
        while index != -1:
            lowerText[index:rIndex+1]
            newText = changeTag(newText, lowerText, tag, newTag)
            index = text.find('<', rIndex + 1)
            rIndex = text.find('>', index)
                
        print(newText)
main()     