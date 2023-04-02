def fun(num):
    to = 0
    sqr = num ** 2
    while sqr > 0:
        to += sqr% 10
        sqr //= 10
    return to
def funct(nums):
    lst = []
    for num in range(nums):
        if fun(num) == num:
            lst.append(num)
    return sum(lst)

print(funct(100000))