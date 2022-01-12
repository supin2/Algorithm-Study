def solution(arr):
    answer = []
    last = -1
    
    for i in range(len(arr)):
        if last != arr[i]:
            answer.append(arr[i])
            last = arr[i]
            
    return answer