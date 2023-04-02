def KMP_PM(string,pattern):
    lps = [0]
    index = 0
    i=1
    while i<len(pattern):
        if pattern[index]==pattern[i]:
            index+=1
            lps.append(index)
            i+=1
        else:
            if index==0:
                lps.append(0)
                i+=1
            else:
                index = lps[index-1]
    j = 0 # pattern iterator
    i = 0 # string iterator
    while i<(len(string)-len(pattern))+1:
        while j<len(pattern):
            if string[i+j]!=pattern[j]:
                break
            j+=1
        if j==len(pattern):
            return i
        else:
            if j==0: 
                i+=1
            else:
                i = i+j-lps[j-1]
                j = lps[j-1]
    return -1

print(KMP_PM("aabcaabcaabd","bcaabd"))