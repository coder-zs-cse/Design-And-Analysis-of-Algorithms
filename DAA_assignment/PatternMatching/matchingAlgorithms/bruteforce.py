def bruteforce_PM(string,pattern):
    for i in range(len(string)-len(pattern)+1):
        j = 0
        while j<len(pattern):
            if string[i+j]!=pattern[j]:
                break
            j+=1
        if j==len(pattern):
            return i
    return -1
