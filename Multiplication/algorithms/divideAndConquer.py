import math
def divideAndConquer(a,b):
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
    pr = divideAndConquer(p,r)
    ps = divideAndConquer(p,s)
    qr = divideAndConquer(q,r)
    qs = divideAndConquer(q,s)
    # print(pr,ps,qr,qs)
    power = n - n//2
    output = (math.pow(10,(2*power)))*pr + math.pow(10,power)*(ps+qr) + qs
    # print(output)
    return (output)

a="192"
b="28"
print(divideAndConquer(a,b))