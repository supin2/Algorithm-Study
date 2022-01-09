def func(num):
    cnt = 0
    for i in range(1, num + 1):
        if num % i == 0:
            cnt += 1
    return cnt

def solution(left, right):
    answer = 0
    
    for num in range(left, right + 1):
        if func(num) % 2 == 0:
            answer += num
        else:
            answer -= num
    return answer