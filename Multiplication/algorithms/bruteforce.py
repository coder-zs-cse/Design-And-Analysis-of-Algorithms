def bruteforce(a,b):
    n = len(a)
    m = len(b)
    result = [0]*(n+m)
    carry =0 
    for i in reversed(range(0,len(b))):
        carry=0
        for j in reversed(range(0,len(a))):
            current = result[i+j+1] + carry + int(a[j])*int(b[i])
            result[i+j+1] = current%10
            carry = current//10
        if carry>0:
            result[i] += carry
    result = "".join(str(element) for element in result)

    return str(int(result))
            
a="1267"
b="34"
print(bruteforce(a,b))