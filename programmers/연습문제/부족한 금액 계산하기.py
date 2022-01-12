def solution(price, money, count):
    sum = 0
    
    for idx in range(1, count + 1):
        sum += price * idx
        
    if sum < money:
        return 0

    return abs(money - sum)