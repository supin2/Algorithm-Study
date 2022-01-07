def solution(array, commands):
    answer = []
    
    for c in commands:
        a = c[0] - 1
        b = c[1]
        lst = array[a:b]
        lst.sort()
        answer.append(lst[c[2] - 1])
        
    return answer