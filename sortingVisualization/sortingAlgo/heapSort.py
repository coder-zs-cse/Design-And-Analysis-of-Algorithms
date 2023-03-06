def heapify(nums,n,index):
    root = nums[index]
    left = 2*index+1
    right = 2*index+2
    largest = index
    if left<n and nums[left]>nums[largest]:
        largest = left
    if right<n and nums[right]>nums[largest]:
        largest = right
    if largest!= index:
        nums[index] = nums[largest]
        nums[largest] = root
        heapify(nums,n,largest)

def heapSort(nums,n):
    for i in reversed(range(0,(int)(n/2))):
        heapify(nums,n,i)
    
    for i in range(1,n):
        temp = nums[n-i]
        nums[n-i] = nums[0]
        nums[0] = temp
        heapify(nums,n-i,0)

