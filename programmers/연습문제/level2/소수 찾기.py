from itertools import permutations
from math import sqrt

def isPrime(n):
    if n < 2: 
        return False

    for i in range(2, int(sqrt(n))+1):
        if n % i == 0:
            return False
    return True


def solution(numbers):
    answer = []
    
    for k in range(1, len(numbers)+1):
        lst = list(map(''.join, permutations(list(numbers), k)))
        
        for i in list(set(lst)):
            if isPrime(int(i)):
                answer.append(int(i))

    answer = len(set(answer))
    return answer