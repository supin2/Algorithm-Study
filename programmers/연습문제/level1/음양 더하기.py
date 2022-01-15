def solution(absolutes, signs):
    answer = 0
    
    for i in range(len(signs)):
        flag = signs[i]
        if flag == True:
            answer += absolutes[i]
        else:
            answer -= absolutes[i]
    return answer