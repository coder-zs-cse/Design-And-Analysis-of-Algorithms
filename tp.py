def max_subseq_sum_dc(A):
    n = len(A)
    
    if n == 1:
        return A[0]
    
    m = (n + 1) // 2
    max_left = max_subseq_sum_dc(A[:m])
    max_right = max_subseq_sum_dc(A[m:])
    
    # Find the maximum subsequence sum that crosses the midpoint
    left_sum = A[m-1]
    left_max = A[m-1]
    for i in range(m-2, -1, -1):
        left_sum += A[i]
        left_max = max(left_max, left_sum)
        
    right_sum = A[m]
    right_max = A[m]
    for i in range(m+1, n):
        right_sum += A[i]
        right_max = max(right_max, right_sum)
    
    cross_max = left_max + right_max
    
    return max(max_left, max_right, cross_max)

# Example usage
A = [-2, -5, 6, -2, -3, 1, 5, -6]
print(max_subseq_sum_dc(A))
