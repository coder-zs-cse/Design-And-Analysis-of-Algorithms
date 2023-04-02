def bruteforce(arr):
    mini = arr[0]
    maxi = arr[0]
    for i in range(1,len(arr)):
        if arr[i]<mini:
            mini = arr[i]
        if arr[i]>maxi:
            maxi = arr[i]
    return (mini,maxi)
arr = [1,2,3,5,2,1,4,3,3,122,2,55,12]
# print(bruteforce(arr))
