def solution(dartResult):
    answer = []
    temp = ''
    bonus = { 'S': 1, 'D': 2, 'T': 3 }
    
    for ch in dartResult:
        if ch.isnumeric():
            temp += ch
        elif ch in ('S', 'D', 'T'):
            score = int(temp)
            temp = ''
            answer.append(score ** bonus[ch])
        elif ch == '*':
            score = answer.pop()
            if len(answer):
                answer[-1] *= 2
            answer.append(score * 2)
        elif ch == '#':
            answer[-1] *= -1
        
    return sum(answer)