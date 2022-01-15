def solution(num):
    for i in range(1, 501):
        if num == 1:
            return i - 1
        num = num / 2 if num % 2 == 0 else num * 3 + 1
    return -1