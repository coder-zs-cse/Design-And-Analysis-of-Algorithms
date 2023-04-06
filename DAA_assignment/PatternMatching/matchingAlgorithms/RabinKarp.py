import math
import functools
def RabinKarp_PM(string, pattern):

    d = 256
    q = 1000000007
    m = len(pattern)
    n = len(string)
    h = functools.reduce(lambda acc, x: (acc*d)%q,range(m-1),1)
    
    patternHash = 0
    substringHash = 0

    patternHash = functools.reduce(lambda acc, c: ((d*acc)%q + ord(c))%q, pattern,0)
    substringHash = functools.reduce(lambda acc,c:((d*acc)%q + ord(c))%q, string[:m],0)

    for s in range(n-m):
        if patternHash == substringHash:
            for i in range(m):
                if string[i+s] != pattern[i]:
                    break
            else:
                return s
        else:
            substringHash = (d*((substringHash - (h*(ord(string[s])%q)))%q) + ord(string[s+m]))%q
    return n-m if patternHash==substringHash else -1

print(RabinKarp_PM("aabcaabcaabd","aabd"))
