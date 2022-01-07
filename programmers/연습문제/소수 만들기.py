from itertools import combinations
import math

def isPrime(n):
    if n < 2:
        return False
    
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0:
            return False
    return True

def solution(nums):
    answer = 0
    
    comb = list(combinations(nums, 3))
    
    for arr in comb:
        if isPrime(sum(arr)):
            answer += 1

    return answer