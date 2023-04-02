def selectionSort(nums,n):
    for i in range(0,n):
        mini = i
        for j in range(i+1,n):
            if nums[j]<nums[mini]:
                mini = j
        temp = nums[mini]
        nums[mini] = nums[i]
        nums[i] = temp

