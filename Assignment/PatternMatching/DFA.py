def patternInString(string,pattern):
    DFA = [0]*len(pattern)
    lastMatchingIndex = 1
    for i in range(1,len(pattern)):
        if pattern[i] == pattern[lastMatchingIndex-1]:
            DFA[i] = lastMatchingIndex
            lastMatchingIndex+=1
        else:
            while lastMatchingIndex!=0 and pattern[lastMatchingIndex-1]!=pattern[i]:
                lastMatchingIndex = DFA[lastMatchingIndex-1]
            DFA[i] = lastMatchingIndex
            lastMatchingIndex+=1
    print(DFA)
    j = 0
    for i in range(len(string)-len(pattern)+1):
        while j<len(pattern) and pattern[j]==string[i+j]:
            j+=1
        if j==len(pattern): return i
        else:
            while j!=0 and pattern[j]!=string[i+j]:
                j = DFA[j-1]
        print(j)
    return -1

print(patternInString("aabcaabcaabd","bcaabde"))


