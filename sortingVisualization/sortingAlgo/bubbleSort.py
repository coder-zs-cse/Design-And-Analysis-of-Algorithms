def bubbleSort(nums,n):
    for i in range(1,n):
        for j in reversed(range(i,n)):
            if nums[j]<nums[j-1]:
                temp = nums[j]
                nums[j] = nums[j-1]
                nums[j-1] = temp
    
