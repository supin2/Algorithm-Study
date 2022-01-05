def solution(n, arr1, arr2):
    answer = []
    
    for num1, num2 in zip(arr1, arr2):
        sum = str(bin(num1 | num2)[2:])
        sum = sum.rjust(n, '0')
        sum = sum.replace('1', '#')
        sum = sum.replace('0', ' ')
        answer.append(sum)
    return answer