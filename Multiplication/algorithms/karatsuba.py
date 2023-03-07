import math
def karatsuba(a,b):
    if len(a)==1 and len(b)==1:
        return int(a)*int(b)
    maxLen = max(len(a),len(b))
    a = a.zfill(maxLen)
    b = b.zfill(maxLen)
    n = len(a)
    m = len(b)
    p = a[0:n//2]
    q = a[n//2:]
    r = b[0:m//2]
    s = b[m//2:]
    # print(a,b,p,q,r,s)
    x = str(int(p) + int(q))
    y = str(int(r) + int(s))

    pr = karatsuba(p,r)
    qs = karatsuba(q,s)
    xy = karatsuba(x,y)
    # print(pr,ps,qr,qs)
    power = n - n//2
    output = (math.pow(10,(2*power)))*pr + math.pow(10,power)*(xy-pr-qs) + qs
    # print(output)
    return (output)

a="192"
b="288"
print(karatsuba(a,b))