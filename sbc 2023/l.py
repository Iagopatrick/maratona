word = input()
n = int(input())
wordB = word
wordC = word
wordG = wordB
s = len(word)
for i in range(int(len(word)/2)):
    
    wordB[i+n] = word[i]
    wordB[i] = word[i + n]

    wordC[s-i] = word[s - n]
    wordC[s - n] = word[s-i]

    wordG = wordC if wordC > wordB else wordB
print(wordG)