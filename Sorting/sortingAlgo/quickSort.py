def pivot(nums,left,right):
    k = left
    value = nums[right]
    for i in range(left,right):
        if nums[i]<=value:
            (nums[k],nums[i]) = (nums[i],nums[k])
            k+=1
    (nums[k],nums[right]) = (nums[right],nums[k])
    return k

def divideAndConquer(nums,left,right):
    if left<right:
        pi = pivot(nums,left,right)
        divideAndConquer(nums,left,pi-1)
        divideAndConquer(nums,pi+1,right)


def quickSort(nums,n):
    divideAndConquer(nums,0,n-1)
