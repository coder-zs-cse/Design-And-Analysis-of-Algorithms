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
            
def mergefourway(arr,left,mid1,mid,mid2,right):
    merge(arr,left,mid1,mid)
    merge(arr,mid+1,mid2,right)
    merge(arr,left,mid,right)


def divideAndConquerModified(arr,left,right):
    if left<right:
        mid = left + (right-left)//2
        mid1 = left + (mid-left)//2
        mid2 = mid+1 + (right-mid-1)//2

        divideAndConquerModified(arr,mid1+1,mid)
        divideAndConquerModified(arr,left,mid1)
        divideAndConquerModified(arr,mid+1,mid2)
        divideAndConquerModified(arr,mid2+1,right)

        mergefourway(arr,left,mid1,mid,mid2,right)
    
        

def modifiedMergeSort(arr,n):
    divideAndConquerModified(arr,0,n-1)