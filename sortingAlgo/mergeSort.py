def merge(nums,left,mid,right):
    leftArrSize = mid - left + 1
    rightArrSize = right - mid
    leftArr = []
    rightArr = []
    for i in range(0,leftArrSize):
        leftArr.append(nums[left+i])
    for i in range(0,rightArrSize):
        rightArr.append(nums[mid+1+i])
    i = 0
    j = 0
    k = left
    while i<leftArrSize and j<rightArrSize:
        if leftArr[i]<=rightArr[j]:
            nums[k] = leftArr[i]
            i+=1
        else:
            nums[k] = rightArr[j]
            j+=1
        k+=1
    while i<leftArrSize:
        nums[k] = leftArr[i]
        i+=1
        k+=1
    while j<rightArrSize:
        nums[k] = rightArr[j]
        j+=1
        k+=1


def divideAndConquer(nums,left,right):
    if left<right:
        mid = left + (right-left)//2
        divideAndConquer(nums,left,mid)
        divideAndConquer(nums,mid+1,right)
        merge(nums,left,mid,right)

# def merge(arr, l, m, r):
#     n1 = m - l + 1
#     n2 = r - m

#     L = [0] * (n1)
#     R = [0] * (n2)


#     for i in range(0, n1):
#         L[i] = arr[l + i]

#     for j in range(0, n2):
#         R[j] = arr[m + 1 + j]

#     i = 0     
#     j = 0    
#     k = l     

#     while i < n1 and j < n2:
#         if L[i] <= R[j]:
#             arr[k] = L[i]
#             i += 1
#         else:
#             arr[k] = R[j]
#             j += 1
#         k += 1

#     while i < n1:
#         arr[k] = L[i]
#         i += 1
#         k += 1

#     while j < n2:
#         arr[k] = R[j]
#         j += 1
#         k += 1

# def divideAndConquer(arr, l, r):
#     if l < r:

#         m = l+(r-l)//2

#         divideAndConquer(arr, l, m)
#         divideAndConquer(arr, m+1, r)
#         merge(arr, l, m, r)

def mergeSort(nums,n):
    divideAndConquer(nums,0,n-1)



