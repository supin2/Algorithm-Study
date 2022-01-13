def solution(n):
    answer = 0
    
    for num in range(2, n + 1):
        if n % num == 1:
            answer = num
            break
    return answer