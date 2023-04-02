def divideAndConquerAlgo(arr,start,end):
    n = end-start+1
    if n<=2:
        if arr[start]<arr[end]:
            return (arr[start],arr[end])
        else :
            return (arr[end],arr[start])
    (min1,max1) = divideAndConquerAlgo(arr,start,start + n//2)
    (min2,max2) = divideAndConquerAlgo(arr,start+n//2,end)
    return (min(min1,min2),max(max1,max2))

def divideAndConquer(arr):
    return divideAndConquerAlgo(arr,0,len(arr)-1)

arr = [2,3,4,5,3,1,344,5,55,32,12,234,34]
# print(divideAndConquer(arr))