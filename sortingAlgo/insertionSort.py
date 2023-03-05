def insertionSort(nums,n):
    for i in range(1,n):
        index = i-1
        value = nums[i]
        while index>=0 and nums[index]>value:
            nums[index+1] = nums[index]
            index-=1
        nums[index+1] = value
