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