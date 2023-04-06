def insertionSort(nums,n):
    for i in range(1,n):
        prevIndex = i-1
        value = nums[i]
        while prevIndex>=0 and nums[prevIndex]>value:
            nums[prevIndex+1] = nums[prevIndex]
            prevIndex-=1
        nums[prevIndex+1] = value

