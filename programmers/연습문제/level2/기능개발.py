from math import ceil

def solution(progresses, speeds):
    answer = []
    progresses = [ceil((100 - a)/b) for a, b in zip(progresses, speeds)]
    pos = 0
    
    for i in range(len(progresses)):
        if progresses[i] > progresses[pos]:
            answer.append(i - pos)
            pos = i
            
    answer.append(len(progresses) - pos)
    return answer