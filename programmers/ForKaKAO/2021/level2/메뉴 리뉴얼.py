import itertools

def solution(orders, course):
    answer = []
    menuMap = [{} for _ in range(11)]
    maxCnt = [0 for _ in range(11)]
    
    for menu in orders:
        for num in range(2, len(menu) + 1):
            for c in itertools.combinations(sorted(menu), num):
                candidate = ''.join(c)
                if candidate not in menuMap[num]:
                    menuMap[num][candidate] = 1
                else:
                    menuMap[num][candidate] += 1
                    maxCnt[num] = max(maxCnt[num], menuMap[num][candidate])
    
    for c in course:
        for k, v in menuMap[c].items():
            if v >= 2 and v == maxCnt[c]:
                answer.append(k)
    answer.sort()
    return answer